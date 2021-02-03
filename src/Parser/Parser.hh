// A Bison parser, made by GNU Bison 3.7.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file ../src/../src/Parser/Parser.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_SRC_SRC_PARSER_PARSER_HH_INCLUDED
# define YY_YY_SRC_SRC_PARSER_PARSER_HH_INCLUDED
// "%code requires" blocks.
#line 13 "/home/espresso/projects/tape/src/Bison/parser.yy"

    #include <string>
    int char_to_sym(char c);
    class Driver;

    class Value;
    class Expression;

#line 58 "../src/../src/Parser/Parser.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 7 "/home/espresso/projects/tape/src/Bison/parser.yy"
namespace yy {
#line 193 "../src/../src/Parser/Parser.hh"




  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // atomic_expression
      // postfix_expression
      // unary_expression
      // cast_expression
      // multiplicative_expression
      // additive_expression
      // shift_expression
      // relational_expression
      // equality_expression
      // and_expression
      // exclusive_or_expression
      // inclusive_or_expression
      // logical_and_expression
      // logical_or_expression
      // conditional_expression
      // assignment_expression
      // expression
      // constant_expression
      char dummy1[sizeof (Expression*)];

      // function_definition
      char dummy2[sizeof (FunctionDecl*)];

      // object_declaration_expression
      char dummy3[sizeof (ObjDecl*)];

      // global_declaration
      char dummy4[sizeof (Statement*)];

      // declaration_expression
      char dummy5[sizeof (VarDecl*)];

      // BOOL_VAL
      char dummy6[sizeof (bool)];

      // CHAR_VAL
      char dummy7[sizeof (char)];

      // FLOAT_VAL
      char dummy8[sizeof (float)];

      // assignment_operator
      // unary_operator
      char dummy9[sizeof (int)];

      // INT_VAL
      char dummy10[sizeof (long long)];

      // STRING_VAL
      // ID
      char dummy11[sizeof (std::string)];

