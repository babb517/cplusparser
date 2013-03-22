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
#include <limits>
#include <cstring>

#include "details/CompoundFileStream.h"
#include "details/parser.hh"
#include "details/Scanner.h"

namespace cplus_parser {
namespace details {

/*********************************************************************************/
/* Constants */
/*********************************************************************************/
size_t const Scanner::BUFFER_SIZE = 255;
size_t const Scanner::INVALID_POS = std::numeric_limits<size_t>::max();

char* Scanner::EOF_BUFFER = new char[BUFFER_SIZE];

/*********************************************************************************/
/* Methods */
/*********************************************************************************/
/// Analyzes the input stream and returns the next token.
Scanner::token_type Scanner::lex(semantic_type* yylval, location_type* yylloc) {
	char* _cursor, *_marker, *_limit;
	FileDescriptor* _tag = tag();

	if (!_tag) return token::END;

	// Setup the read buffer
	_cursor = cursor();
	_marker = _cursor;
	_limit = limit();

	// setup the location
	yylloc->begin.filename = &_tag->name;
	yylloc->begin.column = _tag->col;
	yylloc->begin.line = _tag->line;

	/*!re2c
		re2c:define:YYCTYPE		= "char";
		re2c:define:YYCURSOR	= _bufpos;
		re2c:define:YYMARKER	= _marker;
		re2c:define:YYLIMIT		= _limit;
		re2c:define:YYFILL		= fill(_bufpos, _marker, _limit, %%);
		re2c:define:YYFILL@LEN	= %%;
		re2c:indent:top			= 1;
		re2c:yyfill:enable		= 1;



	*/

}

void Scanner::fill(char*& yycursor, char*& yymarker, char*& yylimit, size_t len) {
	bool err = false;

	// check to ensure we haven't reached the end of a file
	if (mInput->eof()) {
		mInput->nextFile();
		mInput.clear();
	}

	FileDescriptor* _tag = tag();

	if (!_tag || mInput.fail() || !mInput->good()) {
		// no available files
		yycursor = EOF_BUFFER;
		yymarker = EOF_BUFFER;
		yylimit = EOF_BUFFER + len;
	}
	
	// readjust the beginning of the buffer when necessary...
	if (yycursor + len >= &_tag->buffer[BUFFER_SIZE-1]) {
		memmove(_tag->buffer, _tag->cursor, (size_t)(_tag->limit - _tag->cursor));
		_tag->cursor = _tag->buffer;
		_tag->limit -= _tag->cursor - _tag->buffer;
	}

	// fill the buffer
	do {
		// read the input.
		mInput.read(_tag->cursor, _
		



		// error checking and handling.
		
		if ((mInput.bad() || mInput->error()) && !err) {
			err = true;
			mInput->reset();
			mInput.clear();
		}


	} while (len && mInput->good())



}

};}; /* End namespace cplus_parser::details */
