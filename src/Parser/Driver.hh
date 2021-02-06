#ifndef DRIVER_HH_
#define DRIVER_HH_

#include <string>
#include <map>
#include "Parser.hh"
#include "../Ast/Ast.hh"
//#include "Lexer.hh"
#include "location.hh"

// yylex for Flex
# define YY_DECL \
    yy::Parser::symbol_type yylex (Driver *driver)//, std::vector<Stmt*> *fstmt_list) 
// declare for parser
YY_DECL;

struct Driver {
    Driver();
    Tree *f_ast;
    yy::location loc;

    bool show_scan = false;
    bool trace_ast = false;
    std::string fname;

    int parse (const std::string& fname);
    void scan_start();
    void scan_finish();

};


#endif