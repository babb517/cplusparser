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
#include <boost/iterator/iterator_facade.hpp>

#include "statements/Statement.h"

#include "config.h"		// autoheader header

namespace cplus_parser {

/**
 * @brief An arbitrary (almost) first-order formula.
 */
template <typename pelem_base_t>
class Formula : public Statement<pelem_base_t>
{
private:
	/****************************************************************************/
	/* Members */
	/****************************************************************************/
	pelem_base_t* mFormula;		///< The wrapped formula.

public:
	/****************************************************************************/
	/* Constructors / Destructors */
	/****************************************************************************/
	/**
	 * @brief Initializes the formula
	 * @param The formula this statement encapsulates.
	 * NOTE: This object takes ownership of the memory associated with the provided formula.
	 */
	inline Formula(pelem_base_t* formula) 
		: Statement(FORMULA), mFormula(formula)
	{ /* Intentionally Left Blank */ }

	/**
	 * @brief Basic destructor.
	 * frees memory associated with the formula.
	 */
	virtual inline ~Formula() {
		delete mFormula;
	} 
	
	/****************************************************************************/
	/* Accessors */
	/****************************************************************************/
	/// Accesses the head of the rule.
	inline pelem_base_t const* head() { return mHead; }

	/// Accesses the body of the rule.
	inline pelem_base_t const* body() { return mBody; }
};

};