

#ifndef AST_HH_
#define AST_HH_

#include <string>
#include <vector>
#include "SymbolRec.hh"
#include "../Parser/Parser.hh"
enum Type: short {
    I8, I16, I32, I64, 
    uI8, uI16, uI32, uI64,
    F32, F64, 
    uF32, uF64,
    FN, DEF, AUTO
};

class Var {
    Type type;
    bool is_mutable; 
public:
    Var(Type t, bool m) : type(t), is_mutable(m) {}
};

class PureVar : public Var {
    Expr *expr;
public:
    PureVar(Type t, bool m, Expr *e) : Var(t, m), expr(e) {}
};

class AbstractVar : public Var {
    SymbolTable *table;
public:
};



class Node {
public:
    Node() {}
    virtual ~Node() {}
    virtual void print(const std::string& prefix, bool is_last);
    bool isAtomic() const;
};

//
// Statement
//
class IdValue; // fwd
class Stmt : public Node {};

class VarDeclStmt : public Stmt {
    std::string id;
    Expr *expr = nullptr;
public:
    VarDeclStmt(std::string id, bool is_mutable) : id(id) {} // TODO default values
    void setExpr(Expr *expr);
    virtual ~VarDeclStmt();
    virtual void print(const std::string& prefix, bool is_last);
};

class FunctionDeclStmt : public Stmt {
    std::string id;
    StmtList *fn_stmt_list;
    Expr *return_expr;
public:
    FunctionDeclStmt(std::string id) : id(id) {}
    FunctionDeclStmt(StmtList *stmt_list) : fn_stmt_list(stmt_list) {}
    FunctionDeclStmt(StmtList *stmt_list, Expr *return_expr) : fn_stmt_list(stmt_list), return_expr(return_expr) {}
    virtual ~FunctionDeclStmt();
    IdValue *getFnId();
    void setFnId(std::string id);
    virtual void print(const std::string& prefix, bool is_last);
};

class TypeDeclStmt : public Stmt {
    std::string id;
public:
    TypeDeclStmt(std::string id) : id(id) {}
    virtual void print(const std::string& prefix, bool is_last);
};

class StmtList : public Stmt {
    std::vector<Stmt*> stmt_list;
public:
    StmtList(std::initializer_list<Stmt*> stmt_list) : stmt_list(stmt_list) {}
    StmtList() : stmt_list() {}
    virtual ~StmtList();
    void push_back(Stmt* s);
    virtual void print(const std::string& prefix, bool is_last);
};

class ExprStmt : public Stmt {
    Expr *expr;
public:
    ExprStmt(Expr *expr) : expr(expr) {}
    virtual ~ExprStmt();
    virtual void print(const std::string& prefix, bool is_last);
};

class Break : public Stmt {
    u_short layers;
public: 
};

class Continue : public Stmt {
    u_short layers;
public: 
};




//
// Expr
//
class Expr : public Node {
    const bool atomic;
public:
    Expr() : atomic(false) {}
    Expr(bool a) : atomic(a) {}
    virtual ~Expr() {}
    bool isAtomic() const;
};
//typedef std::vector<Expr*> ExprList;

class BopExpr : public Expr {
    Expr *lexpr;
    Expr *rexpr;
    int op;
public:
    BopExpr(int op, Expr *lexpr, Expr *rexpr) 
        : Expr(), lexpr(lexpr), rexpr(rexpr), op(op) {}
    virtual ~BopExpr();
    virtual void print(const std::string& prefix, bool is_last);
};

class UopExpr : public Expr {
    Expr *expr;
    int op;
public:
    UopExpr(int op, Expr *expr) : Expr(), expr(expr), op(op) {}
    virtual ~UopExpr(); 
    virtual void print(const std::string& prefix, bool is_last);
};

class AssignExpr : public Expr {
    IdValue *id;
    Expr *expr;
public:
    AssignExpr(IdValue *id, Expr *expr) : Expr(), id(id), expr(expr) {} // TODO check mutability
    virtual ~AssignExpr();
    virtual void print(const std::string& prefix, bool is_last);
};



//
// Value
//
class Value : public Expr {
public:
    Value(bool a) : Expr(a) {}
};

class IdValue : public Value {
    std::string val;
public:
    IdValue(std::string v) : Value(false), val(v) {}
    virtual ~IdValue() {}
    virtual void print(const std::string& prefix, bool is_last);
};

class StrValue : public Value {
    std::string val;
public:
    StrValue(std::string v) : Value(true), val(v) {}
    virtual void print(const std::string& prefix, bool is_last);
};

class IntValue : public Value {
    long long val;
public:
    IntValue(long long l) : Value(true), val(l) {}
    virtual void print(const std::string& prefix, bool is_last);
};

class FloatValue : public Value {
    double val;
public:
    FloatValue(double v) : Value(true), val(v) {}
    virtual void print(const std::string& prefix, bool is_last);
};


// forward declarations
class ScopeTree;
class SymbolTable;
class Tree {
    StmtList *prog;
    ScopeTree *file_scope;
public:
    Tree(StmtList *prog, ScopeTree *file_scope) 
        : prog(prog), file_scope(file_scope) {}
    ~Tree();
    StmtList *getProg();
    void pruneAst();
};


// bells and whistles
void pref(const std::string& prefix, bool is_last);
const char *psymbol(const int& op);
const char *ppipe(bool is_last);


#endif /* AST_HH_ */
