
#include "Parser/Driver.hh"
#include "Ast/Ast.hh"

int main(int argc, char *argv[]) {
    int result = 1;
    Driver driver;

    std::vector<std::string> source_files;
    std::vector<Tree*> ftrees;
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (arg == "-a")
            driver.trace_ast = true;
        else if (arg == "-s")
            driver.show_scan = true;
        else if (arg.substr(arg.rfind('.')) == ".tape") 
            source_files.push_back(arg);
        else 
            std::cerr << "tape: unrecognized command" << std::endl;
    }

    if (source_files.size() == 0) {
        std::cerr << "tape: expected 1 or more arguments of type *.tape" << std::endl;
    }

    // parse the whole program
    for (const std::string& str : source_files) {
        result = driver.parse(str);
        ftrees.push_back(driver.f_ast);
    }

    // ast elbow grease
    for (Tree *tree : ftrees) {
        if (driver.trace_ast)
            tree->getProg()->print("", false);
    }

    return result;
}