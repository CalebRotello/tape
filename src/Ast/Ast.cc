
#include "Ast.hh"


//
// Stmt
//
void VarDeclStmt::setExpr(Expr *expr) {
    this->expr = expr;
}

IdValue *FunctionDeclStmt::getFnId() {
    return new IdValue(id);
}


void FunctionDeclStmt::setFnId(std::string id) {
    this->id = id;
}


void StmtList::push_back(Stmt *s) {
    stmt_list.push_back(s);
}



//
// Expr 
//


StmtList *Tree::getProg() {
    return prog;
}




// Devoted to printing functions
// TODO tabulation is not perfect
void pref(const std::string& prefix, bool is_last) {
    std::cout << prefix << (is_last ? "|-" : "'-");
}

const char *psymbol(const int& op) {
    return yy::Parser::symbol_name(yy::Parser::symbol_kind_type(op));
}

void Node::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "Node" << std::endl;
}

void FloatValue::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "FloatVal " << val <<std::endl;
}

void IntValue::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "IntVal " << val << std::endl;
}

void StrValue::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "StrVal " << val << std::endl;
}

void IdValue::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "IdValue " << val << std::endl;
}

void AssignExpr::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "AssignExpr" << std::endl;
    id->print(prefix + (is_last? "|   ": "    "), true);
    expr->print(prefix + (is_last? "|   ": "    "), false);
}

void UopExpr::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "UopExpr " << psymbol(op) << std::endl;
    expr->print(prefix + (is_last? "|   ": "    "), true);
}

void BopExpr::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "BopExpr " << psymbol(op) << std::endl;
    rexpr->print(prefix + (is_last? "|   ": "    "), true);
    lexpr->print(prefix + (is_last? "|   ": "    "), false);
}

void ExprStmt::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "ExprStmt" << std::endl;
    expr->print(prefix + (is_last? "|   ": "    "), false);
}

void StmtList::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "StmtList" << std::endl;
    for (size_t i = 0; i < stmt_list.size() - 1; i++)
        stmt_list[i]->print(prefix + (is_last? "|   ": "    "), true);
    stmt_list[stmt_list.size() - 1]->print(prefix + (is_last? "|   ": "    "), false);
}

void TypeDeclStmt::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "TypeDeclStmt " << id << std::endl;
}

void FunctionDeclStmt::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "FunctionDeclStmt " << id << std::endl;
    fn_stmt_list->print(prefix + (is_last? "|   ": "    "), true);
    return_expr->print(prefix + (is_last? "|   ": "    "), false);
}

void VarDeclStmt::print(const std::string& prefix, bool is_last) {
    pref(prefix, is_last);
    std::cout << "VarDeclStmt " << id << std::endl;
    expr->print(prefix + (is_last? "|   ": "    "), true);
}