
//%skeleton "../Parser/Lalr1.cc"
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

    class Value;
    class Expression;
}

%param {Driver *driver}
%locations
%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
    #include "Driver.hh"
    #include "../Ast/AstExpression.hh"
    StatementList whole_program;
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
%token  TYPE_NAME 
%token <std::string> ID

%token POINTER INCREMENT DECREMENT LEFT RIGHT ;
%token AMP_AMP PIPE_PIPE STAR_EQ FSLASH_EQ MOD_EQ PLUS_EQ ;
%token MINUS_EQ LEFT_EQ RIGHT_EQ AMP_EQ;
%token CARROT_EQ PIPE_EQ LT_EQ GT_EQ EQ_EQ BANG_EQ ;

%token TYPEDEF EXTERN STATIC AUTO REGISTER SIZEOF
%token CHAR SIGNED UNSIGNED CONST VOLATILE VOID BOOL LAMBDA
%token I8 I16 I32 I64 F32 F64
%token STRUCT UNION ENUM ELLIPSIS FN LET

%token  CASE DEFAULT IF ELSE SWITCH WHILE FOR CONTINUE BREAK RETURN

%nterm <int> assignment_operator unary_operator

%nterm <Expression*> atomic_expression expression unary_expression postfix_expression assignment_expression cast_expression 
 additive_expression multiplicative_expression shift_expression conditional_expression logical_and_expression constant_expression
 logical_or_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression 
 
%nterm <std::vector<Expression*>*> argument_expression_list

%nterm <Statement*> global_declaration 
%nterm <FunctionDecl*> function_definition
%nterm <VarDecl*> declaration_expression
%nterm <ObjDecl*> object_declaration_expression


%left "+" "-"
%left "*" "/"

%nonassoc ")"
%nonassoc ELSE

%start program
%%

program:
        global_declaration          { whole_program = std::vector<Statement*>(); whole_program.push_back($1); } 
    |   program global_declaration  { whole_program.push_back($2); }
    ;

global_declaration:
        function_definition     { $$ = $1; }
    |   declaration_expression  { $$ = $1; }
    |   object_declaration_expression   { $$ = $1; }
    ;

// FUNCTION
function_definition:
        FN ID "(" ")" ":" declaration_specifier compound_statement                  { $$ = new FunctionDecl(); }
    |   FN ID "(" parameter_list ")" ":" declaration_specifier compound_statement
    ;   

parameter_list:
        parameter
    |   parameter_list "," parameter
    ;

parameter:
        ID ":" declaration_specifier     
    ;

// DECLARATION
declaration_list:
        declaration
    |   declaration_list declaration
    ;

declaration:
        id_list ":" declaration_specifier
    ;

object_declaration_expression:
        struct_or_union ID "{" declaration_list "}" ";" 
    |   struct_or_union ID "{" "}" ";"                  
    |   struct_or_union ID ";"                          
    ;

id_list:
        ID
    |   id_list "," ID
    ;

struct_or_union:
        STRUCT
    |   UNION
    ;

declaration_specifier:
//        type_qualifier type_modifier_list type_name type_suffix_list   
        type_qualifier type_name type_suffix_list   
    ;

type_suffix_list:
        %empty
    |   type_suffix_list type_suffix
    ;

type_suffix:
        "*"
    |   "[" "]"
    |   "[" constant_expression "]"
    ;

type_name:
        CHAR
    |   I8
    |   I16
    |   I32
    |   I64
    |   F32
    |   F64
    |   VOID
    |   BOOL
    |   AUTO
    ;

type_qualifier:
        %empty
    |   CONST
    ;

initializer: 
        assignment_expression
    |   "{" initializer_list "}"
    ;

initializer_list:
        initializer
    |   initializer_list "," initializer
    ;


// STATEMENTS
statement_list:
        statement
    |   statement_list statement
    ;

statement:        
        compound_statement
    |   conditional_statement
    |   expression_statement
    |   labeled_statement
    |   iteration_statement
    |   switch_statement
    |   jump_statement
    ;

