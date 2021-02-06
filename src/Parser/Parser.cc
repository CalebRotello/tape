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
#line 32 "/home/espresso/projects/tape/src/parser.yy"

    #include "Driver.hh"
    #include "../Ast/Ast.hh"
    #include "../Ast/Type.hh"

#line 109 "/home/espresso/projects/tape/src/parser.yy"

typedef yy::Parser::symbol_kind_type skind_type;

#line 56 "../src/../src/Parser/Parser.cc"


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

#line 6 "/home/espresso/projects/tape/src/parser.yy"
namespace yy {
#line 149 "../src/../src/Parser/Parser.cc"

  /// Build a parser object.
  Parser::Parser (Driver *driver_yyarg, StmtList *fstmt_list_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      driver (driver_yyarg),
      fstmt_list (fstmt_list_yyarg)
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
      case symbol_kind::S_initializer: // initializer
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
        value.YY_MOVE_OR_COPY< Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_fn_statement_box: // fn_statement_box
        value.YY_MOVE_OR_COPY< FunctionDeclStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_global_declaration: // global_declaration
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_flow_statement: // flow_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.YY_MOVE_OR_COPY< Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_box: // statement_box
        value.YY_MOVE_OR_COPY< StmtList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.YY_MOVE_OR_COPY< TypeDeclStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< VarDeclStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
      case symbol_kind::S_declaration_hypothesis: // declaration_hypothesis
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
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
      case symbol_kind::S_initializer: // initializer
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
        value.move< Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_fn_statement_box: // fn_statement_box
        value.move< FunctionDeclStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_global_declaration: // global_declaration
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_flow_statement: // flow_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.move< Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_box: // statement_box
        value.move< StmtList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.move< TypeDeclStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_declaration: // declaration
        value.move< VarDeclStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
      case symbol_kind::S_declaration_hypothesis: // declaration_hypothesis
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
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
      case symbol_kind::S_initializer: // initializer
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
        value.copy< Expr* > (that.value);
        break;

      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_fn_statement_box: // fn_statement_box
        value.copy< FunctionDeclStmt* > (that.value);
        break;

      case symbol_kind::S_global_declaration: // global_declaration
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_flow_statement: // flow_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.copy< Stmt* > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_box: // statement_box
        value.copy< StmtList* > (that.value);
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.copy< TypeDeclStmt* > (that.value);
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_declaration: // declaration
        value.copy< VarDeclStmt* > (that.value);
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
      case symbol_kind::S_declaration_hypothesis: // declaration_hypothesis
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_type: // type
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
      case symbol_kind::S_initializer: // initializer
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
        value.move< Expr* > (that.value);
        break;

      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_fn_statement_box: // fn_statement_box
        value.move< FunctionDeclStmt* > (that.value);
        break;

      case symbol_kind::S_global_declaration: // global_declaration
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_flow_statement: // flow_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.move< Stmt* > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_box: // statement_box
        value.move< StmtList* > (that.value);
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.move< TypeDeclStmt* > (that.value);
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_declaration: // declaration
        value.move< VarDeclStmt* > (that.value);
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
      case symbol_kind::S_declaration_hypothesis: // declaration_hypothesis
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.move< char > (that.value);
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.move< float > (that.value);
        break;

      case symbol_kind::S_type: // type
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
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 578 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PLUS: // "+"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 584 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MINUS: // "-"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 590 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AT: // "@"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 596 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP: // "&"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 602 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE: // "|"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 608 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FSLASH: // "/"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 614 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STAR: // "*"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 620 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MOD: // "%"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 626 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LPAREN: // "("
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 632 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RPAREN: // ")"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 638 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LSQUARE: // "["
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 644 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RSQUARE: // "]"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 650 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LBRACE: // "{"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 656 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RBRACE: // "}"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 662 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_SC: // ";"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 668 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LT: // "<"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 674 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_GT: // ">"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 680 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_COLON: // ":"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 686 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CARROT: // "^"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 692 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_COMMA: // ","
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 698 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_QUESTION: // "?"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 704 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_DOT: // "."
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 710 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BANG: // "!"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 716 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TILDE: // "~"
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 722 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < long long > (); }
#line 728 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < float > (); }
#line 734 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 740 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < char > (); }
#line 746 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < bool > (); }
#line 752 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ID: // ID
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 758 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_POINTER: // POINTER
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 764 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_INCREMENT: // INCREMENT
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 770 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_DECREMENT: // DECREMENT
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 776 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LEFT: // LEFT
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 782 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RIGHT: // RIGHT
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 788 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP_AMP: // AMP_AMP
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 794 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE_PIPE: // PIPE_PIPE
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 800 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STAR_EQ: // STAR_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 806 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FSLASH_EQ: // FSLASH_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 812 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MOD_EQ: // MOD_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 818 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PLUS_EQ: // PLUS_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 824 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MINUS_EQ: // MINUS_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 830 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LEFT_EQ: // LEFT_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 836 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RIGHT_EQ: // RIGHT_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 842 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP_EQ: // AMP_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 848 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CARROT_EQ: // CARROT_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 854 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE_EQ: // PIPE_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 860 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LT_EQ: // LT_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 866 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_GT_EQ: // GT_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 872 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_EQ_EQ: // EQ_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 878 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BANG_EQ: // BANG_EQ
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 884 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_IF: // IF
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 890 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 896 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FN: // FN
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 902 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LET: // LET
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 908 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_VAR: // VAR
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 914 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TYPE: // TYPE
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 920 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 926 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FOR: // FOR
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 932 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 938 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MATCH: // MATCH
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 944 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 950 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CONTINUE: // CONTINUE
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 956 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TYPE_NAME: // TYPE_NAME
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 962 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I8: // I8
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 968 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I16: // I16
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 974 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I32: // I32
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 980 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I64: // I64
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 986 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_F32: // F32
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 992 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_F64: // F64
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 998 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_program: // program
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < StmtList* > (); }
#line 1004 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_global_declaration: // global_declaration
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Stmt* > (); }
#line 1010 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < VarDeclStmt* > (); }
#line 1016 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_declaration: // type_declaration
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < TypeDeclStmt* > (); }
#line 1022 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_declaration_list: // type_declaration_list
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1028 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_declaration_member: // type_declaration_member
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1034 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_type: // declaration_type
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1040 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_mods: // type_mods
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1046 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_mod: // type_mod
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1052 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type: // type
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1058 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration: // declaration
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < VarDeclStmt* > (); }
#line 1064 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_hypothesis: // declaration_hypothesis
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < bool > (); }
#line 1070 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_function_declaration: // function_declaration
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < FunctionDeclStmt* > (); }
#line 1076 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_parameter_list: // parameter_list
#line 40 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1082 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement_list: // statement_list
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < StmtList* > (); }
#line 1088 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement: // statement
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Stmt* > (); }
#line 1094 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement_box: // statement_box
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < StmtList* > (); }
#line 1100 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_fn_statement_box: // fn_statement_box
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < FunctionDeclStmt* > (); }
#line 1106 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_flow_statement: // flow_statement
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Stmt* > (); }
#line 1112 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_expression_statement: // expression_statement
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Stmt* > (); }
#line 1118 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_initializer: // initializer
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1124 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_expression: // expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1130 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_constant_expression: // constant_expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1136 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1142 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_atomic_expression: // atomic_expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1148 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1154 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_unary_expression: // unary_expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1160 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1166 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_additive_expression: // additive_expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1172 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_relational_expression: // relational_expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1178 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_equality_expression: // equality_expression
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1184 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_assign_op: // assign_op
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1190 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_unary_op: // unary_op
#line 39 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1196 "../src/../src/Parser/Parser.cc"
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
      case symbol_kind::S_initializer: // initializer
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_constant_expression: // constant_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_atomic_expression: // atomic_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
        yylhs.value.emplace< Expr* > ();
        break;

      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_fn_statement_box: // fn_statement_box
        yylhs.value.emplace< FunctionDeclStmt* > ();
        break;

      case symbol_kind::S_global_declaration: // global_declaration
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_flow_statement: // flow_statement
      case symbol_kind::S_expression_statement: // expression_statement
        yylhs.value.emplace< Stmt* > ();
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement_box: // statement_box
        yylhs.value.emplace< StmtList* > ();
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        yylhs.value.emplace< TypeDeclStmt* > ();
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< VarDeclStmt* > ();
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
      case symbol_kind::S_declaration_hypothesis: // declaration_hypothesis
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_type: // type
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
  case 2: // program: global_declaration
