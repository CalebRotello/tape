// A Bison parser, made by GNU Bison 3.7.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "Parser.hh"


// Unqualified %code blocks.
#line 25 "/home/espresso/projects/tape/src/Bison/parser.yy"

    #include "Driver.hh"

#line 50 "../src/../src/Parser/Parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
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
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "/home/espresso/projects/tape/src/Bison/parser.yy"
namespace yy {
#line 143 "../src/../src/Parser/Parser.cc"

  /// Build a parser object.
  Parser::Parser (Driver *driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign_op: // assign_op
      case symbol_kind::S_unary_op: // unary_op
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign_op: // assign_op
      case symbol_kind::S_unary_op: // unary_op
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_assign_op: // assign_op
      case symbol_kind::S_unary_op: // unary_op
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.move< char > (that.value);
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.move< float > (that.value);
        break;

      case symbol_kind::S_assign_op: // assign_op
      case symbol_kind::S_unary_op: // unary_op
        value.move< int > (that.value);
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_EQ: // "="
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 399 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PLUS: // "+"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 405 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MINUS: // "-"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 411 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AT: // "@"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 417 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP: // "&"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 423 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE: // "|"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 429 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FSLASH: // "/"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 435 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STAR: // "*"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 441 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MOD: // "%"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 447 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LPAREN: // "("
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 453 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RPAREN: // ")"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 459 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LSQUARE: // "["
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 465 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RSQUARE: // "]"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 471 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LBRACE: // "{"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 477 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RBRACE: // "}"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 483 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_SC: // ";"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 489 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LT: // "<"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 495 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_GT: // ">"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 501 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_COLON: // ":"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 507 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CARROT: // "^"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 513 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_COMMA: // ","
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 519 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_QUESTION: // "?"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 525 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_DOT: // "."
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 531 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BANG: // "!"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 537 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TILDE: // "~"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 543 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
#line 29 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < long long > (); }
#line 549 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
#line 29 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < float > (); }
#line 555 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
#line 29 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 561 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
#line 29 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < char > (); }
#line 567 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
#line 29 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < bool > (); }
#line 573 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ID: // ID
#line 29 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 579 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_POINTER: // POINTER
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 585 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_INCREMENT: // INCREMENT
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 591 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_DECREMENT: // DECREMENT
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 597 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LEFT: // LEFT
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 603 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RIGHT: // RIGHT
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 609 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP_AMP: // AMP_AMP
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 615 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE_PIPE: // PIPE_PIPE
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 621 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STAR_EQ: // STAR_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 627 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FSLASH_EQ: // FSLASH_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 633 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MOD_EQ: // MOD_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 639 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PLUS_EQ: // PLUS_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 645 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MINUS_EQ: // MINUS_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 651 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LEFT_EQ: // LEFT_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 657 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RIGHT_EQ: // RIGHT_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 663 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP_EQ: // AMP_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 669 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CARROT_EQ: // CARROT_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 675 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE_EQ: // PIPE_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 681 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LT_EQ: // LT_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 687 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_GT_EQ: // GT_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 693 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_EQ_EQ: // EQ_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 699 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BANG_EQ: // BANG_EQ
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 705 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_IF: // IF
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 711 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 717 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FN: // FN
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 723 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LET: // LET
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 729 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_VAR: // VAR
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 735 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TYPE: // TYPE
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 741 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 747 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FOR: // FOR
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 753 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 759 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MATCH: // MATCH
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 765 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 771 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CONTINUE: // CONTINUE
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 777 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 783 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I8: // I8
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 789 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I16: // I16
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 795 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I32: // I32
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 801 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I64: // I64
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 807 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_F32: // F32
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 813 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_F64: // F64
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 819 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_74_: // "->"
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 825 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_program: // program
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 831 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_global_declaration: // global_declaration
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 837 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 843 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_declaration: // type_declaration
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 849 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_declaration_list: // type_declaration_list
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 855 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_declaration_member: // type_declaration_member
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 861 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_type: // declaration_type
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 867 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_mods: // type_mods
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 873 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_mod: // type_mod
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 879 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type: // type
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 885 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration: // declaration
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 891 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_specification: // declaration_specification
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 897 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_hypothesis: // declaration_hypothesis
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 903 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_function_declaration: // function_declaration
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 909 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_parameter_list: // parameter_list
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 915 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement_list: // statement_list
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 921 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement: // statement
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 927 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement_box: // statement_box
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 933 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_iteration_statement: // iteration_statement
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 939 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_flow_statement: // flow_statement
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 945 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_conditional_statement: // conditional_statement
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 951 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_expression_statement: // expression_statement
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 957 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_initializer: // initializer
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 963 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_initializer_list: // initializer_list
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 969 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_expression: // expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 975 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_constant_expression: // constant_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 981 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_conditional_expression: // conditional_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 987 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 993 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_atomic_expression: // atomic_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 999 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1005 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1011 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_unary_expression: // unary_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1017 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1023 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_additive_expression: // additive_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1029 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_relational_expression: // relational_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1035 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_equality_expression: // equality_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1041 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_logical_expression: // logical_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1047 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_match_expression: // match_expression
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1053 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_pattern_list: // pattern_list
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1059 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_pattern: // pattern
#line 30 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1065 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_assign_op: // assign_op
#line 29 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1071 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_unary_op: // unary_op
#line 29 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1077 "../src/../src/Parser/Parser.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    /// Discard the LAC context in case there still is one left from a
    /// previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
           goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
           goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_assign_op: // assign_op
      case symbol_kind::S_unary_op: // unary_op
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 107: // assign_op: "="
#line 334 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_EQ;          }
#line 1366 "../src/../src/Parser/Parser.cc"
    break;

  case 108: // assign_op: PLUS_EQ
#line 335 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_PLUS_EQ;     }
#line 1372 "../src/../src/Parser/Parser.cc"
    break;

  case 109: // assign_op: MINUS_EQ
#line 336 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_MINUS_EQ;    }
#line 1378 "../src/../src/Parser/Parser.cc"
    break;

  case 110: // assign_op: STAR_EQ
#line 337 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_STAR_EQ;     }
#line 1384 "../src/../src/Parser/Parser.cc"
    break;

  case 111: // assign_op: FSLASH_EQ
#line 338 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_FSLASH_EQ;   }
#line 1390 "../src/../src/Parser/Parser.cc"
    break;

  case 112: // assign_op: MOD_EQ
#line 339 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_MOD_EQ;      }
#line 1396 "../src/../src/Parser/Parser.cc"
    break;

  case 113: // unary_op: "!"
#line 343 "/home/espresso/projects/tape/src/Bison/parser.yy"
        { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_BANG;    }
#line 1402 "../src/../src/Parser/Parser.cc"
    break;

  case 114: // unary_op: "@"
#line 344 "/home/espresso/projects/tape/src/Bison/parser.yy"
        { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_AT;      }
#line 1408 "../src/../src/Parser/Parser.cc"
    break;

  case 115: // unary_op: "&"
#line 345 "/home/espresso/projects/tape/src/Bison/parser.yy"
        { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_AMP;     }
#line 1414 "../src/../src/Parser/Parser.cc"
    break;

  case 116: // unary_op: "-"
#line 346 "/home/espresso/projects/tape/src/Bison/parser.yy"
        { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_MINUS;   }
#line 1420 "../src/../src/Parser/Parser.cc"
    break;

  case 117: // unary_op: "~"
#line 347 "/home/espresso/projects/tape/src/Bison/parser.yy"
        { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_TILDE;   }
#line 1426 "../src/../src/Parser/Parser.cc"
    break;


#line 1430 "../src/../src/Parser/Parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "=", "+", "-", "@", "&", "|",
  "/", "*", "%", "(", ")", "[", "]", "{", "}", ";", "<", ">", ":", "^",
  ",", "?", ".", "!", "~", "INT_VAL", "FLOAT_VAL", "STRING_VAL",
  "CHAR_VAL", "BOOL_VAL", "ID", "POINTER", "INCREMENT", "DECREMENT",
  "LEFT", "RIGHT", "AMP_AMP", "PIPE_PIPE", "STAR_EQ", "FSLASH_EQ",
  "MOD_EQ", "PLUS_EQ", "MINUS_EQ", "LEFT_EQ", "RIGHT_EQ", "AMP_EQ",
  "CARROT_EQ", "PIPE_EQ", "LT_EQ", "GT_EQ", "EQ_EQ", "BANG_EQ", "IF",
  "ELSE", "FN", "LET", "VAR", "TYPE", "RETURN", "FOR", "WHILE", "MATCH",
  "BREAK", "CONTINUE", "TYPE_NAME", "I8", "I16", "I32", "I64", "F32",
  "F64", "->", "$accept", "program", "global_declaration",
  "variable_declaration", "type_declaration", "type_declaration_list",
  "type_declaration_member", "declaration_type", "type_mods", "type_mod",
  "type", "declaration", "declaration_specification",
  "declaration_hypothesis", "function_declaration", "parameter_list",
  "statement_list", "statement", "statement_box", "iteration_statement",
  "flow_statement", "conditional_statement", "expression_statement",
  "initializer", "initializer_list", "expression", "constant_expression",
  "conditional_expression", "assignment_expression", "atomic_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_expression",
  "match_expression", "pattern_list", "pattern", "assign_op", "unary_op", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }


