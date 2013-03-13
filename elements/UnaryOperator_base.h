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

#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

#include "config.h"		// autoheader header

#include "elements/ParseElement_base.h"

namespace cplus_parser {


/**
 * Represents a unary operator and the associated elements it operates on.
 * @type pelem_base_t The base ParseElement class in use, must be a descendant of ParseElement_base.
 */
template<typename pelem_base_t>
class UnaryOperator_base : public pelem_base_t
{
	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);

public:

	/// Enum of the kinds of unary operators this class can be.
	typedef enum {
		UOP_UNKNOWN,
		UOP_NOT,
		UOP_NEGATIVE,
		UOP_ABS,
		UOP_EXOGENOUS,
		UOP_INERTIAL,
		UOP_RIGID
	} UnaryOperatorType;

private:
	UnaryOperatorType mOpType;			///< Which kind of operator an instance represents.
	pelem_base_t* mPostOp; 				///< What comes after (and is affected by) the operator.

public:

	/**
	 * Full constructor.
	 * @param opType the type of operation the operator should perform.
	 * @param postOp the subexpression which occurs after the operator.
	 * @param parens Whether to add parens around the element.
	 */
	inline UnaryOperator_base(UnaryOperatorType opType, T* postOp, bool parens = false)
		: pelem_base_t(PELEM_UOP, parens), mOpType(opType), mPostOp(postOp)
	{ /* IntentionallY Left Blank */ }

	// inherited stuffs
	virtual std::ostream& fullName(std::ostream& out) const;
	inline virtual pelem_base_t* copy() const 			{ return new UnaryOperator_base<pelem_base_t>(opType(), postOp()->copy(), parens()); }

	/// Gets the operator's type.
	inline UnaryOperatorType opType() const 			{ return mOpType; }

	/// Sets the operator's type.
	inline void opType(UnaryOperatorType op) 			{ mOpType = op; }

	/// Gets the operator's sub expression.
	inline pelem_base_t const* postOp() const			{ return mPostOp; }

	/// Sets the operator's sub expression, deallocating any existing sub expression.
	inline void postOp(pelem_base_t* postOp)			{ if (mPostOp) delete mPostOp; mPostOp = postOp; }

	/// Detaches the operator's sub expression, returning it.
	pelem_base_t* detachPostOp();

	/**
	 * Destructor. Deallocates postOp.
	 */
	virtual inline ~UnaryOperator_base() { if(mPostOp) delete mPostOp; }

};

}; /* end namespace cplus_parser */

// Include the implementation file
#include "UnaryOperator_base.impl.h"
