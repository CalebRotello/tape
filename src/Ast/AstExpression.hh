
#ifndef AST_EXPRESSION_HH_
#define AST_EXPRESSION_HH_

#include "../Parser/Parser.hh"

#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

class Statement;
class Expression;
class VarDecl;
class Identifier;

typedef vector<Statement*> StatementList;
typedef vector<Expression*> ExpressionList;
typedef vector<VarDecl*> VarList;

class Node {
public: 
    ~Node() {}
};


///////////////////////////////////////////
// Statements
///////////////////////////////////////////
class Statement : public Node {};

class BlockStmt : public Statement {
    BlockStmt() {}
    // TODO addStmt 
private:
    StatementList stmts;
};

class ExprStmt : public Statement {
public: 
    ExprStmt(Expression *expr) : expr(expr) {}
private:
    Expression *expr;
};

class VarDecl : public Statement {
public:
    VarDecl(int type, Identifier *id, Expression *expr) :
        type(type), id(id), expr(expr) {}
private:
    int type;
    Identifier *id;
    Expression *expr;
};

class FunctionDecl : public Statement {
public:
    FunctionDecl(int type, Identifier *id, VarList *args, StatementList *func) :
        type(type), id(id), args(args), func(func) {}
private:
    int type;
    Identifier *id;
    VarList *args;
    StatementList *func;
};

class ObjDecl : public Statement {
public:
private:
};



///////////////////////////////////////////
// Expressions
///////////////////////////////////////////
class Expression : public Node {};

class Identifier : public Expression {
public:
    Identifier(std::string id_name) : id_name(id_name) {}
private:
    const std::string id_name;
};

class FunctionCall : public Expression {
public:
    FunctionCall(const Expression *id, ExpressionList *args) :
        args(args), id(id) {}
private:
    ExpressionList *args;
    const Expression *id;
};

class BinaryExpr : public Expression {
public:
    BinaryExpr(int op, Expression *lexpr, Expression *rexpr) : 
        op(op), lexpr(lexpr), rexpr(rexpr) {}
private:
    int op;
    Expression *lexpr, *rexpr;
};

class UnaryExpr : public Expression {
public:
    UnaryExpr(int op, Expression *expr) : op(op), expr(expr) {}
private:
    int op;
    Expression *expr;
};

class AssignmentExpr : public Expression {
public:
    AssignmentExpr(int op, Expression *id, Expression *expr) :
        op(op), id(id), expr(expr) {}
private:
    int op;
    Expression *id;
    Expression *expr;
};

class AccessCall : public Expression {
public:
    AccessCall(Expression *obj, Expression *member) : obj(obj), member(member) {}
private:
    Expression *obj;
    Expression *member;
};

class OrExpr : public Expression {
public:
    OrExpr(Expression *question, Expression *t, Expression *f) :
        question(question), t(t), f(f) {}
private:
    Expression *question, *t, *f;
};


///////////////////////////////////////////
// Values
///////////////////////////////////////////
class Value : public Expression {
};

class IVal : public Value {
public:
    IVal(long long val) : val(val) {}
private:
    long long val;
};

class CVal : public Value {
public:
    CVal(char val) : val(val) {}
private:
    char val;
};

class BVal : public Value {
public: 
    BVal(bool val) : val(val) {}
private:
    bool val;
};

class SVal : public Value {
public:    
    SVal(std::string val) : val(val) {}
private:
    std::string val;
};

class FVal : public Value {
public:
    FVal(float val) : val(val) {}
private:
    float val;
};

#endif

#ifndef AST_TYPE_HH_
#define AST_TYPE_HH_

#include <map>
#include <string>
#include <bitset>
#include <vector>
using std::vector;


// just to be useful
//struct BoolBits {
//    unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
//};
//
//union Cbits {
//    BoolBits bits;
//    unsigned char byte;
//};


class TypeTable {
public:
    static TypeTable *getTypeTable() {
        if (!type_table)
            type_table = new TypeTable;
        return type_table;
    }

private:
    static TypeTable *type_table;
    TypeTable();


};

//TypeTable *TypeTable::type_table = 0; 
enum VarRawType {INT, FLOAT, BOOL, CHAR, STRUCT};

class Type {
    Type(int type, size_t bytes, ) : bytes(bytes), type(type) {}
private:
    u_short bytes;
    u_short type;
    std::bitset<8> modifiers;
};

class StructType : public Type {
private:
    SymbolTable local_record;
};

#endif