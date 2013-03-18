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
#include "elements/BinaryOperator_base.h"

namespace cplus_parser {

/**
 * A simple (readonly) wrapper class to easily and efficiently change the operator.
 * @type pelem_base_t The base ParseElement class in use, must be a descendant of ParseElement_base.
 */
template<typename pelem_base_t>
class BinaryWrapper_base : public pelem_base_t {

	BOOST_STATIC_ASSERT_MSG(
		(boost::is_base_of<ParseElement_base, pelem_base_t>::value),
		"pelem_base_t must be a descendant of ParseElement_base"
	);

private:
	BinaryOperator_base<pelem_base_t> const* mWrapped;
	BinaryOperator_base::BinaryOperatorType mType;
	bool mForceParens;
public:

	/**
	 * Constructor.
	 * @param wrappedExpr The expression to wrap.
	 * @param type The new operator type.
	 * @param forceParens Whether to force the presence of parens around the expression.
	 */
	inline BinaryWrapper_base(
			BinaryOperator_base<pelem_base_t> const* wrappedExpr,
			BinaryOperator_base::BinaryOperatorType type,
			bool forceParens = false
	)
		: pelem_base_t(wrappedExpr->getType(), wrappedExpr->parens()), mWrapped(wrappedExpr), mType(type), mForceParens(forceParens)
	{ /* Intetionally Left Blank */ }

	inline virtual std::ostream& fullName(std::ostream& out) const
																{ return mWrapped->fullName(out); }
	inline virtual pelem_base_t* copy() const					{ return new SimpleBinaryOperatorWrapper<pelem_base_t>(mWrapped, mType, mForceParens); }

	/// Gets the operator's type.
	inline BinaryOperator_base::BinaryOperatorType opType() const 	{ return mType; }

	/// Sets the operator's type.
	inline void opType(BinaryOperator_base::BinaryOperatorType op) { mType = op; }


	/// Gets the operator's sub expression.
	inline pelem_base_t const* postOp() const	{ return mWrapped->postOp(); }
	inline pelem_base_t const* preOp() const	{ return mWrapped->preOp(); }


	/// Destructor. Does nothing.
	inline virtual ~BinaryWrapper_base() { /* Intetionally Left Blank */ }

};

}; /* end namespace cplus_parser */
