/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */

/* Line 279 of lalr1.cc  */
#line 38 "parser.cc"


#include "parser.hh"

/* User implementation prologue.  */
/* Line 285 of lalr1.cc  */
#line 258 "parser.yy"

#include "lexerTokenStream.h"

/* Line 285 of lalr1.cc  */
#line 263 "parser.yy"

Translator mainTrans; 						// The main Translator instance, declared by the parser to create a close working relationship.
bool ltsyyendOfFile = false; 				// True if the parser has reached the end of the input stream.
std::ostringstream ltsyyossErr; 			// Output string stream used to store and output error messages from the parser and its helper modules.

/// Clears the contents and error flags of the output string stream used for error reporting.
#define LTSYYRESETOSS \
ltsyyossErr.str(""); \
ltsyyossErr.clear();

/// Placeholder value for parse rules whose lvals ($$) we don't end up needing.
#define PARSERULE_NOT_USED NULL

/// Clears out, deallocates, and nullifies a list/vector/etc. pointer.
#define deallocateList(lst) if (lst) { lst->clear(); delete lst; lst = NULL; }

/// Deallocates and nullifies a non-container pointer.
#define deallocateItem(item) if (item) { delete item; item = NULL; }

// Helper functions for actions.

/**
 * Tries to find an existing normal sort or declare a starred ("something*") sort.
 * Will not instantiate a normal sort (even as a child of a "something*" sort, will
 * report an error instead.
 * @param sortIdent - The name of the sort to check and find.
 * @return A pointer to the associated instantiated sort obect, or NULL if the sort wasn't found.
 */
Sort* checkDynamicSortDecl(std::string* sortIdent);


/* Line 285 of lalr1.cc  */
#line 83 "parser.cc"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

