
#include "Driver.hh"

Driver::Driver() {}//: trace_ast(false), show_scan(false) {}

int Driver::parse(const std::string &fname) {
    this->fname = fname;
    loc.initialize(&fname);
    scan_start();
    StmtList *fstmt_list = new StmtList();
    yy::Parser parse(this, fstmt_list);
    int result = parse();
    scan_finish();
    f_ast = new Tree(fstmt_list, fname);
   return result;
}
