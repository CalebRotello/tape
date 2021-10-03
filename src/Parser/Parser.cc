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
#line 34 "/home/espresso/projects/tape/src/parser.yy"

    #include "Driver.hh"
    #include "../Ast/Ast.hh"
    #include "../Ast/SymbolRec.hh"

#line 111 "/home/espresso/projects/tape/src/parser.yy"

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
  Parser::Parser (Driver *driver_yyarg, StmtList *fstmt_list_yyarg, ScopeTree *scope_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      driver (driver_yyarg),
      fstmt_list (fstmt_list_yyarg),
      scope (scope_yyarg)
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
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 579 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PLUS: // "+"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 585 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MINUS: // "-"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 591 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AT: // "@"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 597 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP: // "&"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 603 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE: // "|"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 609 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FSLASH: // "/"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 615 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STAR: // "*"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 621 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MOD: // "%"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 627 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LPAREN: // "("
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 633 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RPAREN: // ")"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 639 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LSQUARE: // "["
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 645 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RSQUARE: // "]"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 651 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LBRACE: // "{"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 657 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RBRACE: // "}"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 663 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_SC: // ";"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 669 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LT: // "<"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 675 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_GT: // ">"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 681 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_COLON: // ":"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 687 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CARROT: // "^"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 693 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_COMMA: // ","
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 699 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_QUESTION: // "?"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 705 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_DOT: // "."
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 711 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BANG: // "!"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 717 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TILDE: // "~"
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 723 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < long long > (); }
#line 729 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < float > (); }
#line 735 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 741 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < char > (); }
#line 747 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < bool > (); }
#line 753 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ID: // ID
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 759 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_POINTER: // POINTER
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 765 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_INCREMENT: // INCREMENT
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 771 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_DECREMENT: // DECREMENT
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 777 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LEFT: // LEFT
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 783 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RIGHT: // RIGHT
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 789 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP_AMP: // AMP_AMP
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 795 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE_PIPE: // PIPE_PIPE
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 801 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_STAR_EQ: // STAR_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 807 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FSLASH_EQ: // FSLASH_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 813 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MOD_EQ: // MOD_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 819 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PLUS_EQ: // PLUS_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 825 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MINUS_EQ: // MINUS_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 831 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LEFT_EQ: // LEFT_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 837 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RIGHT_EQ: // RIGHT_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 843 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_AMP_EQ: // AMP_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 849 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CARROT_EQ: // CARROT_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 855 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_PIPE_EQ: // PIPE_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 861 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LT_EQ: // LT_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 867 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_GT_EQ: // GT_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 873 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_EQ_EQ: // EQ_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 879 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BANG_EQ: // BANG_EQ
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 885 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_IF: // IF
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 891 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 897 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FN: // FN
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 903 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_LET: // LET
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 909 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_VAR: // VAR
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 915 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_TYPE: // TYPE
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 921 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 927 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_FOR: // FOR
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 933 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 939 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_MATCH: // MATCH
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 945 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 951 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_CONTINUE: // CONTINUE
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 957 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I8: // I8
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 963 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I16: // I16
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 969 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I32: // I32
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 975 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_I64: // I64
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 981 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_F32: // F32
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 987 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_F64: // F64
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 993 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_U_I8: // U_I8
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 999 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_U_I16: // U_I16
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1005 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_U_I32: // U_I32
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1011 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_U_I64: // U_I64
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1017 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_U_F32: // U_F32
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1023 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_U_F64: // U_F64
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1029 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_program: // program
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < StmtList* > (); }
#line 1035 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_global_declaration: // global_declaration
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Stmt* > (); }
#line 1041 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < VarDeclStmt* > (); }
#line 1047 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_declaration: // type_declaration
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < TypeDeclStmt* > (); }
#line 1053 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_declaration_list: // type_declaration_list
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1059 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_declaration_member: // type_declaration_member
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1065 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_type: // declaration_type
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1071 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_mods: // type_mods
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1077 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type_mod: // type_mod
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1083 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_type: // type
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1089 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration: // declaration
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < VarDeclStmt* > (); }
#line 1095 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_declaration_hypothesis: // declaration_hypothesis
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < bool > (); }
#line 1101 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_function_declaration: // function_declaration
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < FunctionDeclStmt* > (); }
#line 1107 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_parameter_list: // parameter_list
#line 42 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << "<>"; }
#line 1113 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement_list: // statement_list
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < StmtList* > (); }
#line 1119 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement: // statement
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Stmt* > (); }
#line 1125 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_statement_box: // statement_box
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < StmtList* > (); }
#line 1131 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_fn_statement_box: // fn_statement_box
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < FunctionDeclStmt* > (); }
#line 1137 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_flow_statement: // flow_statement
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Stmt* > (); }
#line 1143 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_expression_statement: // expression_statement
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Stmt* > (); }
#line 1149 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_initializer: // initializer
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1155 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_expression: // expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1161 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_constant_expression: // constant_expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1167 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1173 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_atomic_expression: // atomic_expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1179 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1185 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_unary_expression: // unary_expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1191 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1197 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_additive_expression: // additive_expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1203 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_relational_expression: // relational_expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1209 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_equality_expression: // equality_expression
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < Expr* > (); }
#line 1215 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_assign_op: // assign_op
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1221 "../src/../src/Parser/Parser.cc"
        break;

      case symbol_kind::S_unary_op: // unary_op
