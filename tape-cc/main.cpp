
#include <vector>

#include "Parser/Lexer.h"

int main(int argc, char **argv) {
    // NOTE assume argv[1] is one and only file
    // TODO handle file inputs
    const std::string filename(argv[1]);

    Lexer lexer = Lexer();
    lexer.openFile(filename);


    /* get a list of lexemes/tokens from the input source file
    */
    Token *tok = lexer.nextToken();
    std::vector<Token*> v = std::vector<Token*>();
    v.push_back(tok);
    while (!lexer.reachedEndOfInput()) {
        tok = lexer.nextToken();
        if (tok != nullptr) {
            v.push_back(tok);
            std::cout << *tok << std::endl;
        }
    }
    // verify
    for (auto& t : v) {
        std::cout << *t << std::endl;
    }

    //std::cout << *((TokenInt *) &v[0]) << std::endl;
    std::cout << ((TokenInt *) v[0])->getValue() << std::endl;


   
    return 0;
}