#line 123 "/home/espresso/projects/tape/src/parser.yy"
                                { fstmt_list->push_back(yystack_[0].value.as < Stmt* > ()); }
#line 1528 "../src/../src/Parser/Parser.cc"
    break;

  case 3: // program: program global_declaration
#line 124 "/home/espresso/projects/tape/src/parser.yy"
                                { fstmt_list->push_back(yystack_[0].value.as < Stmt* > ()); }
#line 1534 "../src/../src/Parser/Parser.cc"
    break;

  case 4: // global_declaration: variable_declaration ";"
#line 128 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = yystack_[1].value.as < VarDeclStmt* > (); }
#line 1540 "../src/../src/Parser/Parser.cc"
    break;

  case 5: // global_declaration: function_declaration
#line 129 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = yystack_[0].value.as < FunctionDeclStmt* > (); }
#line 1546 "../src/../src/Parser/Parser.cc"
    break;

  case 6: // global_declaration: type_declaration
#line 130 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = yystack_[0].value.as < TypeDeclStmt* > (); }
#line 1552 "../src/../src/Parser/Parser.cc"
    break;

  case 7: // variable_declaration: declaration "=" initializer
#line 134 "/home/espresso/projects/tape/src/parser.yy"
                                { yystack_[2].value.as < VarDeclStmt* > ()->setExpr(yystack_[0].value.as < Expr* > ()); yylhs.value.as < VarDeclStmt* > () = yystack_[2].value.as < VarDeclStmt* > (); }
