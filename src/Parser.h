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

#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

#include "details/Scanner.h"
#include "details/parser.hh"
#include "Handler.h"

namespace cplus_parser {

/**
 * A wrapper class for the complete parser.
 * Used as the top-level interface for the parser library.
 * @type pelem_base_t The base parse element type that all elements should inherit from. Must be derived from ParseElement_base.
 * @type pelem_uop_t The unary operator type to use. Must be derived from UnaryOperator_base<pelem_base_t>.
 * @type pelem_bop_t The binary operator type to use. Must be derived from BinaryOperator_base<pelem_base_t>.
 * @type pelem_quant_t The quantifier operator type to use. Must be derived from Quantifier_base<pelem_base_t>.
 */
template<
	typename pelem_base_t,
	typename pelem_uop_t,
	typename pelem_bop_t,
	typename pelem_quant_t
>
class Parser
{
	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);

	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<UnaryOperator_base<pelem_base_t>, pelem_uop_t>::value),
		"pelem_uop_t must be a descendant of UnaryOperator_base<pelem_base_t>"
	);

	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<BinaryOperator_base<pelem_base_t>, pelem_bop_t>::value),
		"pelem_bop_t must be a descendant of BinaryOperator_base<pelem_base_t>"
	);

	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<Quantifier_base<pelem_base_t>, pelem_quant_t>::value),
		"pelem_quant_t must be a descendant of Quantifier_base<pelem_base_t>"
	);

private:
	/**********************************************************************/
	/* Members */
	/**********************************************************************/
	Handler<pelem_base_t>* mParseHandler;		///< The handler used to provide upward mobility to parser elements.
	bool mOwnsHandler;							///< Whether this object owns the handler object.

	details::Scanner mScanner;					///< The internal RE2C lexer used to tokenize the input stream.
	details::parser mParser;					///< The internal bison-generated parser that does all the heavy lifting for us.

public:
	/**********************************************************************/
	/* Constructor / Destructor */
	/**********************************************************************/
	/**
	 * @brief Initializes a parser object.
	 * @param handler The handler used to manage the symbol table and process statements.
	 * @param own Whether this parser object should take ownership of the handler (deallocate the handler during the destruction of this object)/
	 */
	inline Parser(Handler<pelem_base_t>* handler, bool own = true)
		: mParseHandler(handler), mOwnsHandler(own), mParser(this), mScanner(this)
	{ // TODO

	}

	/**
	 * @brief Basic destructor.
	 * @param Deallocated the handler if this object owns it.
	 */
	inline ~Parser() { if (mOwnsHandler) delete mParseHandler; }


	/**********************************************************************/
	/* Accessors / Mutators */
	/**********************************************************************/




};

}; /* end namespace cplus_parser */