#line 41 "/home/espresso/projects/tape/src/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 1227 "../src/../src/Parser/Parser.cc"
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
#line 125 "/home/espresso/projects/tape/src/parser.yy"
                                { fstmt_list->push_back(yystack_[0].value.as < Stmt* > ()); }
#line 1559 "../src/../src/Parser/Parser.cc"
    break;

  case 3: // program: program global_declaration
#line 126 "/home/espresso/projects/tape/src/parser.yy"
                                { fstmt_list->push_back(yystack_[0].value.as < Stmt* > ()); }
#line 1565 "../src/../src/Parser/Parser.cc"
    break;

  case 4: // global_declaration: variable_declaration ";"
#line 130 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = yystack_[1].value.as < VarDeclStmt* > (); }
#line 1571 "../src/../src/Parser/Parser.cc"
    break;

  case 5: // global_declaration: function_declaration
#line 131 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = yystack_[0].value.as < FunctionDeclStmt* > (); }
#line 1577 "../src/../src/Parser/Parser.cc"
    break;

  case 6: // global_declaration: type_declaration
#line 132 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = yystack_[0].value.as < TypeDeclStmt* > (); }
#line 1583 "../src/../src/Parser/Parser.cc"
    break;

  case 7: // variable_declaration: declaration "=" initializer
#line 136 "/home/espresso/projects/tape/src/parser.yy"
                                { yystack_[2].value.as < VarDeclStmt* > ()->setExpr(yystack_[0].value.as < Expr* > ()); yylhs.value.as < VarDeclStmt* > () = yystack_[2].value.as < VarDeclStmt* > (); }
#line 1589 "../src/../src/Parser/Parser.cc"
    break;

  case 8: // variable_declaration: declaration
#line 137 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < VarDeclStmt* > () = yystack_[0].value.as < VarDeclStmt* > (); }
#line 1595 "../src/../src/Parser/Parser.cc"
    break;

  case 9: // type_declaration: TYPE ID "=" type type_mods
#line 141 "/home/espresso/projects/tape/src/parser.yy"
                                                { yylhs.value.as < TypeDeclStmt* > () = new TypeDeclStmt(yystack_[3].value.as < std::string > ()); }
#line 1601 "../src/../src/Parser/Parser.cc"
    break;

  case 10: // type_declaration: TYPE ID "=" "{" type_declaration_list "}"
#line 142 "/home/espresso/projects/tape/src/parser.yy"
                                                { yylhs.value.as < TypeDeclStmt* > () = new TypeDeclStmt(yystack_[4].value.as < std::string > ()); }
#line 1607 "../src/../src/Parser/Parser.cc"
    break;

  case 22: // type: I8
#line 177 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::I8;    }
#line 1613 "../src/../src/Parser/Parser.cc"
    break;

  case 23: // type: I16
#line 178 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::I16;   }
#line 1619 "../src/../src/Parser/Parser.cc"
    break;

  case 24: // type: I32
#line 179 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::I32;   }
#line 1625 "../src/../src/Parser/Parser.cc"
    break;

  case 25: // type: I64
#line 180 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::I64;   }
#line 1631 "../src/../src/Parser/Parser.cc"
    break;

  case 26: // type: F32
#line 181 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::F32;   }
#line 1637 "../src/../src/Parser/Parser.cc"
    break;

  case 27: // type: F64