conditional_statement:
        IF "(" expression ")" statement
    |   IF "(" expression ")" statement ELSE statement
    ;

compound_statement:
        "{" statement_list "}"
    ;

labeled_statement:
        CASE conditional_expression ":" statement
    |   DEFAULT ":" statement
    ;

jump_statement:
        RETURN expression_statement
    |   BREAK ";"
    |   CONTINUE ";"
    ;
    
expression_statement:
        expression ";"
    |   declaration_expression 
    |   ";"
    ;

declaration_expression:
        LET declaration assignment_operator initializer_list  ";"   
    |   LET declaration ";"
    ;
switch_statement:
        SWITCH "(" expression ")" statement
    ;
    
iteration_statement:
        FOR "(" expression_statement expression_statement expression ")" statement
    |   WHILE "(" expression ")" statement      
    ;




// EXPRESSIONS
atomic_expression:
        ID                  { $$ = new Identifier($1); }   
    |   INT_VAL             { $$ = new IVal($1); }
    |   CHAR_VAL            { $$ = new CVal($1); }
    |   BOOL_VAL            { $$ = new BVal($1); }
    |   FLOAT_VAL           { $$ = new FVal($1); }
    |   STRING_VAL          { $$ = new SVal($1); }
    |   "(" expression ")"  { $$ = $2; }
    ;

postfix_expression: 
        atomic_expression                                   { $$ = $1; } 
    |   postfix_expression "[" expression "]"               { $$ = $1; } // todo access
    |   postfix_expression "(" ")"                          { $$ = new FunctionCall($1, nullptr); }  // todo access
    |   postfix_expression "(" argument_expression_list ")" { $$ = new FunctionCall($1, $3); } // todo access
    |   postfix_expression "." ID                           { $$ = new AccessCall($1, new Identifier($3)); } 
    |   postfix_expression POINTER ID                       { $$ = new AccessCall($1, new Identifier($3)); } 
    |   postfix_expression INCREMENT                        { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_PLUS, $1, new IVal(1)); } 
    |   postfix_expression DECREMENT                        { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_MINUS, $1, new IVal(1));} 
    ;

argument_expression_list: 
        assignment_expression                               { ExpressionList *l = new ExpressionList; l->push_back($1); }                        
    |   argument_expression_list "," assignment_expression  { $1->push_back($3); $$ = $1; }
    ;

unary_expression: 
        postfix_expression              { $$ = $1; }
    |   INCREMENT unary_expression      { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_PLUS, new IVal(1), $2); }
    |   DECREMENT unary_expression      { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_MINUS, new IVal(1), $2); }
    |   unary_operator cast_expression  { $$ = new UnaryExpr($1, $2); }
//    |   SIZEOF "(" unary_expression ")" { $$ = new IVal(1); } // todo
    |   SIZEOF "(" type_name ")"        { $$ = new IVal(1); } // todo
    ;

cast_expression: 
        unary_expression                    { $$ = $1; }   
//    |   "(" type_name ")" cast_expression   { $$ = $4; } // todo
    ;

multiplicative_expression: 
        cast_expression                                 { $$ = $1; }
    |   multiplicative_expression "*" cast_expression   { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_STAR, $1, $3);    }
    |   multiplicative_expression "/" cast_expression   { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_FSLASH, $1, $3);  }
    |   multiplicative_expression "%" cast_expression   { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_MOD, $1, $3);     }
    ;

additive_expression: 
        multiplicative_expression                           { $$ = $1; }
    |   additive_expression "+" multiplicative_expression   { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_PLUS, $1, $3);    }
    |   additive_expression "-" multiplicative_expression   { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_MINUS, $1, $3);   }
    ;

shift_expression:   
        additive_expression                         { $$ = $1; } 
    |   shift_expression LEFT additive_expression   { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_LEFT, $1, $3); }
    |   shift_expression RIGHT additive_expression  { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_RIGHT, $1, $3); }
    ;

