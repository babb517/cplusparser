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
#include <iostream>

#include "elements/Identifier_base.h"
#include "config.h"


namespace cplus_parser {

// Outputs the original full name of the element, including parameters.
template <typename pelem_base_t>
std::ostream& Identifier_base<pelem_base_t>::fullName(std::ostream& out) const
{
	out << baseName();
	if(arity()) {
		out << "(";
		int i = 0;
		for(std::list<pelem_base_t*>::const_iterator vIter = paramsBegin(); vIter != paramsEnd(); vIter++) {
			if(*vIter)
			{
				if(i++ > 0)	out <<",";
				(*vIter)->fullName(out);
			}
		}
		out << ")";
	}
	return out;
}

// Destructor.
template <typename pelem_base_t>
Identifier_base<pelem_base_t::~Identifier_base()
{
	for(std::list<pelem_base_t*>::iterator vIter = paramsBegin(); vIter != paramsEnd(); vIter++) {
		if(*vIter) delete *vIter;
	}
}

}; /* end namespace cplus_parser */
