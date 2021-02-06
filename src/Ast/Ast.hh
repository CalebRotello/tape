

#ifndef AST_HH_
#define AST_HH_

#include <string>
#include <vector>
#include "../Parser/Parser.hh"



class Node {
public:
    virtual void print(u_short i) const;
};
class IdValue;
class StmtList;




//
// Statement
//
class Stmt : public Node {
public:
};

class VarDeclStmt : public Stmt {
    std::string id;
    Expr *expr = nullptr;
public:
    VarDeclStmt(std::string id, bool is_mutable) : id(id) {} // TODO default values
    void setExpr(Expr *expr);
    virtual void print(u_short i) const;
};

class FunctionDeclStmt : public Stmt {
    std::string id;
    StmtList *fn_stmt_list;
    Expr *return_expr;
public:
    FunctionDeclStmt(std::string id) : id(id) {}
    FunctionDeclStmt(StmtList *stmt_list) : fn_stmt_list(stmt_list) {}
    FunctionDeclStmt(StmtList *stmt_list, Expr *return_expr) : fn_stmt_list(stmt_list), return_expr(return_expr) {}
    IdValue *getFnId();
    void setFnId(std::string id);
    virtual void print(u_short i) const;
};

class TypeDeclStmt : public Stmt {
    std::string id;
public:
    TypeDeclStmt(std::string id) : id(id) {}
};

class StmtList : public Stmt {
    std::vector<Stmt*> stmt_list;
public:
    StmtList(std::initializer_list<Stmt*> stmt_list) : stmt_list(stmt_list) {}
    StmtList() : stmt_list() {}
    void push_back(Stmt* s);
    virtual void print(u_short i) const;
};

class ExprStmt : public Stmt {
    Expr *expr;
public:
    ExprStmt(Expr *expr) : expr(expr) {}
};

class ActionStmt : public Stmt {
};




//
// Expr
//
class Expr : public Node {};
typedef std::vector<Expr*> ExprList;

class BopExpr : public Expr {
    Expr *lexpr;
    Expr *rexpr;
    int op;
public:
    BopExpr(int op, Expr *lexpr, Expr *rexpr) : lexpr(lexpr), rexpr(rexpr), op(op) {}
};

class UopExpr : public Expr {
    Expr *expr;
    int op;
public:
    UopExpr(int op, Expr *expr) : expr(expr), op(op) {}
};

class AssignExpr : public Expr {
    IdValue *id;
    Expr *expr;
public:
    AssignExpr(IdValue *id, Expr *expr) : id(id), expr(expr) {} // TODO check mutability
};



//
// Value
//
class Value : public Expr {};

class IdValue : public Value {
    std::string val;
public:
    IdValue(std::string v) : val(v) {}
};

class StrValue : public Value {
    std::string val;
public:
    StrValue(std::string v) : val(v) {}
};

class IntValue : public Value {
    long long val;
public:
    IntValue(long long l) : val(l) {}
};

class FloatValue : public Value {
    double val;
public:
    FloatValue(double v) : val(v) {}
};


class Tree {
    StmtList *prog;
    std::string fname;
public:
    Tree(StmtList *prog, std::string fname) : prog(prog), fname(fname) {}
    StmtList *getProg();
};


// bells and whistles
void prettyprint(const Node *n, u_short layer);
void ptab(u_short i);

#endif /* AST_HH_ */
