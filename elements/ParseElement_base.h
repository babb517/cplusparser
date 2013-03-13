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
#include "config.h"		// autoheader header

namespace cplus_parser {

/**
 * General parent of all self-contained, self-translating parse tree elements.
 */
class ParseElement_base
{
public:

	/// The possible types of a ParseElement instance.
	typedef enum {
		PELEM_PELEM,
		PELEM_UOP,
		PELEM_BOP,
		PELEM_QUANT,
		PELEM_BASELIKE,
		PELEM_CONSTLIKE,
		PELEM_OBJLIKE,
		PELEM_VARLIKE
	} ParseElementType;

private:

	bool mParens; 					///< If true, the expression should be wrapped in parentheses
	ParseElementType mElemType; 	///< The type of the parse element instance.

public:

	/**
	 * Default constructor. Sets elemType.
	 * @param elemType The type that the element is.
	 * @param parens Whether to add parens around the element.
	 */
	inline ParseElement_base(ParseElementType elemType, bool parens = false)
		: mParens(parens), mElemType(elemType)
		{ /* Intentionally Left Blank */ }

	/**
	 * @brief Prints the untranslated element string.
	 * @param out The output stream to print to.
	 * @return out.
	 */
	virtual std::ostream& fullName(std::ostream& out) const = 0;

	/**
	 * @brief Returns an exact copy of the parse element.
	 * @return A copy of this element.
	 */
	virtual ParseElement_base* copy() const = 0;

	/// Alternative helper to fullName(std::ostream&).
	inline std::string fullName() const 						{ std::ostringstream ret; fullName(ret); return ret.str(); }

	/// Gets the type of the parse element.
	inline ParseElementType getType() const 					{ return mElemType; }

	/**
	 * Sets whether the expression is wrapped in parentheses.
	 * @param parens Whether the expression should be wrapped in parentheses.
	 */
	inline void parens(bool parens) { this->mParens = parens; }

	/// Gets whether the element is encompassed in parens
	inline bool parens() const { return mParens; }

	/**
	 * Destructor. Empty.
	 */
	inline virtual ~ParseElement_base() { /* Intentionally Left Blank */};

};


}; /* end namespace cplus_parser */