#line 182 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::F64;   }
#line 1643 "../src/../src/Parser/Parser.cc"
    break;

  case 28: // type: U_I8
#line 183 "/home/espresso/projects/tape/src/parser.yy"
          { yylhs.value.as < int > () = Type::U_I8;    }
#line 1649 "../src/../src/Parser/Parser.cc"
    break;

  case 29: // type: U_I16
#line 184 "/home/espresso/projects/tape/src/parser.yy"
          { yylhs.value.as < int > () = Type::U_I16;   }
#line 1655 "../src/../src/Parser/Parser.cc"
    break;

  case 30: // type: U_I32
#line 185 "/home/espresso/projects/tape/src/parser.yy"
          { yylhs.value.as < int > () = Type::U_I32;   }
#line 1661 "../src/../src/Parser/Parser.cc"
    break;

  case 31: // type: U_I64
#line 186 "/home/espresso/projects/tape/src/parser.yy"
          { yylhs.value.as < int > () = Type::U_I64;   }
#line 1667 "../src/../src/Parser/Parser.cc"
    break;

  case 32: // type: U_F32
#line 187 "/home/espresso/projects/tape/src/parser.yy"
          { yylhs.value.as < int > () = Type::U_F32;   }
#line 1673 "../src/../src/Parser/Parser.cc"
    break;

  case 33: // type: U_F64
#line 188 "/home/espresso/projects/tape/src/parser.yy"
          { yylhs.value.as < int > () = Type::U_F64;   }
#line 1679 "../src/../src/Parser/Parser.cc"
    break;

  case 34: // type: FN
#line 189 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::FN;    }
#line 1685 "../src/../src/Parser/Parser.cc"
    break;

  case 35: // type: ID
#line 190 "/home/espresso/projects/tape/src/parser.yy"
        { yylhs.value.as < int > () = Type::DEF;   }
#line 1691 "../src/../src/Parser/Parser.cc"
    break;

  case 36: // declaration: declaration_hypothesis ID declaration_type
#line 194 "/home/espresso/projects/tape/src/parser.yy"
                                               { yylhs.value.as < VarDeclStmt* > () = new VarDeclStmt(yystack_[1].value.as < std::string > (), yystack_[2].value.as < bool > ()); }
#line 1697 "../src/../src/Parser/Parser.cc"
    break;

  case 37: // declaration_hypothesis: LET
#line 198 "/home/espresso/projects/tape/src/parser.yy"
        {yylhs.value.as < bool > ()=false;}
#line 1703 "../src/../src/Parser/Parser.cc"
    break;

  case 38: // declaration_hypothesis: VAR
#line 198 "/home/espresso/projects/tape/src/parser.yy"
                         {yylhs.value.as < bool > ()=true;}
#line 1709 "../src/../src/Parser/Parser.cc"
    break;

  case 39: // function_declaration: FN ID "(" parameter_list ")" declaration_type fn_statement_box
#line 202 "/home/espresso/projects/tape/src/parser.yy"
                                                                    { yystack_[0].value.as < FunctionDeclStmt* > ()->setFnId(yystack_[5].value.as < std::string > ()); yylhs.value.as < FunctionDeclStmt* > () = yystack_[0].value.as < FunctionDeclStmt* > (); }
#line 1715 "../src/../src/Parser/Parser.cc"
    break;

  case 40: // function_declaration: FN ID "(" parameter_list ")" declaration_type ";"
#line 203 "/home/espresso/projects/tape/src/parser.yy"
                                                                    { yylhs.value.as < FunctionDeclStmt* > () = new FunctionDeclStmt(yystack_[5].value.as < std::string > ()); }
#line 1721 "../src/../src/Parser/Parser.cc"
    break;

  case 44: // statement_list: statement
#line 216 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < StmtList* > () = new StmtList({yystack_[0].value.as < Stmt* > ()}); }
#line 1727 "../src/../src/Parser/Parser.cc"
    break;

  case 45: // statement_list: statement_list statement
#line 217 "/home/espresso/projects/tape/src/parser.yy"
                                { yystack_[1].value.as < StmtList* > ()->push_back(yystack_[0].value.as < Stmt* > ()); yylhs.value.as < StmtList* > () = yystack_[1].value.as < StmtList* > (); }
#line 1733 "../src/../src/Parser/Parser.cc"
    break;

  case 46: // statement: statement_box
