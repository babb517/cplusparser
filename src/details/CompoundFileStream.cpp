/*
 * Copyright (c) 2010-2013 <Joseph Babb, Michael Cassollary, Joohyung Lee>
 *
 * For information on how to contact the authors, please visit
 *	http://reasoning.eas.asu.edu/cplus2asp
 *
 * This file is part of the cplus2asp system.
 *
 * cplus2asp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cplus2asp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <list>
#include <string>
#include <exception>
#include <fstream>
#include <cstring>

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/exception.hpp>
#include <boost/iostreams/device/file.hpp>

#include "details/CompoundFileStream.h"

namespace cplus_parser {
namespace details {


/**
 * @brief The number of bytes to allocate to a buffer at a time.
 */
#define BUFFER_BLOCK_SIZE 1024


/**
 * @brief Copies elements from one array to another in reverse.
 * @param src The base address of the array to copy from.
 * @param dest The base address of the array to copy to (pointing the destination of the last element to copied from src).
 */
template<typename T>
void reverse_copy(T const* src, T* dest, size_t n) {
	size_t max_i = n-1;
	for (size_t i = 0; i < n; i++) {
		dest[max_i-i] = src[i];
	}
}


/*****************************************************************************************/
/* File Context */
/*****************************************************************************************/

/// Free the context
CompoundFileSource::FileContext::~FileContext() {
	if (buf) delete buf;
	if (source) {
		if (source->is_open()) source->close();
		delete source;
	}
}

/******************************************************************************************/
/* Compound File Source */
/******************************************************************************************/

// Constructor
CompoundFileSource::CompoundFileSource(void* nullptr_hack) {
	state(CLOSED);
}

// Place a file on the stack.
bool CompoundFileSource::place(std::string const& filename, bool top) {
	// State handling...
	if (state() == ERROR) return false;

	// initialize the new context
	FileContext* context = new FileContext(filename, "", NULL, 0);

	// Step 1) Validate the name..
	//if (!boost::filesystem::native(filename)) {
	//	// The file's name isn't a valid format.
	//	delete context;
	//	return false;
	//}


	// Step 2) Attempt to resolve the file.

	// Try the present working directory...
	boost::filesystem::path filepath = boost::filesystem::absolute(filename);

	// Check if we (eventually) found it.
	if (!boost::filesystem::exists(filepath)) {
		// We don't really know where the file is.
		delete context;
		return false;
	}

	// Resolve all symlinks and finalize the path we're using.
	context->resolved = boost::filesystem::canonical(filepath).string();

	// Step 3) Ensure the file is readable and open it.
	try {
		context->source = new boost::filesystem::ifstream(filepath);
	} catch (std::exception& e) {
		// We can't open the source stream.
		// TODO: We should really throw this to some sort of debugging output.
	}
	if (!context->source || !context->source->good()) {
		// We can't open the file for some reason.
		delete context;
		return false;
	}

	// make sure we copy our locality!
	context->source->imbue(mLocale);

	// Step 4) Add the file context to the stack.
	if (top) {
		mStack.push_front(context);
	} else {
		mStack.push_back(context);
	}

	// Indicate that our state is good to go.
	state(GOOD);
	return true;
}

// Pops the top file context off the stack.
bool CompoundFileSource::nextFile() {
	if (state() == ERROR) return false;

	size_t size = mStack.size();

	// pop off the old state.
	if (size > 1) {
		delete mStack.front();
		mStack.pop_front();
		state(GOOD);
	} else {
		state(END);
	}
	return state() == GOOD;
}

void CompoundFileSource::reset() {
	if (source()) {
		source()->clear();
		state(GOOD);
	} else {
		state(END);
	}
}

// Closes the stream, freeing all available resourced.
void CompoundFileSource::close() {
	for (std::list<FileContext*>::iterator it = mStack.begin(); it != mStack.end(); it++) {
		delete *it;
	}
	mStack.clear();
	state(CLOSED);
}

// Places a number of buffered characters into the input stream to be reread later.
bool CompoundFileSource::putback(char const* c, std::streamsize n) {
	FileContext* context;
	std::streamsize newpos;

	switch (state()) {
	case END:
	case GOOD:
		// We should have the last file that we read from
		// at the top of stack, so let's add it to the buffer
		context = mStack.front();
		newpos = context->bufpos + n;

		if (n >= context->bufsize) {
			// Overflow, expand the buffer.
			context->bufsize = (size_t)(((n + 1) / BUFFER_BLOCK_SIZE) + 1) * BUFFER_BLOCK_SIZE;
			context->buf = (char*)realloc(context->buf, context->bufsize);
		}

		// Copy the contents...
		// Note that this should be done in reverse order, so the last
		// part of the buffer comes out first.
		reverse_copy(c, context->buf + context->bufpos, (size_t)n);
		context->bufpos = (size_t)newpos;
		return true;

	case ERROR:
	case CLOSED:
	default:
		return false;

	}
}

// Imbues the steam with a provided locality for locality sensitive operations.
void CompoundFileSource::imbue(std::locale const& loc) {
	mLocale = loc;

	// Propogate the changes to each of the open streams.
	for (std::list<FileContext*>::iterator it = mStack.begin(); it != mStack.end(); it++) {
		if ((*it)->source) (*it)->source->imbue(mLocale);
	}
}

// Reads from any open files
std::streamsize CompoundFileSource::read(char* c, std::streamsize n) {
	std::streamsize needed = n;

	// If we've already hit then end, make sure to tell them.
	if (state() == END) return -1;


	// Read from each file starting from the top until we have 
	// all the characters we that we need (or run out of files).
	while (needed && state() == GOOD) {
		FileContext* context = mStack.front();
		std::streamsize size;

		// Check the buffer.
		if (context->bufpos) {
			// we have something...
			size = (context->bufpos  > needed) ? needed : context->bufpos;
			reverse_copy(context->buf + context->bufpos - 1,c, (size_t)size);
			c += size;
			needed -= size;
			context->bufpos -= (size_t)size;
		}

		// now try the device...
		if (needed) {
			context->source->read(c, needed);
			if (context->source->eof()) {
				// We've read the entire file.
				needed -= context->source->gcount();
				c += context->source->gcount();
				nextFile();
			} else if (context->source->fail()) {
				// Something just went horribly wrong...
				error();
			} else {
				// Everything is a-ok and we have everything we need!
				needed = 0;
			}
		}
	}

	return n - needed;
}

};}; /* end namespace cplus_parser::details */