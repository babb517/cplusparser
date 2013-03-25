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
#include "Location.h"

#include "config.h"		// autoheader header

namespace cplus_parser {

/**
 * @brief A rule 'head <= tails' under the causal logic semantics.
 */
template <typename pelem_base_t>
class CausalRule : public Statement<pelem_base_t>
{
private:
	/****************************************************************************/
	/* Members */
	/****************************************************************************/
	pelem_base_t* mHead;		///< The head of the rule.
	pelem_base_t* mBody;		///< The body of the rule.

public:
	/****************************************************************************/
	/* Constructors / Destructors */
	/****************************************************************************/
	/**
	 * @brief Initializes the causal rule of the form 'head <= body'.
	 * @param head The head of the rule.
	 * @param body The body of the rule.
	 */
	inline CausalRule(Location const& loc, pelem_base_t* head, pelem_base_t* body) 
		: Statement<pelem_base_t>(RULE_CAUSAL, loc), mHead(head), mBody(body)
	{ /* Intentionally Left Blank */ }

	/****************************************************************************/
	/* Accessors */
	/****************************************************************************/
	/// Accesses the head of the rule.
	inline pelem_base_t const* head() { return mHead; }

	/// Accesses the body of the rule.
	inline pelem_base_t const* body() { return mBody; }
};

};