
#ifndef SYMBOL_TABLE_HH_
#define SYMBOL_TABLE_HH_

#include <map>
#include <vector>
#include <string>

#include "AstExpression.hh"


class SymbolRecord {
public:
    SymbolRecord(int type, void *mem, size_t size) : 
        type(type), mem(mem), size(size) {}
    void *getMem();

private:
    int type;
    void *mem;
    size_t size;
};


class SymbolTable {
public:
    SymbolTable();
    int addRecord(Identifier *id, Expression *expr);
private:
    std::map<std::string, Expression*> record_map;
};

#endif