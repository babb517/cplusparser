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

#include <boost/iostreams/concepts.hpp>
#include <boost/iostreams/categories.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/iostreams/stream.hpp>

#include <string>
#include <list>


namespace cplus_parser {
namespace details {

/**
 * @brief An enumeration of the various states that the file stream can take.
 */
typedef enum {
	GOOD = 0,			///< Indicates the stream is ready and has more characters to read.
	ERROR,				///< Indicates that an error ocurred and the stream has been forcefully closed.
	END,				///< Indicates that the stream has reached the end of all files.
	END_OF_FILE,		///< Indicates that the stream has reach the end of one of the files, but more files are available.
	CLOSED				///< Indicates that the stream has been closed and there are no more characters to read.
} FileState;

/**
 * @brief An extension of the ifstream in order to allow for reading from multiple files seamlessly.
 * @param tag_t A type that's used to tag each file that we're working with meta data.
 * @param TagArgs The argument types accepted by the tag's initializer.
 */
template <typename tag_t, typename... TagArgs>
class CompoundFileSource {

public:
	/***********************************************************************/
	/* Types */
	/***********************************************************************/

	/**
		* @brief The type to use as the character type.
		*/
	typedef char char_type;

	/**
		* @brief The definition of exactly what this device is capable of.
		* source_tag				- The device is able to read characters.
		* closable_tag				- The device should be closed when it's obsolete.
		* peekable_tag				- The device allows for the next character to be seen without reading it.
		* localizable_tag			- The device should be notified when the locality of the stream changes.
		* optimally_buffered_tag	- The device provides a default buffer size to use.
		*/
	typedef struct
		: boost::iostreams::source_tag,
			boost::iostreams::closable_tag,
			boost::iostreams::peekable_tag,
			boost::iostreams::localizable_tag,
			boost::iostreams::optimally_buffered_tag
	{ } category;

private:

	/***********************************************************************/
	/* Private types */
	/***********************************************************************/

	/**
	 * @brief A simple structure representing the current state of a file we are reading.
	 */
	struct FileContext {
		std::string file;						///< The file name specified by the user.
		tag_t tag;								///< The tag used to provide file meta-data.

		char* buf;								///< A buffer used to store data that has be put back into the stream.
		size_t bufsize;							///< The size of buf.
		size_t bufpos;							///< The position that we're at within buf.

		std::ifstream* source;					///< The source used to read from, or null if we don't have a stream open.

		/**
		 * @brief Initializes the context, allocated a buffer if a non-zero buffer size was specified.
		 */
		inline FileContext(std::string const& _file, std::ifstream* _source, size_t _bufsize, TagArgs... _args)
			: file(_file), tag(_args...), buf(NULL), bufsize(_bufsize), bufpos(0), source(_source)
			{ if (bufsize) buf = new char[bufsize]; }

		/**
		 * @brief Deallocated the buffer, closes, and deallocates the source.
		 */
		~FileContext();

		/// Places a number of buffered characters into this file's input buffer for later.
		void put(char const* c, std::streamsize n);
	};


	/***********************************************************************/
	/* Members */
	/***********************************************************************/
	std::list<FileContext*> mStack;			///< The stack of files we are currently reading through.

	std::locale mLocale;					///< Our current locale. Used to propogate to each source.
	FileState mState;						///< The current state of the stream.
	bool mAutoAdvance;						///< Whether we should automatically advance files when we reach the end of one.

public:
	/// The stream type encapsulating the compound file source.
	typedef boost::iostreams::stream<CompoundFileSource<tag_t,TagArgs... > > Stream;

	/***********************************************************************/
	/* Constructors / Destructors */
	/***********************************************************************/

	/**
	 * @brief Basic Constructor.
 	 * Initializes the filestream.
	 * @param autoAdvance whether the stream should automatically advance between files, of if nextFile must be called manually.
	 */
	CompoundFileSource(bool autoAdvance);

	/**
	 * @brief Basic Destructor.
	 * Closes all open input streams.
	 */
	virtual ~CompoundFileSource();

	/***********************************************************************/
	/***********************************************************************/

	/**
	 * @brief adds the specified file to the end of the effective input stream.
	 * @param file The file to add.
	 * @param args The arguments used to initialize the tag.
	 */
	inline bool append(std::string const& file, TagArgs... args) { return place(file, false, args...); }

