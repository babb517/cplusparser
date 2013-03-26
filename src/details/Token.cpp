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

	case T_INTEGER:			return data()->c_str();
	case T_IDENTIFIER:		return data()->c_str();
	case T_STRING:			return data()->c_str();
	case T_ASP:				return data()->c_str();
	case T_COMMENT:			return data()->c_str();

	case T_CONSTANTS:		return "constants";
	case T_INCLUDE:			return "include";
	case T_MACROS:			return "macros";
	case T_OBJECTS:			return "objects";
	case T_QUERY:			return "query";
	case T_SHOW:			return "show";
	case T_SORTS:			return "sorts";
	case T_VARIABLES:		return "variables";

	case T_ABACTION:		return "abAction";
	case T_ACTION:			return "action";
	case T_ADDITIVEACTION:	return "additiveAction";
	case T_ADDITIVEFLUENT:	return "additiveFluent";
	case T_AFTER:			return "after";
	case T_ALWAYS:			return "always";
	case T_ANY:				return "any";
	case T_ASSUMING:		return "assuming";
	case T_ATTRIBUTE:		return "attribute";
	case T_BY:				return "by";
	case T_CAUSED:			return "caused";
	case T_CAUSES:			return "causes";
	case T_IMPOSSIBLE:		return "impossible";
	case T_CONSTRAINT:		return "constraint";
	case T_DECREMENTS:		return "decrements";
	case T_DEFAULT:			return "default";
	case T_DYNAMICAB:		return "dynamicAbnormality";
	case T_EXOGENOUS:		return "exogenous";
	case T_EXOGENOUSACTION:	return "exogenousAction";
	case T_IF:				return "if";
	case T_INCREMENTS:		return "increments";
	case T_INERTIAL:		return "inertial";
	case T_INERTIALFLUENT:	return "inertialFluent";
	case T_LABEL:			return "label";
	case T_MAY_CAUSE:		return "may cause";
	case T_MAXADDITIVE:		return "maxadditive";
	case T_MAXSTEP:			return "maxstep";
	case T_NEVER:			return "never";
	case T_NOCONCURRENCY:	return "noconcurrency";
	case T_STRONG_NOCONCURRENCY:			
							return "strong_noconcurrency";
	case T_NONEXECUTABLE:	return "nonexecutable";
	case T_OF:				return "of";
	case T_POSSIBLY_CAUSED:	return "possibly caused";
	case T_RIGID:			return "rigid";
	case T_SDFLUENT:		return "sdFluent";
	case T_SIMPLEFLUENT:	return "simpleFluent";
	case T_STATICAB:		return "staticAbnormality";
	case T_UNLESS:			return "unless";
	case T_WHEN:			return "when";
	case T_FOLLOWING:		return "following";
	case T_WHERE:			return "where";

	case T_FALSE:			return "false";
	case T_NONE:			return "none";
	case T_TRUE:			return "true";

	case T_ABS:				return "abs";
	case T_AT:				return "@";
	case T_BRACKET_L:		return "{";
	case T_BRACKET_R:		return "}";
	case T_COLON_DASH:		return ":-";
	case T_PAREN_L:			return "(";
	case T_PAREN_R:			return ")";
	case T_PERIOD:			return ".";
	case T_PIPE:			return "|";

	case T_SEMICOLON:		return ";";
	case T_DBL_COLON:		return "::";
	case T_ARROW_LEQ:		return "<=";
	case T_ARROW_REQ:		return "=>";
	case T_ARROW_LDASH:		return "<-";
	case T_ARROW_RDASH:		return "->";
	case T_COLON:			return ":";
	case T_COMMA:			return ",";
	case T_EQUIV:			return "<->";
	case T_IMPL:			return "->";
	case T_DBL_PLUS:		return "++";
	case T_AMP:				return "&";
	case T_EQ: 				return "=";
	case T_DBL_EQ:			return "==";
	case T_NOT_EQ:			return "\\=";
	case T_LTHAN:			return "<";
	case T_GTHAN:			return ">";
	case T_EQ_LTHAN:		return "=<";
	case T_GTHAN_EQ:		return ">=";
	case T_NOT:				return "not";
	case T_DBL_PERIOD:		return "..";
	case T_DASH:			return "-";
	case T_PLUS:			return "+";
	case T_DBL_GTHAN:		return ">>";
	case T_STAR:			return "*";
	case T_INT_DIV:			return "//";
	case T_MOD:				return "mod";
	case T_BIG_CONJ:		return "/\\";
	case T_BIG_DISJ:		return "\\/";
	case T_POUND:			return "#";
	case T_UMINUS:			return "-";

	case T_EOF:				return "<EOF>";
	case T_ERR:				return (data()) ? data()->c_str() : "<BAD TOKEN>";

	case T_DEBUG_INSERT:	return "#debug_insert_file.";
	case T_DEBUG_APPEND:	return "#debug_append_file.";
	case T_DEBUG_INJECT:	return "#debug_inject_string.";

	default:				return (data()) ? data()->c_str() : "<UNKNOWN TOKEN>";
	}
}




}; }; /* end namespace cplus_parser::details */
