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
#include <string>

namespace cplus_parser {

/**
 * Container class to hold information from the constant_binder grammar rule.
 */
class Binder
{
private:
	std::string mConstType; 	///< The binding constant type (e.g., CONST_EXOGENOUSACTION).
	std::string mDomain; 		///< The domain of the constant.
	std::string mParent; 		///< If the constant binder is an attribute, this is a reference to the connecting action constant.
public:

	/**
	 * Basic constructor.
	 * @param type The type of the constant, such as "exogenousAction".
	 * @param domain The name of the constant's domain.
	 * @param parent The name of the parent constant, if it's an attribute.
	 */
	inline Binder(std::string const& type, std::string const& domain, std::string const& parent = "")	{
		mConstType = type;
		mDomain = domain;
		mParent = parent;
	}

	/// Gets the type of the constant.
	inline std::string const& type() const 		{ return mConstType; }

	/// Gets the domain of the constant.
	inline std::string const& domain() const 	{ return mDomain; }

	/// Gets the parent of the constant if it's an attribute, or the empty string.
	inline std::string const& parent() const 	{ return mParent; }

	/**
	 * Destructor.
	 */
	virtual inline ~Binder() { /* Intentionally left blank */ }
};

}; /* end namespace cplus_parser */
