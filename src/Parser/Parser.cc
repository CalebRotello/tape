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
#line 28 "/home/espresso/projects/tape/src/Bison/parser.yy"

    #include "Driver.hh"
    #include "../Ast/AstExpression.hh"
    StatementList whole_program;

#line 52 "../src/../src/Parser/Parser.cc"


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

#line 7 "/home/espresso/projects/tape/src/Bison/parser.yy"
namespace yy {
#line 145 "../src/../src/Parser/Parser.cc"

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
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.YY_MOVE_OR_COPY< FunctionDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
        value.YY_MOVE_OR_COPY< ObjDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_global_declaration: // global_declaration
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
        value.YY_MOVE_OR_COPY< VarDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
      case symbol_kind::S_unary_operator: // unary_operator
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.YY_MOVE_OR_COPY< std::vector<Expression*>* > (YY_MOVE (that.value));
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
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< FunctionDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
        value.move< ObjDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_global_declaration: // global_declaration
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
        value.move< VarDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<Expression*>* > (YY_MOVE (that.value));
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
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        value.copy< Expression* > (that.value);
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.copy< FunctionDecl* > (that.value);
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
        value.copy< ObjDecl* > (that.value);
        break;

      case symbol_kind::S_global_declaration: // global_declaration
        value.copy< Statement* > (that.value);
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
        value.copy< VarDecl* > (that.value);
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.copy< std::vector<Expression*>* > (that.value);
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
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        value.move< Expression* > (that.value);
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< FunctionDecl* > (that.value);
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
        value.move< ObjDecl* > (that.value);
        break;

      case symbol_kind::S_global_declaration: // global_declaration
        value.move< Statement* > (that.value);
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
        value.move< VarDecl* > (that.value);
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.move< char > (that.value);
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.move< float > (that.value);
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< int > (that.value);
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<Expression*>* > (that.value);
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
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 565 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PLUS: // "+"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 571 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MINUS: // "-"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 577 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AT: // "@"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 583 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP: // "&"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 589 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE: // "|"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 595 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FSLASH: // "/"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 601 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STAR: // "*"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 607 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MOD: // "%"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 613 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LPAREN: // "("
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 619 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RPAREN: // ")"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 625 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LSQUARE: // "["
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 631 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RSQUARE: // "]"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 637 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LBRACE: // "{"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 643 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RBRACE: // "}"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 649 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_SC: // ";"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 655 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LT: // "<"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 661 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_GT: // ">"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 667 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_COLON: // ":"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 673 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CARROT: // "^"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 679 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_COMMA: // ","
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 685 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_QUESTION: // "?"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 691 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_DOT: // "."
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 697 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BANG: // "!"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 703 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TILDE: // "~"
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 709 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < long long > (); }
#line 715 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < float > (); }
#line 721 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 727 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < char > (); }
#line 733 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < bool > (); }
#line 739 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 745 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ID: // ID
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 751 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_POINTER: // POINTER
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 757 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_INCREMENT: // INCREMENT
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 763 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_DECREMENT: // DECREMENT
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 769 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LEFT: // LEFT
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 775 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RIGHT: // RIGHT
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 781 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP_AMP: // AMP_AMP
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 787 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE_PIPE: // PIPE_PIPE
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 793 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STAR_EQ: // STAR_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 799 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FSLASH_EQ: // FSLASH_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 805 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MOD_EQ: // MOD_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 811 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PLUS_EQ: // PLUS_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 817 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MINUS_EQ: // MINUS_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 823 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LEFT_EQ: // LEFT_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 829 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RIGHT_EQ: // RIGHT_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 835 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP_EQ: // AMP_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 841 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CARROT_EQ: // CARROT_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 847 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE_EQ: // PIPE_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 853 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LT_EQ: // LT_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 859 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_GT_EQ: // GT_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 865 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_EQ_EQ: // EQ_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 871 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BANG_EQ: // BANG_EQ
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 877 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TYPEDEF: // TYPEDEF
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 883 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_EXTERN: // EXTERN
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 889 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STATIC: // STATIC
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 895 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AUTO: // AUTO
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 901 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_REGISTER: // REGISTER
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 907 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_SIZEOF: // SIZEOF
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 913 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CHAR: // CHAR
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 919 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_SIGNED: // SIGNED
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 925 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_UNSIGNED: // UNSIGNED
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 931 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CONST: // CONST
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 937 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_VOLATILE: // VOLATILE
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 943 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_VOID: // VOID
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 949 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BOOL: // BOOL
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 955 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LAMBDA: // LAMBDA
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 961 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I8: // I8
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 967 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I16: // I16
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 973 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I32: // I32
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 979 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I64: // I64
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 985 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_F32: // F32
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 991 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_F64: // F64
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 997 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1003 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_UNION: // UNION
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1009 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ENUM: // ENUM
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1015 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ELLIPSIS: // ELLIPSIS
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1021 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FN: // FN
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1027 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LET: // LET
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1033 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CASE: // CASE
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1039 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_DEFAULT: // DEFAULT
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1045 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_IF: // IF
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1051 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1057 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_SWITCH: // SWITCH
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1063 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1069 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FOR: // FOR
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1075 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CONTINUE: // CONTINUE
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1081 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1087 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1093 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_program: // program
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1099 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_global_declaration: // global_declaration
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Statement* > (); }
#line 1105 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_function_definition: // function_definition
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < FunctionDecl* > (); }
#line 1111 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_parameter_list: // parameter_list
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1117 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_parameter: // parameter
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1123 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_list: // declaration_list
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1129 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration: // declaration
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1135 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < ObjDecl* > (); }
#line 1141 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_id_list: // id_list
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1147 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_struct_or_union: // struct_or_union
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1153 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_specifier: // declaration_specifier
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1159 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_suffix_list: // type_suffix_list
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1165 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_suffix: // type_suffix
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1171 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_name: // type_name
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1177 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_qualifier: // type_qualifier
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1183 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_initializer: // initializer
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1189 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_initializer_list: // initializer_list
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1195 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement_list: // statement_list
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1201 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement: // statement
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1207 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_conditional_statement: // conditional_statement
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1213 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_compound_statement: // compound_statement
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1219 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_labeled_statement: // labeled_statement
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1225 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_jump_statement: // jump_statement
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1231 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_expression_statement: // expression_statement
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1237 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < VarDecl* > (); }
#line 1243 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_switch_statement: // switch_statement
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1249 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_iteration_statement: // iteration_statement
#line 35 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << "<>"; }
#line 1255 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_atomic_expression: // atomic_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1261 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1267 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < std::vector<Expression*>* > (); }
#line 1273 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_unary_expression: // unary_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1279 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_cast_expression: // cast_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1285 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1291 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_additive_expression: // additive_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1297 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_shift_expression: // shift_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1303 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_relational_expression: // relational_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1309 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_equality_expression: // equality_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1315 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_and_expression: // and_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1321 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1327 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1333 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1339 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_logical_or_expression: // logical_or_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1345 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_conditional_expression: // conditional_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1351 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1357 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_expression: // expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1363 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_constant_expression: // constant_expression
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 1369 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1375 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_unary_operator: // unary_operator
#line 34 "/home/espresso/projects/tape/src/Bison/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1381 "../src/../src/Parser/Parser.cc"
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
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
        yylhs.value.emplace< Expression* > ();
        break;

      case symbol_kind::S_function_definition: // function_definition
        yylhs.value.emplace< FunctionDecl* > ();
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
        yylhs.value.emplace< ObjDecl* > ();
        break;

      case symbol_kind::S_global_declaration: // global_declaration
        yylhs.value.emplace< Statement* > ();
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
        yylhs.value.emplace< VarDecl* > ();
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
      case symbol_kind::S_unary_operator: // unary_operator
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        yylhs.value.emplace< std::vector<Expression*>* > ();
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
  case 2: // program: global_declaration