#line 1558 "../src/../src/Parser/Parser.cc"
    break;

  case 8: // variable_declaration: declaration
#line 135 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < VarDeclStmt* > () = yystack_[0].value.as < VarDeclStmt* > (); }
#line 1564 "../src/../src/Parser/Parser.cc"
    break;

  case 9: // type_declaration: TYPE ID "=" type type_mods
#line 139 "/home/espresso/projects/tape/src/parser.yy"
                                                { yylhs.value.as < TypeDeclStmt* > () = new TypeDeclStmt(yystack_[3].value.as < std::string > ()); }
#line 1570 "../src/../src/Parser/Parser.cc"
    break;

  case 10: // type_declaration: TYPE ID "=" "{" type_declaration_list "}"
#line 140 "/home/espresso/projects/tape/src/parser.yy"
                                                { yylhs.value.as < TypeDeclStmt* > () = new TypeDeclStmt(yystack_[4].value.as < std::string > ()); }
#line 1576 "../src/../src/Parser/Parser.cc"
    break;

  case 22: // type: I8
#line 175 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::I8;    }
#line 1582 "../src/../src/Parser/Parser.cc"
    break;

  case 23: // type: I16
#line 176 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::I16;   }
#line 1588 "../src/../src/Parser/Parser.cc"
    break;

  case 24: // type: I32
#line 177 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::I32;   }
#line 1594 "../src/../src/Parser/Parser.cc"
    break;

  case 25: // type: I64
#line 178 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::I64;   }
#line 1600 "../src/../src/Parser/Parser.cc"
    break;

  case 26: // type: F32
#line 179 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::F32;   }
#line 1606 "../src/../src/Parser/Parser.cc"
    break;

  case 27: // type: F64
#line 180 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::F64;   }
#line 1612 "../src/../src/Parser/Parser.cc"
    break;

  case 28: // type: FN
#line 181 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::FN;    }
#line 1618 "../src/../src/Parser/Parser.cc"
    break;

  case 29: // type: ID
#line 182 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::DEF;   }
#line 1624 "../src/../src/Parser/Parser.cc"
    break;

  case 30: // declaration: declaration_hypothesis ID declaration_type
#line 186 "/home/espresso/projects/tape/src/parser.yy"
                                               { yylhs.value.as < VarDeclStmt* > () = new VarDeclStmt(yystack_[1].value.as < std::string > (), yystack_[2].value.as < bool > ()); }
#line 1630 "../src/../src/Parser/Parser.cc"
    break;

  case 31: // declaration_hypothesis: LET
#line 190 "/home/espresso/projects/tape/src/parser.yy"
        {yylhs.value.as < bool > ()=false;}
#line 1636 "../src/../src/Parser/Parser.cc"
    break;

  case 32: // declaration_hypothesis: VAR
#line 190 "/home/espresso/projects/tape/src/parser.yy"
                         {yylhs.value.as < bool > ()=true;}
#line 1642 "../src/../src/Parser/Parser.cc"
    break;

  case 33: // function_declaration: FN ID "(" parameter_list ")" declaration_type fn_statement_box
#line 194 "/home/espresso/projects/tape/src/parser.yy"
                                                                    { yystack_[0].value.as < FunctionDeclStmt* > ()->setFnId(yystack_[5].value.as < std::string > ()); yylhs.value.as < FunctionDeclStmt* > () = yystack_[0].value.as < FunctionDeclStmt* > (); }