#line 221 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Stmt* > () = yystack_[0].value.as < StmtList* > (); }
#line 1739 "../src/../src/Parser/Parser.cc"
    break;

  case 47: // statement: expression_statement
#line 222 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Stmt* > () = yystack_[0].value.as < Stmt* > (); }
#line 1745 "../src/../src/Parser/Parser.cc"
    break;

  case 48: // statement: flow_statement
#line 223 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Stmt* > () = yystack_[0].value.as < Stmt* > (); }
#line 1751 "../src/../src/Parser/Parser.cc"
    break;

  case 49: // statement_box: "{" statement_list "}"
#line 227 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < StmtList* > () = yystack_[1].value.as < StmtList* > (); }
#line 1757 "../src/../src/Parser/Parser.cc"
    break;

  case 50: // fn_statement_box: "{" statement_list expression "}"
#line 231 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < FunctionDeclStmt* > () = new FunctionDeclStmt(yystack_[2].value.as < StmtList* > (), yystack_[1].value.as < Expr* > ()); }
#line 1763 "../src/../src/Parser/Parser.cc"
    break;

  case 51: // fn_statement_box: "{" statement_list RETURN expression ";" "}"
#line 232 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < FunctionDeclStmt* > () = new FunctionDeclStmt(yystack_[4].value.as < StmtList* > (), yystack_[2].value.as < Expr* > ()); }
#line 1769 "../src/../src/Parser/Parser.cc"
    break;

  case 52: // fn_statement_box: statement_box
#line 233 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < FunctionDeclStmt* > () = new FunctionDeclStmt(yystack_[0].value.as < StmtList* > ()); }
#line 1775 "../src/../src/Parser/Parser.cc"
    break;

  case 53: // flow_statement: BREAK
#line 237 "/home/espresso/projects/tape/src/parser.yy"
          { yylhs.value.as < Stmt* > () = new Break; }
#line 1781 "../src/../src/Parser/Parser.cc"
    break;

  case 54: // flow_statement: CONTINUE
#line 237 "/home/espresso/projects/tape/src/parser.yy"
                                         { yylhs.value.as < Stmt* > () = new Continue; }
#line 1787 "../src/../src/Parser/Parser.cc"
    break;

  case 55: // expression_statement: expression ";"
#line 241 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = new ExprStmt(yystack_[1].value.as < Expr* > ()); }
#line 1793 "../src/../src/Parser/Parser.cc"
    break;

  case 56: // expression_statement: variable_declaration ";"
#line 242 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Stmt* > () = yystack_[1].value.as < VarDeclStmt* > (); }
#line 1799 "../src/../src/Parser/Parser.cc"
    break;

  case 57: // initializer: expression
#line 246 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1805 "../src/../src/Parser/Parser.cc"
    break;

  case 58: // expression: function_declaration
#line 252 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Expr* > () = yystack_[0].value.as < FunctionDeclStmt* > ()->getFnId(); }
#line 1811 "../src/../src/Parser/Parser.cc"
    break;

  case 59: // expression: assignment_expression
#line 253 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1817 "../src/../src/Parser/Parser.cc"
    break;

  case 60: // constant_expression: equality_expression
