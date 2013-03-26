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

#pragma once

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
#include "utils/utils.h"

namespace cplus_parser {
namespace details {


/**
 * @brief The number of bytes to allocate to a buffer at a time.
 */
#define BUFFER_BLOCK_SIZE 1024

/*****************************************************************************************/
/* File Context */
/*****************************************************************************************/

/// Free the context
template <typename tag_t, typename... TagArgs>
CompoundFileSource<tag_t, TagArgs...>::FileContext::~FileContext() {
	if (buf) free(buf);
	if (source) {
		if (source->is_open()) source->close();
		delete source;
	}
}


// Places a number of buffered characters into this file's input buffer for later.
template <typename tag_t, typename... TagArgs>
void CompoundFileSource<tag_t, TagArgs...>::FileContext::put(char const* c, std::streamsize n) {
	std::streamsize newpos;

	newpos = bufpos + n;

	if (newpos >= bufsize) {
		// Overflow, expand the buffer.
		bufsize = (size_t)(((newpos + 1) / BUFFER_BLOCK_SIZE) + 1) * BUFFER_BLOCK_SIZE;
		buf = (char*)realloc(buf, bufsize);
	}

	// Copy the contents...
	// Note that this should be done in reverse order, so the last
	// part of the buffer comes out first.
	utils::reverse_copy(buf + bufpos, c, n);

	bufpos = (size_t)newpos;
}

/******************************************************************************************/
/* Compound File Source */
/******************************************************************************************/

// Constructor
template <typename tag_t, typename... TagArgs>
CompoundFileSource<tag_t, TagArgs...>::CompoundFileSource(bool autoAdvance) {
	mAutoAdvance = autoAdvance;
	state(CLOSED);
}

template <typename tag_t, typename... TagArgs>
CompoundFileSource<tag_t, TagArgs...>::~CompoundFileSource() { 
	if (state() != CLOSED) close(); 
};



// Injects the provided input data into the read stream at either the current location or the end.
template <typename tag_t, typename... TagArgs>
bool CompoundFileSource<tag_t, TagArgs...>::inject(char const* data, size_t n,bool here, TagArgs... args) {
	if (state() == ERROR) return false;
	
	FileContext* context = new FileContext("<INJECTED TEXT>", NULL, 0, args...);

	context->put(data, n);

	if (here)
		mStack.push_front(context);
	else
		mStack.push_back(context);	


	state(GOOD);
	return true;
}


// Place a file on the stack.
template <typename tag_t, typename... TagArgs>
bool CompoundFileSource<tag_t, TagArgs...>::place(std::string const& file, bool top, TagArgs... args) {
	// State handling...
	if (state() == ERROR) return false;

	// initialize the new context
	FileContext* context = new FileContext(file, NULL, 0, args...);

	// Step 1) Validate the name..
	//if (!boost::filesystem::native(filename)) {
	//	// The file's name isn't a valid format.
	//	delete context;
	//	return false;
	//}8


	// Step 2) Attempt to resolve the file.

	// Try the present working directory...
	boost::filesystem::path filepath = boost::filesystem::absolute(file);

	// Check if we (eventually) found it.
	if (!boost::filesystem::exists(filepath)) {
		// We don't really know where the file is.
		delete context;
		return false;
	}

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
template <typename tag_t, typename... TagArgs>
bool CompoundFileSource<tag_t, TagArgs...>::nextFile() {
	if (state() == ERROR) return false;

	size_t size = mStack.size();

	
	// pop off the old state.
	if (size) {
		delete mStack.front();
		mStack.pop_front();
	}

	if (size > 1) {
		state(GOOD);
	} else {
		state(END);
	}
	return state() == GOOD;
}

template <typename tag_t, typename... TagArgs>
void CompoundFileSource<tag_t, TagArgs...>::reset() {
	if (source()) {
		source()->clear();
		if (state() == ERROR) state(GOOD);
	} else {
		state(END);
	}
}

// Closes the stream, freeing all available resourced.
template <typename tag_t, typename... TagArgs>
void CompoundFileSource<tag_t, TagArgs...>::close() {
	for (size_t sz = mStack.size(); sz; sz--) {
		delete mStack.front();
		mStack.pop_front();
	}

	mStack.clear();
	state(CLOSED);
}

// Places a number of buffered characters into the input stream to be reread later.
template <typename tag_t, typename... TagArgs>
bool CompoundFileSource<tag_t, TagArgs...>::putback(char const* c, std::streamsize n) {
	switch (state()) {
	case END:
	case END_OF_FILE:
	case GOOD:
		mStack.front()->put(c, n);
		return true;

	case ERROR:
	case CLOSED:
	default:
		return false;

	}
}


// Imbues the steam with a provided locality for locality sensitive operations.
template <typename tag_t, typename... TagArgs>
void CompoundFileSource<tag_t, TagArgs...>::imbue(std::locale const& loc) {
	mLocale = loc;

	// Propogate the changes to each of the open streams.
	for (typename std::list<FileContext*>::iterator it = mStack.begin(); it != mStack.end(); it++) {
		if ((*it)->source) (*it)->source->imbue(mLocale);
	}
}

// Reads from any open files
template <typename tag_t, typename... TagArgs>
std::streamsize CompoundFileSource<tag_t, TagArgs...>::read(char* c, std::streamsize n) {
	std::streamsize needed = n;

	// If we've already hit the end, make sure to tell them.
	if (state() == END) return -1;
	if (state() == END_OF_FILE && !autoAdvance()) return -1;

	// Read from each file starting from the top until we have 
	// all the characters we that we need (or run out of files).
	while (needed && state() == GOOD) {
		FileContext* context = mStack.front();
		std::streamsize size;

		// Check the buffer.
		if (context->bufpos) {
			// we have something...
			size = (context->bufpos  > needed) ? needed : context->bufpos;
			utils::reverse_copy(c, context->buf + context->bufpos - size, size);
			c += size;
			needed -= size;
			context->bufpos -= (size_t)size;
		}

		// now try the device...
		if (needed) {
			if (context->source) {
				context->source->read(c, needed);
				if (context->source->eof()) {
					// We've read the entire file.
					needed -= context->source->gcount();
					c += context->source->gcount();

					// Flag that we've reached the end of the file or continue to the next file.
					if (autoAdvance()) nextFile();
					else state(END_OF_FILE);
				} else if (context->source->fail()) {
					// Something just went horribly wrong...
					state(ERROR);
				} else {
					// Everything is a-ok and we have everything we need!
					needed = 0;
				}
			} else {
				// It looks like this was a psuedo file. Just pop it off.
				if (autoAdvance()) nextFile();
				else state(END_OF_FILE);
			}
		}
	}

	return n - needed;
}

};}; /* end namespace cplus_parser::details */