#line 1648 "../src/../src/Parser/Parser.cc"
    break;

  case 34: // function_declaration: FN ID "(" parameter_list ")" declaration_type ";"
#line 195 "/home/espresso/projects/tape/src/parser.yy"
                                                                    { yylhs.value.as < FunctionDeclStmt* > () = new FunctionDeclStmt(yystack_[5].value.as < std::string > ()); }
#line 1654 "../src/../src/Parser/Parser.cc"
    break;

  case 38: // statement_list: statement
#line 208 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < StmtList* > () = new StmtList({yystack_[0].value.as < Stmt* > ()}); }
#line 1660 "../src/../src/Parser/Parser.cc"
    break;

  case 39: // statement_list: statement_list statement
#line 209 "/home/espresso/projects/tape/src/parser.yy"
                                { yystack_[1].value.as < StmtList* > ()->push_back(yystack_[0].value.as < Stmt* > ()); yylhs.value.as < StmtList* > () = yystack_[1].value.as < StmtList* > (); }
#line 1666 "../src/../src/Parser/Parser.cc"
    break;

  case 40: // statement: statement_box
#line 213 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Stmt* > () = yystack_[0].value.as < StmtList* > (); }
#line 1672 "../src/../src/Parser/Parser.cc"
    break;

  case 41: // statement: expression_statement
#line 214 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Stmt* > () = yystack_[0].value.as < Stmt* > (); }
#line 1678 "../src/../src/Parser/Parser.cc"
    break;

  case 42: // statement: flow_statement
#line 215 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Stmt* > () = yystack_[0].value.as < Stmt* > (); }
#line 1684 "../src/../src/Parser/Parser.cc"
    break;

  case 43: // statement_box: "{" statement_list "}"
#line 219 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < StmtList* > () = yystack_[1].value.as < StmtList* > (); }
#line 1690 "../src/../src/Parser/Parser.cc"
    break;

  case 44: // fn_statement_box: "{" statement_list expression "}"
#line 223 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < FunctionDeclStmt* > () = new FunctionDeclStmt(yystack_[2].value.as < StmtList* > (), yystack_[1].value.as < Expr* > ()); }
#line 1696 "../src/../src/Parser/Parser.cc"
    break;

  case 45: // fn_statement_box: "{" statement_list RETURN expression ";" "}"
#line 224 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < FunctionDeclStmt* > () = new FunctionDeclStmt(yystack_[4].value.as < StmtList* > (), yystack_[2].value.as < Expr* > ()); }
#line 1702 "../src/../src/Parser/Parser.cc"
    break;

  case 46: // fn_statement_box: statement_box
#line 225 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < FunctionDeclStmt* > () = new FunctionDeclStmt(yystack_[0].value.as < StmtList* > ()); }
#line 1708 "../src/../src/Parser/Parser.cc"
    break;

  case 47: // flow_statement: BREAK
#line 229 "/home/espresso/projects/tape/src/parser.yy"
          { yylhs.value.as < Stmt* > () = new ActionStmt; }
#line 1714 "../src/../src/Parser/Parser.cc"
    break;

  case 48: // flow_statement: CONTINUE
#line 229 "/home/espresso/projects/tape/src/parser.yy"
                                              { yylhs.value.as < Stmt* > () = new ActionStmt; }
#line 1720 "../src/../src/Parser/Parser.cc"
    break;

  case 49: // expression_statement: expression ";"
#line 233 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = new ExprStmt(yystack_[1].value.as < Expr* > ()); }
#line 1726 "../src/../src/Parser/Parser.cc"
    break;

  case 50: // expression_statement: variable_declaration ";"
#line 234 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = yystack_[1].value.as < VarDeclStmt* > (); }
#line 1732 "../src/../src/Parser/Parser.cc"
    break;

  case 51: // initializer: expression
#line 238 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1738 "../src/../src/Parser/Parser.cc"
    break;

  case 52: // expression: function_declaration
#line 244 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Expr* > () = yystack_[0].value.as < FunctionDeclStmt* > ()->getFnId(); }
#line 1744 "../src/../src/Parser/Parser.cc"
    break;

  case 53: // expression: assignment_expression
#line 245 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1750 "../src/../src/Parser/Parser.cc"
    break;

  case 54: // constant_expression: equality_expression