#line 109 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                    { whole_program = std::vector<Statement*>(); whole_program.push_back(yystack_[0].value.as < Statement* > ()); }
#line 1711 "../src/../src/Parser/Parser.cc"
    break;

  case 3: // program: program global_declaration
#line 110 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                    { whole_program.push_back(yystack_[0].value.as < Statement* > ()); }
#line 1717 "../src/../src/Parser/Parser.cc"
    break;

  case 4: // global_declaration: function_definition
#line 114 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                { yylhs.value.as < Statement* > () = yystack_[0].value.as < FunctionDecl* > (); }
#line 1723 "../src/../src/Parser/Parser.cc"
    break;

  case 5: // global_declaration: declaration_expression
#line 115 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                { yylhs.value.as < Statement* > () = yystack_[0].value.as < VarDecl* > (); }
#line 1729 "../src/../src/Parser/Parser.cc"
    break;

  case 6: // global_declaration: object_declaration_expression
#line 116 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                        { yylhs.value.as < Statement* > () = yystack_[0].value.as < ObjDecl* > (); }
#line 1735 "../src/../src/Parser/Parser.cc"
    break;

  case 7: // function_definition: FN ID "(" ")" ":" declaration_specifier compound_statement
#line 121 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                                                    { yylhs.value.as < FunctionDecl* > () = new FunctionDecl(); }
#line 1741 "../src/../src/Parser/Parser.cc"
    break;

  case 70: // atomic_expression: ID
#line 287 "/home/espresso/projects/tape/src/Bison/parser.yy"
                            { yylhs.value.as < Expression* > () = new Identifier(yystack_[0].value.as < std::string > ()); }
#line 1747 "../src/../src/Parser/Parser.cc"
    break;

  case 71: // atomic_expression: INT_VAL
