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
#include <iostream>

#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

#include "config.h"		// autoheader header

#include "elements/ParseElement_base.h"

namespace cplus_parser {

// Returns an original string representation of this operator and its operands.
template <typename pelem_base_t>
std::ostream& BinaryOperator_base<pelem_base_t>::fullName(std::ostream& out) const
{
	if(preOp() && postOp()) {
		preOp()->fullName(out);
		out << opToString(opType());
		postOp()->fullName(out);
	}
	else if(!preOp()) {
		postOp()->fullName(out);
	}
	else if(!postOp()) {
		preOp()->fullName(out);
	}
	return out;
}

// Detaches the operator's sub expression, returning it.
template <typename pelem_base_t>
pelem_base_t* BinaryOperator_base<pelem_base_t>::detachPostOp() {
	ParseElement* ret = mPostOp;
	mPostOp = NULL;
	return ret;
}

// Detaches the operator's sub expression, returning it.
template <typename pelem_base_t>
pelem_base_t* BinaryOperator_base<pelem_base_t>::detachPreOp() {
	ParseElement* ret = mPreOp;
	mPreOp = NULL;
	return ret;
}

// Converts an operatory to a string representation.
template <typename pelem_base_t>
std::string BinaryOperator_base<pelem_base_t>::opToString(BinaryOperatorType op) {
	std::string opStr;
	switch(op)
	{
	case BOP_PLUS:
		opStr = " + ";
		break;
	case BOP_MINUS:
		opStr = " - ";
		break;
	case BOP_TIMES:
		opStr = " * ";
		break;
	case BOP_DIVIDE:
		opStr = " / ";
		break;
	case BOP_MOD:
		opStr = " \\ ";
		break;
	case BOP_AND:
		opStr = " & ";
		break;
	case BOP_OR:
		opStr = " | ";
		break;
	case BOP_EQUIV:
		opStr = " <--> ";
		break;
	case BOP_IMPL:
		opStr = " -> ";
		break;
	case BOP_EQ:
		opStr = " == ";
		break;
	case BOP_NEQ:
		opStr = " != ";
		break;
	case BOP_DBL_EQ:
		opStr = " == ";
		break;
	case BOP_LTHAN:
		opStr = " < ";
		break;
	case BOP_GTHAN:
		opStr = " > ";
		break;
	case BOP_LTHAN_EQ:
		opStr = " <= ";
		break;
	case BOP_GTHAN_EQ:
		opStr = " >= ";
		break;
	default:
		// Unknown, this is a problem...
		opStr = " BAD_OP ";
		break;
	}
	return opStr;
}

}; /* end namespace cplus_parser */