#line 249 "/home/espresso/projects/tape/src/parser.yy"
                        { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1756 "../src/../src/Parser/Parser.cc"
    break;

  case 55: // assignment_expression: constant_expression
#line 254 "/home/espresso/projects/tape/src/parser.yy"
                        { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1762 "../src/../src/Parser/Parser.cc"
    break;

  case 56: // assignment_expression: unary_expression assign_op constant_expression
#line 255 "/home/espresso/projects/tape/src/parser.yy"
                                                    {
                                                        Expr *const_expr = yystack_[0].value.as < Expr* > ();
                                                        if (yystack_[1].value.as < int > () != skind_type::S_EQ)  
                                                            const_expr = new BopExpr(yystack_[1].value.as < int > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());
                                                        yylhs.value.as < Expr* > () = new AssignExpr((IdValue*)yystack_[2].value.as < Expr* > (), const_expr); // TODO implement a real "get id"
                                                    }
#line 1773 "../src/../src/Parser/Parser.cc"
    break;

  case 57: // atomic_expression: ID
#line 264 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new IdValue(yystack_[0].value.as < std::string > ());     }
#line 1779 "../src/../src/Parser/Parser.cc"
    break;

  case 58: // atomic_expression: INT_VAL
#line 265 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new IntValue(yystack_[0].value.as < long long > ());    }
#line 1785 "../src/../src/Parser/Parser.cc"
    break;

  case 59: // atomic_expression: CHAR_VAL
#line 266 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new IntValue(yystack_[0].value.as < char > ());    }
#line 1791 "../src/../src/Parser/Parser.cc"
    break;

  case 60: // atomic_expression: BOOL_VAL
#line 267 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new IntValue(yystack_[0].value.as < bool > ());    }
#line 1797 "../src/../src/Parser/Parser.cc"
    break;

  case 61: // atomic_expression: FLOAT_VAL
#line 268 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new FloatValue(yystack_[0].value.as < float > ());  }
#line 1803 "../src/../src/Parser/Parser.cc"
    break;

  case 62: // atomic_expression: STRING_VAL
#line 269 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new StrValue(yystack_[0].value.as < std::string > ());    }
#line 1809 "../src/../src/Parser/Parser.cc"
    break;

  case 63: // atomic_expression: "(" expression ")"
#line 270 "/home/espresso/projects/tape/src/parser.yy"
                       { yylhs.value.as < Expr* > () = yystack_[1].value.as < Expr* > ();           }
#line 1815 "../src/../src/Parser/Parser.cc"
    break;

  case 64: // postfix_expression: atomic_expression
#line 274 "/home/espresso/projects/tape/src/parser.yy"
                                    { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1821 "../src/../src/Parser/Parser.cc"
    break;

  case 65: // postfix_expression: postfix_expression INCREMENT
#line 275 "/home/espresso/projects/tape/src/parser.yy"
                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_PLUS, yystack_[1].value.as < Expr* > (), new IntValue(1));    }
#line 1827 "../src/../src/Parser/Parser.cc"
    break;

  case 66: // postfix_expression: postfix_expression DECREMENT
#line 276 "/home/espresso/projects/tape/src/parser.yy"
                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_MINUS, yystack_[1].value.as < Expr* > (), new IntValue(1));   }
#line 1833 "../src/../src/Parser/Parser.cc"
    break;

  case 67: // unary_expression: postfix_expression
#line 280 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1839 "../src/../src/Parser/Parser.cc"
    break;

  case 68: // unary_expression: INCREMENT unary_expression
#line 281 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_PLUS, yystack_[0].value.as < Expr* > (), new IntValue(1));  }
#line 1845 "../src/../src/Parser/Parser.cc"
    break;

  case 69: // unary_expression: DECREMENT unary_expression
#line 282 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_MINUS, yystack_[0].value.as < Expr* > (), new IntValue(1)); }
#line 1851 "../src/../src/Parser/Parser.cc"
    break;

  case 70: // unary_expression: unary_op unary_expression
#line 283 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = new UopExpr(yystack_[1].value.as < int > (), yystack_[0].value.as < Expr* > ()); }
#line 1857 "../src/../src/Parser/Parser.cc"
    break;

  case 71: // multiplicative_expression: unary_expression
#line 288 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1863 "../src/../src/Parser/Parser.cc"
    break;

  case 72: // multiplicative_expression: multiplicative_expression "*" unary_expression
#line 289 "/home/espresso/projects/tape/src/parser.yy"
                                                   { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_STAR, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());    }
#line 1869 "../src/../src/Parser/Parser.cc"
    break;

  case 73: // multiplicative_expression: multiplicative_expression "/" unary_expression
#line 290 "/home/espresso/projects/tape/src/parser.yy"
                                                   { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_FSLASH, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());  }
