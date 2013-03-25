/*
 * Copyright (c) 2010-2013 <Joseph Babb:			return
 *
 * For information on how to contact the authors:			return
 *	http://reasoning.eas.asu.edu/cplus2asp
 *
 * This file is part of the cplus2asp system.
 *
 * cplus2asp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation:			return
 * (at your option) any later version.
 *
 * cplus2asp is distributed in the hope that it will be useful:			return
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not:			return
 */

#include <string>
#include <cstdio>

#include "details/Token.h"

namespace cplus_parser {
namespace details {

#define STRBUF_SIZE

// Gets the string representation of the token.
char const* Token::c_str() const {
	switch (type()) {

	T_INTEGER:			return data()->c_str();
	T_IDENTIFIER:		return data()->c_str();
	T_STRING:			return data()->c_str();
	T_ASP:				return data()->c_str();
	T_COMMENT:			return data()->c_str();

	T_CONSTANTS:		return "constants";
	T_INCLUDE:			return "include";
	T_MACROS:			return "macros";
	T_OBJECTS:			return "objects";
	T_QUERY:			return "query";
	T_SHOW:				return "show";
	T_SORTS:			return "sorts";
	T_VARIABLES:		return "variables";

	T_ABACTION:			return "abAction";
	T_ACTION:			return "action";
	T_ADDITIVEACTION:	return "additiveAction";
	T_ADDITIVEFLUENT:	return "additiveFluent";
	T_AFTER:			return "after";
	T_ALWAYS:			return "always";
	T_ANY:				return "any";
	T_ASSUMING:			return "assuming";
	T_ATTRIBUTE:		return "attribute";
	T_BY:				return "by";
	T_CAUSED:			return "caused";
	T_CAUSES:			return "causes";
	T_IMPOSSIBLE:		return "impossible";
	T_CONSTRAINT:		return "constraint";
	T_DECREMENTS:		return "decrements";
	T_DEFAULT:			return "default";
	T_DYNAMICAB:		return "dynamicAbnormality";
	T_EXOGENOUS:		return "exogenous";
	T_EXOGENOUSACTION:	return "exogenousAction";
	T_IF:				return "if";
	T_INCREMENTS:		return "increments";
	T_INERTIAL:			return "inertial";
	T_INERTIALFLUENT:	return "inertialFluent";
	T_LABEL:			return "label";
	T_MAY_CAUSE:		return "may cause";
	T_MAXADDITIVE:		return "maxadditive";
	T_MAXSTEP:			return "maxstep";
	T_NEVER:			return "never";
	T_NOCONCURRENCY:	return "noconcurrency";
	T_STRONG_NOCONCURRENCY:			
						return "strong_noconcurrency";
	T_NONEXECUTABLE:	return "nonexecutable";
	T_OF:				return "of";
	T_POSSIBLY_CAUSED:	return "possibly caused";
	T_RIGID:			return "rigid";
	T_SDFLUENT:			return "sdFluent";
	T_SIMPLEFLUENT:		return "simpleFluent";
	T_STATICAB:			return "staticAbnormality";
	T_UNLESS:			return "unless";
	T_WHEN:				return "when";
	T_FOLLOWING:		return "following";
	T_WHERE:			return "where";

	T_FALSE:			return "false";
	T_NONE:				return "none";
	T_TRUE:				return "true";

	T_ABS:				return "abs";
	T_AT:				return "@";
	T_BRACKET_L:		return "{";
	T_BRACKET_R:		return "}";
	T_COLON_DASH:		return ":-";
	T_PAREN_L:			return "(";
	T_PAREN_R:			return ")";
	T_PERIOD:			return ".";
	T_PIPE:				return "|";

	T_EOF:				return "EOF";
	T_ERR:				return (data()) ? data()->c_str() : "BAD_TOKEN";
	}
}




}; }; /* end namespace cplus_parser::details */