relational_expression: 
        shift_expression                                { $$ = $1; } 
    |   relational_expression "<" shift_expression      { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_LT, $1, $3); }  
    |   relational_expression ">" shift_expression      { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_GT, $1, $3); }
    |   relational_expression LT_EQ shift_expression    { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_LT_EQ, $1, $3); }
    |   relational_expression GT_EQ shift_expression    { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_GT_EQ, $1, $3); }
    ;

equality_expression: 
        relational_expression                               { $$ = $1; } 
    |   equality_expression EQ_EQ relational_expression     { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_EQ_EQ, $1, $3); }
    |   equality_expression BANG_EQ relational_expression   { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_BANG_EQ, $1, $3); }
    ;

and_expression: 
        equality_expression                     { $$ = $1; } 
    |   and_expression "&" equality_expression  { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_AMP, $1, $3); }
    ;

exclusive_or_expression:   
        and_expression                              { $$ = $1; } 
    |   exclusive_or_expression "^" and_expression  { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_CARROT, $1, $3); }
    ;

inclusive_or_expression: 
        exclusive_or_expression                             { $$ = $1; }
    |   inclusive_or_expression "|" exclusive_or_expression { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_PIPE, $1, $3); }
    ;

logical_and_expression: 
        inclusive_or_expression                                 { $$ = $1; } 
    |   logical_and_expression AMP_AMP inclusive_or_expression  { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_AMP_AMP, $1, $3); }
    ;

logical_or_expression: 
        logical_and_expression                                  { $$ = $1; } 
    |   logical_or_expression PIPE_PIPE logical_and_expression  { $$ = new BinaryExpr(yy::Parser::symbol_kind_type::S_PIPE_PIPE, $1, $3); }
    ;

conditional_expression:   
        logical_or_expression                                           { $$ = $1; }                 
    |   logical_or_expression "?" expression ":" conditional_expression { $$ = new OrExpr($1, $3, $5); }
                                                                        
    ;

assignment_expression:   
        conditional_expression                                     {$$ = $1; } // todo
    |   unary_expression assignment_operator assignment_expression {$$ = new AssignmentExpr($2, $1, $3); }
    ;

expression: 
        assignment_expression                   { $$ = $1; } 
//    |   expression "," assignment_expression
    ;

constant_expression: 
        conditional_expression  { $$ = $1; }
    ;

// OPERATORS
assignment_operator:
        "="         { $$ = yy::Parser::symbol_kind_type::S_EQ; }  
    |   STAR_EQ     { $$ = yy::Parser::symbol_kind_type::S_STAR_EQ; }
    |   FSLASH_EQ   { $$ = yy::Parser::symbol_kind_type::S_FSLASH_EQ; }
    |   MOD_EQ      { $$ = yy::Parser::symbol_kind_type::S_MOD_EQ; }
    |   PLUS_EQ     { $$ = yy::Parser::symbol_kind_type::S_PLUS_EQ; }
    |   MINUS_EQ    { $$ = yy::Parser::symbol_kind_type::S_MINUS_EQ; }
    |   LEFT_EQ     { $$ = yy::Parser::symbol_kind_type::S_LEFT_EQ; }
    |   RIGHT_EQ    { $$ = yy::Parser::symbol_kind_type::S_RIGHT_EQ; }
    |   AMP_EQ      { $$ = yy::Parser::symbol_kind_type::S_AMP_EQ; }
    |   CARROT_EQ   { $$ = yy::Parser::symbol_kind_type::S_CARROT_EQ; }
    |   PIPE_EQ     { $$ = yy::Parser::symbol_kind_type::S_PIPE_EQ; }
    ;

unary_operator:
        "@"     { $$ = yy::Parser::symbol_kind_type::S_AT;      } 
    |   "-"     { $$ = yy::Parser::symbol_kind_type::S_MINUS;   }
    |   "&"     { $$ = yy::Parser::symbol_kind_type::S_AMP;    }
    |   "!"     { $$ = yy::Parser::symbol_kind_type::S_BANG;    }
    |   "~"     { $$ = yy::Parser::symbol_kind_type::S_TILDE;   }
    ;



%%


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