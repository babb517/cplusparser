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

#include <iostream>
#include <string>

namespace cplus_parser {

/**
 * @brief A simple class that tracks the location of an object in the input.
 */
class Location {
public:
	/***********************************************************************/
	/* Members */
	/***********************************************************************/
	// beginning
	std::string const*	begin_file;			///< beginning file name.
	size_t				begin_col;			///< beginning column #.
	size_t				begin_line;			///< beginning line #.

	// ending
	std::string const*  end_file;			///< end file name./
	size_t				end_col;			///< end column #.
	size_t				end_line;			///< end line #.


	/// Default constructor, pointers set to NULL and that's it.
	inline Location() : begin_file(NULL), end_file(NULL) { }

	/**
	 * @brief Basic Constructor. Initializes the location at the provided point.
	 */
	inline Location(std::string const* file, size_t line, size_t col)
	{ init(file, line, col); }

	/// Initializes the location's start and end.
	inline void init(std::string const* file, size_t line, size_t col)
	{ 
		begin(file, line, col);
		end(file, line, col);
	}

	/// Sets the start location.
	inline void begin(std::string const* file, size_t line, size_t col)
	{
		begin_file =file;
		begin_col = col;
		begin_line = line;
	}

	/// Sets the end of location.
	inline void end(std::string const* file, size_t line, size_t col)
	{
		end_file = file;
		end_col = col;
		end_line = line;
	}

	/// increments the ending line by \a n.
	inline void line(size_t n) { end_line += n; }

	/// increments the ending column by \a n.
	inline void col(size_t n) { end_col += n; }

	/// Constructs a standardized string representation of this location.
	std::string str() const;

	/// Outputs a string representation of this location to the provided output stream.
	std::ostream& output(std::ostream& out) const;
};



}; /* end namespace cplus_parser */
