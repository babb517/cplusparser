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

#include<string>
#include<list>

#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

#include "Location.h"
#include "elements/ParseElement_base.h"
#include "parser_types.h"
#include "statements/Statement.h"


#define CPLUS_PARSER_HANDLER_MSG_LEVEL_MASK			0xFFFF0000
#define CPLUS_PARSER_HANDLER_MSG_ERR_CODE_MASK		0x0000FFFF


namespace cplus_parser {

/**
 * @brief An interface class used to handle the upward mobility of messages.
 */
class MessageHandler
{
public:
	/*******************************************************************************************/
	/* Types */
	/*******************************************************************************************/
	/// A type to provide flags for a message.
	typedef uint32_t MessageFlag;

	/// A list of well-defined message levels.
	typedef enum {
		MSG_DEBUG = 0,
		MSG_DEBUG_SCANNER_VERBOSE = 1,
		MSG_DEBUG_SCANNER = 2,
		MSG_VERBOSE = 32,
		MSG_PRAGMA = 64,
		MSG_WARN = 128,
		MSG_ERROR = 255
	} MessageLevel;

	/*******************************************************************************************/
	/* Static Helpers */
	/*******************************************************************************************/
	/**
	 * @brief Creates the flag appropriate for the provided level and code.
	 * @param level The level that is used to determine whether the message should be suppressed.
	 * @param code The error code associated with the message. 
	 */
	static inline MessageFlag msgflag(uint16_t level, uint16_t code = 0) { return ((MessageFlag)(level << 16)) | ((MessageFlag)code); }

	/**
	 * @brief Extracts the message level from the message flag.
	 * @param flag The flag to extract the level from.
	 * @return The level stored within the mesage flag.
	 */
	static inline uint16_t msglevel(MessageFlag flag) { return (uint16_t)((CPLUS_PARSER_HANDLER_MSG_LEVEL_MASK & flag) >> 16); }

	/**
	 * @brief Extracts the message error code from the message flag.
	 * @param flag The flag to extract the level from.
	 * @return The error code stored within the message flag.
	 */
	static inline uint16_t msgcode(MessageFlag flag) { return (uint16_t)(CPLUS_PARSER_HANDLER_MSG_ERR_CODE_MASK & flag); }

	/*******************************************************************************************/
	/* Interface Methods */
	/*******************************************************************************************/

	/**
	 * @brief Attempts to display a message to the user, assuming that the message is above the masked level.
	 * @param flags The message flags. Includes teh message level as well as (possibly) a message error code.
	 * @param msg The message format string (see printf).
	 * @param ... The arguments for the format string (see printf).
	 * @return True if the message was displayed, false otherwise.
	 */
	virtual bool message(MessageFlag flags, char const* msg, ...) = 0;

	/**
	 * @brief Attempts to display a message to the user, assuming that the message is above the masked level.
	 * @param flags The message flags. Includes teh message level as well as (possibly) a message error code.
	 * @param loc The location that the error pertains to.
	 * @param msg The message format string (see printf).
	 * @param ... The arguments for the format string (see printf).
	 * @return True if the message was displayed, false otherwise.
	 */
	virtual bool message(Location const& loc, MessageFlag flags, char const* msg, ...) = 0;

};


/**
 * An interface class used to handle the creation of the various parser constructs.
 * @type pelem_base_t The base parse element type that all elements should inherit from. Must be derived from ParseElement_base.
 */
template<typename pelem_base_t>
class StatementHandler 
{

	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);
public:


	/*******************************************************************************************/
	/* Interface Methods */
	/*******************************************************************************************/
	/**
	 * @brief Maps an identifier and parameters to a concrete reference in the external symbol table and creates an appropriate Identifier_base like instance.
	 * @param outIdentifier A pointer to the resulting identifier. Setting it to NULL results in the identifier being removed from the parse stream, causing the parser to continue as if it never existed.
	 * @param identifier The base identifier of the object.
	 * @param params The parameters of the object, or NULL if empty. 
	 * NOTE: Management of the associated memory blocks is the responsibility of this method. If the parameter list is unused it should be deallocated prior to returning.
	 * @return True if the identifier was valid, false to throw a parse error.
	 */
	virtual bool identify(Identifier_base<pelem_base_t>*& outIdentifier, std::string const& identifier, std::list<pelem_base_t*>* params = NULL) = 0;

	/**
	 * @brief Processes a complete program statement, providing the actual semantics of the syntatic construct.
	 * @param stmt The statement to process and execute.
	 * NOTE: Management of the memory associated with stmt is the responsibility of this method. Any memory that is no longer in use should be deallocated prior to returning.
	 * @return True if the statement has been accepted, false to throw a parse error.
	 */
	virtual bool process(Statement<pelem_base_t>* stmt) = 0;

};

}; /* end namespace cplus_parser */
