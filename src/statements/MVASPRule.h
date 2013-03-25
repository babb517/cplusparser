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

#include <list>

#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>
#include <boost/iterator/iterator_facade.hpp>

#include "config.h"		// autoheader header

#include "statements/Statement.h"

#include "elements/Binding.h"
#include "elements/Identifier_base.h"

namespace cplus_parser {

/**
 * @brief A statement representing a multi-valued answer set programming rule head :- b1, b2, ..., bn.
 */
template<typename pelem_base_t>
class MVASPRule : public Statement<pelem_base_t> 
{
public:
	/***********************************************************************/
	/* Types */
	/***********************************************************************/
	/// An iterator to iterator over the ASP rule's body.
	typedef typename std::list<pelem_base_t*>::const_iterator const_iterator;
private:
	/***********************************************************************/
	/* Members */
	/***********************************************************************/
	pelem_base_t* mHead;						///< The formula in the head of the rule.
	std::list<pelem_base_t*>* mBodyList;			///< The formulas in the body of hte rule.

	/***********************************************************************/
	/* Constructors / Destructors */
	/***********************************************************************/
	/**
	 * @brief Initializes the multi-valued ASP rule. 
	 * @param head The head of the multi-valued ASP rule (or NULL for empty).
	 * @param body The body of the multi-valued ASP rule (or NULL for empty).
	 * NOTE: This object takes ownership the memory associated with the head and body provided.
	 */
	inline MVASPRule(pelem_base_t* head = NULL, std::list<pelem_base_t*>* body = NULL)
		: mHead(head)
	{
		if (body) mBodyList = body;
		else mBodyList = new std::list<pelem_base_t*>();
	}

	/**
	 * @brief Destructor.
	 * Deallocates memory associated with the head and body.
	 */
	virtual inline ~MVASPRule() {
		if (mHead) delete mHead;
		size_t sz = mBodyList->size();
		for (;sz;sz--) { delete mBodyList->front(); mBodyList->pop_front(); }
	}

	/***********************************************************************/
	/* Accessors / Mutators */
	/***********************************************************************/
	/// Gets the head of the rule (or NULL for empty).
	inline pelem_base_t const* head() const { return mHead; }

	/// Gets an iterator for the beginning of the body.
	inline const_iterator beginBody() const { return mBodyList->begin(); }

	/// Gets an iterator for the end of the body.
	inline const_iterator endBody() const { return mBodyList->end(); }

	/// Sets the head of the ASP rule.
	inline void head(pelem_base_t* head) { if (mHead) delete mHead; mHead = head; }

	/// Adds an element to the body of ASP rule.
	inline void addToBody(pelem_base_t* formula) { mBodyList->push_back(formula); }
};
};