#line 288 "/home/espresso/projects/tape/src/Bison/parser.yy"
                            { yylhs.value.as < Expression* > () = new IVal(yystack_[0].value.as < long long > ()); }
#line 1753 "../src/../src/Parser/Parser.cc"
    break;

  case 72: // atomic_expression: CHAR_VAL
#line 289 "/home/espresso/projects/tape/src/Bison/parser.yy"
                            { yylhs.value.as < Expression* > () = new CVal(yystack_[0].value.as < char > ()); }
#line 1759 "../src/../src/Parser/Parser.cc"
    break;

  case 73: // atomic_expression: BOOL_VAL
#line 290 "/home/espresso/projects/tape/src/Bison/parser.yy"
                            { yylhs.value.as < Expression* > () = new BVal(yystack_[0].value.as < bool > ()); }
#line 1765 "../src/../src/Parser/Parser.cc"
    break;

  case 74: // atomic_expression: FLOAT_VAL
#line 291 "/home/espresso/projects/tape/src/Bison/parser.yy"
                            { yylhs.value.as < Expression* > () = new FVal(yystack_[0].value.as < float > ()); }
#line 1771 "../src/../src/Parser/Parser.cc"
    break;

  case 75: // atomic_expression: STRING_VAL
#line 292 "/home/espresso/projects/tape/src/Bison/parser.yy"
                            { yylhs.value.as < Expression* > () = new SVal(yystack_[0].value.as < std::string > ()); }
#line 1777 "../src/../src/Parser/Parser.cc"
    break;

  case 76: // atomic_expression: "(" expression ")"
#line 293 "/home/espresso/projects/tape/src/Bison/parser.yy"
                            { yylhs.value.as < Expression* > () = yystack_[1].value.as < Expression* > (); }
#line 1783 "../src/../src/Parser/Parser.cc"
    break;

  case 77: // postfix_expression: atomic_expression
#line 297 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1789 "../src/../src/Parser/Parser.cc"
    break;

  case 78: // postfix_expression: postfix_expression "[" expression "]"
#line 298 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = yystack_[3].value.as < Expression* > (); }
#line 1795 "../src/../src/Parser/Parser.cc"
    break;

  case 79: // postfix_expression: postfix_expression "(" ")"
#line 299 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new FunctionCall(yystack_[2].value.as < Expression* > (), nullptr); }
#line 1801 "../src/../src/Parser/Parser.cc"
    break;

  case 80: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 300 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new FunctionCall(yystack_[3].value.as < Expression* > (), yystack_[1].value.as < std::vector<Expression*>* > ()); }
#line 1807 "../src/../src/Parser/Parser.cc"
    break;

  case 81: // postfix_expression: postfix_expression "." ID
#line 301 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new AccessCall(yystack_[2].value.as < Expression* > (), new Identifier(yystack_[0].value.as < std::string > ())); }
#line 1813 "../src/../src/Parser/Parser.cc"
    break;

  case 82: // postfix_expression: postfix_expression POINTER ID
#line 302 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new AccessCall(yystack_[2].value.as < Expression* > (), new Identifier(yystack_[0].value.as < std::string > ())); }
#line 1819 "../src/../src/Parser/Parser.cc"
    break;

  case 83: // postfix_expression: postfix_expression INCREMENT
#line 303 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_PLUS, yystack_[1].value.as < Expression* > (), new IVal(1)); }
#line 1825 "../src/../src/Parser/Parser.cc"
    break;

  case 84: // postfix_expression: postfix_expression DECREMENT
#line 304 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_MINUS, yystack_[1].value.as < Expression* > (), new IVal(1));}
#line 1831 "../src/../src/Parser/Parser.cc"
    break;

  case 85: // argument_expression_list: assignment_expression
#line 308 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { ExpressionList *l = new ExpressionList; l->push_back(yystack_[0].value.as < Expression* > ()); }
#line 1837 "../src/../src/Parser/Parser.cc"
    break;

  case 86: // argument_expression_list: argument_expression_list "," assignment_expression
#line 309 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yystack_[2].value.as < std::vector<Expression*>* > ()->push_back(yystack_[0].value.as < Expression* > ()); yylhs.value.as < std::vector<Expression*>* > () = yystack_[2].value.as < std::vector<Expression*>* > (); }
#line 1843 "../src/../src/Parser/Parser.cc"
    break;

  case 87: // unary_expression: postfix_expression
#line 313 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                        { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1849 "../src/../src/Parser/Parser.cc"
    break;

  case 88: // unary_expression: INCREMENT unary_expression
#line 314 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                        { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_PLUS, new IVal(1), yystack_[0].value.as < Expression* > ()); }
#line 1855 "../src/../src/Parser/Parser.cc"
    break;

  case 89: // unary_expression: DECREMENT unary_expression
