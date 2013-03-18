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
 * Container class to hold information that is used to bind various identifiers.
 */
class Binder
{
private:
	/**********************************************************/
	/* Members */
	/**********************************************************/
	std::string mPrimary;		///< The primary binding descriptor, such as exogenousAction, attribute, or some sort name.
	std::string mSeconday; 		///< The secondary binding descriptor (the part that occurs in parentheses) such as a sort.
	std::string mTertiary; 		///< The tertiary binding descriptor, such as the parent action in the event the primary descriptor is attribute.
public:
	/**********************************************************/
	/* Constructors / Destructors */
	/**********************************************************/

	/**
	 * Basic constructor.
	 * @param primary The primary binding descriptor string.
	 * @param secondary The secondary binding descriptor string.
	 * @param tertiary The tertiary binding descriptor string.
	 */
	inline Binder(std::string const& primary, std::string const& secondary = "", std::string const& tertiary = "")	
		: mPrimary(primary), mSeconday(secondary), mTertiary(tertiary) 
	{ /* Intentionally left blank */ }

	/**
	 * Destructor.
	 */
	virtual inline ~Binder() { /* Intentionally left blank */ }

	/**********************************************************/
	/* Accessors */
	/**********************************************************/

	/// Gets the primary binding.
	inline std::string const& primary() const 		{ return mPrimary; }

	/// Gets the secondary binding.
	inline std::string const& secondary() const 	{ return mSeconday; }

	/// Gets the tertiary binding.
	inline std::string const& tertiary() const 	{ return mTertiary; }
};



}; /* end namespace cplus_parser */
