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
#include <string>

#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>
#include <boost/iterator/iterator_facade.hpp>

#include "config.h"		// autoheader header

#include "statements/Statement.h"

namespace cplus_parser {

template <typename pelem_base_t>
class Query : public Statement<pelem_base_t>
{
public:
	/*********************************************************/
	/* Types */
	/*********************************************************/
	/// Query iterator type.
	typedef std::list<pelem_base_t*>::const_iterator const_iterator;

	/// Query types
	typedef enum {
		QUERY,		///< Standard (monotonic) query.
		NMQUERY		///< Non-monotonic query.
	} QueryType;


private:
	/*********************************************************/
	/* Members */
	/*********************************************************/
	QueryType mType;							///< The type of query this object represents.
	std::list<pelem_base_t*>* mFormulas;		///< The formulas associated with this query.
	std::string mLabel;							///< The label of this query.
	pelem_base_t* mMinstep;						///< The minimum step for this query.
	pelem_base_t* mMaxstep;						///< The maximum step for this query.


public:
	/*********************************************************/
	/* Constructors / Destructors */
	/*********************************************************/
	/**
	 * @brief Initializes a new query object.
	 * @param type The type of query that this object will represent.
	 * @param label A unique name this query will be identified with.
	 * @param minstep An (optional) expression for the first step to attempt to solve for. NULL if not provided.
	 * @param maxstep An (optional) expression for the last step to attempt to solve for. NULL if not provided.
	 * @param formulas An initial list of formulas to add to the query. NULL to create an empty query.
	 */
	inline Query(QueryType type, 
		std::string const& label, 
		pelem_base_t* minstep = NULL, 
		pelem_base_t* maxstep = NULL, 
		std::list<pelem_base_t*>* formulas = NULL
		) : Statement(QUERY), mType(type), mLabel(label), mMinstep(minstep), mMaxstep(maxstep)
	{ 
		if (formulas) mFormulas = formulas; 
		else mFormulas = new std::list<pelem_base_t*>();
	}

	/**
	 * @brief Destructor.
	 * Frees all memory associated with the minstep, maxstep, and formulas.
	 */
	virtual inline ~Query() {
		if (mMinstep) delete mMinstep;
		if (mMaxstep) delete mMaxstep;
		size_t sz = mFormulas->size();
		for (;sz;sz--) { delete mFormulas->front(); mFormulas->pop_front(); }
	}

	/*********************************************************/
	/* Accessors / Mutators */
	/*********************************************************/
	/// Gets the type of query being represented.
	inline QueryType subtype() const { return mType; }

	/// Gets the label of the query.
	inline std::string const& label() const { return mLabel; }

	/// Gets the minimum step of the query (or NULL for not specified).
	inline pelem_base_t const* minstep() const { return mMinstep; }

	/// Gets the maximum step of the query (or NULL for not sepcified).
	inline pelem_base_t const* maxstep() const { return mMaxstep; }

	/// Gets the beginning of the query formula list.
	inline const_iterator begin() const { return mFormulas->begin(); }

	/// Gets the end of the query formula list.
	inline const_iterator end() const { return mFormulas->end(); }

	/**
	 * @brief Adds a formula to the query.
	 * @param formula The query formula to add.
	 * NOTE: This object takes ownership of the formula's memory.
	 */
	inline void add(pelem_base_t* formula) { mFormulas->push_back(formula); }


};
;}