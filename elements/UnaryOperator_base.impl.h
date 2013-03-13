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

#include "elements/UnaryOperator_base.h"
#include "config.h"


namespace cplus_parser {

// Outputs the original string representation of the element.
template<typename pelem_base_t>
std::ostream& UnaryOperator_base<pelem_base_t>::fullName(std::ostream& out) const
{
	if(postOp())
	{
		// Create a CCalc-compatible representation of the operator first.
		switch(opType())
		{
		case UOP_NOT:
			out << "not ";
			break;
		case UOP_NEGATIVE:
			out << "-";
			break;
		case UOP_ABS:
			out << "abs ";
			break;
		case UOP_EXOGENOUS:
			out << "exogenous ";
			break;
		case UOP_INERTIAL:
			out << "inertial ";
			break;
		case UOP_RIGID:
			out << "rigid ";
			break;
		default:
			// Unknown operator, this should never happen
			out << " UNKNOWN ";
			break;
		}
		postOp()->fullName(out);
	}
	return out;
}

// Detaches the operator's sub expression, returning it.
template<typename pelem_base_t>
pelem_base_t* UnaryOperator_base<pelem_base_t>::detachPostOp() {
	pelem_base_t* ret = mPostOp;
	mPostOp = NULL;
	return ret;
}


}; /* end namespace cplus_parser */
