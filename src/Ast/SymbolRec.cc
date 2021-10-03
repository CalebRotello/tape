

#include "SymbolRec.hh"


bool SymbolTable::addRecord(std::string id, Var *var) {
    return table.insert(std::make_pair(id, var)).second;
}

Var *SymbolTable::findRecord(const std::string& id) {
    return (table.count(id) ? table[id] : nullptr);
}

ScopeTree *ScopeTree::goDeeper() {
    if (next_scope == nullptr) {
        next_scope = new ScopeTree(this, level+1);
        return next_scope;
    } else {
        return nullptr;
    }
}

SymbolTable& ScopeTree::getSymbolTable() {
    return symbol_table;
}

Var *ScopeTree::findSymbol(const std::string& id) {
    if (next_scope == nullptr) {
        return symbol_table.findRecord(id);
    } else {
        Var *search = next_scope->findSymbol(id);
        return (search == nullptr ? symbol_table.findRecord(id) : search);
    }
}
