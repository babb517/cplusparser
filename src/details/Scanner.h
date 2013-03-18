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

#include <details/CompoundFileStream.h>
#include "details/parser.hh"

namespace cplus_parser {
namespace details {

class Scanner
{
public:
	/************************************************************************/
	/* Types */
	/************************************************************************/
	typedef parser::location_type location_type;
	typedef parser::semantic_type semantic_type;
	typedef parser::token_type token_type;
	typedef parser::token token;


private:
	/************************************************************************/
	/* Members */
	/************************************************************************/
	CompoundFileStream mInput;				///< A unified input stream to tokenize.
	char* mBuffer;							///< The buffer we're reading from.
	std::streamsize mBufPos;				///< Where we're at in the buffer.
	std::streamsize mInjectedSize;

public:
	/************************************************************************/
	/* Constructors / Destructors */
	/************************************************************************/
	/// Default constructor.
	Scanner();

	/// Frees associated buffer and input stream resources.
	inline ~Scanner() { delete mBuffer; mInput.close(); }

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
};

};}; /* end namespace cplus_parser::details */