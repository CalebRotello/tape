#ifndef DRIVER_HH_
#define DRIVER_HH_

#include <string>
#include <map>
#include "Parser.hh"
#include "../Ast/Ast.hh"
#include "location.hh"

// yylex for Flex
# define YY_DECL \
    yy::Parser::symbol_type yylex (Driver *driver)
// declare for parser
YY_DECL;

struct Driver {
public:
    Driver() : ast_map() {}
    ~Driver();
    yy::location loc;

    bool show_scan = false;
    bool trace_ast = false;
    std::string fname;

    int parse (const std::string& fname);
    void scan_start();
    void scan_finish();

    int traverseAsts();

private:
    std::map<std::string, Tree*> ast_map; // file -> ast
    ScopeTree global_scope = ScopeTree(nullptr, 0);
};


#endif