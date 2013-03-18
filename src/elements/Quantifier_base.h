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

/**
 * Represents a big quantifier group and its associated subformula.
 * @type pelem_base_t The base ParseElement class in use, must be a descendant of ParseElement_base.
 */
template<typename pelem_base_t>
class Quantifier_base : public pelem_base_t
{
	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);

public:
	/// Which kinds of "quantifiers" can be present.
	typedef enum { QUANT_UNKNOWN, QUANT_CONJ, QUANT_DISJ } QuantifierType;

	/// A single quantifier
	typedef std::pair<Quantifier_base::QuantifierType, pelem_base_t*> Quantifier;

	/// A list of quantifiers and their associated variable.
	typedef std::list<Quantifier*> QuantifierList;


private:
	/// A list of the quantifiers present in this grouping, both the kinds
	/// of quantifiers and references to the quantifying variables.
	QuantifierList mQuants;
	pelem_base_t* mPostOp; ///< The bit(s) affected by the quantifier(s).

public:

	/**
	 * Full Constructor.
	 * @param quants The list of quantifiers that encase the sub expression. (Null initializes the expression to have no quantifiers).
	 * @param postOp The sub expression that occurs after the quantifiers.
	 * @param parens Whether to encase the expression in parens.
	 */
	inline Quantifier_base(QuantifierList const* quants = NULL, pelem_base_t* postOp = NULL, bool parens = false)
		: pelem_base_t(PELEM_QUANT, parens), mPostOp(postOp) {
		if (quants) mQuants = *quants;
	}


	// inherited stuffs
	inline virtual bool isArithExpr() const						{ return false; }
	inline virtual bool hasLuaCalls() const						{ return postOp() && postOp()->hasLuaCalls(); }
	virtual std::ostream& fullName(std::ostream& out) const;
	virtual pelem_base_t* copy() const;

	/// Gets the begining of the list of quantifiers.
	inline QuantifierList::const_iterator quantsBegin() const 	{ return mQuants.begin(); }

	/// Gets the end of the list of quantifiers.
	inline QuantifierList::const_iterator quantsEnd() const 	{ return mQuants.end(); }

	/// Gets the number of quantifiers associated with this instance.
	inline size_t numQuants() const								{ return mQuants.size(); }

	/// Adds a quantifier to the list.
	inline void addQuant(Quantifier* newQuant)					{ mQuants.push_back(newQuant); }

	/// Gets the operator's sub expression.
	inline pelem_base_t const* postOp() const	{ return mPostOp; }

	/// Sets the operator's sub expression, deallocating any existing sub expression.
	inline void postOp(pelem_base_t* postOp)	{ if (mPostOp) delete mPostOp; mPostOp = postOp; }

	/// Detaches the operator's sub expression, returning it.
	pelem_base_t* detachPostOp();

	/**
	 * Destructor. Deallocates postOp and the contents of quants.
	 */
	virtual ~Quantifier_base();

protected:
	/// Gets the begining of the list of quantifiers.
	inline QuantifierList::iterator quantsBegin() 	{ return mQuants.begin(); }

	/// Gets the end of the list of quantifiers.
	inline QuantifierList::iterator quantsEnd() 	{ return mQuants.end(); }
};

}; /* end namespce cplus_parser */

// Include the implementation file
#include "elements/Quantifier_base.impl.h"
