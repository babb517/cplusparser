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

#include "elements/Quantifier_base.h"
#include "config.h"


namespace cplus_parser {


// Returns an original string representation of the quantifiers and what's getting quantified.
template <typename pelem_base_t>
std::ostream& Quantifier_base<pelem_base_t>::fullName(std::ostream& out) const
{
	if(postOp() && numQuants())
	{
		out << "[ ";
		for(QuantifierList::const_iterator lIter = quantsBegin(); lIter != quantsEnd(); lIter++)
		{
			if((*lIter) && (*lIter)->second)
			{
				switch((*lIter)->first)
				{
				case QUANT_CONJ:
					out << "/\\ ";
					break;
				case QUANT_DISJ:
					out << "\\/ ";
					break;
				default:
					break;
				}
				(*lIter)->second->fullName(out);
			}
		}
		out << " | ";
		postOp()->fullName(out);
		out << " ]";
	}
	return out;
}

template <typename pelem_base_t>
pelem_base_t* Quantifier_base<pelem_base_t>::copy() const {
	BigQuantifiers* res = new BigQuantifiers(NULL, NULL, parens());
	res->postOp((postOp()) ? postOp()->copy() : NULL);
	for (QuantifierList::const_iterator it = quantsBegin(); it != quantsEnd(); it++) {
		if ((*it)->second)
			res->addQuant(new Quantifier((*it)->first, (*it)->second->copy()));
	}
	return res;
}

// Detaches the operator's sub expression, returning it.
template <typename pelem_base_t>
pelem_base_t* Quantifier_base<pelem_base_t>::detachPostOp() {
	ParseElement* ret = mPostOp;
	mPostOp = NULL;
	return ret;
}

// Destructor.
template <typename pelem_base_t>
Quantifier_base<pelem_base_t>::~Quantifier_base()
{
	for(QuantifierList::iterator lIter = quantsBegin(); lIter != quantsEnd(); lIter++)
	{
		if((*lIter)->second)
		{
			delete (*lIter)->second;
		}
		delete (*lIter);
	}
	if(mPostOp)
		delete mPostOp;
}

}; /* end namespace cplus_parser */
