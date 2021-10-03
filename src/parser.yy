
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
    #include <vector>

    struct Driver;
    class ScopeTree;
    class Expr;
    class Stmt;
    class StmtList;
    class FunctionDeclStmt;
    class VarDeclStmt;
    class TypeDeclStmt;
}

%param {Driver *driver}
%parse-param {StmtList *fstmt_list}
%parse-param {ScopeTree *scope}
%locations 
%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
    #include "Driver.hh"
    #include "../Ast/Ast.hh"
    #include "../Ast/SymbolRec.hh"

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
%token I8 I16 I32 I64 F32 F64 
%token U_I8 U_I16 U_I32 U_I64 U_F32 U_F64

// nonterms
%nterm <int> assign_op unary_op type declaration_type
%nterm <bool> declaration_hypothesis // is mutable
%nterm <Expr*> atomic_expression
%nterm <Expr*> expression multiplicative_expression additive_expression equality_expression relational_expression
%nterm <Expr*> postfix_expression unary_expression assignment_expression constant_expression initializer
%nterm <FunctionDeclStmt*> function_declaration fn_statement_box
%nterm <VarDeclStmt*> declaration variable_declaration
%nterm <TypeDeclStmt*> type_declaration
%nterm <Stmt*> global_declaration statement expression_statement flow_statement
%nterm <StmtList*> statement_list statement_box program

%left "+" "-"
%left "*" "/"
%nonassoc ")"
%nonassoc ELSE

%code {
    typedef yy::Parser::symbol_kind_type skind_type;
}

%start program



%%




program:    
    global_declaration          { fstmt_list->push_back($1); }
|   program global_declaration  { fstmt_list->push_back($2); }
    ;

global_declaration: 
    variable_declaration ";"    { $$ = $1; }
|   function_declaration        { $$ = $1; }  
|   type_declaration            { $$ = $1; }
    ;

variable_declaration:
    declaration "=" initializer { $1->setExpr($3); $$ = $1; }
|   declaration                 { $$ = $1; }
    ;

type_declaration:
    TYPE ID "=" type type_mods                  { $$ = new TypeDeclStmt($2); }  // TODO handle special case of direct string substitution
|   TYPE ID "=" "{" type_declaration_list "}"   { $$ = new TypeDeclStmt($2); }  // TODO care about members
    ;

// TODO
type_declaration_list:
    type_declaration_member
|   type_declaration_member "," type_declaration_list
    ;

// TODO
type_declaration_member:
    type_declaration
|   variable_declaration
    ;

// TODO
declaration_type:
    %empty              { $$ = Type::AUTO; }
|   ":" type type_mods  { $$ = $2; }
    ;

// TODO
type_mods:
    %empty
|   type_mods type_mod   
    ;

// TODO
type_mod:
    "*"
|   "[" "]"
|   "[" constant_expression "]"
    ;

type:
    I8  { $$ = Type::I8;    }
|   I16 { $$ = Type::I16;   }
|   I32 { $$ = Type::I32;   }
|   I64 { $$ = Type::I64;   }
|   F32 { $$ = Type::F32;   }
|   F64 { $$ = Type::F64;   }
|   U_I8  { $$ = Type::uI8;    }
|   U_I16 { $$ = Type::uI16;   }
|   U_I32 { $$ = Type::uI32;   }
|   U_I64 { $$ = Type::uI64;   }
|   U_F32 { $$ = Type::uF32;   }
|   U_F64 { $$ = Type::uF64;   }
|   FN  { $$ = Type::FN;    }
|   ID  { $$ = Type::DEF;   }
    ;

declaration:
    declaration_hypothesis ID declaration_type { $$ = new VarDeclStmt($2, $1); }  // TODO care about the type
    ;

declaration_hypothesis:
    LET {$$=false;} | VAR{$$=true;} 
    ;

function_declaration:
    FN ID "(" parameter_list ")" declaration_type fn_statement_box  { $7->setFnId($2); $$ = $7; }  // TODO get real function declaration
|   FN ID "(" parameter_list ")" declaration_type ";"               { $$ = new FunctionDeclStmt($2); }
    ;

// TODO
parameter_list:
    %empty
|   ID declaration_type
|   ID declaration_type "," parameter_list
    ;


// statements
statement_list:
    statement                   { $$ = new StmtList({$1}); }    
|   statement_list statement    { $1->push_back($2); $$ = $1; }
    ;

statement:
    statement_box           { $$ = $1; }
|   expression_statement    { $$ = $1; }
|   flow_statement          { $$ = $1; }
    ;

statement_box:
    "{" statement_list "}"  { $$ = $2; }
    ;

fn_statement_box:
    "{" statement_list expression "}"               { $$ = new FunctionDeclStmt($2, $3); }
|   "{" statement_list RETURN expression ";" "}"    { $$ = new FunctionDeclStmt($2, $4); }
|   statement_box                                   { $$ = new FunctionDeclStmt($1); }
    ;