      // argument_expression_list
      char dummy12[sizeof (std::vector<Expression*>*)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 1,                   // error
    YYUNDEF = 2,                   // "invalid token"
    EQ = 3,                        // "="
    PLUS = 4,                      // "+"
    MINUS = 5,                     // "-"
    AT = 6,                        // "@"
    AMP = 7,                       // "&"
    PIPE = 8,                      // "|"
    FSLASH = 9,                    // "/"
    STAR = 10,                     // "*"
    MOD = 11,                      // "%"
    LPAREN = 12,                   // "("
    RPAREN = 13,                   // ")"
    LSQUARE = 14,                  // "["
    RSQUARE = 15,                  // "]"
    LBRACE = 16,                   // "{"
    RBRACE = 17,                   // "}"
    SC = 18,                       // ";"
    LT = 19,                       // "<"
    GT = 20,                       // ">"
    COLON = 21,                    // ":"
    CARROT = 22,                   // "^"
    COMMA = 23,                    // ","
    QUESTION = 24,                 // "?"
    DOT = 25,                      // "."
    BANG = 26,                     // "!"
    TILDE = 27,                    // "~"
    INT_VAL = 28,                  // INT_VAL
    FLOAT_VAL = 29,                // FLOAT_VAL
    STRING_VAL = 30,               // STRING_VAL
    CHAR_VAL = 31,                 // CHAR_VAL
    BOOL_VAL = 32,                 // BOOL_VAL
    TYPE_NAME = 33,                // TYPE_NAME
    ID = 34,                       // ID
    POINTER = 35,                  // POINTER
    INCREMENT = 36,                // INCREMENT
    DECREMENT = 37,                // DECREMENT
    LEFT = 38,                     // LEFT
    RIGHT = 39,                    // RIGHT
    AMP_AMP = 40,                  // AMP_AMP
    PIPE_PIPE = 41,                // PIPE_PIPE
    STAR_EQ = 42,                  // STAR_EQ
    FSLASH_EQ = 43,                // FSLASH_EQ
    MOD_EQ = 44,                   // MOD_EQ
    PLUS_EQ = 45,                  // PLUS_EQ
    MINUS_EQ = 46,                 // MINUS_EQ
    LEFT_EQ = 47,                  // LEFT_EQ
    RIGHT_EQ = 48,                 // RIGHT_EQ
    AMP_EQ = 49,                   // AMP_EQ
    CARROT_EQ = 50,                // CARROT_EQ
    PIPE_EQ = 51,                  // PIPE_EQ
    LT_EQ = 52,                    // LT_EQ
    GT_EQ = 53,                    // GT_EQ
    EQ_EQ = 54,                    // EQ_EQ
    BANG_EQ = 55,                  // BANG_EQ
    TYPEDEF = 56,                  // TYPEDEF
    EXTERN = 57,                   // EXTERN
    STATIC = 58,                   // STATIC
    AUTO = 59,                     // AUTO
    REGISTER = 60,                 // REGISTER
    SIZEOF = 61,                   // SIZEOF
    CHAR = 62,                     // CHAR
    SIGNED = 63,                   // SIGNED
    UNSIGNED = 64,                 // UNSIGNED
    CONST = 65,                    // CONST
    VOLATILE = 66,                 // VOLATILE
    VOID = 67,                     // VOID
    BOOL = 68,                     // BOOL
    LAMBDA = 69,                   // LAMBDA
    I8 = 70,                       // I8
    I16 = 71,                      // I16
    I32 = 72,                      // I32
    I64 = 73,                      // I64
    F32 = 74,                      // F32
    F64 = 75,                      // F64
    STRUCT = 76,                   // STRUCT
    UNION = 77,                    // UNION
    ENUM = 78,                     // ENUM
    ELLIPSIS = 79,                 // ELLIPSIS
    FN = 80,                       // FN
    LET = 81,                      // LET
    CASE = 82,                     // CASE
    DEFAULT = 83,                  // DEFAULT
    IF = 84,                       // IF
    ELSE = 85,                     // ELSE
    SWITCH = 86,                   // SWITCH
    WHILE = 87,                    // WHILE
    FOR = 88,                      // FOR
    CONTINUE = 89,                 // CONTINUE
    BREAK = 90,                    // BREAK
    RETURN = 91                    // RETURN
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 92, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_EQ = 3,                                // "="
        S_PLUS = 4,                              // "+"
        S_MINUS = 5,                             // "-"
        S_AT = 6,                                // "@"
        S_AMP = 7,                               // "&"
        S_PIPE = 8,                              // "|"
        S_FSLASH = 9,                            // "/"
        S_STAR = 10,                             // "*"
        S_MOD = 11,                              // "%"
        S_LPAREN = 12,                           // "("
        S_RPAREN = 13,                           // ")"
        S_LSQUARE = 14,                          // "["
        S_RSQUARE = 15,                          // "]"
        S_LBRACE = 16,                           // "{"
        S_RBRACE = 17,                           // "}"
        S_SC = 18,                               // ";"
        S_LT = 19,                               // "<"
        S_GT = 20,                               // ">"
        S_COLON = 21,                            // ":"
        S_CARROT = 22,                           // "^"
        S_COMMA = 23,                            // ","
        S_QUESTION = 24,                         // "?"
        S_DOT = 25,                              // "."
        S_BANG = 26,                             // "!"
        S_TILDE = 27,                            // "~"
        S_INT_VAL = 28,                          // INT_VAL
        S_FLOAT_VAL = 29,                        // FLOAT_VAL
        S_STRING_VAL = 30,                       // STRING_VAL
        S_CHAR_VAL = 31,                         // CHAR_VAL
        S_BOOL_VAL = 32,                         // BOOL_VAL
        S_TYPE_NAME = 33,                        // TYPE_NAME
        S_ID = 34,                               // ID
        S_POINTER = 35,                          // POINTER
        S_INCREMENT = 36,                        // INCREMENT
        S_DECREMENT = 37,                        // DECREMENT
        S_LEFT = 38,                             // LEFT
        S_RIGHT = 39,                            // RIGHT
        S_AMP_AMP = 40,                          // AMP_AMP
        S_PIPE_PIPE = 41,                        // PIPE_PIPE
        S_STAR_EQ = 42,                          // STAR_EQ
        S_FSLASH_EQ = 43,                        // FSLASH_EQ
        S_MOD_EQ = 44,                           // MOD_EQ
        S_PLUS_EQ = 45,                          // PLUS_EQ
        S_MINUS_EQ = 46,                         // MINUS_EQ
        S_LEFT_EQ = 47,                          // LEFT_EQ
        S_RIGHT_EQ = 48,                         // RIGHT_EQ
        S_AMP_EQ = 49,                           // AMP_EQ
        S_CARROT_EQ = 50,                        // CARROT_EQ
        S_PIPE_EQ = 51,                          // PIPE_EQ
        S_LT_EQ = 52,                            // LT_EQ
        S_GT_EQ = 53,                            // GT_EQ
        S_EQ_EQ = 54,                            // EQ_EQ
        S_BANG_EQ = 55,                          // BANG_EQ
        S_TYPEDEF = 56,                          // TYPEDEF
        S_EXTERN = 57,                           // EXTERN
        S_STATIC = 58,                           // STATIC
        S_AUTO = 59,                             // AUTO
        S_REGISTER = 60,                         // REGISTER
        S_SIZEOF = 61,                           // SIZEOF
        S_CHAR = 62,                             // CHAR
        S_SIGNED = 63,                           // SIGNED
        S_UNSIGNED = 64,                         // UNSIGNED
        S_CONST = 65,                            // CONST
        S_VOLATILE = 66,                         // VOLATILE
        S_VOID = 67,                             // VOID
        S_BOOL = 68,                             // BOOL
        S_LAMBDA = 69,                           // LAMBDA
        S_I8 = 70,                               // I8
        S_I16 = 71,                              // I16
        S_I32 = 72,                              // I32
        S_I64 = 73,                              // I64
        S_F32 = 74,                              // F32
        S_F64 = 75,                              // F64
        S_STRUCT = 76,                           // STRUCT
        S_UNION = 77,                            // UNION
        S_ENUM = 78,                             // ENUM
        S_ELLIPSIS = 79,                         // ELLIPSIS
        S_FN = 80,                               // FN
        S_LET = 81,                              // LET
        S_CASE = 82,                             // CASE
        S_DEFAULT = 83,                          // DEFAULT
        S_IF = 84,                               // IF
        S_ELSE = 85,                             // ELSE
        S_SWITCH = 86,                           // SWITCH
        S_WHILE = 87,                            // WHILE
        S_FOR = 88,                              // FOR
        S_CONTINUE = 89,                         // CONTINUE
        S_BREAK = 90,                            // BREAK
        S_RETURN = 91,                           // RETURN
        S_YYACCEPT = 92,                         // $accept
        S_program = 93,                          // program
        S_global_declaration = 94,               // global_declaration
        S_function_definition = 95,              // function_definition
        S_parameter_list = 96,                   // parameter_list
        S_parameter = 97,                        // parameter
        S_declaration_list = 98,                 // declaration_list
        S_declaration = 99,                      // declaration
        S_object_declaration_expression = 100,   // object_declaration_expression
        S_id_list = 101,                         // id_list
        S_struct_or_union = 102,                 // struct_or_union
        S_declaration_specifier = 103,           // declaration_specifier
        S_type_suffix_list = 104,                // type_suffix_list
        S_type_suffix = 105,                     // type_suffix
        S_type_name = 106,                       // type_name
        S_type_qualifier = 107,                  // type_qualifier
        S_initializer = 108,                     // initializer
        S_initializer_list = 109,                // initializer_list
        S_statement_list = 110,                  // statement_list
        S_statement = 111,                       // statement
        S_conditional_statement = 112,           // conditional_statement
        S_compound_statement = 113,              // compound_statement
        S_labeled_statement = 114,               // labeled_statement
        S_jump_statement = 115,                  // jump_statement
        S_expression_statement = 116,            // expression_statement
        S_declaration_expression = 117,          // declaration_expression
        S_switch_statement = 118,                // switch_statement
        S_iteration_statement = 119,             // iteration_statement
        S_atomic_expression = 120,               // atomic_expression
        S_postfix_expression = 121,              // postfix_expression
        S_argument_expression_list = 122,        // argument_expression_list
        S_unary_expression = 123,                // unary_expression
        S_cast_expression = 124,                 // cast_expression
        S_multiplicative_expression = 125,       // multiplicative_expression
        S_additive_expression = 126,             // additive_expression
        S_shift_expression = 127,                // shift_expression
        S_relational_expression = 128,           // relational_expression
        S_equality_expression = 129,             // equality_expression
        S_and_expression = 130,                  // and_expression
        S_exclusive_or_expression = 131,         // exclusive_or_expression
        S_inclusive_or_expression = 132,         // inclusive_or_expression
        S_logical_and_expression = 133,          // logical_and_expression
        S_logical_or_expression = 134,           // logical_or_expression
        S_conditional_expression = 135,          // conditional_expression
        S_assignment_expression = 136,           // assignment_expression
        S_expression = 137,                      // expression
        S_constant_expression = 138,             // constant_expression
        S_assignment_operator = 139,             // assignment_operator
        S_unary_operator = 140                   // unary_operator
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
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
        value.move< Expression* > (std::move (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< FunctionDecl* > (std::move (that.value));
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
        value.move< ObjDecl* > (std::move (that.value));
        break;

      case symbol_kind::S_global_declaration: // global_declaration
        value.move< Statement* > (std::move (that.value));
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
        value.move< VarDecl* > (std::move (that.value));
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.move< char > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.move< float > (std::move (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.move< long long > (std::move (that.value));
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<Expression*>* > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Expression*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Expression*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FunctionDecl*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FunctionDecl*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ObjDecl*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ObjDecl*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Statement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Statement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VarDecl*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VarDecl*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, char&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const char& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, float&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const float& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, long long&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const long long& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Expression*>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Expression*>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
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
        value.template destroy< Expression* > ();
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.template destroy< FunctionDecl* > ();
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
        value.template destroy< ObjDecl* > ();
        break;

      case symbol_kind::S_global_declaration: // global_declaration
        value.template destroy< Statement* > ();
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
        value.template destroy< VarDecl* > ();
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.template destroy< char > ();
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.template destroy< float > ();
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
      case symbol_kind::S_unary_operator: // unary_operator
        value.template destroy< int > ();
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.template destroy< long long > ();
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.template destroy< std::vector<Expression*>* > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::YYEOF || tok == token::YYerror || tok == token::YYUNDEF || tok == token::EQ || tok == token::PLUS || tok == token::MINUS || tok == token::AT || tok == token::AMP || tok == token::PIPE || tok == token::FSLASH || tok == token::STAR || tok == token::MOD || tok == token::LPAREN || tok == token::RPAREN || tok == token::LSQUARE || tok == token::RSQUARE || tok == token::LBRACE || tok == token::RBRACE || tok == token::SC || tok == token::LT || tok == token::GT || tok == token::COLON || tok == token::CARROT || tok == token::COMMA || tok == token::QUESTION || tok == token::DOT || tok == token::BANG || tok == token::TILDE || tok == token::TYPE_NAME || tok == token::POINTER || tok == token::INCREMENT || tok == token::DECREMENT || tok == token::LEFT || tok == token::RIGHT || tok == token::AMP_AMP || tok == token::PIPE_PIPE || tok == token::STAR_EQ || tok == token::FSLASH_EQ || tok == token::MOD_EQ || tok == token::PLUS_EQ || tok == token::MINUS_EQ || tok == token::LEFT_EQ || tok == token::RIGHT_EQ || tok == token::AMP_EQ || tok == token::CARROT_EQ || tok == token::PIPE_EQ || tok == token::LT_EQ || tok == token::GT_EQ || tok == token::EQ_EQ || tok == token::BANG_EQ || tok == token::TYPEDEF || tok == token::EXTERN || tok == token::STATIC || tok == token::AUTO || tok == token::REGISTER || tok == token::SIZEOF || tok == token::CHAR || tok == token::SIGNED || tok == token::UNSIGNED || tok == token::CONST || tok == token::VOLATILE || tok == token::VOID || tok == token::BOOL || tok == token::LAMBDA || tok == token::I8 || tok == token::I16 || tok == token::I32 || tok == token::I64 || tok == token::F32 || tok == token::F64 || tok == token::STRUCT || tok == token::UNION || tok == token::ENUM || tok == token::ELLIPSIS || tok == token::FN || tok == token::LET || tok == token::CASE || tok == token::DEFAULT || tok == token::IF || tok == token::ELSE || tok == token::SWITCH || tok == token::WHILE || tok == token::FOR || tok == token::CONTINUE || tok == token::BREAK || tok == token::RETURN);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::YYEOF || tok == token::YYerror || tok == token::YYUNDEF || tok == token::EQ || tok == token::PLUS || tok == token::MINUS || tok == token::AT || tok == token::AMP || tok == token::PIPE || tok == token::FSLASH || tok == token::STAR || tok == token::MOD || tok == token::LPAREN || tok == token::RPAREN || tok == token::LSQUARE || tok == token::RSQUARE || tok == token::LBRACE || tok == token::RBRACE || tok == token::SC || tok == token::LT || tok == token::GT || tok == token::COLON || tok == token::CARROT || tok == token::COMMA || tok == token::QUESTION || tok == token::DOT || tok == token::BANG || tok == token::TILDE || tok == token::TYPE_NAME || tok == token::POINTER || tok == token::INCREMENT || tok == token::DECREMENT || tok == token::LEFT || tok == token::RIGHT || tok == token::AMP_AMP || tok == token::PIPE_PIPE || tok == token::STAR_EQ || tok == token::FSLASH_EQ || tok == token::MOD_EQ || tok == token::PLUS_EQ || tok == token::MINUS_EQ || tok == token::LEFT_EQ || tok == token::RIGHT_EQ || tok == token::AMP_EQ || tok == token::CARROT_EQ || tok == token::PIPE_EQ || tok == token::LT_EQ || tok == token::GT_EQ || tok == token::EQ_EQ || tok == token::BANG_EQ || tok == token::TYPEDEF || tok == token::EXTERN || tok == token::STATIC || tok == token::AUTO || tok == token::REGISTER || tok == token::SIZEOF || tok == token::CHAR || tok == token::SIGNED || tok == token::UNSIGNED || tok == token::CONST || tok == token::VOLATILE || tok == token::VOID || tok == token::BOOL || tok == token::LAMBDA || tok == token::I8 || tok == token::I16 || tok == token::I32 || tok == token::I64 || tok == token::F32 || tok == token::F64 || tok == token::STRUCT || tok == token::UNION || tok == token::ENUM || tok == token::ELLIPSIS || tok == token::FN || tok == token::LET || tok == token::CASE || tok == token::DEFAULT || tok == token::IF || tok == token::ELSE || tok == token::SWITCH || tok == token::WHILE || tok == token::FOR || tok == token::CONTINUE || tok == token::BREAK || tok == token::RETURN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::BOOL_VAL);
      }
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::BOOL_VAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, char v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::CHAR_VAL);
      }
#else
      symbol_type (int tok, const char& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::CHAR_VAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, float v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::FLOAT_VAL);
      }