/* Line 353 of lalr1.cc  */
#line 28 "parser.yy"
namespace cplus_parser { namespace details {
/* Line 353 of lalr1.cc  */
#line 179 "parser.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 4: /* T_IDENTIFIER */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 246 "parser.cc"
        break;
      case 5: /* T_STRING */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 253 "parser.cc"
        break;
      case 110: /* constant_schema_outer_list */
/* Line 455 of lalr1.cc  */
#line 463 "parser.yy"
        { if(((*yyvaluep).l_constant) != NULL) { deallocateList(((*yyvaluep).l_constant)); } };
/* Line 455 of lalr1.cc  */
#line 260 "parser.cc"
        break;
      case 111: /* constant_schema_list */
/* Line 455 of lalr1.cc  */
#line 463 "parser.yy"
        { if(((*yyvaluep).l_constant) != NULL) { deallocateList(((*yyvaluep).l_constant)); } };
/* Line 455 of lalr1.cc  */
#line 267 "parser.cc"
        break;
      case 112: /* constant_outer_schema */
/* Line 455 of lalr1.cc  */
#line 457 "parser.yy"
        { delete ((*yyvaluep).constant); };
/* Line 455 of lalr1.cc  */
#line 274 "parser.cc"
        break;
      case 113: /* constant_schema */
/* Line 455 of lalr1.cc  */
#line 457 "parser.yy"
        { delete ((*yyvaluep).constant); };
/* Line 455 of lalr1.cc  */
#line 281 "parser.cc"
        break;
      case 114: /* constant_schema_nodecl */
/* Line 455 of lalr1.cc  */
#line 457 "parser.yy"
        { delete ((*yyvaluep).constant); };
/* Line 455 of lalr1.cc  */
#line 288 "parser.cc"
        break;
      case 115: /* constant_outer_binder */
/* Line 455 of lalr1.cc  */
#line 467 "parser.yy"
        { if(((*yyvaluep).constant_binder_t) != NULL) { deallocateItem(((*yyvaluep).constant_binder_t)); } };
/* Line 455 of lalr1.cc  */
#line 295 "parser.cc"
        break;
      case 116: /* constant_binder */
/* Line 455 of lalr1.cc  */
#line 467 "parser.yy"
        { if(((*yyvaluep).constant_binder_t) != NULL) { deallocateItem(((*yyvaluep).constant_binder_t)); } };
/* Line 455 of lalr1.cc  */
#line 302 "parser.cc"
        break;
      case 123: /* object_outer_schema_list */
/* Line 455 of lalr1.cc  */
#line 464 "parser.yy"
        { if(((*yyvaluep).l_object) != NULL) { deallocateList(((*yyvaluep).l_object)); } };
/* Line 455 of lalr1.cc  */
#line 309 "parser.cc"
        break;
      case 124: /* object_schema_list */
/* Line 455 of lalr1.cc  */
#line 464 "parser.yy"
        { if(((*yyvaluep).l_object) != NULL) { deallocateList(((*yyvaluep).l_object)); } };
/* Line 455 of lalr1.cc  */
#line 316 "parser.cc"
        break;
      case 125: /* object_outer_schema */
/* Line 455 of lalr1.cc  */
#line 459 "parser.yy"
        { delete ((*yyvaluep).object); };
/* Line 455 of lalr1.cc  */
#line 323 "parser.cc"
        break;
      case 126: /* object_schema */
/* Line 455 of lalr1.cc  */
#line 459 "parser.yy"
        { delete ((*yyvaluep).object); };
/* Line 455 of lalr1.cc  */
#line 330 "parser.cc"
        break;
      case 131: /* sort_spec_outer_tuple */
/* Line 455 of lalr1.cc  */
#line 465 "parser.yy"
        { if(((*yyvaluep).l_sort) != NULL) { deallocateList(((*yyvaluep).l_sort)); } };
/* Line 455 of lalr1.cc  */
#line 337 "parser.cc"
        break;
      case 132: /* sort_spec_tuple */
/* Line 455 of lalr1.cc  */
#line 465 "parser.yy"
        { if(((*yyvaluep).l_sort) != NULL) { deallocateList(((*yyvaluep).l_sort)); } };
/* Line 455 of lalr1.cc  */
#line 344 "parser.cc"
        break;
      case 133: /* sort_spec */
/* Line 455 of lalr1.cc  */
#line 461 "parser.yy"
        { delete ((*yyvaluep).sort); };
/* Line 455 of lalr1.cc  */
#line 351 "parser.cc"
        break;
      case 134: /* sort_identifier_with_ab */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 358 "parser.cc"
        break;
      case 135: /* sort_outer_identifier */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 365 "parser.cc"
        break;
      case 136: /* sort_identifier */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 372 "parser.cc"
        break;
      case 137: /* sort_identifier_no_range */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 379 "parser.cc"
        break;
      case 138: /* sort_identifier_name */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 386 "parser.cc"
        break;
      case 139: /* sort_constant_name */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 393 "parser.cc"
        break;
      case 145: /* variable_outer_list */
/* Line 455 of lalr1.cc  */
#line 466 "parser.yy"
        { if(((*yyvaluep).l_variable) != NULL) { deallocateList(((*yyvaluep).l_variable)); } };
/* Line 455 of lalr1.cc  */
#line 400 "parser.cc"
        break;
      case 146: /* variable_list */
/* Line 455 of lalr1.cc  */
#line 466 "parser.yy"
        { if(((*yyvaluep).l_variable) != NULL) { deallocateList(((*yyvaluep).l_variable)); } };
/* Line 455 of lalr1.cc  */
#line 407 "parser.cc"
        break;
      case 147: /* variable_binding */
/* Line 455 of lalr1.cc  */
#line 461 "parser.yy"
        { delete ((*yyvaluep).sort); };
/* Line 455 of lalr1.cc  */
#line 414 "parser.cc"
        break;
      case 200: /* lua_indicator */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 421 "parser.cc"
        break;
      case 203: /* sort_identifier_list */
/* Line 455 of lalr1.cc  */
#line 465 "parser.yy"
        { if(((*yyvaluep).l_sort) != NULL) { deallocateList(((*yyvaluep).l_sort)); } };
/* Line 455 of lalr1.cc  */
#line 428 "parser.cc"
        break;
      case 208: /* num_range */
/* Line 455 of lalr1.cc  */
#line 458 "parser.yy"
        { delete ((*yyvaluep).numRange); };
/* Line 455 of lalr1.cc  */
#line 435 "parser.cc"
        break;
      case 209: /* extended_integer */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 442 "parser.cc"
        break;
      case 210: /* extended_integer_outer_expression */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 449 "parser.cc"
        break;
      case 211: /* extended_integer_expression */
/* Line 455 of lalr1.cc  */
#line 455 "parser.yy"
        { delete ((*yyvaluep).str); };
/* Line 455 of lalr1.cc  */
#line 456 "parser.cc"
        break;

	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval, &yylloc);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 670 of lalr1.cc  */
#line 471 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 473 "parser.yy"
    { 
		(yyval.not_used) = PARSERULE_NOT_USED; 

		// Ensure that we append the footer
		// after the program has finished translating
		mainTrans.outputFooter();
		
}
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 483 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 484 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 487 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 488 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 489 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 490 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 491 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 492 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 493 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 494 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 496 "parser.yy"
    { 
	(yyval.not_used) = PARSERULE_NOT_USED;
	/* On an error, go to the end of the bad statement and try to continue.
       Set the error handler to not wait to report syntax errors if more show up. */
	yyerrok;
}
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 501 "parser.yy"
    {(yyval.not_used) = PARSERULE_NOT_USED;}
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 509 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 512 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 513 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 516 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 517 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 520 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 521 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 525 "parser.yy"
    {
	// Fill in each Constant's type and domain and translate each of them.
	bool constantError = true; // Set to true if any of the constants have trouble getting added to the symbol table.
	Sort* tempSort = NULL;
	if((yysemantic_stack_[(3) - (1)].l_constant) != NULL && (yysemantic_stack_[(3) - (3)].constant_binder_t) != NULL)
	{
		tempSort = (yysemantic_stack_[(3) - (3)].constant_binder_t)->domain;
		if((yysemantic_stack_[(3) - (3)].constant_binder_t)->constType == Constant::CONST_STATICAB || (yysemantic_stack_[(3) - (3)].constant_binder_t)->constType == Constant::CONST_DYNAMICAB || tempSort != NULL)
		{
			constantError = false;
			std::list<Constant*>::iterator lIter;
			// If the binding type is "attribute", turn the Constant objects into Attribute objects before adding them.
			if((yysemantic_stack_[(3) - (3)].constant_binder_t)->constType == Constant::CONST_ATTRIBUTE)
			{
				Attribute* tempAttribute = NULL;
				for(lIter = (yysemantic_stack_[(3) - (1)].l_constant)->begin(); lIter != (yysemantic_stack_[(3) - (1)].l_constant)->end(); ++lIter)
				{
					tempAttribute = (*lIter)->makeAttribute(NULL);
					deallocateItem(*lIter);
					(*lIter) = tempAttribute;
				}
			}
			
			for(lIter = (yysemantic_stack_[(3) - (1)].l_constant)->begin(); lIter != (yysemantic_stack_[(3) - (1)].l_constant)->end(); ++lIter)
			{	// Try to add each constant to the symbol table before hooking it up and translating it.
				int addSymResult = mainTrans.addConstant(*lIter);
				if(addSymResult != SymbolTable::ADDSYM_OK)
				{	// Something went wrong adding this constant, skip connecting & translating it.
					if(addSymResult == SymbolTable::ADDSYM_DUP)
					{	// Duplicate constant declarations are errors, but give a separate error message for clarity.
						ltsyystartParseError(ltsyylloc);
						ltsyyossErr << "Duplicate constant declaration: \"" << (*lIter)->fullName() << "\".";
						ltsyyreportError();
						deallocateItem(*lIter);
						constantError = true;
					}
					else
					{	// Other constant adding errors can get grouped together.
						ltsyystartParseError(ltsyylloc);
						ltsyyossErr << "Bad constant declaration: \"" << (*lIter)->fullName() << "\".";
						ltsyyreportError();
						deallocateItem(*lIter);
						constantError = true;
					}
				}
				else
				{	// Successfully added constant, hook it up and translate it.
					(*lIter)->constType((yysemantic_stack_[(3) - (3)].constant_binder_t)->constType);
					(*lIter)->domain(tempSort);
					if((*lIter)->constType() == Constant::CONST_ATTRIBUTE && (yysemantic_stack_[(3) - (3)].constant_binder_t)->parent != NULL)
					{
						((Attribute*)(*lIter))->parent((yysemantic_stack_[(3) - (3)].constant_binder_t)->parent);
					}
					// Translate each constant once its information is complete.
					mainTrans.translateConstantDecl(*lIter);
				}
			}
		}
		else
		{
			// Deallocate all of the constants in the errant list, they're never going to get used by anything.
			for(std::list<Constant*>::iterator lIter = (yysemantic_stack_[(3) - (1)].l_constant)->begin(); lIter != (yysemantic_stack_[(3) - (1)].l_constant)->end(); ++lIter)
			{
				deallocateItem(*lIter);
			}
		}
	}
	if((yysemantic_stack_[(3) - (3)].constant_binder_t) != NULL)
	{
		deallocateItem((yysemantic_stack_[(3) - (3)].constant_binder_t));
	}
	if((yysemantic_stack_[(3) - (1)].l_constant) != NULL)
	{
		deallocateList((yysemantic_stack_[(3) - (1)].l_constant));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
	if (constantError)
	{
		YYERROR;
	}
}
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 609 "parser.yy"
    {
	(yyval.l_constant) = (yysemantic_stack_[(1) - (1)].l_constant);
}
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 613 "parser.yy"
    {
	(yyval.l_constant) = (yysemantic_stack_[(3) - (2)].l_constant);
}
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 619 "parser.yy"
    {
	// Create a new constant list, add the schema as the first element.
	(yyval.l_constant) = new std::list<Constant*>;
	if((yysemantic_stack_[(1) - (1)].constant) != NULL)
	{
		(yyval.l_constant)->push_back((yysemantic_stack_[(1) - (1)].constant));
	}
}
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 628 "parser.yy"
    {
	// Merge a schema into an existing list.
	(yyval.l_constant) = NULL;
	if((yysemantic_stack_[(3) - (1)].l_constant) != NULL && (yysemantic_stack_[(3) - (3)].constant) != NULL)
	{
		(yyval.l_constant) = (yysemantic_stack_[(3) - (1)].l_constant);
		(yyval.l_constant)->push_back((yysemantic_stack_[(3) - (3)].constant));
	}
	if((yysemantic_stack_[(3) - (1)].l_constant) == NULL)
	{
		deallocateItem((yysemantic_stack_[(3) - (3)].constant));
	}
	if((yysemantic_stack_[(3) - (3)].constant) == NULL)
	{
		for(std::list<Constant*>::iterator lIter = (yysemantic_stack_[(3) - (1)].l_constant)->begin(); lIter != (yysemantic_stack_[(3) - (1)].l_constant)->end(); ++lIter)
		{
			deallocateItem(*lIter);
		}
		deallocateItem((yysemantic_stack_[(3) - (3)].constant));
	}
}
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 652 "parser.yy"
    {
	(yyval.constant) = (yysemantic_stack_[(1) - (1)].constant);
}
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 656 "parser.yy"
    {
	(yyval.constant) = (yysemantic_stack_[(3) - (2)].constant);
}
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 662 "parser.yy"
    {
	// Create a new Constant from a bare identifier.
	(yyval.constant) = new Constant(*(yysemantic_stack_[(1) - (1)].str), Constant::CONST_UNKNOWN);
	deallocateItem((yysemantic_stack_[(1) - (1)].str));
}
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 668 "parser.yy"
    {
	// Create a new Constant from a parameterized identifier.
	(yyval.constant) = NULL;
	if((yysemantic_stack_[(4) - (3)].l_sort) != NULL)
	{
		(yyval.constant) = new Constant(*(yysemantic_stack_[(4) - (1)].str), Constant::CONST_UNKNOWN, (ConstSortList*)(yysemantic_stack_[(4) - (3)].l_sort));
		deallocateList((yysemantic_stack_[(4) - (3)].l_sort));
	}
	deallocateItem((yysemantic_stack_[(4) - (1)].str));
}
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 682 "parser.yy"
    {
	(yyval.constant) = mainTrans.getConstant(*(yysemantic_stack_[(1) - (1)].str), NULL);
	deallocateItem((yysemantic_stack_[(1) - (1)].str));
}
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 687 "parser.yy"
    {
	(yyval.constant) = NULL;
	if((yysemantic_stack_[(4) - (3)].l_sort) != NULL)
	{
		(yyval.constant) = mainTrans.getConstant(*(yysemantic_stack_[(4) - (1)].str), (yysemantic_stack_[(4) - (3)].l_sort));
		deallocateList((yysemantic_stack_[(4) - (3)].l_sort));
	}
	deallocateItem((yysemantic_stack_[(4) - (1)].str));
}
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 699 "parser.yy"
    {
	(yyval.constant_binder_t) = (yysemantic_stack_[(1) - (1)].constant_binder_t);
}
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 703 "parser.yy"
    {
	(yyval.constant_binder_t) = (yysemantic_stack_[(3) - (2)].constant_binder_t);
}
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 709 "parser.yy"
    {
	// Two possibilities, check for each:
	// 1) The identifier is a plain constant type (e.g. "exogenousAction").
	// 2) The identifier is something else, which is a shortcut for "rigid(identifier)".
	Constant::ConstantType constType = Constant::CONST_UNKNOWN;
	std::string tempIdent = (*(yysemantic_stack_[(1) - (1)].str));
	deallocateItem((yysemantic_stack_[(1) - (1)].str));
	// Check for a real constant type.
	constType = Constant::stringToConstType(tempIdent.c_str());
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	if (constType == Constant::CONST_STATICAB || constType == Constant::CONST_DYNAMICAB) {
		// it's an abnormality
		(yyval.constant_binder_t)->constType = constType;
		(yyval.constant_binder_t)->domain = NULL;
	} 
	else if(constType != Constant::CONST_UNKNOWN)
	{	// Basic constant binder with Boolean domain.
		(yyval.constant_binder_t)->constType = constType;
		std::string domainName = "boolean";
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl(&domainName);
	}
	else
	{	// If it wasn't a real constant type, it's just a shortcut for "rigid(identifier)".
		(yyval.constant_binder_t)->constType = Constant::CONST_RIGID;
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl(&tempIdent);
		if((yyval.constant_binder_t)->domain == NULL)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << tempIdent << "\" not declared, can't use as the domain of a constant declaration.";
			ltsyyreportError();
		}
		if((yyval.constant_binder_t)->domain == NULL)
		{	// If $$'s domain attribute is NULL, an error happened.
			deallocateItem((yyval.constant_binder_t));
			YYERROR;
		}
	}
}
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 748 "parser.yy"
    {
	// Basic constant binder with given domain.
	Constant::ConstantType constType = Constant::CONST_UNKNOWN;
	std::string tempIdent = (*(yysemantic_stack_[(4) - (1)].str));
	deallocateItem((yysemantic_stack_[(4) - (1)].str));

	// Figure out which constant type was given.
	constType = Constant::stringToConstType(tempIdent.c_str());
	
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	(yyval.constant_binder_t)->constType = constType;
	if((yysemantic_stack_[(4) - (3)].str) != NULL)
	{
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl((yysemantic_stack_[(4) - (3)].str));
		deallocateItem((yysemantic_stack_[(4) - (3)].str));
	}
	if((yyval.constant_binder_t)->domain == NULL)
	{	// Start error mode if anything went wrong.
		deallocateItem((yyval.constant_binder_t));
		YYERROR;
	}
}
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 771 "parser.yy"
    {
	// Attribute binder with Boolean(*) domain.
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	(yyval.constant_binder_t)->constType = Constant::CONST_ATTRIBUTE;
	std::string* domainName = new std::string("boolean*");
	(yyval.constant_binder_t)->domain = checkDynamicSortDecl(domainName);
	deallocateItem(domainName);
	if((yysemantic_stack_[(3) - (3)].constant) != NULL)
	{
		(yyval.constant_binder_t)->parent = (yysemantic_stack_[(3) - (3)].constant);
	}
	else
	{	// Something's wrong, start error mode.
		deallocateItem((yyval.constant_binder_t));
		YYERROR;
	}
}
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 789 "parser.yy"
    {
	// Attribute binder with given(*) domain.
	(yyval.constant_binder_t) = new PT_constant_binder_t;
	(yyval.constant_binder_t)->constType = Constant::CONST_ATTRIBUTE;
	if((yysemantic_stack_[(6) - (3)].str) != NULL)
	{
		std::string* domainName = new std::string(*(yysemantic_stack_[(6) - (3)].str));
		(*domainName) += "*";
		(yyval.constant_binder_t)->domain = checkDynamicSortDecl(domainName);
		deallocateItem(domainName);
		if((yyval.constant_binder_t)->domain == NULL)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *(yysemantic_stack_[(6) - (3)].str) << "\" not declared, can't use as the domain of a constant declaration.";
			ltsyyreportError();
		}
		deallocateItem((yysemantic_stack_[(6) - (3)].str));
	}
	if((yysemantic_stack_[(6) - (6)].constant) != NULL)
	{
		(yyval.constant_binder_t)->parent = (yysemantic_stack_[(6) - (6)].constant);
	}
	if((yyval.constant_binder_t)->domain == NULL || (yyval.constant_binder_t)->parent == NULL)
	{	// If $$'s attributes are NULL, an error happened.
		deallocateItem((yyval.constant_binder_t));
		YYERROR;
	}
}
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 863 "parser.yy"
    {
	// The new style of maxAdditive declaration. Insert a hint comment with the given maxAdditive value.
	if((yysemantic_stack_[(5) - (4)].str) != NULL)
	{
		std::string maxAdditiveHint = "% [MaxAdditive:";
		maxAdditiveHint += *((yysemantic_stack_[(5) - (4)].str));
		maxAdditiveHint += "]";
		mainTrans.output(maxAdditiveHint, IPART_NONE, true);
		(yyval.not_used) = PARSERULE_NOT_USED;
		deallocateItem((yysemantic_stack_[(5) - (4)].str));
	}
}
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 879 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 882 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 883 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 886 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 887 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 890 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 891 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 895 "parser.yy"
    {
	// Connect each Object in the list to its sort, (try to) add them to the symbol table, and translate each object.
	Sort* tempSort = NULL;
	bool objectError = false; // Set to true if a serious error happens during object adding.
	if((yysemantic_stack_[(3) - (1)].l_object) != NULL && (yysemantic_stack_[(3) - (3)].str) != NULL)
	{
		tempSort = mainTrans.getSort(*(yysemantic_stack_[(3) - (3)].str));
		if(tempSort != NULL)
		{
			for(ObjectList::iterator lIter = (yysemantic_stack_[(3) - (1)].l_object)->begin(); lIter != (yysemantic_stack_[(3) - (1)].l_object)->end(); ++lIter)
			{	// Try to add the object to the symbol table (mostly to check for dupes).
			
				if ((*lIter)->isLua()) {
					// They appear to have included a LUA call in the object definition. Don't allow this.

					ltsyystartParseError(ltsyylloc);
					ltsyyossErr << "Bad object declaration: \"" << (*lIter)->fullName() << "\". LUA calls may not be present in object declarations!";
					ltsyyreportError();
					deallocateItem(*lIter);
					objectError = true;
					
				} else {
			
					int addSymResult = mainTrans.addObject(*lIter);
					if(addSymResult != SymbolTable::ADDSYM_OK)
					{	// Something went wrong adding the object, skip connecting & translating it.
						if(addSymResult == SymbolTable::ADDSYM_DUP)
						{	// Warn about duplicate object declarations (not an error), then move on.
							ltsyystartCaution(ltsyylloc);
							ltsyyossErr << "Duplicate object declaration: \"" << (*lIter)->fullName() << "\".";
							ltsyyreportCaution();
							deallocateItem(*lIter);
						}
						else
						{	// A real object error.
							ltsyystartParseError(ltsyylloc);
							ltsyyossErr << "Bad object declaration: \"" << (*lIter)->fullName() << "\".";
							ltsyyreportError();
							deallocateItem(*lIter);
							objectError = true;
						}
					}
					else
					{	// Object add went okay, connect the sort to the object and translate them.
						tempSort->addObject(*lIter);

						// Translate each object as we add it to the sort's domain.
						mainTrans.translateObjectDecl(*lIter, tempSort);
					}
				}
			}
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *(yysemantic_stack_[(3) - (3)].str) << "\" not declared, can't use as the target of an object declaration.";
			ltsyyreportError();
			// Deallocate all of the objects in the errant list, they're never going to get used by anything.
			for(ObjectList::iterator lIter = (yysemantic_stack_[(3) - (1)].l_object)->begin(); lIter != (yysemantic_stack_[(3) - (1)].l_object)->end(); ++lIter)
			{
				deallocateItem(*lIter);
			}
		}
		deallocateList((yysemantic_stack_[(3) - (1)].l_object));
		deallocateItem((yysemantic_stack_[(3) - (3)].str));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(tempSort == NULL || objectError == true)
	{	// If the binding sort never got a match or an object had a problem getting added, an error occurred.
		YYERROR;
	}
}
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 970 "parser.yy"
    {
	(yyval.l_object) = (yysemantic_stack_[(1) - (1)].l_object);
}
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 974 "parser.yy"
    {
	(yyval.l_object) = (yysemantic_stack_[(3) - (2)].l_object);
}
    break;

  case 51:
/* Line 670 of lalr1.cc  */
#line 980 "parser.yy"
    {
	// Create a new list and make the new object the first element.
	(yyval.l_object) = NULL;
	if((yysemantic_stack_[(1) - (1)].object) != NULL)
	{
		(yyval.l_object) = new ObjectList();
		(yyval.l_object)->push_back((yysemantic_stack_[(1) - (1)].object));
	}
}
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 990 "parser.yy"
    {
	// Merge a new object with an exisiting list.
	(yyval.l_object) = NULL;
	if((yysemantic_stack_[(3) - (1)].l_object) != NULL && (yysemantic_stack_[(3) - (3)].object) != NULL)
	{
		(yyval.l_object) = (yysemantic_stack_[(3) - (1)].l_object);
		(yyval.l_object)->push_back((yysemantic_stack_[(3) - (3)].object));
	}
	if((yysemantic_stack_[(3) - (1)].l_object) == NULL)
	{
		deallocateItem((yysemantic_stack_[(3) - (3)].object));
	}
	if((yysemantic_stack_[(3) - (3)].object) == NULL)
	{
		for(ObjectList::iterator lIter = (yysemantic_stack_[(3) - (1)].l_object)->begin(); lIter != (yysemantic_stack_[(3) - (1)].l_object)->end(); ++lIter)
		{
			deallocateItem(*lIter);
		}
		deallocateList((yysemantic_stack_[(3) - (1)].l_object));
	}
}
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 1014 "parser.yy"
    {
	(yyval.object) = (yysemantic_stack_[(1) - (1)].object);
}
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 1018 "parser.yy"
    {
	(yyval.object) = (yysemantic_stack_[(3) - (2)].object);
}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 1024 "parser.yy"
    {
	// Create a new Object from a bare identifier.
	(yyval.object) = new Object(*(yysemantic_stack_[(1) - (1)].str), Object::OBJ_NAME);
	deallocateItem((yysemantic_stack_[(1) - (1)].str));
}
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 1030 "parser.yy"
    {
	// Create a new Object from a parameterized identifier.
	(yyval.object) = new Object(*(yysemantic_stack_[(4) - (1)].str), Object::OBJ_NAME, (yysemantic_stack_[(4) - (3)].l_sort));
	deallocateList((yysemantic_stack_[(4) - (3)].l_sort));
	deallocateItem((yysemantic_stack_[(4) - (1)].str));
}
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 1037 "parser.yy"
    {
	// Create a new object from arbitrary math.
	(yyval.object) = new Object(*(yysemantic_stack_[(1) - (1)].str), Object::OBJ_NAME);
	deallocateItem((yysemantic_stack_[(1) - (1)].str)); // Free dynamic memory that's not needed anymore.
}
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 1043 "parser.yy"
    {
	// Upcast a NumberRange into an Object.
	(yyval.object) = (Object*)(yysemantic_stack_[(1) - (1)].numRange);
}
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 1052 "parser.yy"
    {
	if ((yysemantic_stack_[(4) - (3)].v_parseElement)) {
		mainTrans.translateShowStmt(*(yysemantic_stack_[(4) - (3)].v_parseElement));
	} else {
		YYERROR;
	}
	deallocateList((yysemantic_stack_[(4) - (3)].v_parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 60:
/* Line 670 of lalr1.cc  */
#line 1065 "parser.yy"
    {
	if ((yysemantic_stack_[(1) - (1)].parseElement)) {
		(yyval.v_parseElement) = new ParseElementList();
		(yyval.v_parseElement)->push_back((yysemantic_stack_[(1) - (1)].parseElement));
	} else {
		(yyval.v_parseElement) = NULL;
	}
	 
}
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 1075 "parser.yy"
    {
	if ((yysemantic_stack_[(3) - (1)].v_parseElement)) {
		(yyval.v_parseElement) = (yysemantic_stack_[(3) - (1)].v_parseElement);
		if ((yysemantic_stack_[(3) - (3)].parseElement)) (yysemantic_stack_[(3) - (1)].v_parseElement)->push_back((yysemantic_stack_[(3) - (3)].parseElement));
	} else if ((yysemantic_stack_[(3) - (3)].parseElement)) {
		(yyval.v_parseElement) = new ParseElementList();
		(yyval.v_parseElement)->push_back((yysemantic_stack_[(3) - (3)].parseElement));
	} else {
		(yyval.v_parseElement) = NULL;
	}
}
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 1089 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 1093 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_EQ, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 1107 "parser.yy"
    {
	// Deallocate the main sort list of the statement.
	if((yysemantic_stack_[(4) - (3)].l_sort) != NULL)
	{
		deallocateList((yysemantic_stack_[(4) - (3)].l_sort));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 1118 "parser.yy"
    {
	(yyval.l_sort) = (yysemantic_stack_[(1) - (1)].l_sort);
}
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 1122 "parser.yy"
    {
	(yyval.l_sort) = (yysemantic_stack_[(3) - (2)].l_sort);
}
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 1128 "parser.yy"
    {
	(yyval.l_sort) = new SortList();
	(yyval.l_sort)->push_back((yysemantic_stack_[(1) - (1)].sort));
}
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 1133 "parser.yy"
    {
	(yyval.l_sort) = NULL;
	if((yysemantic_stack_[(3) - (1)].l_sort) != NULL || (yysemantic_stack_[(3) - (3)].l_sort) != NULL)
	{
		(yyval.l_sort) = new  SortList();
	}
	// Merge the two sort lists, if they exist.
	if((yysemantic_stack_[(3) - (1)].l_sort) != NULL)
	{
		for(SortList::iterator lIter = (yysemantic_stack_[(3) - (1)].l_sort)->begin(); lIter != (yysemantic_stack_[(3) - (1)].l_sort)->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				(yyval.l_sort)->push_back((*lIter));
			}
		}
		deallocateList((yysemantic_stack_[(3) - (1)].l_sort));
	}
	if((yysemantic_stack_[(3) - (3)].l_sort) != NULL)
	{
		for(SortList::iterator lIter = (yysemantic_stack_[(3) - (3)].l_sort)->begin(); lIter != (yysemantic_stack_[(3) - (3)].l_sort)->end(); ++lIter)
		{
			if((*lIter) != NULL)
			{
				(yyval.l_sort)->push_back((*lIter));
			}
		}
		deallocateList((yysemantic_stack_[(3) - (3)].l_sort));
	}
}
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 1166 "parser.yy"
    {
	// Have a helper function handle making and translating the sort.
	(yyval.sort) = mainTrans.addSort(*(yysemantic_stack_[(1) - (1)].str), NULL, true, false);
	deallocateItem((yysemantic_stack_[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 1176 "parser.yy"
    {
	// Have a helper function handle making and translating the sort.
	(yyval.sort) = mainTrans.addSort(*(yysemantic_stack_[(3) - (1)].str), (yysemantic_stack_[(3) - (3)].l_sort), true, false);
	deallocateItem((yysemantic_stack_[(3) - (1)].str));
	deallocateList((yysemantic_stack_[(3) - (3)].l_sort));
	if((yyval.sort) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 1189 "parser.yy"
    {
	(yyval.str) = (yysemantic_stack_[(1) - (1)].str);
}
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 1193 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("staticAbnormality");
}
    break;

  case 73:
/* Line 670 of lalr1.cc  */
#line 1198 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("dynamicAbnormality");
}
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 1205 "parser.yy"
    {
	(yyval.str) = (yysemantic_stack_[(1) - (1)].str);
}
    break;

  case 75:
/* Line 670 of lalr1.cc  */
#line 1209 "parser.yy"
    {
	(yyval.str) = (yysemantic_stack_[(3) - (2)].str);
}
    break;

  case 76:
/* Line 670 of lalr1.cc  */
#line 1217 "parser.yy"
    {
	// A standard identifier.
	(yyval.str) = (yysemantic_stack_[(1) - (1)].str);
}
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 1222 "parser.yy"
    {
	// A quick-and-dirty dynamically declared sort.

	// Turn it into a sort and pass it down the chain.
	if((yysemantic_stack_[(1) - (1)].numRange) != NULL)
	{
		(yyval.str) = new std::string();
		*(yyval.str) = Translator::numRangeToSortName((yysemantic_stack_[(1) - (1)].numRange)->min(), (yysemantic_stack_[(1) - (1)].numRange)->max());
		Sort* tempSort = mainTrans.getSort(*(yyval.str));
		if(tempSort == NULL)
		{
			// Have a helper function handle making and translating the sort.
			tempSort = mainTrans.addSort(*(yyval.str), NULL, true, false);
			// Also add the number range as an object for this new sort.
			int addResult = mainTrans.addObject((yysemantic_stack_[(1) - (1)].numRange));
			if(addResult == SymbolTable::ADDSYM_OK)
			{
				tempSort->addObject((yysemantic_stack_[(1) - (1)].numRange));
				// Output the translation of the object declaration.
				mainTrans.translateObjectDecl((yysemantic_stack_[(1) - (1)].numRange), tempSort);
			}
		}
		if(tempSort == NULL)
		{
			// We were unable to allocate the sort properly. Error.
			deallocateItem((yysemantic_stack_[(1) - (1)].numRange));
			YYERROR;
		}
	} else {
	      // The number range doesn't exist?
	      YYERROR;
	}
}
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 1258 "parser.yy"
    {
	(yyval.str) = (yysemantic_stack_[(1) - (1)].str);
}
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 1262 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yysemantic_stack_[(2) - (1)].str)) + "*";
	deallocateItem((yysemantic_stack_[(2) - (1)].str));
}
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 1268 "parser.yy"
    {
	// Alternate way to express the idea of a starred sort.
	(yyval.str) = new std::string;
	(*(yyval.str)) = (*(yysemantic_stack_[(3) - (1)].str)) + "*";
	deallocateItem((yysemantic_stack_[(3) - (1)].str));
}
    break;

  case 81:
/* Line 670 of lalr1.cc  */
#line 1277 "parser.yy"
    {
	(yyval.str) = (yysemantic_stack_[(1) - (1)].str);
}
    break;

  case 82:
/* Line 670 of lalr1.cc  */
#line 1281 "parser.yy"
    {
	(yyval.str) = (yysemantic_stack_[(1) - (1)].str);
}
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 1287 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("abAction");
}
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 1292 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("action");
}
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 1297 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveAction");
}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 1302 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("additiveFluent");
}
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 1307 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("exogenousAction");
}
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 1312 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("inertialFluent");
}
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 1317 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("rigid");
}
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 1322 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("sdFluent");
}
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 1327 "parser.yy"
    {
	// Directly referencing an internal sort, return the name of the desired sort.
	(yyval.str) = new std::string("simpleFluent");
}
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 1335 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 1338 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 1339 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 1342 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 96:
/* Line 670 of lalr1.cc  */
#line 1343 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 97:
/* Line 670 of lalr1.cc  */
#line 1346 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 1347 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 99:
/* Line 670 of lalr1.cc  */
#line 1351 "parser.yy"
    {
	// Connect the variables in the list to the binding sort, then translate them.
	if((yysemantic_stack_[(3) - (1)].l_variable) != NULL && (yysemantic_stack_[(3) - (3)].sort) != NULL)
	{
		std::list<Variable*>::iterator vIter;
		for(vIter = (yysemantic_stack_[(3) - (1)].l_variable)->begin(); vIter != (yysemantic_stack_[(3) - (1)].l_variable)->end(); ++vIter)
		{
			(*vIter)->domain((yysemantic_stack_[(3) - (3)].sort));
			mainTrans.translateVariableDecl(*vIter);
		}
	}
	if((yysemantic_stack_[(3) - (1)].l_variable) != NULL)
	{	// Clear out the list, we don't need it anymore.
		deallocateList((yysemantic_stack_[(3) - (1)].l_variable));
	}
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 1371 "parser.yy"
    {
	(yyval.l_variable) = (yysemantic_stack_[(1) - (1)].l_variable);
}
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 1375 "parser.yy"
    {
	(yyval.l_variable) = (yysemantic_stack_[(3) - (2)].l_variable);
}
    break;

  case 102:
/* Line 670 of lalr1.cc  */
#line 1381 "parser.yy"
    {
	// Create a new list of Variables, add this one as the first item.
	(yyval.l_variable) = new std::list<Variable*>;
	Variable* tempVar = new Variable(*(yysemantic_stack_[(1) - (1)].str), NULL);
	int addSymResult = mainTrans.addVariable(tempVar);
	if(addSymResult != SymbolTable::ADDSYM_OK)
	{
		if(addSymResult == SymbolTable::ADDSYM_DUP)
		{	// Warn about duplicate variable declarations (not an error), then grab the already-declared variable.
			ltsyystartCaution(ltsyylloc);
			ltsyyossErr << "Duplicate variable declaration: \"" << *(yysemantic_stack_[(1) - (1)].str) << "\".";
			ltsyyreportCaution();
			deallocateItem(tempVar);
			tempVar = mainTrans.getVariable(*(yysemantic_stack_[(1) - (1)].str));
			(yyval.l_variable)->push_back(tempVar);
		}
		else
		{	// A real variable error.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bad variable declaration: \"" << *(yysemantic_stack_[(1) - (1)].str) << "\".";
			ltsyyreportError();
			deallocateList((yyval.l_variable));
			deallocateItem(tempVar);
		}
	}
	else
	{
		(yyval.l_variable)->push_back(tempVar);
	}
	deallocateItem((yysemantic_stack_[(1) - (1)].str));
	if(tempVar == NULL || (yyval.l_variable) == NULL)
	{	// If $$ or tempVar are NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 1417 "parser.yy"
    {
	// Merge a new variable declaration into an existing list of variables.
	if((yysemantic_stack_[(3) - (1)].l_variable) == NULL)
	{
		(yyval.l_variable) = new std::list<Variable*>;
	}
	Variable* tempVar = new Variable(*(yysemantic_stack_[(3) - (3)].str), NULL);
	int addSymResult = mainTrans.addVariable(tempVar);
	if(addSymResult != SymbolTable::ADDSYM_OK)
	{
		if(addSymResult == SymbolTable::ADDSYM_DUP)
		{	// Warn about duplicate variable declarations (not an error), then grab the already-declared variable.
			ltsyystartCaution(ltsyylloc);
			ltsyyossErr << "Duplicate variable declaration: \"" << *(yysemantic_stack_[(3) - (3)].str) << "\".";
			ltsyyreportCaution();
			deallocateItem(tempVar);
			tempVar = mainTrans.getVariable(*(yysemantic_stack_[(3) - (3)].str));
			(yyval.l_variable)->push_back(tempVar);
		}
		else
		{	// A real variable error.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bad variable declaration: \"" << *(yysemantic_stack_[(3) - (3)].str) << "\".";
			ltsyyreportError();
			deallocateItem(tempVar);
		}
	}
	else
	{
		(yyval.l_variable)->push_back(tempVar);
	}
	deallocateItem((yysemantic_stack_[(3) - (3)].str));
	if(tempVar == NULL)
	{	// If tempVar is NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 1457 "parser.yy"
    {
	// Find the sort in question, create it if it doesn't exist and is a "something*" sort (whose "something" exists already), or report an error.
	(yyval.sort) = mainTrans.getSort(*(yysemantic_stack_[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{
		(yyval.sort) = checkDynamicSortDecl((yysemantic_stack_[(1) - (1)].str)); // Reports appropriate errors, we just need to YYERROR if that happens.
	}
	deallocateItem((yysemantic_stack_[(1) - (1)].str));
	if((yyval.sort) == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 1511 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 106:
/* Line 670 of lalr1.cc  */
#line 1512 "parser.yy"
    { (yyval.parseElement) = (yysemantic_stack_[(2) - (2)].parseElement);   }
    break;

  case 107:
/* Line 670 of lalr1.cc  */
#line 1515 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 108:
/* Line 670 of lalr1.cc  */
#line 1516 "parser.yy"
    { (yyval.parseElement) = (yysemantic_stack_[(2) - (2)].parseElement); }
    break;

  case 109:
/* Line 670 of lalr1.cc  */
#line 1519 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 110:
/* Line 670 of lalr1.cc  */
#line 1520 "parser.yy"
    { (yyval.parseElement) = (yysemantic_stack_[(2) - (2)].parseElement);   }
    break;

  case 111:
/* Line 670 of lalr1.cc  */
#line 1523 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 112:
/* Line 670 of lalr1.cc  */
#line 1524 "parser.yy"
    { (yyval.parseElement) = (yysemantic_stack_[(2) - (2)].parseElement);   }
    break;

  case 113:
/* Line 670 of lalr1.cc  */
#line 1527 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 114:
/* Line 670 of lalr1.cc  */
#line 1528 "parser.yy"
    { (yyval.parseElement) = (yysemantic_stack_[(2) - (2)].parseElement);   }
    break;

  case 115:
/* Line 670 of lalr1.cc  */
#line 1531 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 116:
/* Line 670 of lalr1.cc  */
#line 1532 "parser.yy"
    { (yyval.parseElement) = (yysemantic_stack_[(2) - (2)].parseElement);   }
    break;

  case 117:
/* Line 670 of lalr1.cc  */
#line 1535 "parser.yy"
    { (yyval.parseElement) = NULL; }
    break;

  case 118:
/* Line 670 of lalr1.cc  */
#line 1536 "parser.yy"
    { (yyval.parseElement) = (yysemantic_stack_[(2) - (2)].parseElement);   }
    break;

  case 119:
/* Line 670 of lalr1.cc  */
#line 1542 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 120:
/* Line 670 of lalr1.cc  */
#line 1543 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 121:
/* Line 670 of lalr1.cc  */
#line 1546 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 122:
/* Line 670 of lalr1.cc  */
#line 1547 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 123:
/* Line 670 of lalr1.cc  */
#line 1548 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 124:
/* Line 670 of lalr1.cc  */
#line 1549 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 125:
/* Line 670 of lalr1.cc  */
#line 1550 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 126:
/* Line 670 of lalr1.cc  */
#line 1551 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 127:
/* Line 670 of lalr1.cc  */
#line 1552 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 128:
/* Line 670 of lalr1.cc  */
#line 1553 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 129:
/* Line 670 of lalr1.cc  */
#line 1554 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 130:
/* Line 670 of lalr1.cc  */
#line 1555 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 131:
/* Line 670 of lalr1.cc  */
#line 1556 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 132:
/* Line 670 of lalr1.cc  */
#line 1557 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 133:
/* Line 670 of lalr1.cc  */
#line 1558 "parser.yy"
    { (yyval.not_used) = PARSERULE_NOT_USED; }
    break;

  case 134:
/* Line 670 of lalr1.cc  */
#line 1563 "parser.yy"
    {
	bool transResult = mainTrans.translateAlwaysLaw((yysemantic_stack_[(4) - (2)].parseElement), (yysemantic_stack_[(4) - (3)].parseElement), (yysemantic_stack_[(4) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(4) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(4) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(4) - (4)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 135:
/* Line 670 of lalr1.cc  */
#line 1577 "parser.yy"
    {
	bool transResult = mainTrans.translateConstraintLaw((yysemantic_stack_[(7) - (2)].parseElement), (yysemantic_stack_[(7) - (3)].parseElement), (yysemantic_stack_[(7) - (4)].parseElement), (yysemantic_stack_[(7) - (5)].parseElement), (yysemantic_stack_[(7) - (6)].parseElement), (yysemantic_stack_[(7) - (7)].parseElement), true);
	deallocateItem((yysemantic_stack_[(7) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (7)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 136:
/* Line 670 of lalr1.cc  */
#line 1592 "parser.yy"
    {
	bool transResult = mainTrans.translateConstraintLaw((yysemantic_stack_[(7) - (2)].parseElement), (yysemantic_stack_[(7) - (3)].parseElement), (yysemantic_stack_[(7) - (4)].parseElement), (yysemantic_stack_[(7) - (5)].parseElement), (yysemantic_stack_[(7) - (6)].parseElement), (yysemantic_stack_[(7) - (7)].parseElement), false);
	deallocateItem((yysemantic_stack_[(7) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (7)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 1607 "parser.yy"
    {
	bool transResult = mainTrans.translateConstraintLaw((yysemantic_stack_[(7) - (2)].parseElement), (yysemantic_stack_[(7) - (3)].parseElement), (yysemantic_stack_[(7) - (4)].parseElement), (yysemantic_stack_[(7) - (5)].parseElement), (yysemantic_stack_[(7) - (6)].parseElement), (yysemantic_stack_[(7) - (7)].parseElement), false);
	deallocateItem((yysemantic_stack_[(7) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (7)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 1624 "parser.yy"
    {
	bool transResult = mainTrans.translateDefaultLaw((yysemantic_stack_[(9) - (2)].parseElement), (yysemantic_stack_[(9) - (3)].parseElement), (yysemantic_stack_[(9) - (4)].parseElement), (yysemantic_stack_[(9) - (5)].parseElement), (yysemantic_stack_[(9) - (6)].parseElement), (yysemantic_stack_[(9) - (7)].parseElement), (yysemantic_stack_[(9) - (8)].parseElement), (yysemantic_stack_[(9) - (9)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (7)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (8)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (9)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 139:
/* Line 670 of lalr1.cc  */
#line 1643 "parser.yy"
    {
	bool transResult = mainTrans.translateDeclarativeLaw((yysemantic_stack_[(3) - (2)].parseElement), NULL, NULL, NULL, NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].parseElement), SimpleUnaryOperator::UOP_EXOGENOUS);
	deallocateItem((yysemantic_stack_[(3) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(3) - (3)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 140:
/* Line 670 of lalr1.cc  */
#line 1656 "parser.yy"
    {
	bool transResult = mainTrans.translateDeclarativeLaw((yysemantic_stack_[(3) - (2)].parseElement), NULL, NULL, NULL, NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].parseElement), SimpleUnaryOperator::UOP_INERTIAL);
	deallocateItem((yysemantic_stack_[(3) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(3) - (3)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 1669 "parser.yy"
    {
	bool transResult = mainTrans.translateNonexecutableLaw((yysemantic_stack_[(5) - (2)].parseElement), (yysemantic_stack_[(5) - (3)].parseElement), (yysemantic_stack_[(5) - (4)].parseElement), (yysemantic_stack_[(5) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(5) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(5) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(5) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(5) - (5)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 1684 "parser.yy"
    {
	/*
	 * Let's _try_ to handle this, but we should throw a warning as this statement is not fully supported.
	 */

	ltsyystartWarning(ltsyylloc);
	ltsyyossErr << "Rules of the form \"rigid p [where F]\" are not fully supported and may produce unintended behavior. Please declare the constant as rigid instead.";
	ltsyyreportWarning();

	bool transResult = mainTrans.translateDeclarativeLaw((yysemantic_stack_[(3) - (2)].parseElement), NULL, NULL, NULL, NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].parseElement), SimpleUnaryOperator::UOP_RIGID);
	deallocateItem((yysemantic_stack_[(3) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(3) - (3)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 143:
/* Line 670 of lalr1.cc  */
#line 1705 "parser.yy"
    {
	bool transResult = mainTrans.translatePossiblyCausedLaw((yysemantic_stack_[(9) - (2)].parseElement), (yysemantic_stack_[(9) - (3)].parseElement), (yysemantic_stack_[(9) - (4)].parseElement), (yysemantic_stack_[(9) - (5)].parseElement), (yysemantic_stack_[(9) - (6)].parseElement), (yysemantic_stack_[(9) - (7)].parseElement), (yysemantic_stack_[(9) - (8)].parseElement), (yysemantic_stack_[(9) - (9)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (7)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (8)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (9)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 144:
/* Line 670 of lalr1.cc  */
#line 1724 "parser.yy"
    {
	bool transResult = mainTrans.translateMayCauseLaw((yysemantic_stack_[(6) - (1)].parseElement), (yysemantic_stack_[(6) - (3)].parseElement), (yysemantic_stack_[(6) - (4)].parseElement), (yysemantic_stack_[(6) - (5)].parseElement), (yysemantic_stack_[(6) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(6) - (1)].parseElement));
	deallocateItem((yysemantic_stack_[(6) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(6) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(6) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(6) - (6)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 145:
/* Line 670 of lalr1.cc  */
#line 1740 "parser.yy"
    {
	bool transResult = mainTrans.translateCausesLaw((yysemantic_stack_[(7) - (1)].parseElement), (yysemantic_stack_[(7) - (3)].parseElement), (yysemantic_stack_[(7) - (4)].parseElement), (yysemantic_stack_[(7) - (5)].parseElement), (yysemantic_stack_[(7) - (6)].parseElement), (yysemantic_stack_[(7) - (7)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (1)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(7) - (7)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 146:
/* Line 670 of lalr1.cc  */
#line 1757 "parser.yy"
    {
	// This one's easy, it's just a pass-through.
	mainTrans.output("noconcurrency.", IPART_BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 1763 "parser.yy"
    {
	// This one is also very easy.
	mainTrans.output("strong_noconcurrency.", IPART_BASE, true);
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 1771 "parser.yy"
    {
	bool transResult = mainTrans.translateIncrementLaw((yysemantic_stack_[(8) - (1)].parseElement), (yysemantic_stack_[(8) - (3)].parseElement), (yysemantic_stack_[(8) - (5)].parseElement), (yysemantic_stack_[(8) - (6)].parseElement), (yysemantic_stack_[(8) - (7)].parseElement), (yysemantic_stack_[(8) - (8)].parseElement), true);
	deallocateItem((yysemantic_stack_[(8) - (1)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (7)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (8)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 1787 "parser.yy"
    {
	bool transResult = mainTrans.translateIncrementLaw((yysemantic_stack_[(8) - (1)].parseElement), (yysemantic_stack_[(8) - (3)].parseElement), (yysemantic_stack_[(8) - (5)].parseElement), (yysemantic_stack_[(8) - (6)].parseElement), (yysemantic_stack_[(8) - (7)].parseElement), (yysemantic_stack_[(8) - (8)].parseElement), false);
	deallocateItem((yysemantic_stack_[(8) - (1)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (7)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (8)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
	
	if(!transResult)
	{
		YYERROR;
	}
}
    break;

  case 150:
/* Line 670 of lalr1.cc  */
#line 1805 "parser.yy"
    {
	// This is a law of the form c=v.
	// Which is really just a lazy shortcut for
	// caused c=v.

	mainTrans.translateCausalLaw((yysemantic_stack_[(8) - (1)].parseElement), (yysemantic_stack_[(8) - (2)].parseElement), (yysemantic_stack_[(8) - (3)].parseElement), (yysemantic_stack_[(8) - (4)].parseElement), (yysemantic_stack_[(8) - (5)].parseElement), (yysemantic_stack_[(8) - (6)].parseElement), (yysemantic_stack_[(8) - (7)].parseElement), (yysemantic_stack_[(8) - (8)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (1)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (7)].parseElement));
	deallocateItem((yysemantic_stack_[(8) - (8)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 151:
/* Line 670 of lalr1.cc  */
#line 1824 "parser.yy"
    {
	mainTrans.translateCausalLaw((yysemantic_stack_[(9) - (2)].parseElement), (yysemantic_stack_[(9) - (3)].parseElement), (yysemantic_stack_[(9) - (4)].parseElement), (yysemantic_stack_[(9) - (5)].parseElement), (yysemantic_stack_[(9) - (6)].parseElement), (yysemantic_stack_[(9) - (7)].parseElement), (yysemantic_stack_[(9) - (8)].parseElement), (yysemantic_stack_[(9) - (9)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (2)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (3)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (4)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (5)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (6)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (7)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (8)].parseElement));
	deallocateItem((yysemantic_stack_[(9) - (9)].parseElement));
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 152:
/* Line 670 of lalr1.cc  */
#line 1839 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 153:
/* Line 670 of lalr1.cc  */
#line 1843 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("true", mainTrans.getOrCreateSimpleObjectLike("true"));
}
    break;

  case 154:
/* Line 670 of lalr1.cc  */
#line 1847 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("false", mainTrans.getOrCreateSimpleObjectLike("false"));
}
    break;

  case 155:
/* Line 670 of lalr1.cc  */
#line 1853 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 156:
/* Line 670 of lalr1.cc  */
#line 1857 "parser.yy"
    {
	if((yysemantic_stack_[(3) - (2)].parseElement) != NULL)
	{
		(yysemantic_stack_[(3) - (2)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yysemantic_stack_[(3) - (2)].parseElement);
}
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 1867 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 158:
/* Line 670 of lalr1.cc  */
#line 1871 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yysemantic_stack_[(2) - (2)].parseElement));
}
    break;

  case 159:
/* Line 670 of lalr1.cc  */
#line 1875 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_AND, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 160:
/* Line 670 of lalr1.cc  */
#line 1879 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_OR, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 161:
/* Line 670 of lalr1.cc  */
#line 1883 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 162:
/* Line 670 of lalr1.cc  */
#line 1887 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 163:
/* Line 670 of lalr1.cc  */
#line 1893 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 164:
/* Line 670 of lalr1.cc  */
#line 1897 "parser.yy"
    {
	if((yysemantic_stack_[(3) - (2)].parseElement) != NULL)
	{
		(yysemantic_stack_[(3) - (2)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yysemantic_stack_[(3) - (2)].parseElement);
}
    break;

  case 165:
/* Line 670 of lalr1.cc  */
#line 1907 "parser.yy"
    {
	// This is really only allowed to be a constant/variable/object expression, verify that.
	if((yysemantic_stack_[(1) - (1)].parseElement) != NULL)
	{
		if((yysemantic_stack_[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_BASELIKE && (yysemantic_stack_[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_CONSTLIKE && (yysemantic_stack_[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_OBJLIKE && (yysemantic_stack_[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_VARLIKE)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bare expression \"" << (yysemantic_stack_[(1) - (1)].parseElement)->fullName() << "\" not allowed there, did you forget an equality or comparison sign?";
			ltsyyreportError();
			deallocateItem((yysemantic_stack_[(1) - (1)].parseElement));
		}
	}
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
	if((yyval.parseElement) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 166:
/* Line 670 of lalr1.cc  */
#line 1926 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_EQ, (yysemantic_stack_[(3) - (3)].parseElement));

}
    break;

  case 167:
/* Line 670 of lalr1.cc  */
#line 1931 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_NEQ, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 168:
/* Line 670 of lalr1.cc  */
#line 1935 "parser.yy"
    {

	SimpleBinaryOperator::BinaryOperatorType type;
	// A bunch of possible operators bundle into COMPARISON. Find out which one.
	switch((yysemantic_stack_[(3) - (2)].integer))
	{
	case T_DBL_EQ:
		type = SimpleBinaryOperator::BOP_DBL_EQ;
		break;
	case T_LTHAN:
		type = SimpleBinaryOperator::BOP_LTHAN;
		break;
	case T_GTHAN:
		type = SimpleBinaryOperator::BOP_GTHAN;
		break;
	case T_EQ_LTHAN:
		type = SimpleBinaryOperator::BOP_LTHAN_EQ;
		break;
	case T_GTHAN_EQ:
		type = SimpleBinaryOperator::BOP_GTHAN_EQ;
		break;
	default:
		type = SimpleBinaryOperator::BOP_UNKNOWN;
	}
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), type, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 169:
/* Line 670 of lalr1.cc  */
#line 1962 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 170:
/* Line 670 of lalr1.cc  */
#line 1968 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 171:
/* Line 670 of lalr1.cc  */
#line 1974 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 172:
/* Line 670 of lalr1.cc  */
#line 1980 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 173:
/* Line 670 of lalr1.cc  */
#line 1986 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 174:
/* Line 670 of lalr1.cc  */
#line 1990 "parser.yy"
    {
	if((yysemantic_stack_[(3) - (2)].parseElement) != NULL)
	{
		(yysemantic_stack_[(3) - (2)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yysemantic_stack_[(3) - (2)].parseElement);
}
    break;

  case 175:
/* Line 670 of lalr1.cc  */
#line 2000 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 176:
/* Line 670 of lalr1.cc  */
#line 2004 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yysemantic_stack_[(2) - (2)].parseElement));
}
    break;

  case 177:
/* Line 670 of lalr1.cc  */
#line 2008 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_AND, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 178:
/* Line 670 of lalr1.cc  */
#line 2012 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_OR, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 179:
/* Line 670 of lalr1.cc  */
#line 2016 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 180:
/* Line 670 of lalr1.cc  */
#line 2020 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 181:
/* Line 670 of lalr1.cc  */
#line 2026 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 182:
/* Line 670 of lalr1.cc  */
#line 2030 "parser.yy"
    {
	if((yysemantic_stack_[(3) - (2)].parseElement) != NULL)
	{
		(yysemantic_stack_[(3) - (2)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yysemantic_stack_[(3) - (2)].parseElement);
}
    break;

  case 183:
/* Line 670 of lalr1.cc  */
#line 2040 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
	if((yyval.parseElement) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 184:
/* Line 670 of lalr1.cc  */
#line 2048 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 185:
/* Line 670 of lalr1.cc  */
#line 2054 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 186:
/* Line 670 of lalr1.cc  */
#line 2058 "parser.yy"
    {
	if((yysemantic_stack_[(3) - (2)].parseElement) != NULL)
	{
		(yysemantic_stack_[(3) - (2)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yysemantic_stack_[(3) - (2)].parseElement);
}
    break;

  case 187:
/* Line 670 of lalr1.cc  */
#line 2068 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 188:
/* Line 670 of lalr1.cc  */
#line 2072 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_AND, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 189:
/* Line 670 of lalr1.cc  */
#line 2078 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 190:
/* Line 670 of lalr1.cc  */
#line 2082 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yysemantic_stack_[(2) - (2)].parseElement));
}
    break;

  case 191:
/* Line 670 of lalr1.cc  */
#line 2086 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_EQ, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 192:
/* Line 670 of lalr1.cc  */
#line 2092 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yysemantic_stack_[(5) - (2)].l_quantPair) != NULL && (yysemantic_stack_[(5) - (4)].parseElement) != NULL)
	{
		(yyval.parseElement) = new BigQuantifiers((yysemantic_stack_[(5) - (2)].l_quantPair), (yysemantic_stack_[(5) - (4)].parseElement));
	} else if ((yysemantic_stack_[(5) - (4)].parseElement)) {
		(yyval.parseElement) = (yysemantic_stack_[(5) - (4)].parseElement);
	}

	if ((yysemantic_stack_[(5) - (2)].l_quantPair)) deallocateList((yysemantic_stack_[(5) - (2)].l_quantPair));
	

	
}
    break;

  case 193:
/* Line 670 of lalr1.cc  */
#line 2109 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yysemantic_stack_[(5) - (2)].l_quantPair) != NULL && (yysemantic_stack_[(5) - (4)].parseElement) != NULL)
	{
		(yyval.parseElement) = new BigQuantifiers((yysemantic_stack_[(5) - (2)].l_quantPair), (yysemantic_stack_[(5) - (4)].parseElement));
	} else if ((yysemantic_stack_[(5) - (4)].parseElement)) {
		(yyval.parseElement) = (yysemantic_stack_[(5) - (4)].parseElement);
	}

	if ((yysemantic_stack_[(5) - (2)].l_quantPair)) deallocateList((yysemantic_stack_[(5) - (2)].l_quantPair));
  
}
    break;

  case 194:
/* Line 670 of lalr1.cc  */
#line 2124 "parser.yy"
    {
	(yyval.l_quantPair) = NULL;
	if((yysemantic_stack_[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new BigQuantifiers::QuantifierList();
		(yyval.l_quantPair)->push_back((yysemantic_stack_[(1) - (1)].p_quantPair));
	}
}
    break;

  case 195:
/* Line 670 of lalr1.cc  */
#line 2133 "parser.yy"
    {
	(yyval.l_quantPair) = NULL;
	if((yysemantic_stack_[(1) - (1)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = new BigQuantifiers::QuantifierList();
		(yyval.l_quantPair)->push_back((yysemantic_stack_[(1) - (1)].p_quantPair));
	}
}
    break;

  case 196:
/* Line 670 of lalr1.cc  */
#line 2142 "parser.yy"
    {
	if((yysemantic_stack_[(2) - (1)].l_quantPair) != NULL && (yysemantic_stack_[(2) - (2)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = (yysemantic_stack_[(2) - (1)].l_quantPair);
		(yyval.l_quantPair)->push_back((yysemantic_stack_[(2) - (2)].p_quantPair));
	}
	else
	{
		if((yysemantic_stack_[(2) - (1)].l_quantPair) != NULL)
		{
			for(BigQuantifiers::QuantifierList::iterator lIter = (yysemantic_stack_[(2) - (1)].l_quantPair)->begin(); lIter != (yysemantic_stack_[(2) - (1)].l_quantPair)->end(); ++lIter)
			{
				if((*lIter)->second != NULL)
				{
					deallocateItem((*lIter)->second);
				}
				deallocateItem(*lIter);
			}
			deallocateList((yysemantic_stack_[(2) - (1)].l_quantPair));
		}
		if((yysemantic_stack_[(2) - (2)].p_quantPair) != NULL)
		{
			if((yysemantic_stack_[(2) - (2)].p_quantPair)->second != NULL)
			{
				deallocateItem((yysemantic_stack_[(2) - (2)].p_quantPair)->second);
			}
			deallocateItem((yysemantic_stack_[(2) - (2)].p_quantPair));
		}
		(yyval.l_quantPair) = NULL;
	}
}
    break;

  case 197:
/* Line 670 of lalr1.cc  */
#line 2174 "parser.yy"
    {
	if((yysemantic_stack_[(2) - (1)].l_quantPair) != NULL && (yysemantic_stack_[(2) - (2)].p_quantPair) != NULL)
	{
		(yyval.l_quantPair) = (yysemantic_stack_[(2) - (1)].l_quantPair);
		(yyval.l_quantPair)->push_back((yysemantic_stack_[(2) - (2)].p_quantPair));
	}
	else
	{
		if((yysemantic_stack_[(2) - (1)].l_quantPair) != NULL)
		{
			for(BigQuantifiers::QuantifierList::iterator lIter = (yysemantic_stack_[(2) - (1)].l_quantPair)->begin(); lIter != (yysemantic_stack_[(2) - (1)].l_quantPair)->end(); ++lIter)
			{
				if((*lIter)->second != NULL)
				{
					deallocateItem((*lIter)->second);
				}
				deallocateItem(*lIter);
			}
			deallocateList((yysemantic_stack_[(2) - (1)].l_quantPair));
		}
		if((yysemantic_stack_[(2) - (2)].p_quantPair) != NULL)
		{
			if((yysemantic_stack_[(2) - (2)].p_quantPair)->second != NULL)
			{
				deallocateItem((yysemantic_stack_[(2) - (2)].p_quantPair)->second);
			}
			deallocateItem((yysemantic_stack_[(2) - (2)].p_quantPair));
		}
		(yyval.l_quantPair) = NULL;
	}
}
    break;

  case 198:
/* Line 670 of lalr1.cc  */
#line 2208 "parser.yy"
    {
	(yyval.p_quantPair) = new BigQuantifiers::Quantifier( BigQuantifiers::QUANT_CONJ, NULL);

	// That identifier better be a variable...
	Variable* varRef = mainTrans.getVariableLike(*(yysemantic_stack_[(2) - (2)].str));
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans.getConstantLike(*(yysemantic_stack_[(2) - (2)].str),0) || mainTrans.getObjectLike(*(yysemantic_stack_[(2) - (2)].str),0)) {
			// They've given us something that clearly isn't a variable.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Unexpected token \"" << *(yysemantic_stack_[(2) - (2)].str) << "\" in quantifier. Expected a variable.";
			ltsyyreportError();
		} else {
			// They've given us an undeclared identifier.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << *(yysemantic_stack_[(2) - (2)].str) << "\" is undeclared.";
			ltsyyreportError();
		}
		
		// For the sake of system stability, we'll return a new variable.
		varRef = new Variable(*(yysemantic_stack_[(2) - (2)].str));
		if (mainTrans.addVariable(varRef) == SymbolTable::ADDSYM_OK) { 
			(yyval.p_quantPair)->second = new VariableLikeElement(*(yysemantic_stack_[(2) - (2)].str), varRef);
		} else {
			(yyval.p_quantPair)->second = NULL;
		}
		
	}
	else
	{
		(yyval.p_quantPair)->second = new VariableLikeElement(*(yysemantic_stack_[(2) - (2)].str), varRef);
	}
	deallocateItem((yysemantic_stack_[(2) - (2)].str));
}
    break;

  case 199:
/* Line 670 of lalr1.cc  */
#line 2247 "parser.yy"
    {
	(yyval.p_quantPair) = new std::pair<enum BigQuantifiers::QuantifierType, ParseElement*>();
	(yyval.p_quantPair)->first = BigQuantifiers::QUANT_DISJ;
	// Guess that the identifier is a variable, otherwise just default to object.
	Variable* varRef = mainTrans.getVariableLike(*(yysemantic_stack_[(2) - (2)].str));
	if(varRef == NULL)
	{
		// It's not. We should tell them.
		// First. Let's figure out exactly what kind of error it is...
		if (mainTrans.getConstantLike(*(yysemantic_stack_[(2) - (2)].str),0) || mainTrans.getObjectLike(*(yysemantic_stack_[(2) - (2)].str),0)) {
			// They've given us something that clearly isn't a variable.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Unexpected token \"" << *(yysemantic_stack_[(2) - (2)].str) << "\" in quantifier. Expected a variable.";
			ltsyyreportError();
		} else {
			// They've given us an undeclared identifier.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "\"" << *(yysemantic_stack_[(2) - (2)].str) << "\" is undeclared.";
			ltsyyreportError();
		}
		
		// For the sake of system stability, we'll return a new variable.
		varRef = new Variable(*(yysemantic_stack_[(2) - (2)].str));
		if (mainTrans.addVariable(varRef) == SymbolTable::ADDSYM_OK) { 
			(yyval.p_quantPair)->second = new VariableLikeElement(*(yysemantic_stack_[(2) - (2)].str), varRef);
		} else {
			(yyval.p_quantPair)->second = NULL;
		}
		
	}
	else
	{
		(yyval.p_quantPair)->second  = new VariableLikeElement(*(yysemantic_stack_[(2) - (2)].str), varRef);
	}
	deallocateItem((yysemantic_stack_[(2) - (2)].str));
}
    break;

  case 200:
/* Line 670 of lalr1.cc  */
#line 2288 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	int addQueryResult = mainTrans.addQuery(mainTrans.tempQuery);
	if(addQueryResult != SymbolTable::ADDSYM_OK)
	{
		if(addQueryResult == SymbolTable::ADDSYM_DUP)
		{	// Query with same label already exists.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "A query with label \"" << mainTrans.tempQuery->label << "\" already exists, query labels must be unique.";
			ltsyyreportError();
		}
		else
		{	// General error.
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Query malformed or missing critical information (e.g., maxstep).";
			ltsyyreportError();
		}
		// We can just error here, the error reporting functions already handle creating a new tempQuery.
		YYERROR;
	}
	else
	{	// It added okay, translate it and make a new tempQuery without destroying the one that just got added.
		mainTrans.translateQuery(mainTrans.tempQuery);
		mainTrans.allocateNewTempQuery();
	}
}
    break;

  case 201:
/* Line 670 of lalr1.cc  */
#line 2317 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 202:
/* Line 670 of lalr1.cc  */
#line 2321 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
}
    break;

  case 203:
/* Line 670 of lalr1.cc  */
#line 2327 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if(mainTrans.tempQuery->label == "")
	{
		mainTrans.tempQuery->label = utils::to_string((yysemantic_stack_[(3) - (3)].integer));
	}
	else
	{
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "label already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
		ltsyyreportError();
		YYERROR;
	}
}
    break;

  case 204:
/* Line 670 of lalr1.cc  */
#line 2378 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if ((yysemantic_stack_[(3) - (3)].numRange)) {
		if(mainTrans.tempQuery->maxstep == "")
		{
			mainTrans.tempQuery->maxstep = (yysemantic_stack_[(3) - (3)].numRange)->baseName();
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "maxstep already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
		deallocateItem((yysemantic_stack_[(3) - (3)].numRange));
	}

}
    break;

  case 205:
/* Line 670 of lalr1.cc  */
#line 2397 "parser.yy"
    {
	if ((yysemantic_stack_[(3) - (3)].str)) {
		if(mainTrans.tempQuery->maxstep == "")
		{
			mainTrans.tempQuery->maxstep = *(yysemantic_stack_[(3) - (3)].str);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "maxstep already defined as \"" << mainTrans.tempQuery->maxstep << "\" in this query, can only define it once per query.";
			ltsyyreportError();
			YYERROR;
		}
		deallocateItem((yysemantic_stack_[(3) - (3)].str));
	}
}
    break;

  case 206:
/* Line 670 of lalr1.cc  */
#line 2415 "parser.yy"
    {
	(yyval.not_used) = PARSERULE_NOT_USED;
	if((yysemantic_stack_[(1) - (1)].parseElement) != NULL)
	{
		// Add this new condition to the temp query.
		mainTrans.tempQuery->queryConditions.push_back((yysemantic_stack_[(1) - (1)].parseElement));
	}
	else
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Query body formula is NULL!";
		ltsyyreportWarning();
	}
}
    break;

  case 207:
/* Line 670 of lalr1.cc  */
#line 2433 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 208:
/* Line 670 of lalr1.cc  */
#line 2437 "parser.yy"
    {
	if((yysemantic_stack_[(3) - (2)].parseElement) != NULL)
	{
		(yysemantic_stack_[(3) - (2)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yysemantic_stack_[(3) - (2)].parseElement);
}
    break;

  case 209:
/* Line 670 of lalr1.cc  */
#line 2445 "parser.yy"
    {
	// Turn the time stamp into a plain, translated string representation, then propogate it through the body formula.
	if((yysemantic_stack_[(3) - (1)].parseElement) != NULL && (yysemantic_stack_[(3) - (3)].parseElement) != NULL)
	{
		(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_BIND_STEP, (yysemantic_stack_[(3) - (3)].parseElement));
	} 
	else if ((yysemantic_stack_[(3) - (3)].parseElement) != NULL) 
	{
		(yyval.parseElement) = (yysemantic_stack_[(3) - (3)].parseElement);
	}
	else
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Query body formula is NULL!";
		ltsyyreportWarning();
	}
}
    break;

  case 210:
/* Line 670 of lalr1.cc  */
#line 2465 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 211:
/* Line 670 of lalr1.cc  */
#line 2469 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, (yysemantic_stack_[(2) - (2)].parseElement));
}
    break;

  case 212:
/* Line 670 of lalr1.cc  */
#line 2473 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_AND, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 213:
/* Line 670 of lalr1.cc  */
#line 2477 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_OR, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 214:
/* Line 670 of lalr1.cc  */
#line 2481 "parser.yy"
    {
		(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_EQUIV, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 215:
/* Line 670 of lalr1.cc  */
#line 2485 "parser.yy"
    {
		(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_IMPL, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 216:
/* Line 670 of lalr1.cc  */
#line 2491 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 217:
/* Line 670 of lalr1.cc  */
#line 2495 "parser.yy"
    {
	if((yysemantic_stack_[(3) - (2)].parseElement) != NULL)
	{
		(yysemantic_stack_[(3) - (2)].parseElement)->parens(true);
	}
	(yyval.parseElement) = (yysemantic_stack_[(3) - (2)].parseElement);
}
    break;

  case 218:
/* Line 670 of lalr1.cc  */
#line 2505 "parser.yy"
    {
	// This is really only allowed to be a constant/variable/object expression, verify that.
	if((yysemantic_stack_[(1) - (1)].parseElement) != NULL)
	{
		if((yysemantic_stack_[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_BASELIKE && (yysemantic_stack_[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_CONSTLIKE && (yysemantic_stack_[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_OBJLIKE && (yysemantic_stack_[(1) - (1)].parseElement)->getType() != ParseElement::PELEM_VARLIKE)
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Bare expression \"" << (yysemantic_stack_[(1) - (1)].parseElement)->fullName() << "\" not allowed there, did you forget an equality or comparison sign?";
			ltsyyreportError();
			deallocateItem((yysemantic_stack_[(1) - (1)].parseElement));
		}
	}
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
	if((yyval.parseElement) == NULL)
	{
		YYERROR;
	}
}
    break;

  case 219:
/* Line 670 of lalr1.cc  */
#line 2524 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_EQ, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 220:
/* Line 670 of lalr1.cc  */
#line 2528 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_NEQ, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 221:
/* Line 670 of lalr1.cc  */
#line 2532 "parser.yy"
    {
	SimpleBinaryOperator::BinaryOperatorType type;
	// A bunch of possible operators bundle into COMPARISON. Find out which one.
	switch((yysemantic_stack_[(3) - (2)].integer))
	{
	case T_DBL_EQ:
		type = SimpleBinaryOperator::BOP_DBL_EQ;
		break;
	case T_LTHAN:
		type = SimpleBinaryOperator::BOP_LTHAN;
		break;
	case T_GTHAN:
		type = SimpleBinaryOperator::BOP_GTHAN;
		break;
	case T_EQ_LTHAN:
		type = SimpleBinaryOperator::BOP_LTHAN_EQ;
		break;
	case T_GTHAN_EQ:
		type = SimpleBinaryOperator::BOP_GTHAN_EQ;
		break;
	default:
		type = SimpleBinaryOperator::BOP_UNKNOWN;
	}

	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), type, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 222:
/* Line 670 of lalr1.cc  */
#line 2559 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 223:
/* Line 670 of lalr1.cc  */
#line 2565 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yysemantic_stack_[(5) - (2)].l_quantPair) != NULL && (yysemantic_stack_[(5) - (4)].parseElement) != NULL)
	{
		(yyval.parseElement) = new BigQuantifiers((yysemantic_stack_[(5) - (2)].l_quantPair), (yysemantic_stack_[(5) - (4)].parseElement));
		deallocateList((yysemantic_stack_[(5) - (2)].l_quantPair));
	} else if ((yysemantic_stack_[(5) - (4)].parseElement)) {
		(yyval.parseElement) = (yysemantic_stack_[(5) - (4)].parseElement);
	}

	if ((yysemantic_stack_[(5) - (2)].l_quantPair)) deallocateList((yysemantic_stack_[(5) - (2)].l_quantPair));
}
    break;

  case 224:
/* Line 670 of lalr1.cc  */
#line 2582 "parser.yy"
    {
	// Guess what kind of instance this might be, go with the best match.
	// Guess variable, then constant, then try object.
	Variable* varRef = mainTrans.getVariableLike(*(yysemantic_stack_[(2) - (2)].str));
	if(varRef == NULL)
	{
		Constant* constRef = mainTrans.getConstantLike(*(yysemantic_stack_[(2) - (2)].str),0);
		if(constRef == NULL || (yysemantic_stack_[(2) - (1)].str) != NULL)
		{
			Object* objRef = mainTrans.getObjectLike(*(yysemantic_stack_[(2) - (2)].str),0, (yysemantic_stack_[(2) - (1)].str) != NULL);
			
			if (objRef == NULL) {
				// This doesn't appear to be a declared identifier.
				// We may be inside an unless clause, we'll guess
				// constant and check if it is being dynamically
				// declared later.
				
				(yyval.parseElement) = new ConstantLikeElement(*(yysemantic_stack_[(2) - (2)].str), NULL);
			
			} else { 
				(yyval.parseElement) = new ObjectLikeElement(*(yysemantic_stack_[(2) - (2)].str), objRef);
			}
		}
		else
		{
			(yyval.parseElement) = new ConstantLikeElement(*(yysemantic_stack_[(2) - (2)].str), constRef);
		}
	}
	else
	{
		(yyval.parseElement) = new VariableLikeElement(*(yysemantic_stack_[(2) - (2)].str), varRef);
	}
	deallocateItem((yysemantic_stack_[(2) - (1)].str));
	deallocateItem((yysemantic_stack_[(2) - (2)].str));
}
    break;

  case 225:
/* Line 670 of lalr1.cc  */
#line 2618 "parser.yy"
    {
	// Guess what kind of instance this might be, go with the best match.
	// Guess constant, then try object.
	Constant* constRef = mainTrans.getConstantLike(*(yysemantic_stack_[(5) - (2)].str),(yysemantic_stack_[(5) - (4)].v_parseElement)->size());
	if(constRef == NULL || (yysemantic_stack_[(5) - (1)].str) != NULL)
	{
		Object* objRef = mainTrans.getObjectLike(*(yysemantic_stack_[(5) - (2)].str),(yysemantic_stack_[(5) - (4)].v_parseElement)->size(), (yysemantic_stack_[(5) - (1)].str) != NULL);
		
		if (objRef == NULL) {
			// This doesn't appear to be a declared identifier.
			// We may be inside an unless clause, we'll guess
			// constant and check if it is being dynamically
			// declared later.
			
			(yyval.parseElement) = new ConstantLikeElement(*(yysemantic_stack_[(5) - (2)].str), NULL, (yysemantic_stack_[(5) - (4)].v_parseElement));
		
		} else {
		
			(yyval.parseElement) = new ObjectLikeElement(*(yysemantic_stack_[(5) - (2)].str), objRef, (yysemantic_stack_[(5) - (4)].v_parseElement));
		}
	}
	else
	{
		(yyval.parseElement) = new ConstantLikeElement(*(yysemantic_stack_[(5) - (2)].str), constRef, (yysemantic_stack_[(5) - (4)].v_parseElement));
	}

	deallocateItem((yysemantic_stack_[(5) - (1)].str));
	deallocateItem((yysemantic_stack_[(5) - (2)].str));
	deallocateList((yysemantic_stack_[(5) - (4)].v_parseElement));
}
    break;

  case 226:
/* Line 670 of lalr1.cc  */
#line 2651 "parser.yy"
    { (yyval.str) = NULL; }
    break;

  case 227:
/* Line 670 of lalr1.cc  */
#line 2652 "parser.yy"
    { (yyval.str) = new std::string("@"); }
    break;

  case 228:
/* Line 670 of lalr1.cc  */
#line 2655 "parser.yy"
    {
	(yyval.v_parseElement) = NULL;
	if((yysemantic_stack_[(1) - (1)].parseElement) != NULL)
	{
		(yyval.v_parseElement) = new ParseElementList();
		(yyval.v_parseElement)->push_back((yysemantic_stack_[(1) - (1)].parseElement));
	}
}
    break;

  case 229:
/* Line 670 of lalr1.cc  */
#line 2664 "parser.yy"
    {
	(yyval.v_parseElement) = NULL;
	if((yysemantic_stack_[(3) - (1)].v_parseElement) != NULL && (yysemantic_stack_[(3) - (3)].parseElement) != NULL)
	{
		(yyval.v_parseElement) = (yysemantic_stack_[(3) - (1)].v_parseElement);
		(yyval.v_parseElement)->push_back((yysemantic_stack_[(3) - (3)].parseElement));
	}
}
    break;

  case 230:
/* Line 670 of lalr1.cc  */
#line 2675 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 231:
/* Line 670 of lalr1.cc  */
#line 2681 "parser.yy"
    {
	Sort* tempSort = mainTrans.getSort(*(yysemantic_stack_[(1) - (1)].str));
	(yyval.l_sort) = NULL;
	if(tempSort != NULL)
	{
		(yyval.l_sort) = new SortList();
		(yyval.l_sort)->push_back(tempSort);
	}
	else
	{
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "Sort \"" << *(yysemantic_stack_[(1) - (1)].str) << "\" not declared, can't use as part of another declaration.";
		ltsyyreportError();
	}
	deallocateItem((yysemantic_stack_[(1) - (1)].str));
	if((yyval.l_sort) == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 232:
/* Line 670 of lalr1.cc  */
#line 2702 "parser.yy"
    {
	(yyval.l_sort) = NULL;
	if((yysemantic_stack_[(3) - (1)].l_sort) != NULL)
	{
		(yyval.l_sort) = (yysemantic_stack_[(3) - (1)].l_sort);
		Sort* tempSort = mainTrans.getSort(*(yysemantic_stack_[(3) - (3)].str));
		if(tempSort != NULL)
		{
			(yyval.l_sort)->push_back(tempSort);
		}
		else
		{
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *(yysemantic_stack_[(3) - (3)].str) << "\" not declared, can't use as part of another declaration.";
			ltsyyreportError();
			deallocateList((yyval.l_sort));
		}
	}
	deallocateItem((yysemantic_stack_[(3) - (3)].str));
	if((yyval.l_sort) == NULL)
	{	// If $$ is NULL, something went wrong.
		YYERROR;
	}
}
    break;

  case 233:
/* Line 670 of lalr1.cc  */
#line 2729 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("true", mainTrans.getOrCreateSimpleObjectLike("true"));
}
    break;

  case 234:
/* Line 670 of lalr1.cc  */
#line 2733 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("false", mainTrans.getOrCreateSimpleObjectLike("false"));
}
    break;

  case 235:
/* Line 670 of lalr1.cc  */
#line 2737 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement("none", mainTrans.getOrCreateSimpleObjectLike("none"));
}
    break;

  case 236:
/* Line 670 of lalr1.cc  */
#line 2741 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 237:
/* Line 670 of lalr1.cc  */
#line 2747 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 238:
/* Line 670 of lalr1.cc  */
#line 2751 "parser.yy"
    {
	(yyval.parseElement) = NULL;
	if((yysemantic_stack_[(3) - (2)].parseElement) != NULL)
	{
		(yyval.parseElement) = (yysemantic_stack_[(3) - (2)].parseElement);
		(yyval.parseElement)->parens(true);
	}
}
    break;

  case 239:
/* Line 670 of lalr1.cc  */
#line 2762 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 240:
/* Line 670 of lalr1.cc  */
#line 2766 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_PLUS, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 241:
/* Line 670 of lalr1.cc  */
#line 2770 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_MINUS, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 242:
/* Line 670 of lalr1.cc  */
#line 2774 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_TIMES, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 243:
/* Line 670 of lalr1.cc  */
#line 2778 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_DIVIDE, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 244:
/* Line 670 of lalr1.cc  */
#line 2782 "parser.yy"
    {
	(yyval.parseElement) = new SimpleBinaryOperator((yysemantic_stack_[(3) - (1)].parseElement), SimpleBinaryOperator::BOP_MOD, (yysemantic_stack_[(3) - (3)].parseElement));
}
    break;

  case 245:
/* Line 670 of lalr1.cc  */
#line 2786 "parser.yy"
    {
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_ABS, (yysemantic_stack_[(2) - (2)].parseElement));
}
    break;

  case 246:
/* Line 670 of lalr1.cc  */
#line 2790 "parser.yy"
    {
	// Not necessary to flag parenBefore and parenAfter, translation of abs
	// automatically adds parentheses around the expression.
	(yyval.parseElement) = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_ABS, (yysemantic_stack_[(4) - (3)].parseElement));
}
    break;

  case 247:
/* Line 670 of lalr1.cc  */
#line 2798 "parser.yy"
    {
	(yyval.parseElement) = new ObjectLikeElement(*(yysemantic_stack_[(1) - (1)].str), mainTrans.getOrCreateSimpleObjectLike(*(yysemantic_stack_[(1) - (1)].str)));
	deallocateItem((yysemantic_stack_[(1) - (1)].str));
}
    break;

  case 248:
/* Line 670 of lalr1.cc  */
#line 2803 "parser.yy"
    {
	(yyval.parseElement) = (yysemantic_stack_[(1) - (1)].parseElement);
}
    break;

  case 249:
/* Line 670 of lalr1.cc  */
#line 2809 "parser.yy"
    {
	(yyval.numRange) = new NumberRange(*(yysemantic_stack_[(3) - (1)].str), *(yysemantic_stack_[(3) - (3)].str));
	deallocateItem((yysemantic_stack_[(3) - (1)].str));
	deallocateItem((yysemantic_stack_[(3) - (3)].str));
}
    break;

  case 250:
/* Line 670 of lalr1.cc  */
#line 2817 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = utils::to_string((yysemantic_stack_[(1) - (1)].integer));
}
    break;

  case 251:
/* Line 670 of lalr1.cc  */
#line 2822 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxAdditive";
}
    break;

  case 252:
/* Line 670 of lalr1.cc  */
#line 2827 "parser.yy"
    {
	(yyval.str) = new std::string;
	(*(yyval.str)) = "maxstep";
}
    break;

  case 253:
/* Line 670 of lalr1.cc  */
#line 2832 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) = "-";
	(*(yyval.str)) += (*(yysemantic_stack_[(2) - (2)].str));
	deallocateItem((yysemantic_stack_[(2) - (2)].str));
}
    break;

  case 254:
/* Line 670 of lalr1.cc  */
#line 2841 "parser.yy"
    {
	(yyval.str) = (yysemantic_stack_[(1) - (1)].str);
}
    break;

  case 255:
/* Line 670 of lalr1.cc  */
#line 2845 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += "(";
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (2)].str));
	(*(yyval.str)) += ")";
	deallocateItem((yysemantic_stack_[(3) - (2)].str));
}
    break;

  case 256:
/* Line 670 of lalr1.cc  */
#line 2855 "parser.yy"
    {
	(yyval.str) = (yysemantic_stack_[(1) - (1)].str);
}
    break;

  case 257:
/* Line 670 of lalr1.cc  */
#line 2859 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (1)].str));
	(*(yyval.str)) += " + ";
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (3)].str));
	deallocateItem((yysemantic_stack_[(3) - (1)].str));
	deallocateItem((yysemantic_stack_[(3) - (3)].str));
}
    break;

  case 258:
/* Line 670 of lalr1.cc  */
#line 2868 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (1)].str));
	(*(yyval.str)) += " - ";
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (3)].str));
	deallocateItem((yysemantic_stack_[(3) - (1)].str));
	deallocateItem((yysemantic_stack_[(3) - (3)].str));
}
    break;

  case 259:
/* Line 670 of lalr1.cc  */
#line 2877 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (1)].str));
	(*(yyval.str)) += " * ";
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (3)].str));
	deallocateItem((yysemantic_stack_[(3) - (1)].str));
	deallocateItem((yysemantic_stack_[(3) - (3)].str));
}
    break;

  case 260:
/* Line 670 of lalr1.cc  */
#line 2886 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (1)].str));
	(*(yyval.str)) += " // ";
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (3)].str));
	deallocateItem((yysemantic_stack_[(3) - (1)].str));
	deallocateItem((yysemantic_stack_[(3) - (3)].str));
}
    break;

  case 261:
/* Line 670 of lalr1.cc  */
#line 2895 "parser.yy"
    {
	(yyval.str) = new std::string();
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (1)].str));
	(*(yyval.str)) += " mod ";
	(*(yyval.str)) += (*(yysemantic_stack_[(3) - (3)].str));
	deallocateItem((yysemantic_stack_[(3) - (1)].str));
	deallocateItem((yysemantic_stack_[(3) - (3)].str));
}
    break;

  case 262:
/* Line 670 of lalr1.cc  */
#line 2907 "parser.yy"
    {
	(yyval.integer) = (yysemantic_stack_[(1) - (1)].integer);
}
    break;

  case 263:
/* Line 670 of lalr1.cc  */
#line 2911 "parser.yy"
    {
	(yyval.integer) = (yysemantic_stack_[(1) - (1)].integer);
}
    break;

  case 264:
/* Line 670 of lalr1.cc  */
#line 2917 "parser.yy"
    {
	(yyval.integer) = T_UMINUS;
}
    break;

  case 265:
/* Line 670 of lalr1.cc  */
#line 2921 "parser.yy"
    {
	(yyval.integer) = (yysemantic_stack_[(1) - (1)].integer);
}
    break;

  case 266:
/* Line 670 of lalr1.cc  */
#line 2927 "parser.yy"
    {
	(yyval.integer) = (yysemantic_stack_[(1) - (1)].integer);
}
    break;

  case 267:
/* Line 670 of lalr1.cc  */
#line 2931 "parser.yy"
    {
	(yyval.integer) = (yysemantic_stack_[(1) - (1)].integer);
}
    break;

  case 268:
/* Line 670 of lalr1.cc  */
#line 2935 "parser.yy"
    {
	(yyval.integer) = (yysemantic_stack_[(1) - (1)].integer);
}
    break;

  case 269:
/* Line 670 of lalr1.cc  */
#line 2939 "parser.yy"
    {
	(yyval.integer) = (yysemantic_stack_[(1) - (1)].integer);
}
    break;

  case 270:
/* Line 670 of lalr1.cc  */
#line 2943 "parser.yy"
    {
	(yyval.integer) = (yysemantic_stack_[(1) - (1)].integer);
}
    break;


/* Line 670 of lalr1.cc  */
#line 3907 "parser.cc"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
          }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int parser::yypact_ninf_ = -314;
  const short int
  parser::yypact_[] =
  {
       476,   -16,  -314,   738,   653,   738,   738,   653,    16,    16,
    -314,  -314,   738,  -314,  -314,   738,   653,    16,  -314,  -314,
    -314,   450,  -314,    48,   606,   738,  -314,  -314,    63,    52,
     545,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    43,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,    57,   811,  -314,  -314,  -314,  -314,  -314,
    -314,    81,   812,   817,  -314,  -314,  -314,   738,  -314,   790,
    -314,  -314,   111,  -314,    64,   138,  -314,  -314,    51,    16,
     317,   317,    64,    80,    80,   317,   221,    64,    80,   764,
      65,   817,   162,   172,   135,  -314,  -314,    22,   421,   728,
      16,   815,    23,    69,   838,    88,   146,   180,  -314,  -314,
    -314,  -314,  -314,   653,   653,   738,   653,   653,  -314,   738,
     738,   738,  -314,   225,   738,   208,    32,  -314,  -314,  -314,
    -314,    32,  -314,    32,   764,   764,   764,   764,   764,  -314,
     137,    80,   138,   227,   225,   111,    32,  -314,   738,   253,
     253,   225,   738,  -314,  -314,   253,   272,   225,  -314,   764,
      95,  -314,  -314,   738,  -314,  -314,   266,    22,   -33,  -314,
    -314,  -314,     5,  -314,  -314,  -314,   274,   421,   101,  -314,
    -314,  -314,     7,  -314,  -314,  -314,  -314,  -314,   537,  -314,
     276,   283,    48,   750,   191,  -314,   844,  -314,  -314,  -314,
    -314,   819,   280,   750,   204,  -314,   278,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,   815,   260,  -314,
    -314,   282,   205,  -314,  -314,    33,   303,  -314,   304,  -314,
     306,   302,   419,  -314,  -314,  -314,    64,   356,   838,   361,
      64,   230,   115,   308,   738,   367,  -314,    32,  -314,  -314,
    -314,   316,   316,  -314,  -314,  -314,    48,   137,  -314,   850,
    -314,  -314,  -314,  -314,  -314,   137,  -314,  -314,   367,  -314,
    -314,   838,    16,   272,   272,   367,   838,  -314,   272,    80,
     367,   817,  -314,   481,   685,   321,   341,   348,   354,   362,
    -314,    35,   607,    36,   685,   357,   374,   381,   389,   390,
     398,  -314,   421,   711,   490,   419,   419,   419,   419,   419,
     419,   469,   419,   196,   805,   409,    -6,  -314,   728,   750,
     750,   750,   750,    32,    32,    32,   750,  -314,  -314,    16,
      32,   413,   423,  -314,   815,   815,   429,  -314,    44,   424,
     430,    19,  -314,    23,   711,   474,   419,   763,   253,   764,
     764,   272,   838,   253,    83,  -314,  -314,   246,   850,   431,
     433,   137,   137,   137,   137,  -314,   253,  -314,   448,   448,
     253,   448,  -314,   253,  -314,  -314,  -314,   103,  -314,   537,
    -314,  -314,  -314,  -314,    49,  -314,    14,  -314,  -314,   646,
    -314,  -314,  -314,  -314,  -314,   441,   503,  -314,   147,  -314,
    -314,  -314,  -314,  -314,   357,   685,  -314,   575,  -314,   841,
     371,   371,  -314,  -314,  -314,  -314,  -314,   293,   750,  -314,
    -314,   446,   519,   236,   308,  -314,  -314,  -314,  -314,   844,
    -314,  -314,  -314,   413,  -314,  -314,   521,   430,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   841,  -314,   272,   313,   313,
      80,   272,  -314,    32,   137,  -314,  -314,   564,   270,   308,
    -314,   272,   137,    80,    80,   272,    80,   272,  -314,   685,
      49,   348,   523,   685,   463,   473,   685,   362,  -314,   473,
     390,   695,    19,    80,   272,   272,  -314,   448,  -314,   799,
     448,  -314,   850,  -314,  -314,   448,  -314,   448,  -314,   465,
     486,  -314,   496,  -314,  -314,   498,  -314,  -314,    80,    80,
      80,  -314,    80,    80,    80,   685,   509,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,   170,   523,  -314,  -314
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  parser::yydefact_[] =
  {
         0,     0,   250,   226,   226,   226,   226,   226,   226,   226,
     251,   252,   226,   146,   147,   226,   226,   226,   234,   235,
     233,   226,   227,     0,     0,   226,    15,   265,   264,     0,
       0,     4,     6,     7,     8,    10,    11,    12,    13,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,     0,   105,   155,   157,   163,   169,     9,
     248,     0,   165,   236,   237,   239,   247,   226,    14,   113,
     154,   153,   226,   264,   105,   152,   185,   187,   189,   226,
     109,   109,   105,   117,   117,   109,   105,   105,   117,   226,
       0,   245,     0,     0,     0,   194,   195,     0,     0,   226,
     226,     0,     0,     0,     0,   155,   163,   237,   253,     1,
       5,   119,   120,   226,   226,   226,   226,   226,   263,   226,
     226,   226,   262,   107,   226,   224,   226,   268,   267,   270,
     269,   226,   266,   226,   226,   226,   226,   226,   226,   158,
     226,   117,     0,   185,   107,   226,   226,   190,   226,   111,
     111,   107,   226,   139,   140,   111,   113,   107,   142,   226,
       0,   198,   199,   226,   196,   197,    30,     0,     0,    17,
      19,    21,     0,    24,    26,    28,    55,     0,     0,    42,
      44,    46,     0,    49,    51,    53,    58,   256,    57,   254,
       0,   252,     0,   226,     0,   201,   206,   207,   210,   216,
     222,   218,   237,   226,     0,    60,    62,    81,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,    65,
      67,    69,    78,    82,   102,     0,     0,    93,    95,    97,
       0,   100,     0,   156,   164,   238,   105,     0,   106,     0,
     105,   161,   162,   160,   226,   109,   159,   226,   166,   167,
     168,   240,   241,   244,   243,   242,     0,   226,   114,   171,
     173,   175,   181,   184,   183,   226,   134,   186,   109,   188,
     191,   110,   226,   113,   113,   109,   170,   118,   113,   117,
     109,     0,   246,     0,     0,     0,    17,    21,    24,    28,
      16,     0,     0,     0,     0,     0,    42,    46,    49,    53,
     254,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   216,   237,   200,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   211,    59,   226,
     226,     0,    65,    64,     0,     0,     0,    79,     0,     0,
      97,   100,    92,     0,     0,     0,     0,     0,   111,   226,
     226,   113,   108,   111,     0,   228,   230,     0,     0,   173,
     181,   226,   226,   226,   226,   176,   111,   112,   115,   115,
     111,   115,   141,   111,   192,   231,    76,     0,    77,     0,
      18,    22,    25,    29,     0,    20,     0,    73,    72,     0,
      23,    34,    36,    71,    74,    82,     0,    27,     0,    43,
      47,    50,    54,   255,    45,     0,    48,     0,    52,   249,
     257,   258,   261,   260,   259,   203,   204,   256,   226,   208,
     217,   202,   214,   215,   213,   212,   219,   220,   221,   209,
      61,    63,    66,    68,    70,    80,     0,     0,    94,    98,
     101,    96,   104,    99,   103,     0,    40,   113,   105,   105,
     117,   113,   225,   226,   226,   174,   182,   179,   180,   178,
     177,   113,   226,   117,   117,   113,   117,   113,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,     0,     0,   117,   113,   113,   144,   115,   229,     0,
     115,   116,   172,   136,   135,   115,   137,   115,   232,     0,
      32,    38,     0,    35,    75,     0,   223,   145,   117,   117,
     117,   193,   117,   117,   117,     0,     0,    37,   149,   148,
     150,   151,   138,   143,     0,     0,    33,    39
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -314,  -314,  -314,   534,  -314,   402,   404,   285,  -156,   104,
     -83,   290,  -166,    66,  -314,   210,  -314,  -314,  -146,   417,
    -314,   435,  -314,   445,   331,  -155,  -314,  -314,   307,  -314,
    -204,   434,  -314,  -314,  -273,    53,   -85,  -314,  -267,  -314,
     264,   427,  -314,  -201,  -314,  -202,  -314,   -67,   -37,   -53,
      70,   -93,  -313,   -80,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
      27,   432,   628,  -314,   629,  -314,  -314,  -314,  -200,   403,
    -314,   411,   -51,   587,  -314,  -314,  -314,  -163,   -92,   -89,
    -314,   343,  -314,   149,  -314,  -314,   477,  -314,    38,  -314,
    -314,   213,  -284,   -82,    -9,    13,  -314,   -95,   -28,   -19,
    -136,    -8,     2,   471
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    29,    30,    31,    32,   168,   169,   170,   171,   172,
     288,   174,   175,   501,   390,   391,    33,    34,   178,   179,
     180,   181,   182,   183,   184,   185,    35,   204,   205,    36,
     218,   219,   220,   392,   393,   375,   376,   222,   223,    37,
     226,   227,   228,   229,   230,   231,   443,   123,   245,   149,
     273,   141,   463,   153,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      74,    54,    55,    56,    57,   277,   258,   491,   259,   260,
     261,   262,    75,    76,    77,    58,   263,    94,    95,    96,
      59,   194,   195,   196,   197,   198,   199,   200,    60,    61,
     354,   355,   377,    62,    63,    64,    65,   378,    66,   379,
     189,   124,    67,   133
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int parser::yytable_ninf_ = -227;
  const short int
  parser::yytable_[] =
  {
       108,   289,   164,   186,   154,   165,    79,   144,   158,    79,
     398,   287,    91,   331,   173,   151,   221,   201,    79,   156,
     157,   142,   299,   341,   340,   395,   166,   224,   150,   313,
     406,   295,   155,   290,    82,     2,   291,   224,   107,   166,
     166,   300,    78,    87,   248,    78,    83,    84,   224,   249,
      68,   250,   109,   166,    78,    88,   464,   358,   466,   235,
     472,   266,   108,   279,   270,   365,     2,   145,     2,   326,
     187,   442,    10,    11,    79,   292,    22,   303,   473,   188,
     160,   293,   186,   304,   440,   125,   167,   225,    18,    19,
      20,    21,    22,   357,   269,   345,   159,   338,   115,   384,
     396,   203,   107,    10,    11,    10,    11,   268,   436,   111,
      78,   201,   202,   470,   275,    79,    79,   147,    79,    79,
     280,   201,   395,   112,    90,   251,   252,   253,   254,   255,
     433,   434,   221,   146,   145,   152,   341,   437,   206,   232,
     236,   237,   265,   239,   240,    92,    93,    79,   452,   187,
     281,    78,    78,   233,    78,    78,   404,    90,   188,   453,
     282,   457,   458,   459,   460,   356,   161,   301,   468,   348,
     302,    22,   107,   351,   510,    72,   162,   512,   264,   469,
     368,   369,   513,    78,   514,   371,   134,   135,   322,   136,
     137,   138,   353,   120,   121,   203,   122,    22,   256,   372,
      27,   257,   163,    73,   187,   203,   316,   186,   173,   186,
     300,   234,   478,   347,   118,   366,   202,   416,   289,   122,
     274,   164,   370,   469,   165,   278,    27,   373,   471,    73,
     477,   524,    92,    93,   482,   526,   201,   201,   201,   201,
     201,   426,   427,   428,   201,   235,   469,   244,   431,   221,
     221,   364,   480,   300,   489,   115,   187,   317,   450,   265,
     318,   145,   492,   418,   187,   164,   187,   265,   165,   300,
     328,   300,   247,   329,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   188,   417,   188,   409,   410,   411,   412,
     413,   414,   267,    92,    93,   264,   336,   118,   119,   120,
     121,   337,   122,   264,   289,   272,   322,   119,   120,   121,
     367,   122,   186,   454,   320,   321,   187,   122,   187,   322,
     203,   203,   203,   203,   203,   140,   333,   445,   203,   334,
     284,   202,   202,   202,   202,   202,   201,   148,   294,   202,
     448,   449,   314,    92,    93,   394,   311,   115,   362,   363,
     364,   122,   327,   312,   483,   326,   394,   364,   487,  -205,
     330,   187,  -205,   265,   265,   265,   265,   206,   490,   342,
     486,   356,   495,   343,   497,   335,   344,   187,   345,   187,
     349,   484,   485,   493,   494,   350,   496,   148,   188,   122,
     291,   508,   509,   118,   119,   120,   121,   394,   122,   264,
     264,   264,   264,   507,   134,   135,   380,   136,   137,   138,
     136,   137,   138,   381,   322,   322,   322,   322,   447,   382,
     203,   322,     2,   451,     2,   176,   302,   383,   518,   519,
     520,   202,   521,   522,   523,    69,   461,    80,    81,   399,
     465,   187,   475,   467,    85,   187,   400,    86,   187,   364,
     364,   364,   364,     2,   401,   402,   265,   104,   479,    10,
      11,    10,    11,   403,   265,   308,   309,   310,   422,   423,
     424,   425,   415,   322,   420,   429,    -2,     1,   444,     2,
    -226,   364,   334,   346,   364,   177,   435,   187,   432,   438,
      10,    11,   264,     2,   176,   439,   455,     3,   456,   139,
     264,     4,   462,     5,     6,   476,     7,   166,     8,    21,
      22,    90,     9,    90,    89,   318,    10,    11,    12,    13,
      14,    15,   498,    16,    17,   224,   502,   500,   503,   505,
      10,    11,    18,    19,    20,    21,    22,    23,   504,    24,
      25,   293,    90,   374,    26,    -3,     1,   238,     2,  -226,
     515,   241,   242,   243,   407,   525,   246,   118,   119,   120,
     121,   516,   122,   517,   110,    27,     3,   481,    28,   285,
       4,   286,     5,     6,   499,     7,   385,     8,     2,   176,
     271,     9,    90,   397,   276,    10,    11,    12,    13,    14,
      15,   527,    16,    17,   296,   283,   319,   320,   321,   474,
     122,    18,    19,    20,    21,    22,    23,   441,    24,    25,
       2,   207,   297,    26,    97,    10,    11,    98,    99,   100,
     101,   102,   298,   208,   209,   210,   211,   305,   306,   307,
     386,   308,   309,   310,    27,   408,   430,    28,   387,   346,
     212,   361,   362,   363,   213,   122,   103,    10,    11,     2,
     207,   332,   339,   105,   106,   214,   215,   216,   388,   143,
     359,   421,   208,   209,   210,   211,   488,    90,   360,   386,
     315,   389,   325,     0,     0,     0,   352,   387,     0,   212,
       0,     0,     0,   213,     0,     0,    10,    11,     2,   207,
       0,     0,     0,     0,   214,   215,   216,   388,     0,    90,
       0,   208,   209,   210,   211,     0,     0,     0,     0,    70,
     405,    71,     0,    22,     2,   207,     0,    72,   212,     0,
       0,     0,   213,     0,     0,    10,    11,   208,   209,   210,
     211,     2,     0,   214,   215,   216,     0,     0,    90,     0,
       0,     2,    27,     0,   212,    73,     0,     0,   213,   346,
       0,    10,    11,     2,     0,     0,     0,   506,     0,   214,
     215,   216,     0,     0,     0,     0,   190,     2,    10,   191,
       0,   118,   319,   320,   321,   405,   122,    90,    10,    11,
       0,     0,     0,     0,    18,    19,    20,    21,    22,   192,
      10,    11,   193,     0,    18,    19,    20,    21,    22,    23,
       0,     0,    25,    90,    10,    11,    18,    19,    20,    21,
      22,   192,     0,     0,   193,     0,     0,    27,     0,   207,
      28,     0,     0,    21,    22,     0,     0,    27,   159,   446,
      28,   208,   209,   210,   211,     0,     0,   113,     0,    27,
     114,     0,    28,   140,     0,   115,   116,     0,   212,     0,
     117,     0,   213,     0,   306,   307,    90,   308,   309,   310,
       0,   511,     0,   214,   215,   216,   118,   119,   120,   121,
     419,   122,     0,     0,     0,   118,   361,   362,   363,   217,
     122,   118,   319,   320,   321,     0,   122,   118,   119,   120,
     121,     0,   122,     0,   126,   127,   128,   129,   130,   131,
     132,   323,   127,   128,   129,   130,   324,   132,   134,   135,
       0,   136,   137,   138,   118,   119,   120,   121,     0,   122,
     118,   319,   320,   321,     0,   122,   118,   361,   362,   363,
       0,   122,   306,   307,     0,   308,   309,   310
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
        28,   167,    94,    98,    84,    94,     4,    74,    88,     7,
     294,   167,    21,   217,    97,    82,   101,    99,    16,    86,
      87,    72,   177,   225,   225,   292,     4,     4,    81,   192,
     303,   177,    85,    66,     7,     3,    69,     4,    25,     4,
       4,   177,     4,    16,   126,     7,     8,     9,     4,   131,
      66,   133,     0,     4,    16,    17,   369,   257,   371,    65,
      46,   141,    90,   156,   146,   265,     3,    75,     3,    75,
      98,   344,    40,    41,    72,    70,    60,    70,    64,    98,
      89,    76,   177,    76,    65,     4,    64,    64,    56,    57,
      58,    59,    60,   256,   145,    76,    64,    64,    34,    64,
      64,    99,    89,    40,    41,    40,    41,   144,    64,    66,
      72,   193,    99,    64,   151,   113,   114,    79,   116,   117,
     157,   203,   389,    66,    92,   134,   135,   136,   137,   138,
     334,   335,   217,    82,   142,    55,   338,   338,   100,    70,
     113,   114,   140,   116,   117,    97,    98,   145,    65,   177,
     159,   113,   114,    65,   116,   117,   302,    92,   177,    76,
      65,   361,   362,   363,   364,   247,     4,    66,    65,   236,
      69,    60,   159,   240,   487,    64,     4,   490,   140,    76,
     273,   274,   495,   145,   497,   278,    91,    92,   196,    94,
      95,    96,   245,    78,    79,   193,    81,    60,    61,   279,
      89,    64,    67,    92,   232,   203,   193,   302,   291,   304,
     346,    65,    65,   232,    76,   268,   203,   312,   384,    81,
     150,   313,   275,    76,   313,   155,    89,   280,   384,    92,
     396,   515,    97,    98,   436,    65,   318,   319,   320,   321,
     322,   323,   324,   325,   326,    65,    76,    22,   330,   334,
     335,   259,   407,   389,   454,    34,   284,    66,   351,   257,
      69,   269,   462,    67,   292,   357,   294,   265,   357,   405,
      66,   407,    64,    69,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   302,   312,   304,   305,   306,   307,   308,
     309,   310,    65,    97,    98,   257,    91,    76,    77,    78,
      79,    96,    81,   265,   470,    52,   314,    77,    78,    79,
     272,    81,   407,    67,    78,    79,   344,    81,   346,   327,
     318,   319,   320,   321,   322,    53,    66,   346,   326,    69,
      64,   318,   319,   320,   321,   322,   418,    20,    64,   326,
     349,   350,   193,    97,    98,   292,    70,    34,    78,    79,
     358,    81,   203,    70,   447,    75,   303,   365,   451,    66,
      82,   389,    69,   361,   362,   363,   364,   329,   461,    66,
     450,   453,   465,    69,   467,    93,    70,   405,    76,   407,
      24,   448,   449,   463,   464,    24,   466,    20,   407,    81,
      69,   484,   485,    76,    77,    78,    79,   344,    81,   361,
     362,   363,   364,   483,    91,    92,    65,    94,    95,    96,
      94,    95,    96,    65,   422,   423,   424,   425,   348,    65,
     418,   429,     3,   353,     3,     4,    69,    65,   508,   509,
     510,   418,   512,   513,   514,     3,   366,     5,     6,    65,
     370,   469,   389,   373,    12,   473,    65,    15,   476,   457,
     458,   459,   460,     3,    65,    65,   454,    25,   405,    40,
      41,    40,    41,    65,   462,    94,    95,    96,   319,   320,
     321,   322,     3,   481,    65,   326,     0,     1,     4,     3,
       4,   489,    69,    64,   492,    64,    57,   515,    65,    65,
      40,    41,   454,     3,     4,    65,    65,    21,    65,    67,
     462,    25,    54,    27,    28,    64,    30,     4,    32,    59,
      60,    92,    36,    92,    64,    69,    40,    41,    42,    43,
      44,    45,   469,    47,    48,     4,   473,     4,    65,   476,
      40,    41,    56,    57,    58,    59,    60,    61,    65,    63,
      64,    76,    92,    62,    68,     0,     1,   115,     3,     4,
      64,   119,   120,   121,    64,    46,   124,    76,    77,    78,
      79,    65,    81,    65,    30,    89,    21,   418,    92,   167,
      25,   167,    27,    28,   470,    30,   291,    32,     3,     4,
     148,    36,    92,   293,   152,    40,    41,    42,    43,    44,
      45,   525,    47,    48,   177,   163,    77,    78,    79,   389,
      81,    56,    57,    58,    59,    60,    61,   343,    63,    64,
       3,     4,   177,    68,     8,    40,    41,    11,    12,    13,
      14,    15,   177,    16,    17,    18,    19,    90,    91,    92,
      23,    94,    95,    96,    89,   304,   329,    92,    31,    64,
      33,    77,    78,    79,    37,    81,    40,    40,    41,     3,
       4,   217,   225,    25,    25,    48,    49,    50,    51,    72,
     257,   318,    16,    17,    18,    19,   453,    92,   257,    23,
     193,    64,   201,    -1,    -1,    -1,   244,    31,    -1,    33,
      -1,    -1,    -1,    37,    -1,    -1,    40,    41,     3,     4,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    -1,    92,
      -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    56,
      64,    58,    -1,    60,     3,     4,    -1,    64,    33,    -1,
      -1,    -1,    37,    -1,    -1,    40,    41,    16,    17,    18,
      19,     3,    -1,    48,    49,    50,    -1,    -1,    92,    -1,
      -1,     3,    89,    -1,    33,    92,    -1,    -1,    37,    64,
      -1,    40,    41,     3,    -1,    -1,    -1,    62,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    38,     3,    40,    41,
      -1,    76,    77,    78,    79,    64,    81,    92,    40,    41,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      40,    41,    64,    -1,    56,    57,    58,    59,    60,    61,
      -1,    -1,    64,    92,    40,    41,    56,    57,    58,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    89,    -1,     4,
      92,    -1,    -1,    59,    60,    -1,    -1,    89,    64,    66,
      92,    16,    17,    18,    19,    -1,    -1,    26,    -1,    89,
      29,    -1,    92,    53,    -1,    34,    35,    -1,    33,    -1,
      39,    -1,    37,    -1,    91,    92,    92,    94,    95,    96,
      -1,    62,    -1,    48,    49,    50,    76,    77,    78,    79,
      65,    81,    -1,    -1,    -1,    76,    77,    78,    79,    64,
      81,    76,    77,    78,    79,    -1,    81,    76,    77,    78,
      79,    -1,    81,    -1,    82,    83,    84,    85,    86,    87,
      88,    82,    83,    84,    85,    86,    87,    88,    91,    92,
      -1,    94,    95,    96,    76,    77,    78,    79,    -1,    81,
      76,    77,    78,    79,    -1,    81,    76,    77,    78,    79,
      -1,    81,    91,    92,    -1,    94,    95,    96
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,     1,     3,    21,    25,    27,    28,    30,    32,    36,
      40,    41,    42,    43,    44,    45,    47,    48,    56,    57,
      58,    59,    60,    61,    63,    64,    68,    89,    92,   102,
     103,   104,   105,   117,   118,   127,   130,   140,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   172,   173,   174,   175,   186,   191,
     199,   200,   204,   205,   206,   207,   209,   213,    66,   172,
      56,    58,    64,    92,   171,   183,   184,   185,   199,   213,
     172,   172,   171,   199,   199,   172,   172,   171,   199,    64,
      92,   205,    97,    98,   188,   189,   190,     8,    11,    12,
      13,    14,    15,    40,   172,   173,   175,   206,   209,     0,
     104,    66,    66,    26,    29,    34,    35,    39,    76,    77,
      78,    79,    81,   148,   212,     4,    82,    83,    84,    85,
      86,    87,    88,   214,    91,    92,    94,    95,    96,   172,
      53,   152,   183,   184,   148,   212,    82,   199,    20,   150,
     150,   148,    55,   154,   154,   150,   148,   148,   154,    64,
     205,     4,     4,    67,   189,   190,     4,    64,   106,   107,
     108,   109,   110,   111,   112,   113,     4,    64,   119,   120,
     121,   122,   123,   124,   125,   126,   208,   209,   210,   211,
      38,    41,    61,    64,   192,   193,   194,   195,   196,   197,
     198,   204,   206,   213,   128,   129,   199,     4,    16,    17,
      18,    19,    33,    37,    48,    49,    50,    64,   131,   132,
     133,   137,   138,   139,     4,    64,   141,   142,   143,   144,
     145,   146,    70,    65,    65,    65,   171,   171,   172,   171,
     171,   172,   172,   172,    22,   149,   172,    64,   204,   204,
     204,   205,   205,   205,   205,   205,    61,    64,   177,   179,
     180,   181,   182,   187,   199,   213,   154,    65,   149,   183,
     204,   172,    52,   151,   151,   149,   172,   176,   151,   152,
     149,   205,    65,   172,    64,   106,   107,   109,   111,   113,
      66,    69,    70,    76,    64,   119,   120,   122,   124,   126,
     211,    66,    69,    70,    76,    90,    91,    92,    94,    95,
      96,    70,    70,   188,   194,   197,   206,    66,    69,    77,
      78,    79,   212,    82,    87,   214,    75,   194,    66,    69,
      82,   131,   132,    66,    69,    93,    91,    96,    64,   142,
     144,   146,    66,    69,    70,    76,    64,   210,   148,    24,
      24,   148,   172,   150,   201,   202,   204,   188,   179,   180,
     182,    77,    78,    79,   212,   179,   150,   199,   152,   152,
     150,   152,   154,   150,    62,   136,   137,   203,   208,   210,
      65,    65,    65,    65,    64,   108,    23,    31,    51,    64,
     115,   116,   134,   135,   136,   139,    64,   112,   203,    65,
      65,    65,    65,    65,   119,    64,   135,    64,   125,   210,
     210,   210,   210,   210,   210,     3,   208,   209,    67,    65,
      65,   192,   194,   194,   194,   194,   204,   204,   204,   194,
     129,   204,    65,   131,   131,    57,    64,   144,    65,    65,
      65,   141,   135,   147,     4,   210,    66,   151,   205,   205,
     152,   151,    65,    76,    67,    65,    65,   179,   179,   179,
     179,   151,    54,   153,   153,   151,   153,   151,    65,    76,
      64,   109,    46,    64,   116,   136,    64,   113,    65,   136,
     126,   194,   146,   152,   148,   148,   154,   152,   202,   179,
     152,   178,   179,   154,   154,   152,   154,   152,   136,   110,
       4,   114,   136,    65,    65,   136,    62,   154,   152,   152,
     153,    62,   153,   153,   153,    64,    65,    65,   154,   154,
     154,   154,   154,   154,   203,    46,    65,   114
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   106,   106,   107,
     107,   108,   108,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     117,   118,   119,   119,   120,   120,   121,   121,   122,   123,
     123,   124,   124,   125,   125,   126,   126,   126,   126,   127,
     128,   128,   129,   129,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   135,   135,   136,   136,   137,   137,
     137,   138,   138,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   140,   141,   141,   142,   142,   143,   143,   144,
     145,   145,   146,   146,   147,   148,   148,   149,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   157,   158,   158,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   167,   168,   168,
     169,   170,   171,   171,   171,   172,   172,   173,   173,   173,
     173,   173,   173,   174,   174,   175,   175,   175,   175,   175,
     176,   177,   178,   179,   179,   180,   180,   180,   180,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   185,   186,   187,   188,   188,   188,   188,   189,   190,
     191,   192,   192,   193,   193,   193,   193,   194,   194,   194,
     195,   195,   195,   195,   195,   195,   196,   196,   197,   197,
     197,   197,   197,   198,   199,   199,   200,   200,   201,   201,
     202,   203,   203,   204,   204,   204,   204,   205,   205,   206,
     206,   206,   206,   206,   206,   206,   206,   207,   207,   208,
     209,   209,   209,   209,   210,   210,   211,   211,   211,   211,
     211,   211,   212,   212,   213,   213,   214,   214,   214,   214,
     214
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     4,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     4,     1,     4,     1,     3,     1,     4,     3,     6,
       5,     4,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     4,     1,     1,     4,
       1,     3,     1,     3,     4,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     7,     7,     7,     9,     3,
       3,     5,     3,     9,     6,     7,     1,     1,     8,     8,
       8,     9,     1,     1,     1,     1,     3,     1,     2,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     3,     1,     3,     1,
       2,     3,     5,     5,     1,     1,     2,     2,     2,     2,
       4,     1,     3,     3,     3,     3,     1,     1,     3,     3,
       1,     2,     3,     3,     3,     3,     1,     3,     1,     3,
       3,     3,     1,     5,     2,     5,     0,     1,     1,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       3,     3,     3,     3,     3,     2,     4,     1,     1,     3,
       1,     1,     1,     2,     1,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "T_INTEGER", "T_IDENTIFIER",
  "T_STRING", "T_ASP", "T_COMMENT", "T_CONSTANTS", "T_INCLUDE", "T_MACROS",
  "T_OBJECTS", "T_QUERY", "T_SHOW", "T_SORTS", "T_VARIABLES", "T_ABACTION",
  "T_ACTION", "T_ADDITIVEACTION", "T_ADDITIVEFLUENT", "T_AFTER",
  "T_ALWAYS", "T_ASSUMING", "T_ATTRIBUTE", "T_BY", "T_CAUSED", "T_CAUSES",
  "T_IMPOSSIBLE", "T_CONSTRAINT", "T_DECREMENTS", "T_DEFAULT",
  "T_DYNAMICAB", "T_EXOGENOUS", "T_EXOGENOUSACTION", "T_IF",
  "T_INCREMENTS", "T_INERTIAL", "T_INERTIALFLUENT", "T_LABEL",
  "T_MAY_CAUSE", "T_MAXADDITIVE", "T_MAXSTEP", "T_NEVER",
  "T_NOCONCURRENCY", "T_STRONG_NOCONCURRENCY", "T_NONEXECUTABLE", "T_OF",
  "T_POSSIBLY_CAUSED", "T_RIGID", "T_SDFLUENT", "T_SIMPLEFLUENT",
  "T_STATICAB", "T_UNLESS", "T_WHEN", "T_FOLLOWING", "T_WHERE", "T_FALSE",
  "T_NONE", "T_TRUE", "T_ABS", "T_AT", "T_BRACKET_L", "T_BRACKET_R",
  "T_COLON_DASH", "T_PAREN_L", "T_PAREN_R", "T_PERIOD", "T_PIPE", "T_NOOP",
  "T_SEMICOLON", "T_DBL_COLON", "T_ARROW_LDASH", "T_ARROW_REQ",
  "T_ARROW_LEQ", "T_ARROW_RDASH", "T_COLON", "T_COMMA", "T_EQUIV",
  "T_IMPL", "T_DBL_PLUS", "T_DBL_AMP", "T_AMP", "T_EQ", "T_GTHAN_EQ",
  "T_EQ_LTHAN", "T_GTHAN", "T_LTHAN", "T_NOT_EQ", "T_DBL_EQ", "T_NOT",
  "T_DBL_PERIOD", "T_PLUS", "T_DASH", "T_DBL_GTHAN", "T_MOD", "T_INT_DIV",
  "T_STAR", "T_BIG_CONJ", "T_BIG_DISJ", "T_POUND", "T_UMINUS", "$accept",
  "program", "statement_sequence", "statement", "constant_statement",
  "constant_spec_outer_tuple", "constant_spec_tuple",
  "constant_outer_spec", "constant_spec", "constant_schema_outer_list",
  "constant_schema_list", "constant_outer_schema", "constant_schema",
  "constant_schema_nodecl", "constant_outer_binder", "constant_binder",
  "maxadditive_statement", "object_statement", "object_spec_outer_tuple",
  "object_spec_tuple", "object_outer_spec", "object_spec",
  "object_outer_schema_list", "object_schema_list", "object_outer_schema",
  "object_schema", "show_statement", "atomic_formula_list",
  "atomic_formula", "sort_statement", "sort_spec_outer_tuple",
  "sort_spec_tuple", "sort_spec", "sort_identifier_with_ab",
  "sort_outer_identifier", "sort_identifier", "sort_identifier_no_range",
  "sort_identifier_name", "sort_constant_name", "variable_statement",
  "variable_spec_outer_tuple", "variable_spec_tuple",
  "variable_outer_spec", "variable_spec", "variable_outer_list",
  "variable_list", "variable_binding", "cl_if_clause",
  "cl_assuming_clause", "cl_after_clause", "cl_unless_clause",
  "cl_when_clause", "cl_following_clause", "cl_where_clause", "causal_law",
  "causal_law_shortcut_forms", "cl_always_forms", "cl_constraint_forms",
  "cl_default_forms", "cl_exogenous_forms", "cl_inertial_forms",
  "cl_nonexecutable_forms", "cl_rigid_forms", "cl_possibly_caused_forms",
  "cl_may_cause_forms", "cl_causes_forms", "cl_noconcurrency_forms",
  "cl_increment_forms", "cl_trivial_forms", "causal_law_basic_forms",
  "cl_head_formula", "cl_body_formula", "cl_body_formula_inner",
  "cl_body_term", "cl_body_term_inner", "cl_where_expr", "cl_when_expr",
  "cl_following_expr", "cl_body_formula_bool",
  "cl_body_formula_bool_inner", "cl_body_term_bool",
  "cl_body_term_bool_inner", "literal_assign_conj",
  "literal_assign_conj_inner", "literal_assign_expr",
  "expr_big_expression", "expr_big_expression_bool",
  "expr_big_quantifiers", "expr_big_conj", "expr_big_disj",
  "query_statement", "query_expression_tuple", "query_expression",
  "query_body_formula", "query_body_formula_inner", "query_body_term",
  "query_body_term_inner", "expr_big_query_expression", "constant_expr",
  "lua_indicator", "parameter_list", "parameter_general",
  "sort_identifier_list", "extended_value_expression",
  "extended_math_expression", "extended_math_expr_inner",
  "extended_math_term", "num_range", "extended_integer",
  "extended_integer_outer_expression", "extended_integer_expression",
  "AND", "NOT", "COMPARISON", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
       102,     0,    -1,    -1,   103,    -1,   104,    -1,   103,   104,
      -1,   105,    -1,   117,    -1,   118,    -1,   191,    -1,   127,
      -1,   130,    -1,   140,    -1,   155,    -1,     1,    66,    -1,
      68,    -1,    63,     8,   106,    66,    -1,   107,    -1,    64,
     107,    65,    -1,   108,    -1,   106,    69,   108,    -1,   109,
      -1,    64,   109,    65,    -1,   110,    70,   115,    -1,   111,
      -1,    64,   111,    65,    -1,   112,    -1,   110,    76,   112,
      -1,   113,    -1,    64,   113,    65,    -1,     4,    -1,     4,
      64,   203,    65,    -1,     4,    -1,     4,    64,   203,    65,
      -1,   116,    -1,    64,   116,    65,    -1,   134,    -1,   139,
      64,   136,    65,    -1,    23,    46,   114,    -1,    23,    64,
     136,    65,    46,   114,    -1,    63,    40,    70,   210,    66,
      -1,    63,    11,   119,    66,    -1,   120,    -1,    64,   120,
      65,    -1,   121,    -1,   119,    69,   119,    -1,   122,    -1,
      64,   122,    65,    -1,   123,    70,   135,    -1,   124,    -1,
      64,   124,    65,    -1,   125,    -1,   123,    76,   125,    -1,
     126,    -1,    64,   126,    65,    -1,     4,    -1,     4,    64,
     203,    65,    -1,   210,    -1,   208,    -1,    63,    13,   128,
      66,    -1,   129,    -1,   128,    69,   129,    -1,   199,    -1,
     199,    82,   204,    -1,    63,    14,   131,    66,    -1,   132,
      -1,    64,   132,    65,    -1,   133,    -1,   131,    69,   131,
      -1,   137,    -1,   137,    93,   131,    -1,   135,    -1,    51,
      -1,    31,    -1,   136,    -1,    64,   136,    65,    -1,   137,
      -1,   208,    -1,   138,    -1,   138,    96,    -1,   138,    91,
      57,    -1,     4,    -1,   139,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1,    33,    -1,    37,    -1,    48,    -1,
      49,    -1,    50,    -1,    63,    15,   141,    66,    -1,   142,
      -1,    64,   142,    65,    -1,   143,    -1,   143,    69,   141,
      -1,   144,    -1,    64,   144,    65,    -1,   145,    70,   147,
      -1,   146,    -1,    64,   146,    65,    -1,     4,    -1,   146,
      76,     4,    -1,   135,    -1,    -1,    34,   172,    -1,    -1,
      22,   172,    -1,    -1,    20,   172,    -1,    -1,    52,   199,
      -1,    -1,    53,   177,    -1,    -1,    54,   178,    -1,    -1,
      55,   176,    -1,   156,    66,    -1,   170,    66,    -1,   157,
      -1,   158,    -1,   159,    -1,   160,    -1,   161,    -1,   162,
      -1,   163,    -1,   164,    -1,   165,    -1,   166,    -1,   167,
      -1,   168,    -1,   169,    -1,    21,   172,   152,   154,    -1,
      28,   172,   150,   151,   152,   153,   154,    -1,    27,   172,
     150,   151,   152,   153,   154,    -1,    42,   172,   150,   151,
     152,   153,   154,    -1,    30,   171,   148,   149,   150,   151,
     152,   153,   154,    -1,    32,   199,   154,    -1,    36,   199,
     154,    -1,    45,   172,   148,   152,   154,    -1,    48,   199,
     154,    -1,    47,   171,   148,   149,   150,   151,   152,   153,
     154,    -1,   172,    39,   171,   148,   152,   154,    -1,   172,
      26,   171,   148,   151,   152,   154,    -1,    43,    -1,    44,
      -1,   172,    35,   171,    24,   205,   148,   152,   154,    -1,
     172,    29,   171,    24,   205,   148,   152,   154,    -1,   172,
     148,   149,   150,   151,   152,   153,   154,    -1,    25,   171,
     148,   149,   150,   151,   152,   153,   154,    -1,   183,    -1,
      58,    -1,    56,    -1,   173,    -1,    64,   173,    65,    -1,
     174,    -1,   213,   172,    -1,   172,   212,   172,    -1,   172,
      79,   172,    -1,   172,    77,   172,    -1,   172,    78,   172,
      -1,   175,    -1,    64,   175,    65,    -1,   204,    -1,   204,
      82,   204,    -1,   204,    87,   204,    -1,   204,   214,   204,
      -1,   186,    -1,   172,    -1,   179,    -1,   179,    -1,   180,
      -1,    64,   180,    65,    -1,   181,    -1,   213,   179,    -1,
     179,   212,   179,    -1,   179,    79,   179,    -1,   179,    77,
     179,    -1,   179,    78,   179,    -1,   182,    -1,    64,   182,
      65,    -1,   199,    -1,   187,    -1,   184,    -1,    64,   184,
      65,    -1,   185,    -1,   183,   212,   183,    -1,   199,    -1,
     213,   199,    -1,   199,    82,   204,    -1,    61,   188,    67,
     172,    62,    -1,    61,   188,    67,   179,    62,    -1,   189,
      -1,   190,    -1,   188,   189,    -1,   188,   190,    -1,    97,
       4,    -1,    98,     4,    -1,    63,    12,   192,    66,    -1,
     193,    -1,   192,    69,   192,    -1,    38,    70,     3,    -1,
      41,    70,   208,    -1,    41,    70,   209,    -1,   194,    -1,
     195,    -1,    64,   194,    65,    -1,   206,    75,   194,    -1,
     196,    -1,   213,   194,    -1,   194,   212,   194,    -1,   194,
      79,   194,    -1,   194,    77,   194,    -1,   194,    78,   194,
      -1,   197,    -1,    64,   197,    65,    -1,   204,    -1,   204,
      82,   204,    -1,   204,    87,   204,    -1,   204,   214,   204,
      -1,   198,    -1,    61,   188,    67,   194,    62,    -1,   200,
       4,    -1,   200,     4,    64,   201,    65,    -1,    -1,    60,
      -1,   202,    -1,   201,    76,   202,    -1,   204,    -1,   136,
      -1,   203,    76,   136,    -1,    58,    -1,    56,    -1,    57,
      -1,   205,    -1,   206,    -1,    64,   206,    65,    -1,   207,
      -1,   205,    91,   205,    -1,   205,    92,   205,    -1,   205,
      96,   205,    -1,   205,    95,   205,    -1,   205,    94,   205,
      -1,    59,   205,    -1,    59,    64,   205,    65,    -1,   209,
      -1,   199,    -1,   210,    90,   210,    -1,     3,    -1,    40,
      -1,    41,    -1,    92,   209,    -1,   211,    -1,    64,   211,
      65,    -1,   209,    -1,   210,    91,   210,    -1,   210,    92,
     210,    -1,   210,    96,   210,    -1,   210,    95,   210,    -1,
     210,    94,   210,    -1,    81,    -1,    76,    -1,    92,    -1,
      89,    -1,    88,    -1,    84,    -1,    83,    -1,    86,    -1,
      85,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
  {
         0,     0,     3,     4,     6,     8,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    30,    32,    37,    39,    43,
      45,    49,    51,    55,    59,    61,    65,    67,    71,    73,
      77,    79,    84,    86,    91,    93,    97,    99,   104,   108,
     115,   121,   126,   128,   132,   134,   138,   140,   144,   148,
     150,   154,   156,   160,   162,   166,   168,   173,   175,   177,
     182,   184,   188,   190,   194,   199,   201,   205,   207,   211,
     213,   217,   219,   221,   223,   225,   229,   231,   233,   235,
     238,   242,   244,   246,   248,   250,   252,   254,   256,   258,
     260,   262,   264,   269,   271,   275,   277,   281,   283,   287,
     291,   293,   297,   299,   303,   305,   306,   309,   310,   313,
     314,   317,   318,   321,   322,   325,   326,   329,   330,   333,
     336,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365,   370,   378,   386,   394,   404,
     408,   412,   418,   422,   432,   439,   447,   449,   451,   460,
     469,   478,   488,   490,   492,   494,   496,   500,   502,   505,
     509,   513,   517,   521,   523,   527,   529,   533,   537,   541,
     543,   545,   547,   549,   551,   555,   557,   560,   564,   568,
     572,   576,   578,   582,   584,   586,   588,   592,   594,   598,
     600,   603,   607,   613,   619,   621,   623,   626,   629,   632,
     635,   640,   642,   646,   650,   654,   658,   660,   662,   666,
     670,   672,   675,   679,   683,   687,   691,   693,   697,   699,
     703,   707,   711,   713,   719,   722,   728,   729,   731,   733,
     737,   739,   741,   745,   747,   749,   751,   753,   755,   759,
     761,   765,   769,   773,   777,   781,   784,   789,   791,   793,
     797,   799,   801,   803,   806,   808,   812,   814,   818,   822,
     826,   830,   834,   836,   838,   840,   842,   844,   846,   848,
     850
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   471,   471,   472,   483,   484,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   501,   509,   512,   513,   516,
     517,   520,   521,   524,   608,   612,   618,   627,   651,   655,
     661,   667,   681,   686,   698,   702,   708,   747,   770,   788,
     862,   879,   882,   883,   886,   887,   890,   891,   894,   969,
     973,   979,   989,  1013,  1017,  1023,  1029,  1036,  1042,  1051,
    1064,  1074,  1088,  1092,  1106,  1117,  1121,  1127,  1132,  1165,
    1175,  1188,  1192,  1197,  1204,  1208,  1216,  1221,  1257,  1261,
    1267,  1276,  1280,  1286,  1291,  1296,  1301,  1306,  1311,  1316,
    1321,  1326,  1335,  1338,  1339,  1342,  1343,  1346,  1347,  1350,
    1370,  1374,  1380,  1416,  1456,  1511,  1512,  1515,  1516,  1519,
    1520,  1523,  1524,  1527,  1528,  1531,  1532,  1535,  1536,  1542,
    1543,  1546,  1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,
    1555,  1556,  1557,  1558,  1562,  1576,  1591,  1606,  1623,  1642,
    1655,  1668,  1683,  1704,  1723,  1739,  1756,  1762,  1770,  1786,
    1804,  1823,  1838,  1842,  1846,  1852,  1856,  1866,  1870,  1874,
    1878,  1882,  1886,  1892,  1896,  1906,  1925,  1930,  1934,  1961,
    1967,  1973,  1979,  1985,  1989,  1999,  2003,  2007,  2011,  2015,
    2019,  2025,  2029,  2039,  2047,  2053,  2057,  2067,  2071,  2077,
    2081,  2085,  2091,  2108,  2123,  2132,  2141,  2173,  2207,  2246,
    2287,  2316,  2320,  2326,  2377,  2396,  2414,  2432,  2436,  2444,
    2464,  2468,  2472,  2476,  2480,  2484,  2490,  2494,  2504,  2523,
    2527,  2531,  2558,  2564,  2581,  2617,  2651,  2652,  2654,  2663,
    2674,  2680,  2701,  2728,  2732,  2736,  2740,  2746,  2750,  2761,
    2765,  2769,  2773,  2777,  2781,  2785,  2789,  2797,  2802,  2808,
    2816,  2821,  2826,  2831,  2840,  2844,  2854,  2858,  2867,  2876,
    2885,  2894,  2906,  2910,  2916,  2920,  2926,  2930,  2934,  2938,
    2942
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 937;
  const int parser::yynnts_ = 114;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 109;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 101;

  const unsigned int parser::yyuser_token_number_max_ = 355;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1141 of lalr1.cc  */
#line 28 "parser.yy"
} } // cplus_parser::details
/* Line 1141 of lalr1.cc  */
#line 4952 "parser.cc"
/* Line 1142 of lalr1.cc  */
#line 2949 "parser.yy"


// Tries to find an existing normal sort or declare a starred ("something*") sort.
Sort* checkDynamicSortDecl(std::string* sortIdent)
{
	Sort* retVal = mainTrans.getSort(*sortIdent);
	// Allow dynamic instantiation of starred sorts.
	if(retVal == NULL && sortIdent->length() > 0 && (*sortIdent)[sortIdent->length()-1] == '*')
	{
		// Verify that the non-starred version exists before instantiating the starred version.
		std::string* nonStarIdent = new std::string;
		(*nonStarIdent) = sortIdent->substr(0, sortIdent->length()-1);
		Sort *nonStarSort = mainTrans.getSort(*nonStarIdent);
		if(nonStarSort == NULL)
		{	
			ltsyystartParseError(ltsyylloc);
			ltsyyossErr << "Sort \"" << *nonStarIdent << "\" not declared, can't dynamically use \"" << *sortIdent << "\" as the domain of another declaration.";
			ltsyyreportError();
		}
		else
		{
			// No need to add unstarred version to subsorts, that's done automatically.
			retVal = mainTrans.addSort(*sortIdent, NULL, true, false);
			if(retVal == NULL)
			{
				ltsyystartParseError(ltsyylloc);
				ltsyyossErr << "Bad domain declaration \"" << *sortIdent << "\".";
				ltsyyreportError();
			}
		}
		deallocateItem(nonStarIdent);
	}
	else if(retVal == NULL)
	{	// The domain isn't an undeclared starred case, it's just undeclared.
		ltsyystartParseError(ltsyylloc);
		ltsyyossErr << "Sort \"" << *sortIdent << "\" not declared, can't use as the domain of another declaration.";
		ltsyyreportError();
	}
	return retVal;
}

// Wraps the given element in two new negation operators to create a "not not (...)" wrap.
SimpleUnaryOperator* createNotNot(ParseElement* elem)
{
	SimpleUnaryOperator* retVal = NULL;
	if(elem != NULL)
	{
		elem->parens(true);
		SimpleUnaryOperator* tempNotNot1 = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, elem);
		SimpleUnaryOperator* tempNotNot2 = new SimpleUnaryOperator(SimpleUnaryOperator::UOP_NOT, tempNotNot1);
		retVal = tempNotNot2;
	}
	return retVal;
}

// Deallocates a "not not" wrapper such that the original ParseElement is not touched, and returns the original ParseElement object.
ParseElement* deallocateNotNot(SimpleUnaryOperator* uop)
{
	ParseElement* retVal = NULL;
	if(uop != NULL)
	{
		SimpleUnaryOperator* inner = ((SimpleUnaryOperator*)(uop->detachPostOp()));
		if(inner != NULL)
		{
		    retVal = inner->detachPostOp();
		    deallocateItem(inner);
		}
	       deallocateItem(uop);
	}
	return retVal;
}

// NULLs elem's preOp and postOp before deallocating so the sub-ParseElement objects don't get caught in the deallocation.
void deallocateTempBinaryOp(SimpleBinaryOperator* &elem)
{
	if(elem != NULL)
	{
		elem->detachPreOp();
		elem->detachPostOp();
		deallocateItem(elem);
	}
}

// NULLs elem's postOp before deallocating so the sub-ParseElement object doesn't get caught in the deallocation.
void deallocateTempUnaryOp(SimpleUnaryOperator* &elem)
{
	if(elem != NULL)
	{
		elem->detachPostOp();
		deallocateItem(elem);
	}
}

// Adds a standard parsing caution header to ltsyyossErr.
void ltsyystartCaution(YYLTYPE cautionLoc)
{
	ltsyyossErr << "Caution, ";
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\", ";
		}
		ltsyyossErr << "Line #" << cautionLoc.first_line << "." << cautionLoc.first_column << ": ";
	*/
}

// Adds a standard (location-unaware) parsing caution header to ltsyyossErr.
void ltsyystartCaution()
{
	ltsyyossErr << "Caution, ";
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\"";
		}
		ltsyyossErr << ": ";
	*/
}

// Caution reporting function for the parser.
void ltsyycaution()
{
	if(ltsyyossErr.str() == "")
	{
		ltsyystartCaution(ltsyylloc);
		ltsyyossErr << "Using \"" << ltsyytext << "\" here may not be a good idea.";
	}
	mainTrans.caution(ltsyyossErr.str(), true);
	LTSYYRESETOSS;
}

// Adds a standard parsing warning header to ltsyyossErr.
void ltsyystartWarning(YYLTYPE warningLoc)
{
	ltsyyossErr << "Warning, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\", ";
		}
		ltsyyossErr << "Line #" << warningLoc.first_line << "." << warningLoc.first_column << ": ";
	*/
}

// Adds a standard (location-unaware) parsing warning header to ltsyyossErr.
void ltsyystartWarning()
{
	ltsyyossErr << "Warning, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\"";
		}
		ltsyyossErr << ": ";
	*/
}

// Warning reporting function for the parser.
void ltsyywarning()
{
	if(ltsyyossErr.str() == "")
	{
		ltsyystartWarning(ltsyylloc);
		ltsyyossErr << "Using \"" << ltsyytext << "\" here will probably break something.";
	}
	mainTrans.warn(ltsyyossErr.str(), true);
	LTSYYRESETOSS;
}

// Adds a standard parse error header to ltsyyossErr to make it easier to report errors in actions.
void ltsyystartParseError(YYLTYPE errLoc)
{
	ltsyyossErr << "Parse Error, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\", ";
		}
		ltsyyossErr << "Line #" << errLoc.first_line << "." << errLoc.first_column << ": ";
	*/
}

// Adds a standard (location-unaware) parse error header to ltsyyossErr to make it easier to report errors in actions.
void ltsyystartParseError()
{
	ltsyyossErr << "Parse Error, ";
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\"";
		}
		ltsyyossErr << ": ";
	*/
}

// Adds a standard syntax error header to ltsyyossErr to make it easier to report errors in actions.
void ltsyystartSyntaxError(YYLTYPE errLoc)
{
	ltsyyossErr << "Syntax Error, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\", ";
		}
		ltsyyossErr << "Line #" << errLoc.first_line << "." << errLoc.first_column << ": ";
	*/
}

// Adds a standard (location-unaware) syntax error header to ltsyyossErr to make it easier to report errors in actions.
void ltsyystartSyntaxError()
{
	ltsyyossErr << "Syntax Error, ";
	
	/* This is now handled in the translator error reporting function...
		if(ltsyyFileName != "")
		{
			ltsyyossErr << "File \"" << ltsyyFileName << "\"";
		}
		ltsyyossErr << ": ";
	*/
}

// Error reporting function for the bison parser.
void ltsyyerror(char const* msg)
{
	if(ltsyyossErr.str() == "")
	{
		ltsyystartSyntaxError(ltsyylloc);
		ltsyyossErr << "Unexpected token \"" << ltsyytext << "\".";
	}
	mainTrans.error(ltsyyossErr.str(), true);
	LTSYYRESETOSS;

	// If the translator's temporary query appears to have been partially populated, destroy it and create another in its place.
	if(mainTrans.tempQuery != NULL && (mainTrans.tempQuery->label != "" || mainTrans.tempQuery->maxstep != "" || !(mainTrans.tempQuery->queryConditions.empty())))
	{
		mainTrans.allocateNewTempQuery(true);
	}
	if(mainTrans.tempQuery == NULL)
	{
		mainTrans.allocateNewTempQuery();
	}
}

// Wraps caution reporting for convenience and unification with convention for error reporting.
void ltsyyreportCaution()
{
	ltsyycaution();
}
// Wraps warning reporting for convenience and unification with convention for error reporting.
void ltsyyreportWarning()
{
	ltsyywarning();
}
// Wraps error reporting for ease and to ensure the number of errors gets incremented with each (action-generated) error report.
void ltsyyreportError()
{
	ltsyynerrs++;
	ltsyyerror("");
}

//Retreives the name of the current file the parser is working with.
std::string ltsyyGetFileName() { 
  char* fn = strdup(ltsyyFileName.c_str());
  std::string res = std::string(basename(fn));
  free(fn);
  return res;
}

// Retrieves the current location of the parser.
YYLTYPE ltsyyGetLoc() { return ltsyylloc; }
