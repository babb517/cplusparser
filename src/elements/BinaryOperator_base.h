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

template <typename pelem_base_t>
class BinaryWrapper_base;

/**
 * Represents a binary operator and the associated elements it operates on.
 * @type pelem_base_t The base ParseElement class in use, must be a descendant of ParseElement_base.
 */
template<typename pelem_base_t>
class BinaryOperator_base : public pelem_base_t
{
	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);

	// The wrapper class is used to efficiently use a new operator in a readonly environment.
	friend class SimpleBinaryOperatorWrapper<pelem_base_t>;

public:

	/// Enum of the kinds of unary operators this class can be.
	typedef enum {
		BOP_UNKNOWN,
		BOP_PLUS,
		BOP_MINUS,
		BOP_TIMES,
		BOP_DIVIDE,
		BOP_MOD,
		BOP_AND,
		BOP_OR,
		BOP_EQUIV,
		BOP_IMPL,
		BOP_REV_IMPL, // fake operator to simulate F <- G.
		BOP_EQ,
		BOP_NEQ,
		BOP_DBL_EQ,
		BOP_LTHAN,
		BOP_GTHAN,
		BOP_LTHAN_EQ,
		BOP_GTHAN_EQ,
		BOP_BIND_STEP
	} BinaryOperatorType;

private:
		enum BinaryOperatorType mOpType; ///< Which kind of operator an instance represents.

		pelem_base_t* mPreOp; 	///< The bit(s) bound to the operator that come before it.
		pelem_base_t* mPostOp; 	///< The bit(s) bound to the operator that come after it.
public:

	/**
	 * Full constructor.
	 * @param preOp The sub expression that comes before the operator.
	 * @param opType The binary operator.
	 * @param postOp The sub expression that comes after the operator.
	 * @param parens Whether to encase the expression in parens.
	 */
	inline BinaryOperator_base(pelem_base_t* preOp, BinaryOperatorType opType, pelem_base_t* postOp, bool parens = false)
		: pelem_base_t(PELEM_BOP, parens), mOpType(opType), mPreOp(preOp), mPostOp(postOp)
	{ /* Intentionally Left Blank */ }


	// inherted stuffs
	virtual std::ostream& fullName(std::ostream& out) const;
	inline virtual pelem_base_t* copy() const					{ return new SimpleBinaryOperator<pelem_base_t>(preOp()->copy(), opType(), postOp()->copy(), parens()); }

	/// Gets the operator's type.
	inline BinaryOperatorType opType() const 					{ return mOpType; }

	/// Sets the operator's type.
	inline void opType(BinaryOperatorType op) 					{ mOpType = op; }

	/// Gets a string corresponding to the provided operator type.
	std::string opToString(BinaryOperatorType op) const;

	/// Gets the operator's sub expression.
	inline pelem_base_t const* postOp() const					{ return mPostOp; }
	inline pelem_base_t const* preOp() const					{ return mPreOp; }

	/// Sets the operator's sub expression, deallocating any existing sub expression.
	inline void postOp(pelem_base_t* postOp)					{ if (mPostOp) delete mPostOp; mPostOp = postOp; }
	inline void preOp(pelem_base_t* postOp)						{ if (mPreOp) delete mPreOp; mPreOp = postOp; }

	/// Detaches the operator's sub expression, returning it.
	pelem_base_t* detachPostOp();
	pelem_base_t* detachPreOp();

	/**
	 * Destructor. Deallocates preOp and postOp.
	 */
	virtual inline ~BinaryOperator_base()						{ if (mPreOp) delete mPreOp; if (mPostOp) delete mPostOp; }

protected:

};


}; /* end namespace cplus_parser */

// Include the implementation file.
#include "elements/BinaryOperator_base.impl.h"
