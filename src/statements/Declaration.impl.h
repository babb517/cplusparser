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

#include "elements/Binder.h"
#include "elements/Binding.h"
#include "elements/Identifier_base.h"

namespace cplus_parser {

/**************************************************************************/
/* Declaration<pelem_base_t>::iterator */
/**************************************************************************/

// initialize and point to provided position
template <typename pelem_base_t>
Declaration<pelem_base_t>::const_iterator::const_iterator(
			typename std::list<Binding<pelem_base_t>*>::const_iterator const& outer, 
			typename Binding<pelem_base_t*>::const_iterator const& inner,
			typename std::list<Binding<pelem_base_t>*>::const_iterator const& outerBound)
{
	mSet = false;
	mOuterIt = outer;
	mInnerIt = inner;
	mOuterEnd = outerBound;
}

// initialize and point to position of other (copy constructor).
template <typename pelem_base_t>
Declaration<pelem_base_t>::const_iterator::const_iterator(const_iterator const& other) {
	mSet = false;
	mOuterIt = other.mOuterIt;
	mOuterEnd = other.mOuterEnd;
}

// Move to the next position.
template <typename pelem_base_t>
void Declaration<pelem_base_t>::const_iterator::increment() {
	mSet = false;
	if (mOuterIt != mOuterEnd) {
		if (++mInnerIt == mOuterIt->identifiers.end()) {
			if (++mOuterIt != mOuterEnd) mInnerIt = mOuterIt->identifier.begin();
		}
	}
}

// Updates the internal working space of the iterator.
template <typename pelem_base_t>
void Declaration<pelem_base_t>::const_iterator::set() {
	if (mOuterIt != mOuterEnd && mInnerIt != mOuterIt->identifiers.end()) {
		mTempRef.binder = mOuterIt->binder;
		mTempRef.identifier = *mInnerIt;
	} else {
		mTempRef.binder = NULL;
		mTempRef.identifier = NULL;
	}
	mSet = true;
}


}; /* end namespace cplus_parser */