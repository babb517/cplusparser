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

template <typename pelem_base_t>
class Identifier_base;
class Binder;

namespace cplus_parser {

/**
 * @brief A single binder statement used to bind identifiers (id1,...,idk :: binder)
 */
template <typename pelem_base_t>
class Binding {
public:
	/**********************************************************/
	/* Types */
	/**********************************************************/
	/// An iterator for the binder statement.
	typedef typename std::list<Identifier_base<pelem_base_t>*>::const_iterator const_iterator;
private:
	/**********************************************************/
	/* Members */
	/**********************************************************/
	Binder* mBinder;												///< The binder specifing information for the identifier.
	std::list<Identifier_base<pelem_base_t>*>* mIds;				///< The identifiers being bound by the binder.

public:
	/**********************************************************/
	/* Constructors / Destructors */
	/**********************************************************/
	/**
	 * @brief Initializes a binding object.
	 * @param binder The binder that will be used to bind the identifiers in the binding.
	 * @param Ids A list of initial Ids (or NULL to create an empty binding).
	 * NOTE: This object takes ownership of the memory associated with the binder and list. It's lifetime becomes bound by this object.
	 */
	inline Binding(Binder* binder, std::list<Identifier_base<pelem_base_t>*>* Ids = NULL)
		: mBinder(binder) { 
		if (Ids) mIds = Ids; 
		else mIds = new std::list<Identifier_base<pelem_base_t>*>(); 
	}

	/**
	 * @brief Frees all memory associated with the binder and identifiers list.
	 */
	inline ~Binding() {
		size_t sz = mIds->size();
		delete mBinder;
		for (; sz; sz--) { delete mIds.front(); mIds.pop_front(); }
		delete mIds;
	}


	/**********************************************************/
	/* Accessors / Mutators */
	/**********************************************************/
	/// Gets the binder for the binding statements.
	inline Binder const* binder() const { return mBinder; }

	/// Gets the beginning of the Identifiers being bound.
	inline const_iterator begin() const { return mIds->begin(); }

	/// Gets the end of the Id Identifiers being bound.
	inline const_iterator end() const { return mIds->end(); }

	/// Adds an identifier to the binding.
	/// Note: Ownership of the identifier's memory is taken by this object, it's lifetime becomes bound this object.
	inline void add(Identifier_base<pelem_base_t>* id) { mIds->push_back(id); }
};

}; /* end namespace cplus_parser */


