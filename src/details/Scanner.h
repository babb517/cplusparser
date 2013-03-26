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

#include <string>
#include <list>
#include <sstream>

#include "details/CompoundFileStream.h"
#include "details/Token.h"

namespace cplus_parser {

class MessageHandler;
class Location;

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

	/// A simple type used to track a file.
	struct FileDescriptor {
		std::string const* name;			///< The human-readable name of the file.

		size_t pos;							///< Current position in the file.
		size_t line;						///< Current line in the file.
		size_t col;							///< Current column in the file.
		Location* loc;						///< When specified indicates that all tokens in the file should be tagged with this location data.

		/**
		 * @brief Initiliazes the descriptor.
		 * @param _name The name of the file.
		 * @param _loc An optional fixed location for each of the tokens in the file.
		 */
		inline FileDescriptor(std::string const* _name, Location* _loc = NULL)
			: name(_name), pos(0), line(1), col(1), loc(_loc)
		{ /* Intentionally Left Blank */ }

		/// Frees the location.
		inline ~FileDescriptor() { if (loc) delete loc; }

	};

private:
	/************************************************************************/
	/* Types */
	/************************************************************************/
	/// The variouus states the lexxer can take.
	enum YYCONDTYPE {
		yycCODE,			///< Normal lexxer operation.
		yycSTRING_S,		///< Single quote string literal lexxing.
		yycSTRING_D,		///< Double quote string literal lexxing.
		yycCOMMENT,			///< Line comment lexxing.
		yycBL_COMMENT,		///< Block comment lexxing.
		yycASP,				///< ASP code lexxing
		yycLUA				///< LUA code lexxing

	};

	/************************************************************************/
	/* Members */
	/************************************************************************/
	
	CompoundFileSource<
		FileDescriptor, 
		std::string const*,
		Location*>::Stream mInput;		///< A unified input stream to tokenize.

	std::list<std::string> mNames;		///< The names of the files we're working with.
	

	MessageHandler* mHandler;			///< A handler used to support upwardly mobile messages.

	// re2c context
	YYCONDTYPE mCondition;				///< The current condition of the lexxer.
	char* mBuffer;						///< The read buffer for RE2C.
	char* mBegin;						///< The starting position within the read buffer.
	char* mCursor;						///< The position within the read buffer.
	char* mLimit;						///< The position just after the last filled position in the buffer.
	char* mMarker;						///< The (temporary) position of RE2C.
	char* mBufEnd;						///< The position just after the last one in the buffer.
	char* mLastnl;						///< A pointer to the last newline encountered by the scanner.
	FileDescriptor* mTag;

public:
	/************************************************************************/
	/* Constructors / Destructors */
	/************************************************************************/
	/// Default constructor.
	///
	inline Scanner(MessageHandler* handler) : mInput(false), mHandler(handler) {
		mCondition = yycCODE;
		mBuffer = new char[BUFFER_SIZE];
		mCursor = mBuffer;
		mBegin = mBuffer;
		mLimit = mBuffer;
		mLastnl = mBuffer;
		mBufEnd = mBuffer + BUFFER_SIZE;
		mTag = NULL;
	}

	/************************************************************************/
	/* Accessors / Mutators */
	/************************************************************************/
	/**
	 * @brief Analyzes the input stream and returns the next token.
	 * @param[out] token The token that was read in.
	 * @return The type of token found.
	 */
	TokenType lex(Token& token);

	/**
	 * @brief Appends a file to the end of the input stream.
	 * @param file The file to append.
	 * @param name The human-readable name of the file.
	 * @return True if the file was found and added, false otherwise.
	 */
	bool appendFile(std::string const& file, std::string const& name);

	/**
	 * @brief Appends a file to the beginning of the input stream.
	 * @param file The file to insert.
	 * @param name The human-readable name of the file.
	 * @return True if the file was found and added, false otherwise.
	 */
	bool insertFile(std::string const& file, std::string const& name);
	
	/**
	 * @brief Injects a string at the input streams current location to be read next.
	 * @param str The string to inject.
	 * @param loc The location to display for all tokens injected this way.
	 */
	bool inject(std::string const& str, Location const& loc);

private:
	/************************************************************************/
	/* Private Methods */
	/************************************************************************/
	/// Retrieves the tag for the current file (or NULL)
	inline FileDescriptor* tag() { return mInput->tag(); }

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

	/// Gets the message handler reference.
	inline MessageHandler* handler() { return mHandler; }

	/**
	 * @brief Fills the RE2C buffer.
	 * @param len The minimum number of character to attempt to read.
	 */
	void fill(size_t len); 

	/// Gets the current conditio
	inline YYCONDTYPE condition() const			{ return mCondition; }
	
	/// sets the current condition
	inline void condition(YYCONDTYPE cond) { 
		mCondition = cond; 

#ifdef DEBUG
		handler()->message(
			MessageHandler::msgflag(MessageHandler::MSG_DEBUG_SCANNER_VERBOSE, 0),
			"Entering scanner condition: '%s'", conditionToString(cond)); 	
#endif
	}



	/// Gets a string representation of the condition.
	char const* conditionToString(YYCONDTYPE cond);

	/// Moves to the next file in the list.
	void advance();

	/// Shifts re2c's position back to the beginning.
	void shift();

};

};}; /* end namespace cplus_parser::details */