#line 1875 "../src/../src/Parser/Parser.cc"
    break;

  case 74: // multiplicative_expression: multiplicative_expression "%" unary_expression
#line 291 "/home/espresso/projects/tape/src/parser.yy"
                                                   { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_MOD, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());     }
#line 1881 "../src/../src/Parser/Parser.cc"
    break;

  case 75: // additive_expression: multiplicative_expression
#line 295 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1887 "../src/../src/Parser/Parser.cc"
    break;

  case 76: // additive_expression: additive_expression "+" multiplicative_expression
#line 296 "/home/espresso/projects/tape/src/parser.yy"
                                                      { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_PLUS, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); }
#line 1893 "../src/../src/Parser/Parser.cc"
    break;

  case 77: // additive_expression: additive_expression "-" multiplicative_expression
#line 297 "/home/espresso/projects/tape/src/parser.yy"
                                                      { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_MINUS, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());}
#line 1899 "../src/../src/Parser/Parser.cc"
    break;

  case 78: // relational_expression: additive_expression
#line 301 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1905 "../src/../src/Parser/Parser.cc"
    break;

  case 79: // relational_expression: relational_expression "<" additive_expression
#line 302 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_LT, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());     }
#line 1911 "../src/../src/Parser/Parser.cc"
    break;

  case 80: // relational_expression: relational_expression ">" additive_expression
#line 303 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_GT, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());     }
#line 1917 "../src/../src/Parser/Parser.cc"
    break;

  case 81: // relational_expression: relational_expression LT_EQ additive_expression
#line 304 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_LT_EQ, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());  }
#line 1923 "../src/../src/Parser/Parser.cc"
    break;

  case 82: // relational_expression: relational_expression GT_EQ additive_expression
#line 305 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_GT_EQ, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());  }
#line 1929 "../src/../src/Parser/Parser.cc"
    break;

  case 83: // equality_expression: relational_expression
#line 309 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1935 "../src/../src/Parser/Parser.cc"
    break;

  case 84: // equality_expression: equality_expression EQ_EQ relational_expression
#line 310 "/home/espresso/projects/tape/src/parser.yy"
                                                      { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_EQ_EQ, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());  }
#line 1941 "../src/../src/Parser/Parser.cc"
    break;

  case 85: // equality_expression: equality_expression BANG_EQ relational_expression
#line 311 "/home/espresso/projects/tape/src/parser.yy"
                                                      { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_BANG_EQ, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());}
#line 1947 "../src/../src/Parser/Parser.cc"
    break;

  case 86: // assign_op: "="
#line 316 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_EQ;        }
#line 1953 "../src/../src/Parser/Parser.cc"
    break;

  case 87: // assign_op: PLUS_EQ
#line 317 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_PLUS;      }
#line 1959 "../src/../src/Parser/Parser.cc"
    break;

  case 88: // assign_op: MINUS_EQ
#line 318 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_MINUS;     }
#line 1965 "../src/../src/Parser/Parser.cc"
    break;

  case 89: // assign_op: STAR_EQ
#line 319 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_STAR;      }
#line 1971 "../src/../src/Parser/Parser.cc"
    break;

  case 90: // assign_op: FSLASH_EQ
#line 320 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_FSLASH;    }
#line 1977 "../src/../src/Parser/Parser.cc"
    break;

  case 91: // assign_op: MOD_EQ
#line 321 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_MOD;       }
#line 1983 "../src/../src/Parser/Parser.cc"
    break;

  case 92: // unary_op: "!"
#line 325 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = skind_type::S_BANG;    }
#line 1989 "../src/../src/Parser/Parser.cc"
    break;

  case 93: // unary_op: "@"
#line 326 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = skind_type::S_AT;      }
#line 1995 "../src/../src/Parser/Parser.cc"
    break;

  case 94: // unary_op: "&"
#line 327 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = skind_type::S_AMP;     }
#line 2001 "../src/../src/Parser/Parser.cc"
    break;

  case 95: // unary_op: "-"
#line 328 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = skind_type::S_MINUS;   }
#line 2007 "../src/../src/Parser/Parser.cc"
    break;

  case 96: // unary_op: "~"
#line 329 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = skind_type::S_TILDE;   }
#line 2013 "../src/../src/Parser/Parser.cc"
    break;


