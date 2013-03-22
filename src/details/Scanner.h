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

#include <string>

#include "details/CompoundFileStream.h"
#include "details/parser.hh"

namespace cplus_parser {
namespace details {


class Scanner
{
public:
	/// The size of the RE2C lex buffers
	static size_t const BUFFER_SIZE;

	/// A valid used to indicate an invalid position.
	static size_t const INVALID_POS;

	/************************************************************************/
	/* Types */
	/************************************************************************/
	typedef parser::location_type location_type;
	typedef parser::semantic_type semantic_type;
	typedef parser::token_type token_type;
	typedef parser::token token;

	/// A simple type used to track a file.
	struct FileDescriptor {
		std::string name;					///< The human-readable name of the file.

		size_t pos;							///< Current position in the file.
		size_t line;						///< Current line in the file.
		size_t col;							///< Current column in the file.

		char* buffer;						///< The read buffer for RE2C.
		char* cursor;						///< The position within the read buffer.
		char* limit;						///< The position just after the last filled position in the buffer.

		/**
		 * @brief Initiliazes the descriptor.
		 */
		inline FileDescriptor(std::string const& _name)
			: name(_name), pos(0), line(1), col(1)
		{ buffer = new char[BUFFER_SIZE]; cursor = buffer; limit = buffer; }

		/// Frees the read buffer
		inline ~FileDescriptor() { delete buffer; }

	};

private:
	/************************************************************************/
	/* Members */
	/************************************************************************/
	
	CompoundFileStream<
		FileDescriptor, 
		std::string const&> mInput;					///< A unified input stream to tokenize.

	static char* EOF_BUFFER;						///< A buffer that is used to force RE2C to recognize the end of the input.

public:
	/************************************************************************/
	/* Constructors / Destructors */
	/************************************************************************/
	/// Default constructor.
	inline Scanner() : mInput(false) {
		static bool initialized = false;
		
		if (!initialized) {
			memset(EOF_BUFFER, '\0', BUFFER_SIZE);
			initialized = true;
		}

	}

	/************************************************************************/
	/* Accessors / Mutators */
	/************************************************************************/
	/**
	 * @brief Analyzes the input stream and returns the next token.
	 * @param[out] yylval The value of the returned token.
	 * @param[out] yylloc The location information for the returned token.
	 * @return The type of token that was retrieved.
	 */
	token_type lex(semantic_type* yylval, location_type* yylloc);

	/**
	 * @brief Appends a file to the end of the input stream.
	 * @param file The file to append.
	 * @return True if the file was found and added, false otherwise.
	 */
	bool appendFile(std::string const& file);

	/**
	 * @brief Appends a file to the end of the input stream.
	 * @param file The file to append.
	 * @return True if the file was found and added, false otherwise.
	 */
	void insertFile(std::string const& file);
	
	/**
	 * @brief Injects a string at the input streams current location to be read next.
	 * @param str The string to inject.
	 * @param noloc Whether we should ignore the the injected characters when determining token location.
	 */
	void inject(std::string const& str, bool noloc = true);

private:
	/************************************************************************/
	/* Private Methods */
	/************************************************************************/
	/// Retrieves the tag for the current file (or NULL)
	inline FileDescriptor* tag() { return mInput->tag(); }

	/// Retrieves the buffer for the current file (or EOF_BUFFER).
	inline char*& buffer() { 
		FileDescriptor* _tag = tag(); 
		return (_tag) ? _tag->buffer : EOF_BUFFER;
	}

	/// Retrieves the position of the current read buffer (or EOF_BUFFER).
	inline char*& cursor() {
		FileDescriptor* _tag = tag(); 
		return (_tag) ? _tag->cursor : EOF_BUFFER;
	}

	/// Retrieves the location just after the last one filled in the current read buffer (or EOF_BUFFER).
	inline char*& limit() {
		FileDescriptor* _tag = tag(); 
		return (_tag) ? _tag->limit : EOF_BUFFER;
	}

	/// Retrieves the current position we're at within the current file (or INVALID_POS).
	inline size_t pos() {
		FileDescriptor* _tag = tag(); 
		return (_tag) ? _tag->pos : INVALID_POS;
	}

	/// Retrieves the current line we're at within the current file (or INVALID_POS).
	inline size_t line() {
		FileDescriptor* _tag = tag(); 
		return (_tag) ? _tag->line : INVALID_POS;
	}

	/// Retrieves the current column we're at within the current file (or INVALID_POS).
	inline size_t col() {
		FileDescriptor* _tag = tag(); 
		return (_tag) ? _tag->col : INVALID_POS;
	}

	/**
	 * @brief Fills the RE2C buffer.
	 * @param[out] yycursor The initial position of RE2C in the buffer.
	 * @param[out] yymarker The current position of RE2C in the buffer.
	 * @param[out] yylimit The position right after the last that has been filled in the buffer.
	 * @param len The minimum number of character to attempt to read.
	 */
	void fill(char*& yycursor, char*& yymarker, char*& yylimit, size_t len); 

};

};}; /* end namespace cplus_parser::details */