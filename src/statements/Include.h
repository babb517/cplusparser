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

#include "statements/Statement.h"

#include "config.h"		// autoheader header

namespace cplus_parser {

template <typename pelem_base_t>
class Include : public Statement<pelem_base_t> 
{
public:
	/****************************************************************/
	/* Types */
	/****************************************************************/
	/// An iterator for the included files.
	typedef std::list<std::string>::const_iterator const_iterator;

private:
	/****************************************************************/
	/* Members */
	/****************************************************************/
	std::list<std::string>* mFiles;	///< The files included by this statement.

public:
	/****************************************************************/
	/* Constructors / Destructors */
	/****************************************************************/
	/**
	 * @brief Initializes the include statement object.
	 * @param The location of the include file.
	 * @param files A list of files to add to the include statement initially.
	 * NOTE: This object takes ownership of all memory associated with the files list.
	 */
	inline Include(Location const& loc, std::list<std::string>* files = NULL) 
		: Statement<pelem_base_t>(StatementType::INCLUDE, loc) 
	{
		if (files) mFiles = files;
		else mFiles = new std::list<std::string>();
	}

	/**
	 * @brief basic destructor.
	 * Deallocates all memory associated with the files list.
	 */
	virtual inline ~Include() {
		delete mFiles;
	}

	/****************************************************************/
	/* Accessors */
	/****************************************************************/

	/// Gets an iterator for the beginning of the files list.
	inline const_iterator begin() const { return mFiles->begin(); }

	/// Gets an iterator for the end of the files list.
	inline const_iterator end() const { return mFiles->end(); }
};
};