#else
      symbol_type (int tok, const float& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::FLOAT_VAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, long long v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::INT_VAL);
      }
#else
      symbol_type (int tok, const long long& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::INT_VAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::STRING_VAL || tok == token::ID);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::STRING_VAL || tok == token::ID);
      }
#endif
    };

    /// Build a parser object.
    Parser (Driver *driver_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (location_type l)
      {
        return symbol_type (token::EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const location_type& l)
      {
        return symbol_type (token::EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT (location_type l)
      {
        return symbol_type (token::AT, std::move (l));
      }
#else
      static
      symbol_type
      make_AT (const location_type& l)
      {
        return symbol_type (token::AT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMP (location_type l)
      {
        return symbol_type (token::AMP, std::move (l));
      }
#else
      static
      symbol_type
      make_AMP (const location_type& l)
      {
        return symbol_type (token::AMP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIPE (location_type l)
      {
        return symbol_type (token::PIPE, std::move (l));
      }
#else
      static
      symbol_type
      make_PIPE (const location_type& l)
      {
        return symbol_type (token::PIPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FSLASH (location_type l)
      {
        return symbol_type (token::FSLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_FSLASH (const location_type& l)
      {
        return symbol_type (token::FSLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSQUARE (location_type l)
      {
        return symbol_type (token::LSQUARE, std::move (l));
      }
#else
      static
      symbol_type
      make_LSQUARE (const location_type& l)
      {
        return symbol_type (token::LSQUARE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSQUARE (location_type l)
      {
        return symbol_type (token::RSQUARE, std::move (l));
      }
#else
      static
      symbol_type
      make_RSQUARE (const location_type& l)
      {
        return symbol_type (token::RSQUARE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (location_type l)
      {
        return symbol_type (token::LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const location_type& l)
      {
        return symbol_type (token::LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (location_type l)
      {
        return symbol_type (token::RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const location_type& l)
      {
        return symbol_type (token::RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SC (location_type l)
      {
        return symbol_type (token::SC, std::move (l));
      }
#else
      static
      symbol_type
      make_SC (const location_type& l)
      {
        return symbol_type (token::SC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (location_type l)
      {
        return symbol_type (token::LT, std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const location_type& l)
      {
        return symbol_type (token::LT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (location_type l)
      {
        return symbol_type (token::GT, std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const location_type& l)
      {
        return symbol_type (token::GT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARROT (location_type l)
      {
        return symbol_type (token::CARROT, std::move (l));
      }
#else
      static
      symbol_type
      make_CARROT (const location_type& l)
      {
        return symbol_type (token::CARROT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUESTION (location_type l)
      {
        return symbol_type (token::QUESTION, std::move (l));
      }
#else
      static
      symbol_type
      make_QUESTION (const location_type& l)
      {
        return symbol_type (token::QUESTION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BANG (location_type l)
      {
        return symbol_type (token::BANG, std::move (l));
      }
#else
      static
      symbol_type
      make_BANG (const location_type& l)
      {
        return symbol_type (token::BANG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TILDE (location_type l)
      {
        return symbol_type (token::TILDE, std::move (l));
      }
#else
      static
      symbol_type
      make_TILDE (const location_type& l)
      {
        return symbol_type (token::TILDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_VAL (long long v, location_type l)
      {
        return symbol_type (token::INT_VAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT_VAL (const long long& v, const location_type& l)
      {
        return symbol_type (token::INT_VAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT_VAL (float v, location_type l)
      {
        return symbol_type (token::FLOAT_VAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT_VAL (const float& v, const location_type& l)
      {
        return symbol_type (token::FLOAT_VAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_VAL (std::string v, location_type l)
      {
        return symbol_type (token::STRING_VAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_VAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING_VAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR_VAL (char v, location_type l)
      {
        return symbol_type (token::CHAR_VAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR_VAL (const char& v, const location_type& l)
      {
        return symbol_type (token::CHAR_VAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL_VAL (bool v, location_type l)
      {
        return symbol_type (token::BOOL_VAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL_VAL (const bool& v, const location_type& l)
      {
        return symbol_type (token::BOOL_VAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_NAME (location_type l)
      {
        return symbol_type (token::TYPE_NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE_NAME (const location_type& l)
      {
        return symbol_type (token::TYPE_NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POINTER (location_type l)
      {
        return symbol_type (token::POINTER, std::move (l));
      }
#else
      static
      symbol_type
      make_POINTER (const location_type& l)
      {
        return symbol_type (token::POINTER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INCREMENT (location_type l)
      {
        return symbol_type (token::INCREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_INCREMENT (const location_type& l)
      {
        return symbol_type (token::INCREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECREMENT (location_type l)
      {
        return symbol_type (token::DECREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_DECREMENT (const location_type& l)
      {
        return symbol_type (token::DECREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT (location_type l)
      {
        return symbol_type (token::LEFT, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT (const location_type& l)
      {
        return symbol_type (token::LEFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT (location_type l)
      {
        return symbol_type (token::RIGHT, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT (const location_type& l)
      {
        return symbol_type (token::RIGHT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMP_AMP (location_type l)
      {
        return symbol_type (token::AMP_AMP, std::move (l));
      }
#else
      static
      symbol_type
      make_AMP_AMP (const location_type& l)
      {
        return symbol_type (token::AMP_AMP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIPE_PIPE (location_type l)
      {
        return symbol_type (token::PIPE_PIPE, std::move (l));
      }
#else
      static
      symbol_type
      make_PIPE_PIPE (const location_type& l)
      {
        return symbol_type (token::PIPE_PIPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR_EQ (location_type l)
      {
        return symbol_type (token::STAR_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR_EQ (const location_type& l)
      {
        return symbol_type (token::STAR_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FSLASH_EQ (location_type l)
      {
        return symbol_type (token::FSLASH_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_FSLASH_EQ (const location_type& l)
      {
        return symbol_type (token::FSLASH_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_EQ (location_type l)
      {
        return symbol_type (token::MOD_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD_EQ (const location_type& l)
      {
        return symbol_type (token::MOD_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS_EQ (location_type l)
      {
        return symbol_type (token::PLUS_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS_EQ (const location_type& l)
      {
        return symbol_type (token::PLUS_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS_EQ (location_type l)
      {
        return symbol_type (token::MINUS_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS_EQ (const location_type& l)
      {
        return symbol_type (token::MINUS_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_EQ (location_type l)
      {
        return symbol_type (token::LEFT_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_EQ (const location_type& l)
      {
        return symbol_type (token::LEFT_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_EQ (location_type l)
      {
        return symbol_type (token::RIGHT_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_EQ (const location_type& l)
      {
        return symbol_type (token::RIGHT_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMP_EQ (location_type l)
      {
        return symbol_type (token::AMP_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_AMP_EQ (const location_type& l)
      {
        return symbol_type (token::AMP_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARROT_EQ (location_type l)
      {
        return symbol_type (token::CARROT_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_CARROT_EQ (const location_type& l)
      {
        return symbol_type (token::CARROT_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIPE_EQ (location_type l)
      {
        return symbol_type (token::PIPE_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_PIPE_EQ (const location_type& l)
      {
        return symbol_type (token::PIPE_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT_EQ (location_type l)
      {
        return symbol_type (token::LT_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_LT_EQ (const location_type& l)
      {
        return symbol_type (token::LT_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT_EQ (location_type l)
      {
        return symbol_type (token::GT_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_GT_EQ (const location_type& l)
      {
        return symbol_type (token::GT_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ_EQ (location_type l)
      {
        return symbol_type (token::EQ_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ_EQ (const location_type& l)
      {
        return symbol_type (token::EQ_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BANG_EQ (location_type l)
      {
        return symbol_type (token::BANG_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_BANG_EQ (const location_type& l)
      {
        return symbol_type (token::BANG_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF (location_type l)
      {
        return symbol_type (token::TYPEDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEDEF (const location_type& l)
      {
        return symbol_type (token::TYPEDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTERN (location_type l)
      {
        return symbol_type (token::EXTERN, std::move (l));
      }
#else
      static
      symbol_type
      make_EXTERN (const location_type& l)
      {
        return symbol_type (token::EXTERN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC (location_type l)
      {
        return symbol_type (token::STATIC, std::move (l));
      }
#else
      static
      symbol_type
      make_STATIC (const location_type& l)
      {
        return symbol_type (token::STATIC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AUTO (location_type l)
      {
        return symbol_type (token::AUTO, std::move (l));
      }
#else
      static
      symbol_type
      make_AUTO (const location_type& l)
      {
        return symbol_type (token::AUTO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGISTER (location_type l)
      {
        return symbol_type (token::REGISTER, std::move (l));
      }
#else
      static
      symbol_type
      make_REGISTER (const location_type& l)
      {
        return symbol_type (token::REGISTER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZEOF (location_type l)
      {
        return symbol_type (token::SIZEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_SIZEOF (const location_type& l)
      {
        return symbol_type (token::SIZEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (location_type l)
      {
        return symbol_type (token::CHAR, std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR (const location_type& l)
      {
        return symbol_type (token::CHAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIGNED (location_type l)
      {
        return symbol_type (token::SIGNED, std::move (l));
      }
#else
      static
      symbol_type
      make_SIGNED (const location_type& l)
      {
        return symbol_type (token::SIGNED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNSIGNED (location_type l)
      {
        return symbol_type (token::UNSIGNED, std::move (l));
      }
#else
      static
      symbol_type
      make_UNSIGNED (const location_type& l)
      {
        return symbol_type (token::UNSIGNED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST (location_type l)
      {
        return symbol_type (token::CONST, std::move (l));
      }
#else
      static
      symbol_type
      make_CONST (const location_type& l)
      {
        return symbol_type (token::CONST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOLATILE (location_type l)
      {
        return symbol_type (token::VOLATILE, std::move (l));
      }
#else
      static
      symbol_type
      make_VOLATILE (const location_type& l)
      {
        return symbol_type (token::VOLATILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (location_type l)
      {
        return symbol_type (token::VOID, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const location_type& l)
      {
        return symbol_type (token::VOID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (location_type l)
      {
        return symbol_type (token::BOOL, std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const location_type& l)
      {
        return symbol_type (token::BOOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LAMBDA (location_type l)
      {
        return symbol_type (token::LAMBDA, std::move (l));
      }
#else
      static
      symbol_type
      make_LAMBDA (const location_type& l)
      {
        return symbol_type (token::LAMBDA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_I8 (location_type l)
      {
        return symbol_type (token::I8, std::move (l));
      }
#else
      static
      symbol_type
      make_I8 (const location_type& l)
      {
        return symbol_type (token::I8, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_I16 (location_type l)
      {
        return symbol_type (token::I16, std::move (l));
      }
#else
      static
      symbol_type
      make_I16 (const location_type& l)
      {
        return symbol_type (token::I16, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_I32 (location_type l)
      {
        return symbol_type (token::I32, std::move (l));
      }
#else
      static
      symbol_type
      make_I32 (const location_type& l)
      {
        return symbol_type (token::I32, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_I64 (location_type l)
      {
        return symbol_type (token::I64, std::move (l));
      }
#else
      static
      symbol_type
      make_I64 (const location_type& l)
      {
        return symbol_type (token::I64, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_F32 (location_type l)
      {
        return symbol_type (token::F32, std::move (l));
      }
#else
      static
      symbol_type
      make_F32 (const location_type& l)
      {
        return symbol_type (token::F32, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_F64 (location_type l)
      {
        return symbol_type (token::F64, std::move (l));
      }
#else
      static
      symbol_type
      make_F64 (const location_type& l)
      {
        return symbol_type (token::F64, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT (location_type l)
      {
        return symbol_type (token::STRUCT, std::move (l));
      }
#else
      static
      symbol_type
      make_STRUCT (const location_type& l)
      {
        return symbol_type (token::STRUCT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNION (location_type l)
      {
        return symbol_type (token::UNION, std::move (l));
      }
#else
      static
      symbol_type
      make_UNION (const location_type& l)
      {
        return symbol_type (token::UNION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM (location_type l)
      {
        return symbol_type (token::ENUM, std::move (l));
      }
#else
      static
      symbol_type
      make_ENUM (const location_type& l)
      {
        return symbol_type (token::ENUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLIPSIS (location_type l)
      {
        return symbol_type (token::ELLIPSIS, std::move (l));
      }
#else
      static
      symbol_type
      make_ELLIPSIS (const location_type& l)
      {
        return symbol_type (token::ELLIPSIS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FN (location_type l)
      {
        return symbol_type (token::FN, std::move (l));
      }
#else
      static
      symbol_type
      make_FN (const location_type& l)
      {
        return symbol_type (token::FN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (location_type l)
      {
        return symbol_type (token::LET, std::move (l));
      }
#else
      static
      symbol_type
      make_LET (const location_type& l)
      {
        return symbol_type (token::LET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (location_type l)
      {
        return symbol_type (token::CASE, std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const location_type& l)
      {
        return symbol_type (token::CASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT (location_type l)
      {
        return symbol_type (token::DEFAULT, std::move (l));
      }
#else
      static
      symbol_type
      make_DEFAULT (const location_type& l)
      {
        return symbol_type (token::DEFAULT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (location_type l)
      {
        return symbol_type (token::SWITCH, std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const location_type& l)
      {
        return symbol_type (token::SWITCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (location_type l)
      {
        return symbol_type (token::CONTINUE, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const location_type& l)
      {
        return symbol_type (token::CONTINUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::RETURN, l);
      }
#endif


    class context
    {
    public:
      context (const Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      const location_type& location () const { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const unsigned char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 400,     ///< Last index in yytable_.
      yynnts_ = 49,  ///< Number of nonterminal symbols.
      yyfinal_ = 15 ///< Termination state number.
    };


    // User arguments.
    Driver *driver;

  };

  inline
  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
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
        value.copy< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.copy< FunctionDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
        value.copy< ObjDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_global_declaration: // global_declaration
        value.copy< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
        value.copy< VarDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.copy< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.copy< std::vector<Expression*>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
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
        value.move< Expression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< FunctionDecl* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_object_declaration_expression: // object_declaration_expression
        value.move< ObjDecl* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_global_declaration: // global_declaration
        value.move< Statement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration_expression: // declaration_expression
        value.move< VarDecl* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOL_VAL: // BOOL_VAL
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CHAR_VAL: // CHAR_VAL
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT_VAL: // FLOAT_VAL
        value.move< float > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT_VAL: // INT_VAL
        value.move< long long > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING_VAL: // STRING_VAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< std::vector<Expression*>* > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

#line 7 "/home/espresso/projects/tape/src/Bison/parser.yy"
} // yy
#line 3320 "../src/../src/Parser/Parser.hh"




#endif // !YY_YY_SRC_SRC_PARSER_PARSER_HH_INCLUDED
