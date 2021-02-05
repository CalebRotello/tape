
%require "3.7.1"
%language "c++"
%defines
%define api.token.raw
%define api.namespace {yy}
%define api.parser.class {Parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    int char_to_sym(char c);
    class Driver;

}

%param {Driver *driver}
%locations 
%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
    #include "Driver.hh"
}

%printer { yyo << $$; } <*>;
%printer { yyo << "<>"; } <>;


%token 
 EQ "="
 PLUS "+"
 MINUS "-"
 AT "@"
 AMP "&"
 PIPE "|"
 FSLASH "/"
 STAR "*"
 MOD "%"
 LPAREN "("
 RPAREN ")"
 LSQUARE "["
 RSQUARE "]"
 LBRACE "{"
 RBRACE "}"
 SC ";"
 LT "<"
 GT ">"
 COLON ":"
 CARROT "^"
 COMMA ","
 QUESTION "?"
 DOT "."
 BANG "!"
 TILDE "~"
;

%token <long long> INT_VAL
%token <float> FLOAT_VAL
%token <std::string> STRING_VAL
%token <char> CHAR_VAL
%token <bool> BOOL_VAL
%token <std::string> ID

// ops
%token POINTER INCREMENT DECREMENT LEFT RIGHT ;
%token AMP_AMP PIPE_PIPE STAR_EQ FSLASH_EQ MOD_EQ PLUS_EQ ;
%token MINUS_EQ LEFT_EQ RIGHT_EQ AMP_EQ;
%token CARROT_EQ PIPE_EQ LT_EQ GT_EQ EQ_EQ BANG_EQ ;

// keywords
%token IF ELSE FN LET VAR TYPE RETURN
%token FOR WHILE MATCH BREAK CONTINUE

// types
%token  TYPE_NAME 
%token I8 I16 I32 I64 F32 F64 

// nonterms
%nterm <int> assign_op unary_op


%left "+" "-"
%left "*" "/"
%nonassoc ")"
%nonassoc ELSE

%start program



%%




program:    
    global_declaration
|   program global_declaration
    ;

global_declaration: 
    variable_declaration ";"
|   function_declaration 
|   type_declaration ";"
    ;

variable_declaration:
    declaration "=" initializer 
|   declaration
    ;

type_declaration:
    TYPE ID "=" type type_mods 
|   TYPE ID "=" "{" type_declaration_list "}" 
    ;

type_declaration_list:
    type_declaration_member
|   type_declaration_member "," type_declaration_list
    ;

type_declaration_member:
    type_declaration
|   variable_declaration
    ;


declaration_type:
    %empty
|   ":" type type_mods
    ;

type_mods:
    %empty
|   type_mods type_mod   
    ;

type_mod:
    "*"
|   "[" "]"
|   "[" constant_expression "]"
    ;

type:
    I8 | I16 | I32 | I64 | F32 | FN 
        //| ID
    ;

declaration:
    declaration_hypothesis declaration_specification 
    ;

declaration_specification:
    ID declaration_type
    ;

declaration_hypothesis:
    LET | VAR ;

function_declaration:
    FN ID "(" parameter_list ")" declaration_type statement_box
|   FN ID "(" parameter_list ")" declaration_type ";"
    ;

parameter_list:
    %empty
|   declaration_specification
|   declaration_specification "," parameter_list
    ;


// statements
statement_list:
    statement
|   statement_list statement
    ;

statement:
    statement_box
|   conditional_statement
|   expression_statement
|   flow_statement
|   iteration_statement
    ;

statement_box:
    "{" statement_list "}"
    ;

iteration_statement:
    FOR "(" expression_statement expression_statement expression ")" statement
|   WHILE "(" expression ")" statement
    ;

flow_statement:
    RETURN expression ";" 
|   BREAK ";"
|   CONTINUE ";"
    ;

conditional_statement:
    IF "(" expression ")" statement
|   IF "(" expression ")" statement ELSE statement
    ;

