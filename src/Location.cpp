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

#include <string>
#include <iostream>
#include <sstream>

#include "Location.h"

namespace cplus_parser {

// Constructs a string representation of this location.
std::string Location::str() const {
	std::stringstream tmp;
	output(tmp);
	return tmp.str();
}


// Outputs a string representation of this location to the provided output stream.
std::ostream& Location::output(std::ostream& out) const {
	if (begin_file) out << *begin_file;
	else out << "<no file>";
	out  << "::";
	
	bool diff_files = begin_file != end_file;
	bool diff_pos = diff_files || begin_line != end_line || begin_col != end_col;

	out << begin_line << ":" << begin_col;

	if (diff_pos) {
		out << "-";
	}

	if (diff_files) {
		if (end_file) out << *end_file;
		else out << "<no file>";
		out << "::";
	}

	if (diff_pos) {
		out << end_line << ":" << end_col;
	}

	return out;
}


}; /* end namespace cplus_parser */