#line 2017 "../src/../src/Parser/Parser.cc"

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
  "F64", "$accept", "program", "global_declaration",
  "variable_declaration", "type_declaration", "type_declaration_list",
  "type_declaration_member", "declaration_type", "type_mods", "type_mod",
  "type", "declaration", "declaration_hypothesis", "function_declaration",
  "parameter_list", "statement_list", "statement", "statement_box",
  "fn_statement_box", "flow_statement", "expression_statement",
  "initializer", "expression", "constant_expression",
  "assignment_expression", "atomic_expression", "postfix_expression",
  "unary_expression", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "assign_op", "unary_op", YY_NULLPTR
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


  const signed char Parser::yypact_ninf_ = -109;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      29,   -27,  -109,  -109,    -9,    19,  -109,    13,  -109,    37,
      64,  -109,    58,    72,  -109,  -109,  -109,   153,    80,    75,
      12,  -109,  -109,  -109,   153,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,   225,   225,  -109,  -109,  -109,  -109,  -109,
    -109,    25,     7,    44,    69,    -5,    45,   225,   145,  -109,
      80,   102,    36,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,   104,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,  -109,  -109,    87,    80,  -109,
    -109,   114,   113,    15,  -109,  -109,  -109,  -109,  -109,  -109,
      44,    44,    69,    69,    69,    69,    -5,    -5,    15,    75,
      50,  -109,    36,  -109,   214,  -109,  -109,   141,  -109,  -109,
    -109,  -109,  -109,   122,   141,  -109,  -109,   120,     6,  -109,
    -109,  -109,  -109,   121,  -109,    97,  -109,  -109,   153,  -109,
      88,  -109,   123,  -109,   125,  -109
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,    31,    32,     0,     0,     2,     0,     6,     8,
       0,     5,     0,     0,     1,     3,     4,     0,    15,    35,
       0,    95,    93,    94,     0,    92,    96,    58,    61,    62,
      59,    60,    57,     0,     0,    52,     7,    51,    55,    53,
      64,    67,    71,    75,    78,    83,    54,     0,     0,    30,
      15,     0,     0,    29,    28,    22,    23,    24,    25,    26,
      27,    17,     0,    68,    69,    65,    66,    86,    89,    90,
      91,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    17,    36,    15,    14,
      13,     0,    11,     9,    63,    56,    71,    73,    72,    74,
      76,    77,    79,    80,    81,    82,    84,    85,    16,    35,
       0,    10,     0,    19,     0,    18,    37,     0,    34,    46,
      33,    12,    20,     0,     0,    47,    48,     0,     0,    38,
      40,    42,    41,     0,    21,     0,    50,    43,     0,    39,
       0,    49,     0,    44,     0,    45
  };

  const short
  Parser::yypgoto_[] =
  {
    -109,  -109,   135,     4,   -50,    31,  -109,   -45,    59,  -109,
      96,  -109,  -109,    21,    40,    26,  -108,    41,  -109,  -109,
    -109,  -109,   -16,   -70,  -109,  -109,  -109,   -17,    42,    11,
      51,  -109,  -109,  -109
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,   127,     8,    91,    92,    49,    93,   115,
      61,     9,    10,    35,    51,   128,   129,   130,   120,   131,
     132,    36,   133,    38,    39,    40,    41,    96,    43,    44,
      45,    46,    73,    47
  };

  const unsigned char
  Parser::yytable_[] =
  {
      42,    37,    90,    95,     7,    87,    12,    42,    62,     7,
      67,    21,    22,    23,    79,    80,    63,    64,    24,    14,
     139,    11,   124,   137,    13,   113,    11,   139,    52,   114,
      85,    16,    25,    26,    27,    28,    29,    30,    31,    32,
      17,    33,    34,   110,   123,    53,    81,    82,    68,    69,
      70,    71,    72,    74,    75,    76,    89,    97,    98,    99,
      65,    66,    90,     1,     2,     3,   117,   138,   118,    54,
      19,   125,   126,    77,    78,    20,     1,     2,     3,     4,
      55,    56,    57,    58,    59,    60,     1,     2,     3,     4,
     102,   103,   104,   105,     2,     3,     4,    18,    83,    84,
      42,    48,    21,    22,    23,   143,   141,    42,    50,    24,
     109,    42,   140,   124,   137,    88,    89,    94,    42,   100,
     101,    42,   142,    25,    26,    27,    28,    29,    30,    31,
      32,   111,    33,    34,   106,   107,   112,   134,   136,   141,
      15,   144,   145,   121,    86,   108,    21,    22,    23,   116,
     135,   119,     0,    24,     1,     2,     3,   124,    21,    22,
      23,     0,   125,   126,     0,    24,     0,    25,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    53,    25,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     0,    54,     0,     0,     0,   125,   126,     0,     0,
       1,     0,     0,    55,    56,    57,    58,    59,    60,    21,
      22,    23,     0,     0,     0,     0,    24,     0,     0,   122,
      21,    22,    23,     0,     0,     0,     0,    24,     0,     0,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    25,    26,    27,    28,    29,    30,    31,    32,     0,
      33,    34
  };

  const short
  Parser::yycheck_[] =
  {
      17,    17,    52,    73,     0,    50,    33,    24,    24,     5,
       3,     5,     6,     7,    19,    20,    33,    34,    12,     0,
     128,     0,    16,    17,    33,    10,     5,   135,    16,    14,
      47,    18,    26,    27,    28,    29,    30,    31,    32,    33,
       3,    35,    36,    88,   114,    33,    51,    52,    41,    42,
      43,    44,    45,     9,    10,    11,    52,    74,    75,    76,
      35,    36,   112,    57,    58,    59,    16,    61,    18,    57,
      12,    65,    66,     4,     5,     3,    57,    58,    59,    60,
      68,    69,    70,    71,    72,    73,    57,    58,    59,    60,
      79,    80,    81,    82,    58,    59,    60,    33,    53,    54,
     117,    21,     5,     6,     7,    17,    18,   124,    33,    12,
      23,   128,   128,    16,    17,    13,   112,    13,   135,    77,
      78,   138,   138,    26,    27,    28,    29,    30,    31,    32,
      33,    17,    35,    36,    83,    84,    23,    15,    18,    18,
       5,    18,    17,   112,    48,    86,     5,     6,     7,   109,
     124,   110,    -1,    12,    57,    58,    59,    16,     5,     6,
       7,    -1,    65,    66,    -1,    12,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    33,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    -1,    57,    -1,    -1,    -1,    65,    66,    -1,    -1,
      57,    -1,    -1,    68,    69,    70,    71,    72,    73,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    15,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    57,    58,    59,    60,    75,    76,    77,    78,    85,
      86,    87,    33,    33,     0,    76,    18,     3,    33,    12,
       3,     5,     6,     7,    12,    26,    27,    28,    29,    30,
      31,    32,    33,    35,    36,    87,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   107,    21,    81,
      33,    88,    16,    33,    57,    68,    69,    70,    71,    72,
      73,    84,    96,   101,   101,    35,    36,     3,    41,    42,
      43,    44,    45,   106,     9,    10,    11,     4,     5,    19,
      20,    51,    52,    53,    54,   101,    84,    81,    13,    77,
      78,    79,    80,    82,    13,    97,   101,   101,   101,   101,
     102,   102,   103,   103,   103,   103,   104,   104,    82,    23,
      81,    17,    23,    10,    14,    83,    88,    16,    18,    91,
      92,    79,    15,    97,    16,    65,    66,    77,    89,    90,
      91,    93,    94,    96,    15,    89,    18,    17,    61,    90,
      96,    18,    96,    17,    18,    17
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    74,    75,    75,    76,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    83,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      90,    90,    90,    91,    92,    92,    92,    93,    93,    94,
      94,    95,    96,    96,    97,    98,    98,    99,    99,    99,
      99,    99,    99,    99,   100,   100,   100,   101,   101,   101,
     101,   102,   102,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   107,   107,   107,   107,   107
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     1,     3,     1,     5,
       6,     1,     3,     1,     1,     0,     3,     0,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     7,     7,     0,     2,     4,     1,     2,
       1,     1,     1,     3,     4,     6,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     2,     1,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
  };




#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   123,   123,   124,   128,   129,   130,   134,   135,   139,
     140,   145,   146,   151,   152,   157,   158,   163,   164,   169,
     170,   171,   175,   176,   177,   178,   179,   180,   181,   182,
     186,   190,   190,   194,   195,   200,   201,   202,   208,   209,
     213,   214,   215,   219,   223,   224,   225,   229,   229,   233,
     234,   238,   244,   245,   249,   254,   255,   264,   265,   266,
     267,   268,   269,   270,   274,   275,   276,   280,   281,   282,
     283,   288,   289,   290,   291,   295,   296,   297,   301,   302,
     303,   304,   305,   309,   310,   311,   316,   317,   318,   319,
     320,   321,   325,   326,   327,   328,   329
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


#line 6 "/home/espresso/projects/tape/src/parser.yy"
} // yy
#line 2709 "../src/../src/Parser/Parser.cc"

#line 332 "/home/espresso/projects/tape/src/parser.yy"
 

void yy::Parser::error(const location_type &loc, const std::string &msg) {
    std::cerr << loc << ": " << msg << std::endl;
}