#line 257 "/home/espresso/projects/tape/src/parser.yy"
                        { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1823 "../src/../src/Parser/Parser.cc"
    break;

  case 61: // assignment_expression: constant_expression
#line 262 "/home/espresso/projects/tape/src/parser.yy"
                        { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1829 "../src/../src/Parser/Parser.cc"
    break;

  case 62: // assignment_expression: unary_expression assign_op constant_expression
#line 263 "/home/espresso/projects/tape/src/parser.yy"
                                                    {
                                                        Expr *const_expr = yystack_[0].value.as < Expr* > ();
                                                        if (yystack_[1].value.as < int > () != skind_type::S_EQ)  
                                                            const_expr = new BopExpr(yystack_[1].value.as < int > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());
                                                        yylhs.value.as < Expr* > () = new AssignExpr((IdValue*)yystack_[2].value.as < Expr* > (), const_expr); // TODO implement a real "get id"
                                                    }
#line 1840 "../src/../src/Parser/Parser.cc"
    break;

  case 63: // atomic_expression: ID
#line 272 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new IdValue(yystack_[0].value.as < std::string > ());     }
#line 1846 "../src/../src/Parser/Parser.cc"
    break;

  case 64: // atomic_expression: INT_VAL
#line 273 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new IntValue(yystack_[0].value.as < long long > ());    }
#line 1852 "../src/../src/Parser/Parser.cc"
    break;

  case 65: // atomic_expression: CHAR_VAL
#line 274 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new IntValue(yystack_[0].value.as < char > ());    }
#line 1858 "../src/../src/Parser/Parser.cc"
    break;

  case 66: // atomic_expression: BOOL_VAL
#line 275 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new IntValue(yystack_[0].value.as < bool > ());    }
#line 1864 "../src/../src/Parser/Parser.cc"
    break;

  case 67: // atomic_expression: FLOAT_VAL
#line 276 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new FloatValue(yystack_[0].value.as < float > ());  }
#line 1870 "../src/../src/Parser/Parser.cc"
    break;

  case 68: // atomic_expression: STRING_VAL
#line 277 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < Expr* > () = new StrValue(yystack_[0].value.as < std::string > ());    }
#line 1876 "../src/../src/Parser/Parser.cc"
    break;

  case 69: // atomic_expression: "(" expression ")"
#line 278 "/home/espresso/projects/tape/src/parser.yy"
                       { yylhs.value.as < Expr* > () = yystack_[1].value.as < Expr* > ();           }
#line 1882 "../src/../src/Parser/Parser.cc"
    break;

  case 70: // postfix_expression: atomic_expression
#line 282 "/home/espresso/projects/tape/src/parser.yy"
                                    { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1888 "../src/../src/Parser/Parser.cc"
    break;

  case 71: // postfix_expression: postfix_expression INCREMENT
#line 283 "/home/espresso/projects/tape/src/parser.yy"
                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_PLUS, yystack_[1].value.as < Expr* > (), new IntValue(1));    }
#line 1894 "../src/../src/Parser/Parser.cc"
    break;

  case 72: // postfix_expression: postfix_expression DECREMENT
#line 284 "/home/espresso/projects/tape/src/parser.yy"
                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_MINUS, yystack_[1].value.as < Expr* > (), new IntValue(1));   }
#line 1900 "../src/../src/Parser/Parser.cc"
    break;

  case 73: // unary_expression: postfix_expression
#line 288 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1906 "../src/../src/Parser/Parser.cc"
    break;

  case 74: // unary_expression: INCREMENT unary_expression
#line 289 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_PLUS, yystack_[0].value.as < Expr* > (), new IntValue(1));  }
#line 1912 "../src/../src/Parser/Parser.cc"
    break;

  case 75: // unary_expression: DECREMENT unary_expression
#line 290 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_MINUS, yystack_[0].value.as < Expr* > (), new IntValue(1)); }
#line 1918 "../src/../src/Parser/Parser.cc"
    break;

  case 76: // unary_expression: unary_op unary_expression
#line 291 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = new UopExpr(yystack_[1].value.as < int > (), yystack_[0].value.as < Expr* > ()); }
#line 1924 "../src/../src/Parser/Parser.cc"
    break;

  case 77: // multiplicative_expression: unary_expression
#line 296 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1930 "../src/../src/Parser/Parser.cc"
    break;

  case 78: // multiplicative_expression: multiplicative_expression "*" unary_expression
#line 297 "/home/espresso/projects/tape/src/parser.yy"
                                                   { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_STAR, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());    }
#line 1936 "../src/../src/Parser/Parser.cc"
    break;

  case 79: // multiplicative_expression: multiplicative_expression "/" unary_expression
#line 298 "/home/espresso/projects/tape/src/parser.yy"
                                                   { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_FSLASH, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());  }
#line 1942 "../src/../src/Parser/Parser.cc"
    break;

  case 80: // multiplicative_expression: multiplicative_expression "%" unary_expression
#line 299 "/home/espresso/projects/tape/src/parser.yy"
                                                   { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_MOD, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());     }
#line 1948 "../src/../src/Parser/Parser.cc"
    break;

  case 81: // additive_expression: multiplicative_expression
#line 303 "/home/espresso/projects/tape/src/parser.yy"
                                { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1954 "../src/../src/Parser/Parser.cc"
    break;

  case 82: // additive_expression: additive_expression "+" multiplicative_expression
#line 304 "/home/espresso/projects/tape/src/parser.yy"
                                                      { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_PLUS, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); }
#line 1960 "../src/../src/Parser/Parser.cc"
    break;

  case 83: // additive_expression: additive_expression "-" multiplicative_expression
