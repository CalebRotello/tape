

#ifndef SYMBOL_REC_HH_
#define SYMBOL_REC_HH_

//#include "Ast.hh"

#include <map>
#include <string>

// fwd declaration
class Var;
class SymbolTable {
public:
    /* addRecord
     *  add string/value pair to a scope
     *  return true on success, false on collision 
     */ 
    bool addRecord(std::string id, Var *var);
    Var *findRecord(const std::string& id);

private:
    std::map<std::string, Var*> table; 
};


class ScopeTree {
public:
    ScopeTree(ScopeTree *parent, u_short level) 
        : level(level), symbol_table(), next_scope(nullptr), last_scope(parent) {}
    ScopeTree *goDeeper();
    SymbolTable& getSymbolTable();
    Var *findSymbol(const std::string& id);

private:
    u_short level;
    SymbolTable symbol_table;
    ScopeTree *next_scope;
    ScopeTree *last_scope;
};



#endif /* SYMBOL_REC_HH_ */