#line 315 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                        { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_MINUS, new IVal(1), yystack_[0].value.as < Expression* > ()); }
#line 1861 "../src/../src/Parser/Parser.cc"
    break;

  case 90: // unary_expression: unary_operator cast_expression
#line 316 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                        { yylhs.value.as < Expression* > () = new UnaryExpr(yystack_[1].value.as < int > (), yystack_[0].value.as < Expression* > ()); }
#line 1867 "../src/../src/Parser/Parser.cc"
    break;

  case 91: // unary_expression: SIZEOF "(" type_name ")"
#line 318 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                        { yylhs.value.as < Expression* > () = new IVal(1); }
#line 1873 "../src/../src/Parser/Parser.cc"
    break;

  case 92: // cast_expression: unary_expression
#line 322 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                            { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1879 "../src/../src/Parser/Parser.cc"
    break;

  case 93: // multiplicative_expression: cast_expression
#line 327 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                        { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1885 "../src/../src/Parser/Parser.cc"
    break;

  case 94: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 328 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                        { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_STAR, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ());    }
#line 1891 "../src/../src/Parser/Parser.cc"
    break;

  case 95: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 329 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                        { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_FSLASH, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ());  }
#line 1897 "../src/../src/Parser/Parser.cc"
    break;

  case 96: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 330 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                        { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_MOD, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ());     }
#line 1903 "../src/../src/Parser/Parser.cc"
    break;

  case 97: // additive_expression: multiplicative_expression
#line 334 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1909 "../src/../src/Parser/Parser.cc"
    break;

  case 98: // additive_expression: additive_expression "+" multiplicative_expression
#line 335 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_PLUS, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ());    }
#line 1915 "../src/../src/Parser/Parser.cc"
    break;

  case 99: // additive_expression: additive_expression "-" multiplicative_expression
#line 336 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_MINUS, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ());   }
#line 1921 "../src/../src/Parser/Parser.cc"
    break;

  case 100: // shift_expression: additive_expression
#line 340 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                    { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1927 "../src/../src/Parser/Parser.cc"
    break;

  case 101: // shift_expression: shift_expression LEFT additive_expression
#line 341 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                    { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_LEFT, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1933 "../src/../src/Parser/Parser.cc"
    break;

  case 102: // shift_expression: shift_expression RIGHT additive_expression
#line 342 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                    { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_RIGHT, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1939 "../src/../src/Parser/Parser.cc"
    break;

  case 103: // relational_expression: shift_expression
#line 346 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                        { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1945 "../src/../src/Parser/Parser.cc"
    break;

  case 104: // relational_expression: relational_expression "<" shift_expression
#line 347 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                        { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_LT, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1951 "../src/../src/Parser/Parser.cc"
    break;

  case 105: // relational_expression: relational_expression ">" shift_expression
#line 348 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                        { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_GT, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1957 "../src/../src/Parser/Parser.cc"
    break;

  case 106: // relational_expression: relational_expression LT_EQ shift_expression
#line 349 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                        { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_LT_EQ, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1963 "../src/../src/Parser/Parser.cc"
    break;

  case 107: // relational_expression: relational_expression GT_EQ shift_expression
#line 350 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                        { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_GT_EQ, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1969 "../src/../src/Parser/Parser.cc"
    break;

  case 108: // equality_expression: relational_expression
#line 354 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1975 "../src/../src/Parser/Parser.cc"
    break;

  case 109: // equality_expression: equality_expression EQ_EQ relational_expression
#line 355 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_EQ_EQ, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1981 "../src/../src/Parser/Parser.cc"
    break;

  case 110: // equality_expression: equality_expression BANG_EQ relational_expression
#line 356 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_BANG_EQ, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1987 "../src/../src/Parser/Parser.cc"
    break;

  case 111: // and_expression: equality_expression
#line 360 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 1993 "../src/../src/Parser/Parser.cc"
    break;

  case 112: // and_expression: and_expression "&" equality_expression
#line 361 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_AMP, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1999 "../src/../src/Parser/Parser.cc"
    break;

  case 113: // exclusive_or_expression: and_expression