expression_statement:
    expression ";"
|   variable_declaration ";"
    ;

initializer:
    "{" initializer_list "}"
|   assignment_expression
    ;

initializer_list:
    initializer
|   initializer_list "," initializer
    ;

// expressions
expression:
    function_declaration
|   match_expression 
|   assignment_expression
    ;

constant_expression:
    conditional_expression
    ;

conditional_expression:
    logical_expression "?" expression ":" expression
|   logical_expression
    ;

assignment_expression:
    constant_expression
|   unary_expression assign_op constant_expression;
    ; 

atomic_expression:
    ID 
|   INT_VAL     
|   CHAR_VAL 
|   BOOL_VAL 
|   FLOAT_VAL 
|   STRING_VAL 
|   "(" expression ")"
    ;

postfix_expression:
    atomic_expression
|   postfix_expression "[" expression "]"
|   postfix_expression "(" ")"
|   postfix_expression "(" argument_expression_list ")"
|   postfix_expression "." ID
|   postfix_expression POINTER ID
|   postfix_expression INCREMENT
|   postfix_expression DECREMENT
    ;

argument_expression_list:
    constant_expression
|   argument_expression_list "," constant_expression
    ;

unary_expression:
    postfix_expression
|   INCREMENT unary_expression
|   DECREMENT unary_expression
|   unary_op unary_expression
    ;


multiplicative_expression:
    unary_expression 
|   multiplicative_expression "*" unary_expression
|   multiplicative_expression "/" unary_expression
|   multiplicative_expression "%" unary_expression
    ;

additive_expression:
    multiplicative_expression
|   additive_expression "+" multiplicative_expression
|   additive_expression "-" multiplicative_expression
    ;

relational_expression:
    additive_expression
|   relational_expression "<" additive_expression
|   relational_expression ">" additive_expression
|   relational_expression LT_EQ additive_expression
|   relational_expression GT_EQ additive_expression
    ;

equality_expression:
    relational_expression
|   equality_expression EQ_EQ relational_expression 
|   equality_expression BANG_EQ relational_expression   
    ;

logical_expression:
    equality_expression
    //|   logical_expression AMP_AMP relational_expression
    //|   logical_expression PIPE_PIPE equality_expression
    //|   logical_expression "|" equality_expression
    //|   logical_expression "^" equality_expression
    //|   logical_expression "&" equality_expression
    ;




// functional expressions
match_expression: // todo expression_val
    MATCH expression "{" pattern_list "}"
    ;
    
pattern_list:
    pattern
|   pattern_list "," pattern
    ;
    
pattern:
    expression "->" statement 
    ;

assign_op:
    "="         { $$ = yy::Parser::symbol_kind_type::S_EQ;          }
|   PLUS_EQ     { $$ = yy::Parser::symbol_kind_type::S_PLUS_EQ;     }
|   MINUS_EQ    { $$ = yy::Parser::symbol_kind_type::S_MINUS_EQ;    }
|   STAR_EQ     { $$ = yy::Parser::symbol_kind_type::S_STAR_EQ;     }
|   FSLASH_EQ   { $$ = yy::Parser::symbol_kind_type::S_FSLASH_EQ;   }
|   MOD_EQ      { $$ = yy::Parser::symbol_kind_type::S_MOD_EQ;      }
    ;

unary_op:
    "!" { $$ = yy::Parser::symbol_kind_type::S_BANG;    }
|   "@" { $$ = yy::Parser::symbol_kind_type::S_AT;      }
|   "&" { $$ = yy::Parser::symbol_kind_type::S_AMP;     }
|   "-" { $$ = yy::Parser::symbol_kind_type::S_MINUS;   }
|   "~" { $$ = yy::Parser::symbol_kind_type::S_TILDE;   }
    ;

%% 

void yy::Parser::error(const location_type &loc, const std::string &msg) {
    std::cerr << loc << ": " << msg << std::endl;
}