flow_statement:
    BREAK { $$ = new Break; } | CONTINUE { $$ = new Continue; }
    ;

expression_statement:
    expression ";"              { $$ = new ExprStmt($1); }
|   variable_declaration ";"    { $$ = $1; }
    ;

initializer:
    expression  { $$ = $1; }
    ;


// expressions
expression:
    function_declaration    { $$ = $1->getFnId(); }
|   assignment_expression   { $$ = $1; }
    ;

constant_expression:
    equality_expression { $$ = $1; }
    ;


assignment_expression:
    constant_expression { $$ = $1; }
|   unary_expression assign_op constant_expression  {
                                                        Expr *const_expr = $3;
                                                        if ($2 != skind_type::S_EQ)  
                                                            const_expr = new BopExpr($2, $1, $3);
                                                        $$ = new AssignExpr((IdValue*)$1, const_expr); // TODO implement a real "get id"
                                                    }
    ;

atomic_expression:
    ID          { $$ = new IdValue($1);     }
|   INT_VAL     { $$ = new IntValue($1);    }
|   CHAR_VAL    { $$ = new IntValue($1);    }
|   BOOL_VAL    { $$ = new IntValue($1);    } // this is bad memory, 63 excessive bits
|   FLOAT_VAL   { $$ = new FloatValue($1);  }
|   STRING_VAL  { $$ = new StrValue($1);    }
|   "(" expression ")" { $$ = $2;           }
    ;

postfix_expression:
    atomic_expression               { $$ = $1; }
|   postfix_expression INCREMENT    { $$ = new BopExpr(skind_type::S_PLUS, $1, new IntValue(1));    }
|   postfix_expression DECREMENT    { $$ = new BopExpr(skind_type::S_MINUS, $1, new IntValue(1));   }
    ;

unary_expression:
    postfix_expression          { $$ = $1; }
|   INCREMENT unary_expression  { $$ = new BopExpr(skind_type::S_PLUS, $2, new IntValue(1));  }  // I know this is technically not right
|   DECREMENT unary_expression  { $$ = new BopExpr(skind_type::S_MINUS, $2, new IntValue(1)); }  
|   unary_op unary_expression   { $$ = new UopExpr($1, $2); }
    ;


multiplicative_expression:
    unary_expression            { $$ = $1; }
|   multiplicative_expression "*" unary_expression { $$ = new BopExpr(skind_type::S_STAR, $1, $3);    }
|   multiplicative_expression "/" unary_expression { $$ = new BopExpr(skind_type::S_FSLASH, $1, $3);  }
|   multiplicative_expression "%" unary_expression { $$ = new BopExpr(skind_type::S_MOD, $1, $3);     }
    ;

additive_expression:
    multiplicative_expression   { $$ = $1; }
|   additive_expression "+" multiplicative_expression { $$ = new BopExpr(skind_type::S_PLUS, $1, $3); }
|   additive_expression "-" multiplicative_expression { $$ = new BopExpr(skind_type::S_MINUS, $1, $3);}
    ;

relational_expression:
    additive_expression     { $$ = $1; }
|   relational_expression "<" additive_expression   { $$ = new BopExpr(skind_type::S_LT, $1, $3);     }
|   relational_expression ">" additive_expression   { $$ = new BopExpr(skind_type::S_GT, $1, $3);     }
|   relational_expression LT_EQ additive_expression { $$ = new BopExpr(skind_type::S_LT_EQ, $1, $3);  }
|   relational_expression GT_EQ additive_expression { $$ = new BopExpr(skind_type::S_GT_EQ, $1, $3);  }
    ;

equality_expression:
    relational_expression   { $$ = $1; }
|   equality_expression EQ_EQ relational_expression   { $$ = new BopExpr(skind_type::S_EQ_EQ, $1, $3);  }
|   equality_expression BANG_EQ relational_expression { $$ = new BopExpr(skind_type::S_BANG_EQ, $1, $3);}  
    ;


assign_op:
    "="         { $$ = skind_type::S_EQ;        }
|   PLUS_EQ     { $$ = skind_type::S_PLUS;      } // we already know its an assignment, so return the arithmetic if not eq
|   MINUS_EQ    { $$ = skind_type::S_MINUS;     }
|   STAR_EQ     { $$ = skind_type::S_STAR;      }
|   FSLASH_EQ   { $$ = skind_type::S_FSLASH;    }
|   MOD_EQ      { $$ = skind_type::S_MOD;       }
    ;

unary_op:
    "!"     { $$ = skind_type::S_BANG;    }
|   "@"     { $$ = skind_type::S_AT;      }
|   "&"     { $$ = skind_type::S_AMP;     }
|   "-"     { $$ = skind_type::S_MINUS;   }
|   "~"     { $$ = skind_type::S_TILDE;   }
    ;

%% 

void yy::Parser::error(const location_type &loc, const std::string &msg) {
    std::cerr << loc << ": " << msg << std::endl;
}
