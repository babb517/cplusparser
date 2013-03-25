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

#include "Location.h"
#include "config.h"		// autoheader header


namespace cplus_parser {

/**
 * A list of the various different kinds of statements that the parser can parse.
 */
typedef enum {
	CAUSAL_LAW,							///< A general causal law that covers all possible forms. 
	DECLARATION,						///< A block meant to declare various identifiers.
	QUERY,								///< A statement providing query formulas to enforce upon selection.
	INCLUDE,							///< An include statement.
	MACROS,								///< A macros definition statement.
	RULE_MV_ASP,						///< multi-valued ASP rule (p=v :- f1, f2, f3, ..., fn).
	RULE_CAUSAL,						///< causal rule (F <= G).
	FORMULA								///< General formula (F).

} StatementType;

/**
 * A top-level object for encapsulating a complete program statement.
 * @type pelem_base_t The base parse element type that all elements should inherit from. Must be derived from ParseElement_base.
 */
template<typename pelem_base_t>
class Statement {

	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);

public:
	/************************************************************/
	/* Types */
	/************************************************************/



private:
	/************************************************************/
	/* Members */
	/************************************************************/
	StatementType mType;
	Location mLoc;
public:
	/************************************************************/
	/* Constructors / Destructors */
	/************************************************************/
	/**
	 * @brief Basic constructor.
	 * @param type The type of statement that this object represents.
	 */
	inline Statement(StatementType type, Location const& loc)
		: mType(type), mLoc(loc)
	{
	
	}

	/**
	 * @brief Dummy destructor.
	 */
	inline virtual ~Statement() { /* Intentionally Left Blank */ }

	/************************************************************/
	/* Members */
	/************************************************************/
	/**
	 * @brief Identifies the type of statement that this object represents.
	 * @return A value indicating the concrete statement type that this is.
	 */
	inline StatementType type() const { return mType; }

};


}; /* end namespace cplus_parser */