#line 305 "/home/espresso/projects/tape/src/parser.yy"
                                                      { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_MINUS, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());}
#line 1966 "../src/../src/Parser/Parser.cc"
    break;

  case 84: // relational_expression: additive_expression
#line 309 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 1972 "../src/../src/Parser/Parser.cc"
    break;

  case 85: // relational_expression: relational_expression "<" additive_expression
#line 310 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_LT, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());     }
#line 1978 "../src/../src/Parser/Parser.cc"
    break;

  case 86: // relational_expression: relational_expression ">" additive_expression
#line 311 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_GT, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());     }
#line 1984 "../src/../src/Parser/Parser.cc"
    break;

  case 87: // relational_expression: relational_expression LT_EQ additive_expression
#line 312 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_LT_EQ, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());  }
#line 1990 "../src/../src/Parser/Parser.cc"
    break;

  case 88: // relational_expression: relational_expression GT_EQ additive_expression
#line 313 "/home/espresso/projects/tape/src/parser.yy"
                                                    { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_GT_EQ, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());  }
#line 1996 "../src/../src/Parser/Parser.cc"
    break;

  case 89: // equality_expression: relational_expression
#line 317 "/home/espresso/projects/tape/src/parser.yy"
                            { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); }
#line 2002 "../src/../src/Parser/Parser.cc"
    break;

  case 90: // equality_expression: equality_expression EQ_EQ relational_expression
#line 318 "/home/espresso/projects/tape/src/parser.yy"
                                                      { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_EQ_EQ, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());  }
#line 2008 "../src/../src/Parser/Parser.cc"
    break;

  case 91: // equality_expression: equality_expression BANG_EQ relational_expression
#line 319 "/home/espresso/projects/tape/src/parser.yy"
                                                      { yylhs.value.as < Expr* > () = new BopExpr(skind_type::S_BANG_EQ, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ());}
#line 2014 "../src/../src/Parser/Parser.cc"
    break;

  case 92: // assign_op: "="
#line 324 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_EQ;        }
#line 2020 "../src/../src/Parser/Parser.cc"
    break;

  case 93: // assign_op: PLUS_EQ
#line 325 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_PLUS;      }
#line 2026 "../src/../src/Parser/Parser.cc"
    break;

  case 94: // assign_op: MINUS_EQ
#line 326 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_MINUS;     }
#line 2032 "../src/../src/Parser/Parser.cc"
    break;

  case 95: // assign_op: STAR_EQ
#line 327 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_STAR;      }
#line 2038 "../src/../src/Parser/Parser.cc"
    break;

  case 96: // assign_op: FSLASH_EQ
#line 328 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_FSLASH;    }
#line 2044 "../src/../src/Parser/Parser.cc"
    break;

  case 97: // assign_op: MOD_EQ
#line 329 "/home/espresso/projects/tape/src/parser.yy"
                { yylhs.value.as < int > () = skind_type::S_MOD;       }
#line 2050 "../src/../src/Parser/Parser.cc"
    break;

  case 98: // unary_op: "!"
#line 333 "/home/espresso/projects/tape/src/parser.yy"
            { yylhs.value.as < int > () = skind_type::S_BANG;    }
#line 2056 "../src/../src/Parser/Parser.cc"
    break;

  case 99: // unary_op: "@"
#line 334 "/home/espresso/projects/tape/src/parser.yy"
            { yylhs.value.as < int > () = skind_type::S_AT;      }
#line 2062 "../src/../src/Parser/Parser.cc"
    break;

  case 100: // unary_op: "&"
#line 335 "/home/espresso/projects/tape/src/parser.yy"
            { yylhs.value.as < int > () = skind_type::S_AMP;     }
#line 2068 "../src/../src/Parser/Parser.cc"
    break;

  case 101: // unary_op: "-"
#line 336 "/home/espresso/projects/tape/src/parser.yy"
            { yylhs.value.as < int > () = skind_type::S_MINUS;   }
#line 2074 "../src/../src/Parser/Parser.cc"
    break;

  case 102: // unary_op: "~"
#line 337 "/home/espresso/projects/tape/src/parser.yy"
            { yylhs.value.as < int > () = skind_type::S_TILDE;   }
#line 2080 "../src/../src/Parser/Parser.cc"
    break;


