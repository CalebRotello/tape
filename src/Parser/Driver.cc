
#include "Driver.hh"

Driver::Driver() : trace_ast(false), show_scan(false) {}

int Driver::parse(const std::string &fname) {
    this->fname = fname;
    loc.initialize(&fname);
    scan_start();
    yy::Parser parse(this);
    int result = parse();
    scan_finish();
    return result;
}