  bool
  Parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  Parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (!yy_lac_established_)
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
    return true;
  }

  // Discard any previous initial lookahead context.
  void
  Parser::yy_lac_discard_ (const char* evt)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << evt << '\n';
        yy_lac_established_ = false;
      }
  }

  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short Parser::yypact_ninf_ = -158;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      30,   -19,  -158,  -158,     5,    18,  -158,    26,    53,    43,
      40,  -158,    70,    52,  -158,  -158,  -158,  -158,   289,    65,
    -158,    40,    27,  -158,  -158,  -158,   250,   289,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,   364,   364,  -158,  -158,
    -158,  -158,  -158,    91,     9,   113,    37,   -12,    -5,    77,
     364,   -44,  -158,    71,    95,    81,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,   250,  -158,    97,  -158,  -158,  -158,    -2,
    -158,  -158,   321,   250,    78,    80,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   364,   364,   250,  -158,  -158,    40,
      65,  -158,  -158,    87,    92,    22,   112,  -158,  -158,   289,
    -158,  -158,     7,  -158,   114,  -158,  -158,  -158,  -158,  -158,
    -158,   113,   113,    37,    37,    37,    37,   -12,   -12,   115,
      22,  -158,    17,  -158,    81,  -158,   353,  -158,   250,  -158,
    -158,   364,  -158,   250,   170,  -158,  -158,  -158,  -158,   119,
      63,    -1,  -158,  -158,  -158,   132,   250,   133,   134,   131,
     142,   145,   126,  -158,  -158,  -158,  -158,  -158,  -158,   146,
    -158,   170,  -158,   250,   250,   148,   211,   250,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,   137,  -158,   211,   154,
     170,   250,   170,   116,   155,  -158,   170,   170,  -158,  -158
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,    30,    31,     0,     0,     2,     0,     0,     8,
       0,     5,     0,     0,     1,     3,     4,     6,     0,    15,
      28,    34,     0,   116,   114,   115,     0,     0,   113,   117,
      67,    70,    71,    68,    69,    66,     0,     0,     7,    64,
      61,    55,    73,    83,    87,    91,    94,    99,   102,    63,
       0,     0,    29,    35,     0,     0,    27,    22,    23,    24,
      25,    26,    17,     0,    58,     0,    60,    59,    56,     0,
      84,    85,     0,     0,     0,     0,    79,    80,   107,   110,
     111,   112,   108,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    17,    34,
      15,    14,    13,     0,    11,     9,     0,    72,    54,     0,
      75,    81,     0,    87,     0,    77,    78,    65,    89,    88,
      90,    92,    93,    95,    96,    97,    98,   100,   101,     0,
      16,    36,     0,    10,     0,    19,     0,    18,     0,    57,
      76,     0,    74,     0,     0,    33,    32,    12,    20,     0,
       0,     0,   104,    82,    62,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    39,    43,    42,    40,    41,     0,
      21,     0,   103,     0,     0,     0,     0,     0,    48,    49,
      53,    44,    38,    52,   106,   105,     0,    47,     0,     0,
       0,     0,     0,    50,     0,    46,     0,     0,    51,    45
  };

  const short
  Parser::yypgoto_[] =
  {
    -158,  -158,   164,     1,   -51,    36,  -158,    73,    76,  -158,
     120,  -158,   168,  -158,    29,    94,  -158,   -90,    47,  -158,
    -158,  -158,  -157,   -24,  -158,   -26,   -67,  -158,   -16,  -158,
    -158,  -158,   -27,    -9,    28,    -3,  -158,  -158,  -158,  -158,
      21,  -158,  -158
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,   161,     8,   103,   104,    52,   105,   137,
      62,     9,    53,    10,    64,    54,   162,   163,   164,   165,
     166,   167,   168,    38,    69,   169,    39,    40,    66,    42,
      43,   112,    44,    45,    46,    47,    48,    49,    67,   151,
     152,    84,    50
  };

  const unsigned char
  Parser::yytable_[] =
  {
      65,     7,    41,    68,   102,   111,     7,    90,    91,    70,
      71,    41,    78,    56,    12,   108,   172,   117,    14,   188,
     140,   109,   173,    97,    57,    58,    59,    60,    61,    11,
     141,   191,   135,   144,    11,   145,   136,   106,    13,    92,
      93,    88,    89,    55,    16,   113,    18,   114,    94,    95,
      79,    80,    81,    82,    83,    22,   101,   113,   118,   119,
     120,   113,   113,   113,   113,   113,   113,   113,   113,   149,
     129,    17,   182,    19,   153,     1,     2,     3,     4,   121,
     122,   184,    21,   102,    56,   139,    51,     1,     2,     3,
       4,   127,   128,    41,    99,    57,    58,    59,    60,    61,
     193,    96,   195,    72,   133,    73,   198,   199,   100,   113,
     107,   115,   150,   116,   113,   134,    74,   154,   123,   124,
     125,   126,    85,    86,    87,    75,    76,    77,   138,   142,
     175,    23,    24,    25,   170,   101,   143,   171,    26,     2,
       3,     4,   144,   181,   174,   176,   177,   150,   186,   178,
     190,   189,    28,    29,    30,    31,    32,    33,    34,    35,
     179,    36,    37,   180,   183,   194,   187,   192,   197,    15,
     147,    98,   196,   132,   130,    23,    24,    25,    20,   146,
       0,   155,    26,     1,     2,     3,   144,   156,   157,   158,
      63,   159,   160,   131,   185,     0,    28,    29,    30,    31,
      32,    33,    34,    35,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,     0,
       0,     0,     0,    26,     0,   155,     0,     1,     2,     3,
       0,   156,   157,   158,    63,   159,   160,    28,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     1,     2,
       3,     0,     0,     0,     0,    63,    28,    29,    30,    31,
      32,    33,    34,    35,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,     0,     0,     0,
       0,    26,     0,     0,     0,    27,     0,     1,     0,     0,
       0,     0,     0,     0,    63,    28,    29,    30,    31,    32,
      33,    34,    35,     0,    36,    37,    23,    24,    25,     0,
       0,     0,     0,    26,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,    23,    24,
      25,     0,     0,     0,     0,    26,     0,     0,   148,    23,
      24,    25,     0,     0,     0,     0,    26,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,     0,    36,    37,
      28,    29,    30,    31,    32,    33,    34,    35,     0,    36,
      37
  };

  const short
  Parser::yycheck_[] =
  {
      26,     0,    18,    27,    55,    72,     5,    19,    20,    36,
      37,    27,     3,    57,    33,    17,    17,    84,     0,   176,
      13,    23,    23,    50,    68,    69,    70,    71,    72,     0,
      23,   188,    10,    16,     5,    18,    14,    63,    33,    51,
      52,     4,     5,    16,    18,    72,     3,    73,    53,    54,
      41,    42,    43,    44,    45,     3,    55,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,   136,
      96,    18,   162,    33,   141,    57,    58,    59,    60,    88,
      89,   171,    12,   134,    57,   109,    21,    57,    58,    59,
      60,    94,    95,   109,    23,    68,    69,    70,    71,    72,
     190,    24,   192,    12,    17,    14,   196,   197,    13,   136,
      13,    33,   138,    33,   141,    23,    25,   143,    90,    91,
      92,    93,     9,    10,    11,    34,    35,    36,    16,    15,
     156,     5,     6,     7,    15,   134,    21,    74,    12,    58,
      59,    60,    16,    17,    12,    12,    12,   173,   174,    18,
      13,   177,    26,    27,    28,    29,    30,    31,    32,    33,
      18,    35,    36,    18,    18,   191,    18,    13,    13,     5,
     134,    51,    56,   100,    98,     5,     6,     7,    10,   132,
      -1,    55,    12,    57,    58,    59,    16,    61,    62,    63,
      64,    65,    66,    99,   173,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    -1,    55,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    16,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    15,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    57,    58,    59,    60,    76,    77,    78,    79,    86,
      88,    89,    33,    33,     0,    77,    18,    18,     3,    33,
      87,    12,     3,     5,     6,     7,    12,    16,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    98,   101,
     102,   103,   104,   105,   107,   108,   109,   110,   111,   112,
     117,    21,    82,    87,    90,    16,    57,    68,    69,    70,
      71,    72,    85,    64,    89,   100,   103,   113,    98,    99,
     107,   107,    12,    14,    25,    34,    35,    36,     3,    41,
      42,    43,    44,    45,   116,     9,    10,    11,     4,     5,
      19,    20,    51,    52,    53,    54,    24,   107,    85,    23,
      13,    78,    79,    80,    81,    83,   100,    13,    17,    23,
      13,   101,   106,   107,   100,    33,    33,   101,   107,   107,
     107,   108,   108,   109,   109,   109,   109,   110,   110,   100,
      83,    90,    82,    17,    23,    10,    14,    84,    16,    98,
      13,    23,    15,    21,    16,    18,    93,    80,    15,   101,
     100,   114,   115,   101,   100,    55,    61,    62,    63,    65,
      66,    78,    91,    92,    93,    94,    95,    96,    97,   100,
      15,    74,    17,    23,    12,   100,    12,    12,    18,    18,
      18,    17,    92,    18,    92,   115,   100,    18,    97,   100,
      13,    97,    13,    92,   100,    92,    56,    13,    92,    92
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    75,    76,    76,    77,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    84,    85,    85,    85,    85,    85,    85,    86,    87,
      88,    88,    89,    89,    90,    90,    90,    91,    91,    92,
      92,    92,    92,    92,    93,    94,    94,    95,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   107,   107,   107,   107,   108,   108,   108,
     108,   109,   109,   109,   110,   110,   110,   110,   110,   111,
     111,   111,   112,   113,   114,   114,   115,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   117,   117
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     2,     3,     1,     5,
       6,     1,     3,     1,     1,     0,     3,     0,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     7,     7,     0,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     3,     7,     5,     3,     2,     2,
       5,     7,     2,     2,     3,     1,     1,     3,     1,     1,
       1,     1,     5,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     3,     4,     3,     3,     2,
       2,     1,     3,     1,     2,     2,     2,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     5,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
  };




