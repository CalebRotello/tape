
#include "Ast.hh"


//
// Stmt
//
void VarDeclStmt::print(u_short i) const {
    std::cout << "VarDecl, " << id;
    if (expr != nullptr) {
        std::cout << std::endl;
        prettyprint(expr, i+1);
    }
}

void VarDeclStmt::setExpr(Expr *expr) {
    this->expr = expr;
}

IdValue *FunctionDeclStmt::getFnId() {
    return new IdValue(id);
}

void FunctionDeclStmt::print(u_short i) const {
    std::cout << "FnDecl, " << id << " start {" << std::endl;
    prettyprint(fn_stmt_list, i+1);
    ptab(i);
    std::cout << "} end " << id;
}

void FunctionDeclStmt::setFnId(std::string id) {
    this->id = id;
}

void StmtList::push_back(Stmt *s) {
    stmt_list.push_back(s);
}

void StmtList::print(u_short i) const {
    std::cout << "StmtList" << std::endl;
    for (const Stmt *s : stmt_list)
        prettyprint(s, i+1);
}


StmtList *Tree::getProg() {
    return prog;
}


void prettyprint(const Node *n, u_short layer) {
    ptab(layer);
    std::cout << ":";
    n->print(layer);
    //std::cout << ">" << std::endl;
    std::cout << std::endl;
}


void Node::print(u_short layer) const {
    std::cout << "AbstractNode";
}

void ptab(u_short i) {
    for (auto j = 0; j < i; j++)
        std::cout << "  ";
}