#line 365 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                    { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 2005 "../src/../src/Parser/Parser.cc"
    break;

  case 114: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 366 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                    { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_CARROT, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 2011 "../src/../src/Parser/Parser.cc"
    break;

  case 115: // inclusive_or_expression: exclusive_or_expression
#line 370 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 2017 "../src/../src/Parser/Parser.cc"
    break;

  case 116: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 371 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                            { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_PIPE, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 2023 "../src/../src/Parser/Parser.cc"
    break;

  case 117: // logical_and_expression: inclusive_or_expression
#line 375 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                                { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 2029 "../src/../src/Parser/Parser.cc"
    break;

  case 118: // logical_and_expression: logical_and_expression AMP_AMP inclusive_or_expression
#line 376 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                                { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_AMP_AMP, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 2035 "../src/../src/Parser/Parser.cc"
    break;

  case 119: // logical_or_expression: logical_and_expression
#line 380 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                                { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 2041 "../src/../src/Parser/Parser.cc"
    break;

  case 120: // logical_or_expression: logical_or_expression PIPE_PIPE logical_and_expression
#line 381 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                                { yylhs.value.as < Expression* > () = new BinaryExpr(yy::Parser::symbol_kind_type::S_PIPE_PIPE, yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 2047 "../src/../src/Parser/Parser.cc"
    break;

  case 121: // conditional_expression: logical_or_expression
#line 385 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                                        { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 2053 "../src/../src/Parser/Parser.cc"
    break;

  case 122: // conditional_expression: logical_or_expression "?" expression ":" conditional_expression
#line 386 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                                        { yylhs.value.as < Expression* > () = new OrExpr(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 2059 "../src/../src/Parser/Parser.cc"
    break;

  case 123: // assignment_expression: conditional_expression
#line 391 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                                   {yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 2065 "../src/../src/Parser/Parser.cc"
    break;

  case 124: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 392 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                                   {yylhs.value.as < Expression* > () = new AssignmentExpr(yystack_[1].value.as < int > (), yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 2071 "../src/../src/Parser/Parser.cc"
    break;

  case 125: // expression: assignment_expression
#line 396 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                                { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 2077 "../src/../src/Parser/Parser.cc"
    break;

  case 126: // constant_expression: conditional_expression
#line 401 "/home/espresso/projects/tape/src/Bison/parser.yy"
                                { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 2083 "../src/../src/Parser/Parser.cc"
    break;

  case 127: // assignment_operator: "="
#line 406 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_EQ; }
#line 2089 "../src/../src/Parser/Parser.cc"
    break;

  case 128: // assignment_operator: STAR_EQ
#line 407 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_STAR_EQ; }
#line 2095 "../src/../src/Parser/Parser.cc"
    break;

  case 129: // assignment_operator: FSLASH_EQ
#line 408 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_FSLASH_EQ; }
#line 2101 "../src/../src/Parser/Parser.cc"
    break;

  case 130: // assignment_operator: MOD_EQ
#line 409 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_MOD_EQ; }
#line 2107 "../src/../src/Parser/Parser.cc"
    break;

  case 131: // assignment_operator: PLUS_EQ
#line 410 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_PLUS_EQ; }
#line 2113 "../src/../src/Parser/Parser.cc"
    break;

  case 132: // assignment_operator: MINUS_EQ
#line 411 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_MINUS_EQ; }
#line 2119 "../src/../src/Parser/Parser.cc"
    break;

  case 133: // assignment_operator: LEFT_EQ
#line 412 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_LEFT_EQ; }
#line 2125 "../src/../src/Parser/Parser.cc"
    break;

  case 134: // assignment_operator: RIGHT_EQ
#line 413 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_RIGHT_EQ; }
#line 2131 "../src/../src/Parser/Parser.cc"
    break;

  case 135: // assignment_operator: AMP_EQ
#line 414 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_AMP_EQ; }
#line 2137 "../src/../src/Parser/Parser.cc"
    break;

  case 136: // assignment_operator: CARROT_EQ
#line 415 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_CARROT_EQ; }
#line 2143 "../src/../src/Parser/Parser.cc"
    break;

  case 137: // assignment_operator: PIPE_EQ
#line 416 "/home/espresso/projects/tape/src/Bison/parser.yy"
                    { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_PIPE_EQ; }
#line 2149 "../src/../src/Parser/Parser.cc"
    break;

  case 138: // unary_operator: "@"
#line 420 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_AT;      }
#line 2155 "../src/../src/Parser/Parser.cc"
    break;

  case 139: // unary_operator: "-"
#line 421 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_MINUS;   }
#line 2161 "../src/../src/Parser/Parser.cc"
    break;

  case 140: // unary_operator: "&"
#line 422 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_AMP;    }
#line 2167 "../src/../src/Parser/Parser.cc"
    break;

  case 141: // unary_operator: "!"
#line 423 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_BANG;    }
#line 2173 "../src/../src/Parser/Parser.cc"
    break;

  case 142: // unary_operator: "~"
#line 424 "/home/espresso/projects/tape/src/Bison/parser.yy"
                { yylhs.value.as < int > () = yy::Parser::symbol_kind_type::S_TILDE;   }
#line 2179 "../src/../src/Parser/Parser.cc"
    break;


#line 2183 "../src/../src/Parser/Parser.cc"

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
  "CHAR_VAL", "BOOL_VAL", "TYPE_NAME", "ID", "POINTER", "INCREMENT",
  "DECREMENT", "LEFT", "RIGHT", "AMP_AMP", "PIPE_PIPE", "STAR_EQ",
  "FSLASH_EQ", "MOD_EQ", "PLUS_EQ", "MINUS_EQ", "LEFT_EQ", "RIGHT_EQ",
  "AMP_EQ", "CARROT_EQ", "PIPE_EQ", "LT_EQ", "GT_EQ", "EQ_EQ", "BANG_EQ",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "SIZEOF", "CHAR",
  "SIGNED", "UNSIGNED", "CONST", "VOLATILE", "VOID", "BOOL", "LAMBDA",
  "I8", "I16", "I32", "I64", "F32", "F64", "STRUCT", "UNION", "ENUM",
  "ELLIPSIS", "FN", "LET", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH",
  "WHILE", "FOR", "CONTINUE", "BREAK", "RETURN", "$accept", "program",
  "global_declaration", "function_definition", "parameter_list",
  "parameter", "declaration_list", "declaration",
  "object_declaration_expression", "id_list", "struct_or_union",
  "declaration_specifier", "type_suffix_list", "type_suffix", "type_name",
  "type_qualifier", "initializer", "initializer_list", "statement_list",
  "statement", "conditional_statement", "compound_statement",
  "labeled_statement", "jump_statement", "expression_statement",
  "declaration_expression", "switch_statement", "iteration_statement",
  "atomic_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "expression", "constant_expression",
  "assignment_operator", "unary_operator", YY_NULLPTR
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


  const short Parser::yypact_ninf_ = -173;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      69,  -173,  -173,   -26,   -19,    25,  -173,  -173,  -173,    13,
    -173,    46,  -173,    93,   131,  -173,  -173,   109,     5,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,     4,     2,    59,   -11,  -173,    86,    96,    14,  -173,
    -173,  -173,  -173,   321,     4,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,   321,   321,    91,  -173,    51,  -173,    36,
     317,  -173,   104,   154,   123,    -7,   110,   127,   125,   143,
     116,   -17,  -173,  -173,   321,  -173,  -173,   165,  -173,   145,
      26,  -173,     2,     2,   156,   150,  -173,   177,    45,  -173,
    -173,   165,  -173,     4,   273,   321,   159,   161,  -173,  -173,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,   176,  -173,   181,  -173,     2,
    -173,  -173,  -173,   187,  -173,  -173,    43,  -173,   186,  -173,
    -173,  -173,  -173,  -173,  -173,   104,   104,   154,   154,   123,
     123,   123,   123,    -7,    -7,   110,   127,   125,   143,   182,
     116,   102,  -173,   180,  -173,   181,  -173,  -173,   321,  -173,
     321,  -173,   309,  -173,  -173,   321,   183,   190,   193,   201,
     203,   200,   202,   216,    92,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,   207,  -173,  -173,  -173,  -173,  -173,
     204,   205,   180,   321,   321,   321,   216,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,   180,  -173,   217,   218,   236,   216,
    -173,   180,   180,   180,   321,   144,  -173,  -173,   238,   180,
     180,  -173,  -173
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,    20,    21,     0,     0,     0,     2,     4,     6,     0,
       5,     0,    18,     0,     0,     1,     3,     0,     0,   127,
      66,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,    39,     0,     0,    17,     0,     0,     0,     9,
     139,   138,   140,     0,     0,   141,   142,    71,    74,    75,
      72,    73,    70,     0,     0,     0,    43,     0,    77,    87,
      92,    93,    97,   100,   103,   108,   111,   113,   115,   117,
     119,   121,   123,    41,     0,    40,    14,     0,    19,     0,
       0,    12,    39,    39,     0,     0,   125,     0,     0,    88,
      89,     0,    65,     0,     0,     0,     0,     0,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    90,    38,    37,    28,    35,    36,    29,    30,    31,
      32,    33,    34,    23,    16,     0,    13,     0,    11,    39,
      10,    76,    42,     0,    44,    79,     0,    85,     0,    81,
      82,   124,    95,    94,    96,    98,    99,   101,   102,   104,
     105,   106,   107,   109,   110,   112,   114,   116,   118,     0,
     120,    22,    15,     0,     7,     0,    91,    80,     0,    78,
       0,    25,     0,    24,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45,    48,    47,    50,    53,
      49,    63,    52,    51,     0,     8,    86,   122,    26,   126,
       0,     0,     0,     0,     0,     0,     0,    61,    60,    59,
      56,    46,    62,    27,     0,    58,     0,     0,     0,     0,
      57,     0,     0,     0,     0,    54,    67,    69,     0,     0,
       0,    55,    68
  };

  const short
  Parser::yypgoto_[] =
  {
    -173,  -173,   249,  -173,  -173,   170,  -173,   -29,  -173,  -173,
    -173,   -80,  -173,  -173,   166,  -173,   163,   214,  -173,   160,
    -173,  -133,  -173,  -173,  -172,    95,  -173,  -173,  -173,  -173,
    -173,   -25,   -48,    62,    82,    22,    56,   146,   157,   149,
     142,   155,  -173,  -163,   -30,   -43,  -173,   213,  -173
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,     7,    38,    39,    80,    13,     8,    14,
       9,    76,   171,   183,   133,    77,    56,    57,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,    58,    59,
     146,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    86,   204,   210,    31,    74
  };

  const unsigned char
  Parser::yytable_[] =
  {
      87,    73,   137,   138,   174,    81,    79,   118,    11,    40,
      41,    42,   108,   109,    73,    12,    43,   207,    36,   209,
      44,   219,   211,    12,   119,    15,   121,    84,    89,    90,
      45,    46,    47,    48,    49,    50,    51,    85,    52,    37,
      53,    54,   205,   135,   229,   110,   111,    17,    94,   120,
      95,   136,   148,   152,   153,   154,   177,   234,    18,   175,
      12,    96,   142,    73,   147,    55,   178,    75,    93,    92,
     151,    97,    98,    99,    93,   169,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,    78,   120,    10,    19,    40,    41,    42,
      10,     1,     2,    91,    43,     3,     4,    82,   173,   220,
     184,    20,   181,   101,   102,   103,   182,    83,    45,    46,
      47,    48,    49,    50,    51,    34,    52,    35,    53,    54,
     159,   160,   161,   162,   114,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     1,     2,   115,   206,     3,
       4,   116,    32,    55,    33,   120,   117,   120,   104,   105,
     120,   106,   107,   134,   112,   113,   155,   156,   163,   164,
     226,   227,   228,     4,   185,   186,   187,   139,   188,   189,
     190,   191,   192,   193,    37,    40,    41,    42,   157,   158,
     141,   238,    43,   149,   172,   150,   173,   173,   184,   122,
     176,   179,   213,   180,   212,   214,    45,    46,    47,    48,
      49,    50,    51,   215,    52,   216,    53,    54,   217,   223,
     218,    40,    41,    42,   123,   222,   224,   124,    43,   239,
     231,   232,   125,   126,   184,   127,   128,   129,   130,   131,
     132,    55,    45,    46,    47,    48,    49,    50,    51,   233,
      52,   240,    53,    54,    16,   140,   144,   143,    88,   168,
     165,     4,   185,   186,   187,   167,   188,   189,   190,   191,
     192,   193,   166,   100,   170,     0,     0,    55,    40,    41,
      42,     0,     0,     0,     0,    43,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,    45,
      46,    47,    48,    49,    50,    51,     0,    52,     0,    53,
      54,     0,     0,     0,    40,    41,    42,     0,     0,     0,
      19,    43,     0,     0,   208,     0,    40,    41,    42,     0,
       0,     0,     0,    43,    55,    45,    46,    47,    48,    49,
      50,    51,     0,    52,     0,    53,    54,    45,    46,    47,
      48,    49,    50,    51,   221,    52,     0,    53,    54,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      55,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,   230,     0,     0,     0,     0,     0,
       0,   235,   236,   237,     0,     0,     0,     0,     0,   241,
     242
  };

  const short
  Parser::yycheck_[] =
  {
      43,    31,    82,    83,   137,    34,    17,    24,    34,     5,
       6,     7,    19,    20,    44,    34,    12,   180,    13,   182,
      16,   193,   185,    34,    41,     0,    74,    13,    53,    54,
      26,    27,    28,    29,    30,    31,    32,    23,    34,    34,
      36,    37,   175,    17,   216,    52,    53,    34,    12,    74,
      14,    80,    95,   101,   102,   103,    13,   229,    12,   139,
      34,    25,    17,    93,    94,    61,    23,    65,    23,    18,
     100,    35,    36,    37,    23,   118,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    34,   119,     0,     3,     5,     6,     7,
       5,    76,    77,    12,    12,    80,    81,    21,    16,    17,
      18,    18,    10,     9,    10,    11,    14,    21,    26,    27,
      28,    29,    30,    31,    32,    16,    34,    18,    36,    37,
     108,   109,   110,   111,     7,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    76,    77,    22,   178,    80,
      81,     8,    21,    61,    23,   180,    40,   182,     4,     5,
     185,    38,    39,    18,    54,    55,   104,   105,   112,   113,
     213,   214,   215,    81,    82,    83,    84,    21,    86,    87,
      88,    89,    90,    91,    34,     5,     6,     7,   106,   107,
      13,   234,    12,    34,    18,    34,    16,    16,    18,    34,
      13,    15,    12,    21,    21,    12,    26,    27,    28,    29,
      30,    31,    32,    12,    34,    12,    36,    37,    18,    15,
      18,     5,     6,     7,    59,    18,    21,    62,    12,    85,
      13,    13,    67,    68,    18,    70,    71,    72,    73,    74,
      75,    61,    26,    27,    28,    29,    30,    31,    32,    13,
      34,    13,    36,    37,     5,    85,    93,    91,    44,   117,
     114,    81,    82,    83,    84,   116,    86,    87,    88,    89,
      90,    91,   115,    60,   119,    -1,    -1,    61,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    -1,    36,
      37,    -1,    -1,    -1,     5,     6,     7,    -1,    -1,    -1,
       3,    12,    -1,    -1,    15,    -1,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    61,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    -1,    36,    37,    26,    27,    28,
      29,    30,    31,    32,   194,    34,    -1,    36,    37,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      61,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
     240
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    76,    77,    80,    81,    93,    94,    95,   100,   102,
     117,    34,    34,    99,   101,     0,    94,    34,    12,     3,
      18,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,   139,    21,    23,    16,    18,    13,    34,    96,    97,
       5,     6,     7,    12,    16,    26,    27,    28,    29,    30,
      31,    32,    34,    36,    37,    61,   108,   109,   120,   121,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   140,    65,   103,   107,    34,    17,
      98,    99,    21,    21,    13,    23,   136,   137,   109,   123,
     123,    12,    18,    23,    12,    14,    25,    35,    36,    37,
     139,     9,    10,    11,     4,     5,    38,    39,    19,    20,
      52,    53,    54,    55,     7,    22,     8,    40,    24,    41,
     123,   124,    34,    59,    62,    67,    68,    70,    71,    72,
      73,    74,    75,   106,    18,    17,    99,   103,   103,    21,
      97,    13,    17,   106,   108,    13,   122,   136,   137,    34,
      34,   136,   124,   124,   124,   125,   125,   126,   126,   127,
     127,   127,   127,   128,   128,   129,   130,   131,   132,   137,
     133,   104,    18,    16,   113,   103,    13,    13,    23,    15,
      21,    10,    14,   105,    18,    82,    83,    84,    86,    87,
      88,    89,    90,    91,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   137,   113,   136,   135,    15,   135,
     138,   135,    21,    12,    12,    12,    12,    18,    18,   116,
      17,   111,    18,    15,    21,   111,   137,   137,   137,   116,
     111,    13,    13,    13,   116,   111,   111,   111,   137,    85,
      13,   111,   111
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    92,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    97,    98,    98,    99,   100,   100,   100,   101,   101,
     102,   102,   103,   104,   104,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   113,   114,   114,   115,
     115,   115,   116,   116,   116,   117,   117,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   122,   122,   123,   123,   123,
     123,   123,   124,   125,   125,   125,   125,   126,   126,   126,
     127,   127,   127,   128,   128,   128,   128,   128,   129,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   137,   138,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   140,   140,
     140,   140,   140
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     7,     8,     1,
       3,     3,     1,     2,     3,     6,     5,     3,     1,     3,
       1,     1,     3,     0,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     3,     1,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     3,     4,     3,     2,
       2,     2,     2,     1,     1,     5,     3,     5,     7,     5,
       1,     1,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     4,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };




#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   109,   109,   110,   114,   115,   116,   121,   122,   126,
     127,   131,   136,   137,   141,   145,   146,   147,   151,   152,
     156,   157,   162,   166,   167,   171,   172,   173,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   189,   204,
     205,   209,   211,   215,   216,   229,   230,   234,   235,   236,
     237,   238,   239,   240,   244,   245,   249,   253,   254,   258,
     259,   260,   264,   265,   266,   270,   271,   274,   278,   279,
     287,   288,   289,   290,   291,   292,   293,   297,   298,   299,
     300,   301,   302,   303,   304,   308,   309,   313,   314,   315,
     316,   318,   322,   327,   328,   329,   330,   334,   335,   336,
     340,   341,   342,   346,   347,   348,   349,   350,   354,   355,
     356,   360,   361,   365,   366,   370,   371,   375,   376,   380,
     381,   385,   386,   391,   392,   396,   401,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   420,   421,
     422,   423,   424
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


#line 7 "/home/espresso/projects/tape/src/Bison/parser.yy"
} // yy
#line 2959 "../src/../src/Parser/Parser.cc"

#line 429 "/home/espresso/projects/tape/src/Bison/parser.yy"



void yy::Parser::error(const location_type &loc, const std::string &msg) {
    std::cerr << loc << ": " << msg << std::endl;
}

//int char_to_sym(char c) {
//    switch (c) {
//    case '*':
//        return yy::Parser::symbol_kind_type::S_STAR;
//    case '+':
//        return yy::Parser::symbol_kind_type::S_PLUS;
//    case '-':
//        return yy::Parser::symbol_kind_type::S_MINUS;
//    case '/':
//        return yy::Parser::symbol_kind_type::S_FSLASH;
//    case '@':
//        return yy::Parser::symbol_kind_type::S_AT;
//    case '&':
//        return yy::Parser::symbol_kind_type::S_AMP;  
//    case ''
//        return yy::Parser::symbol_kind_type::S_BANG; 
//        return yy::Parser::symbol_kind_type::S_TILDE;
//    }
//    return yy::Parser::symbol_kind_type::S_YYUNDEF;
//}