	/**
	 * @brief adds the specified file to the current location in the effective input stream.
	 * @param file The file to add.
	 * @param args The arguments used to initialize the tag.
	 */
	inline bool insert(std::string const& file, TagArgs... args) { return place(file, true, args...); }

	/**
	 * Injects the provided input data into the read stream at either the current location or the end.
	 * @param data A buffer containing the data to inject.
	 * @param n The number of bytes to inject.
	 * @param here Whether the data should be injected here or at the end.
	 * @param args The arguments used to initialize the tag.
	 * @return True if succesful, false otherwise.
	 */
	bool inject(char const* data, size_t n,bool here, TagArgs... args);


	/**
	 * @brief Attempts to move to the next file in the stream.
	 * @return True if there are still files in the stream. False otherwise.
	 * @throws InvalidStateException If the stream is in an error state and hasn't been reset.
	 */
	bool nextFile();

	/// Gets the source stream for the file at the top of the stack, or NULL.
	inline std::ifstream const* source() const { return mStack.size() ? mStack.front()->source : NULL; }

	/// Gets the file at the top of the stack, or NULL.
	inline std::string const* file() const { return mStack.size() ? &mStack.front()->file : NULL; }

	/// Gets the tag for the file at the top of the stack, or NULL.
	inline tag_t* tag()					{ return mStack.size() ? &mStack.front()->tag : NULL; }
	/// Gets the tag for the file at the top of the stack, or NULL.
	inline tag_t const* tag() const		{ return mStack.size() ? &mStack.front()->tag : NULL; }

	/**
	 * A function used to tell boost that the input should be unbuffered (from their perspective).
	 * This is to allow for us to push file contexts onto the read stack dynamically.
	 */
	inline std::streamsize optimal_buffer_size() const { return 0; }

	/**
	 * @brief Determines the state of the stream.
	 * @returns The current state of the stream.
	 */
	inline FileState state() const { return mState; }

	/// Determines if the stream is open.
	inline bool is_open() const { return state() != CLOSED; }

	/// Determines if the stream is ready to read from.
	inline bool good() const { return state() == GOOD; }

	/// Determines if the stream has reached the end of a file.
	inline bool eof() const { return state() == END_OF_FILE; }

	/// Determines if the stream has reached the end of ALL files.
	inline bool end() const { return state() == END; }

	/// Determines if the stream has encountered an error.
	inline bool error() const { return state() == ERROR; }

	/// Determines if the stream is running in auto mode.
	inline bool autoAdvance() const { return mAutoAdvance; }

	/// Sets whether the stream is running in auto mode.
	inline void autoAdvance(bool _auto) { mAutoAdvance = _auto; if (state() == END_OF_FILE) nextFile(); }

	/**
	 * @brief Attempts to reset the IO stream after an error has occurred.
	 */
	void reset();

	/**
	 * @brief Closes all input streams.
	 */
	void close();

	/**
	 * @brief Puts the character back into the read stream.
	 * @param c The character to put back.
	 * @return True if successful, false otherwise.
	 */
	bool putback(char c) { return putback(&c, 1); }

	/**
	 * @brief Places a number of buffered characters into the input stream to be reread later.
	 * @param c A buffer containing the charaters to put back.
	 * @param n The number of characters to put back.
	 * @return True if successful, false otherwise.
	 */
	bool putback(char const* c, std::streamsize n);



	/**
	 * @brief Imbues the device with the provided locality.
	 * @param the new locality.
	 */
	void imbue(std::locale const& loc);

	/**
	 * @brief Attempts to read from the input stream.
	 * @param c The buffer to write to.
	 * @param n The number of characters to read.
	 * @returns The number of characters read, or -1 to indicate the end of stream.
	 */
	std::streamsize read(char* c, std::streamsize n);

protected:

	/// Gets the source stream for the top of the stack, or NULL.
	inline std::ifstream* source() { return mStack.size() ? mStack.front()->source : NULL; }

	/// Sets the state of the stream.
	inline void state(FileState state) { mState = state; }

private:


	/**
	 * @brief Resolves and opens the provided file name, placing the resulting context on the stack.
	 * @param file The file to open.
	 * @param args The arguments used to initialize the file's tag.
	 * @param top Whether the file should be placed at the top of the stack, or the bottom.
	 */
	bool place(std::string const& file, bool top, TagArgs... args);

};

};}; /* end namespace cplus_parser::details */

// Include the implementation file.
#include "CompoundFileStream.impl.h"

