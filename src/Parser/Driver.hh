#ifndef DRIVER_HH_
#define DRIVER_HH_

#include <string>
#include <map>
#include "Parser.hh"
//#include "Lexer.hh"
#include "location.hh"

// yylex for Flex
# define YY_DECL \
    yy::Parser::symbol_type yylex (Driver *driver) 
// declare for parser
YY_DECL;

class Driver {
public:
    Driver();
    std::map<std::string, int> vars;
    int result;
    std::string fname;

    bool trace_ast;
    int parse (const std::string& fname);

    bool show_scan;
    void scan_start();
    void scan_finish();
    yy::location loc;
};


#endif