#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   101,   101,   102,   106,   107,   108,   112,   113,   117,
     118,   122,   123,   127,   128,   133,   134,   138,   139,   143,
     144,   145,   149,   149,   149,   149,   149,   149,   154,   158,
     162,   162,   165,   166,   170,   171,   172,   178,   179,   183,
     184,   185,   186,   187,   191,   195,   196,   200,   201,   202,
     206,   207,   211,   212,   216,   217,   221,   222,   227,   228,
     229,   233,   237,   238,   242,   243,   247,   248,   249,   250,
     251,   252,   253,   257,   258,   259,   260,   261,   262,   263,
     264,   268,   269,   273,   274,   275,   276,   281,   282,   283,
     284,   288,   289,   290,   294,   295,   296,   297,   298,   302,
     303,   304,   308,   321,   325,   326,   330,   334,   335,   336,
     337,   338,   339,   343,   344,   345,   346,   347
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 6 "/home/espresso/projects/tape/src/Bison/parser.yy"
} // yy
#line 2176 "../src/../src/Parser/Parser.cc"

#line 350 "/home/espresso/projects/tape/src/Bison/parser.yy"
 

void yy::Parser::error(const location_type &loc, const std::string &msg) {
    std::cerr << loc << ": " << msg << std::endl;
}
