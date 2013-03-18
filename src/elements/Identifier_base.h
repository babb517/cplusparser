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
#include <iostream>

#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

#include "config.h"		// autoheader header

#include "elements/ParseElement_base.h"

namespace cplus_parser {

/**
 * Acts as a base class for parsed elements like constants and objects.
 * @type pelem_base_t The base ParseElement class in use, must be a descendant of ParseElement_base.
 */
template<typename pelem_base_t>
class Identifier_base : public pelem_base_t
{
	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);

private:
	std::string mBaseName; 				///< The original name of the element, sans parameters.
	std::list<pelem_base_t*> mParams; 	///< References to representations of the element's parameters, if any.
public:

	/**
	 * Full constructor.
	 * @param elemType The concrete type that's being instantiated.
	 * @param baseName The base name of the element that's being instantiated (without parameters).
	 * @param symbolRef A pointer to the symbol that this element is an instance of.
	 * @param params The list of parameters associated with this instance. Null if there are no parameters.
	 * @param parens Whether the element should be encased in parens.
	 */
	inline Identifier_base(
			ParseElementType elemType,
			std::string const& baseName,
			ParseElementList* params = NULL,
			bool parens = false
	)
		: pelem_base_t(elemType, parens), mBaseName(baseName)
	{ if (params) mParams = *params; }

	// inherited stuffs
	virtual std::ostream& fullName(std::ostream& out) const;
	virtual pelem_base_t* copy() const = 0;

	/// Gets the base name for the element.
	inline std::string const& baseName() const 								{ return mBaseName; }

	/// Gets an iterator for the beginning of the parameter list.
	inline std::list<pelem_base_t*>::const_iterator paramsBegin() const 	{ return mParams.begin(); }

	/// Gets an iterator for the end of the parameter list.
	inline std::list<pelem_base_t*>::const_iterator paramsEnd() const 		{ return mParams.end(); }

	/// Gets the number of parameters the element has.
	inline size_t arity() const												{ return mParams.size(); }


	/// Clears the list of parameters without deallocating them.
	inline void detachParams() 												{ mParams.clear(); }

	/**
	 * Destructor. Deallocates contents of params.
	 */
	virtual ~Identifier_base();

protected:

	/// Gets an iterator for the beginning of the parameter list.
	inline std::list<pelem_base_t*>::iterator paramsBegin() { return mParams.begin(); }

	/// Gets an iterator for the end of the parameter list.
	inline std::list<pelem_base_t*>::iterator paramsEnd() { return mParams.end(); }

};

}; /* end namespace cplus_parser */

// Include the implementation file.
#include "elements/Identifier_base.impl.h"
