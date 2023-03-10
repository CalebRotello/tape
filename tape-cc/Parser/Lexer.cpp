
#include "Lexer.h"


Token* Lexer::nextToken() {
    this->skipWhitespace();
    if (this->reachedEndOfInput()) 
        return nullptr;

    /* this block of code is a hard-coded DFA, which will
        1. identify the longest-possible lexeme
        2. progress the position to the first character beyond that lexeme
    */
    Token *tok;
    Position first_pos = this->currpos; // separate so the currpos can check the NEXT character (i.e. == is equalsequals)
    // this is the only un-automated part of the code. relies on the names of symbols in the grammar
    switch (this->getCurrChar()) {
        case '*': 
            tok = new Token(TokenType::star, first_pos);
            this->progressCurrPos();
            break;

        case '+':
            tok = new Token(TokenType::plus, first_pos);
            this->progressCurrPos();
            break;

        case '=':
            tok = new Token(TokenType::equals, first_pos);
            this->progressCurrPos();
            break;

        case '-':
            tok = new Token(TokenType::dash, first_pos);
            this->progressCurrPos();
            break;
        
        case '/':
            tok = new Token(TokenType::fslash, first_pos);
            this->progressCurrPos();
            break;

        
        // integer literal
        case '0'...'9':
            // TODO better substring copy and conversion to int
            std::string int_substr;
            int_substr.push_back(this->getCurrChar());
            this->progressCurrPos();
            while (this->getCurrChar() >= '0' && this->getCurrChar() <= '9') {
                int_substr.push_back(this->getCurrChar());
                this->progressCurrPos();
            }
            tok = new TokenInt(TokenType::integerliteral, first_pos, stoi(int_substr));
            break;
    }
    return tok;
}



void Lexer::skipWhitespace() {
    while (isspace(this->getCurrChar())) {
        this->progressCurrPos();
    }
}



void Lexer::openFile(const std::string& filename) {
    this->filename = filename;

    std::ifstream in(this->filename);

    if (in) {
        in.seekg(0, std::ios::end);
        this->sourcecode.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&(this->sourcecode[0]), this->sourcecode.size());
        in.close();

        this->currpos = Position();
        return;
    } 
    throw(errno);
}