#line 2084 "../src/../src/Parser/Parser.cc"

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
  "BREAK", "CONTINUE", "I8", "I16", "I32", "I64", "F32", "F64", "U_I8",
  "U_I16", "U_I32", "U_I64", "U_F32", "U_F64", "$accept", "program",
  "global_declaration", "variable_declaration", "type_declaration",
  "type_declaration_list", "type_declaration_member", "declaration_type",
  "type_mods", "type_mod", "type", "declaration", "declaration_hypothesis",
  "function_declaration", "parameter_list", "statement_list", "statement",
  "statement_box", "fn_statement_box", "flow_statement",
  "expression_statement", "initializer", "expression",
  "constant_expression", "assignment_expression", "atomic_expression",
  "postfix_expression", "unary_expression", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "assign_op", "unary_op", YY_NULLPTR
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


  const short Parser::yypact_ninf_ = -129;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -38,   -22,  -129,  -129,   -10,    24,  -129,    78,  -129,    33,
      66,  -129,    90,   100,  -129,  -129,  -129,   216,    83,    72,
       2,  -129,  -129,  -129,   216,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,   284,   284,  -129,  -129,  -129,  -129,  -129,
    -129,    -2,     9,    51,    62,     6,    39,   284,   -30,  -129,
      83,    94,    31,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,    98,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,  -129,  -129,    89,    83,  -129,  -129,    97,    93,    18,
    -129,  -129,  -129,  -129,  -129,  -129,    51,    51,    62,    62,
      62,    62,     6,     6,    18,    72,    13,  -129,    31,  -129,
     252,  -129,  -129,   204,  -129,  -129,  -129,  -129,  -129,   106,
     204,  -129,  -129,   105,   103,  -129,  -129,  -129,  -129,   107,
    -129,   160,  -129,  -129,   216,  -129,    77,  -129,   108,  -129,
     120,  -129
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,    37,    38,     0,     0,     2,     0,     6,     8,
       0,     5,     0,     0,     1,     3,     4,     0,    15,    41,
       0,   101,    99,   100,     0,    98,   102,    64,    67,    68,
      65,    66,    63,     0,     0,    58,     7,    57,    61,    59,
      70,    73,    77,    81,    84,    89,    60,     0,     0,    36,
      15,     0,     0,    35,    34,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    17,     0,    74,
      75,    71,    72,    92,    95,    96,    97,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    17,    42,    15,    14,    13,     0,    11,     9,
      69,    62,    77,    79,    78,    80,    82,    83,    85,    86,
      87,    88,    90,    91,    16,    41,     0,    10,     0,    19,
       0,    18,    43,     0,    40,    52,    39,    12,    20,     0,
       0,    53,    54,     0,     0,    44,    46,    48,    47,     0,
      21,     0,    56,    49,     0,    45,     0,    55,     0,    50,
       0,    51
  };

  const short
  Parser::yypgoto_[] =
  {
    -129,  -129,   135,     4,   -50,    23,  -129,   -45,    50,  -129,
      95,  -129,  -129,    10,    29,    15,  -128,    30,  -129,  -129,
    -129,  -129,   -16,   -65,  -129,  -129,  -129,   -17,    14,     0,
      11,  -129,  -129,  -129
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,   133,     8,    97,    98,    49,    99,   121,
      67,     9,    10,    35,    51,   134,   135,   136,   126,   137,
     138,    36,   139,    38,    39,    40,    41,   102,    43,    44,
      45,    46,    79,    47
  };

  const unsigned char
  Parser::yytable_[] =
  {
      42,    37,    96,    53,     7,    93,   145,    42,    68,     7,
      11,    12,    73,   145,   101,    11,    69,    70,    52,     1,
       2,     3,     4,    13,    14,    85,    86,    54,   119,   123,
      91,   124,   120,    71,    72,    53,    17,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   116,
      74,    75,    76,    77,    78,   129,    95,    87,    88,    54,
      80,    81,    82,   103,   104,   105,    83,    84,    96,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     1,     2,     3,     4,   108,   109,   110,   111,     2,
       3,     4,    89,    90,   149,   147,    16,   106,   107,    18,
     112,   113,    19,    20,    48,    50,    42,    94,    21,    22,
      23,   100,   115,    42,   117,    24,   118,    42,   146,   130,
     143,   140,    95,   142,    42,   147,   150,    42,   148,    25,
      26,    27,    28,    29,    30,    31,    32,   151,    33,    34,
      15,   127,   114,    92,   122,   141,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     0,   144,    21,    22,    23,   131,   132,
       0,     0,    24,     0,     0,     0,   130,   143,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,    23,     0,     0,     0,     0,    24,     1,     2,     3,
     130,    21,    22,    23,     0,   131,   132,     0,    24,     0,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,     0,    25,    26,    27,    28,    29,    30,    31,    32,
       0,    33,    34,     0,     0,     0,     0,    21,    22,    23,
       0,     1,     2,     3,    24,     0,     0,   128,     0,   131,
     132,     0,     0,     1,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    21,
      22,    23,     0,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34
  };

  const short
  Parser::yycheck_[] =
  {
      17,    17,    52,    33,     0,    50,   134,    24,    24,     5,
       0,    33,     3,   141,    79,     5,    33,    34,    16,    57,
      58,    59,    60,    33,     0,    19,    20,    57,    10,    16,
      47,    18,    14,    35,    36,    33,     3,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    94,
      41,    42,    43,    44,    45,   120,    52,    51,    52,    57,
       9,    10,    11,    80,    81,    82,     4,     5,   118,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    57,    58,    59,    60,    85,    86,    87,    88,    58,
      59,    60,    53,    54,    17,    18,    18,    83,    84,    33,
      89,    90,    12,     3,    21,    33,   123,    13,     5,     6,
       7,    13,    23,   130,    17,    12,    23,   134,   134,    16,
      17,    15,   118,    18,   141,    18,    18,   144,   144,    26,
      27,    28,    29,    30,    31,    32,    33,    17,    35,    36,
       5,   118,    92,    48,   115,   130,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    61,     5,     6,     7,    65,    66,
      -1,    -1,    12,    -1,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    57,    58,    59,
      16,     5,     6,     7,    -1,    65,    66,    -1,    12,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,     5,     6,     7,
      -1,    57,    58,    59,    12,    -1,    -1,    15,    -1,    65,
      66,    -1,    -1,    57,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    57,    58,    59,    60,    80,    81,    82,    83,    90,
      91,    92,    33,    33,     0,    81,    18,     3,    33,    12,
       3,     5,     6,     7,    12,    26,    27,    28,    29,    30,
      31,    32,    33,    35,    36,    92,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   112,    21,    86,
      33,    93,    16,    33,    57,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    89,   101,   106,
     106,    35,    36,     3,    41,    42,    43,    44,    45,   111,
       9,    10,    11,     4,     5,    19,    20,    51,    52,    53,
      54,   106,    89,    86,    13,    82,    83,    84,    85,    87,
      13,   102,   106,   106,   106,   106,   107,   107,   108,   108,
     108,   108,   109,   109,    87,    23,    86,    17,    23,    10,
      14,    88,    93,    16,    18,    96,    97,    84,    15,   102,
      16,    65,    66,    82,    94,    95,    96,    98,    99,   101,
      15,    94,    18,    17,    61,    95,   101,    18,   101,    17,
      18,    17
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    79,    80,    80,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    91,    91,    92,
      92,    93,    93,    93,    94,    94,    95,    95,    95,    96,
      97,    97,    97,    98,    98,    99,    99,   100,   101,   101,
     102,   103,   103,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   105,   106,   106,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   109,   109,   109,   109,   109,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   112
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     1,     3,     1,     5,
       6,     1,     3,     1,     1,     0,     3,     0,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     7,
       7,     0,     2,     4,     1,     2,     1,     1,     1,     3,
       4,     6,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     2,     2,     2,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };




#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   125,   125,   126,   130,   131,   132,   136,   137,   141,
     142,   147,   148,   153,   154,   159,   160,   165,   166,   171,
     172,   173,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   194,   198,   198,   202,
     203,   208,   209,   210,   216,   217,   221,   222,   223,   227,
     231,   232,   233,   237,   237,   241,   242,   246,   252,   253,
     257,   262,   263,   272,   273,   274,   275,   276,   277,   278,
     282,   283,   284,   288,   289,   290,   291,   296,   297,   298,
     299,   303,   304,   305,   309,   310,   311,   312,   313,   317,
     318,   319,   324,   325,   326,   327,   328,   329,   333,   334,
     335,   336,   337
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
#line 2795 "../src/../src/Parser/Parser.cc"

#line 340 "/home/espresso/projects/tape/src/parser.yy"
 

void yy::Parser::error(const location_type &loc, const std::string &msg) {
    std::cerr << loc << ": " << msg << std::endl;
}
