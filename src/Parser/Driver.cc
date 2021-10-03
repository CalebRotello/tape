
#include "Driver.hh"

int Driver::parse(const std::string &fname) {
    this->fname = fname;
    loc.initialize(&fname);
    scan_start();

    StmtList *fstmt_list = new StmtList();
    ScopeTree *scope = new ScopeTree(&global_scope, 1);
    yy::Parser parse(this, fstmt_list, scope);
    int result = parse();
    scan_finish();

    // TODO check filename collisions? maybe this needs error handling not sure
    ast_map.insert(std::make_pair(fname, new Tree(fstmt_list, scope)));
    return result;
}

int Driver::traverseAsts() {
    // do ast things that the asts like to do 
    for (auto &ast : ast_map) {
        if (trace_ast) {
            std::cout << "\n" << ast.first << ":\n";
            ast.second->getProg()->print("", false);
        }
        ast.second->pruneAst();
    }
}

Driver::~Driver() {
    for (auto it : ast_map)
        delete it.second;
}
