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
#include <sstream>

#include "details/CompoundFileStream.h"
#include "Location.h"
#include "details/Token.h"
#include "Handler.h"

namespace cplus_parser {
namespace details {



/// A list of the various types of tokens we can receive.
enum TokenType {
	T_EOF = -2,				// End of File
	T_ERR = -1,				// unrecognized token.

	T_INTEGER,				// Any integer.
	T_DECIMAL,				// Any decimal number.	
	T_IDENTIFIER,			// Any identifier starting with a letter or
							// with underscore(s) and a letter/number, & optionally
							// followed by letters/numbers/underscores,
	T_STRING,				// A quoted string containing arbitrary text.
	T_ASP,					// Raw ASP code from input.
	T_LUA,					// Raw LUA code from input.
	T_COMMENT,				// Raw text from input that was commented out.

	T_CONSTANTS,			// constants
	T_INCLUDE,				// include
	T_MACROS,				// macros
	T_OBJECTS,				// objects
	T_QUERY,				// query
	T_SHOW,					// show
	T_SORTS,				// sorts
	T_VARIABLES,			// variables

	T_ABACTION,				// abAction
	T_ACTION,				// action
	T_ADDITIVEACTION,		// additiveAction
	T_ADDITIVEFLUENT,		// additiveFluent
	T_AFTER,				// after
	T_ALWAYS,				// always
	T_ASSUMING,				// assuming 			-- "if2" construct
	T_ANY,					// any
	T_ATTRIBUTE,			// attribute
	T_BY,					// by
	T_CAUSED,				// caused
	T_CAUSES,				// causes
	T_IMPOSSIBLE,			// impossible
	T_CONSTRAINT,			// constraint
	T_DECREMENTS,			// decrements
	T_DEFAULT,				// default
	T_DYNAMICAB,			// dynamicAbnormality	-- aC+ construct
	T_EXOGENOUS,			// exogenous
	T_EXOGENOUSACTION,		// exogenousAction
	T_IF,					// if
	T_INCREMENTS,			// increments
	T_INERTIAL,				// inertial
	T_INERTIALFLUENT,		// inertialFluent
	T_LABEL,				// label
	T_MAY_CAUSE,			// may cause
	T_MAXADDITIVE,			// maxAdditive
	T_MAXSTEP,				// maxstep
	T_NEVER,				// never
	T_NOCONCURRENCY,		// noconcurrency
	T_STRONG_NOCONCURRENCY,	// strong_noconcurrency
	T_NONEXECUTABLE,		// nonexecutable
	T_OF,					// of
	T_POSSIBLY_CAUSED,		// possibly caused
	T_RIGID,				// rigid
	T_SDFLUENT,				// sdFluent
	T_SIMPLEFLUENT,			// simpleFluent
	T_STATICAB,				// staticAbnormality 	-- aC+ construct
	T_UNLESS,				// unless
	T_WHEN,					// when 				-- aC+ construct
	T_FOLLOWING,			// following 				-- aC+ construct
	T_WHERE,				// where
	T_WHITESPACE,			// whitespace to pass through
	T_FALSE,				// false
	T_NONE,					// none
	T_TRUE,					// true

	T_ABS,					// abs
	T_AT,					// @
	T_BRACKET_L,			// [
	T_BRACKET_R,			// ]
	T_COLON_DASH,			// :-
	T_PAREN_L,				// (
	T_PAREN_R,				// )
	T_PERIOD,				// .
	T_PIPE,					// |

	T_SEMICOLON,			// ;
	T_DBL_COLON,			// ::
	T_ARROW_LEQ,			// <=
	T_ARROW_REQ,			// =>
	T_ARROW_LDASH,			// <-
	T_ARROW_RDASH,			// ->
	T_COLON,				// :
	T_COMMA,				// ,
	T_EQUIV,				// <->
	T_IMPL,					// ->>
	T_DBL_PLUS,				// ++
	T_AMP,					// & OR &&
	T_EQ, 					// =
	T_DBL_EQ,				// ==
	T_NOT_EQ,				// \\= OR <> OR neq
	T_LTHAN,				// <
	T_GTHAN,				// >
	T_EQ_LTHAN,				// =<
	T_GTHAN_EQ,				// >=
	T_NOT,					// not
	T_DBL_PERIOD,			// ..
	T_DASH,					// -
	T_PLUS,					// +
	T_DBL_GTHAN,			// >>
	T_STAR,					// *
	T_INT_DIV,				// //
	T_MOD,					// mod
	T_BIG_CONJ,				//  
	T_BIG_DISJ,				// 
	T_POUND,				// #
	T_UMINUS,				// Pseudo-token,, unary, minus

	T_DEBUG_INSERT,			// DEBUG only token used to forcefully insert a file.
	T_DEBUG_APPEND,			// DEBUG only token used to forcefully append a file.
	T_DEBUG_INJECT,			// DEBUG only token used to forcefully inject a string.



};

class Token {
public:

private:
	TokenType mType;			///< The token's type.
	Location mLoc;				///< The token's location
	std::string* mData;			///< The token's data.
public:
	/****************************************************************/
	/* Constructor / Destructor */
	/****************************************************************/
	/// Default constructor
	/// Pointers NULLED
	inline Token() : mData(NULL) { /* intentionally left blank */ }

	/// Destructor
	/// Deallocates used memory.
	inline ~Token() { 
		if (mData) delete mData;
	}

	/****************************************************************/
	/* Public methods */
	/****************************************************************/
	/// Initializes the token's basic info.
	inline void init(TokenType type, std::string* data) {
		mType = type;
		mData = data;
	}

	/// Initializes the token's location.
	inline void loc_init(std::string const* file, size_t line, size_t col) { mLoc.init(file, line, col); }

	/// Initializes the beginning location of the token.
	inline void loc_begin(std::string const* file, size_t line, size_t col) { mLoc.begin(file, line, col); }

		/// Initializes the ending location of the token.
	inline void loc_end(std::string const* file, size_t line, size_t col) { mLoc.end(file, line, col); }

	/// Gets the token type.
	inline TokenType  type() const { return mType; }

	/// Gets the token location.
	inline Location const& loc() const { return mLoc; }
	inline Location & loc() { return mLoc; }

	/// Gets the token's data
	inline std::string* data() { return mData; }
	inline std::string const* data() const { return mData; }

	/// Sets the token's data.
	inline void data(std::string* data) { mData = data; }

	/// Gets the string representation of the token.
	char const* c_str() const;
};


}; }; /* end namespace cplus_parser::details */
