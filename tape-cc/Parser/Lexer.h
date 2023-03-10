
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <cctype>
#include <cerrno>

#include <iostream>

#include "Token.h"

class Lexer {
    public:
        Lexer() {}

        /* nextToken
            get the next token in the current sourcecode
        */
        Token* nextToken();

        /* openFile
            open a new file for lexing
        */
        void openFile(const std::string& filename);

        /* endoffile */
        const bool reachedEndOfInput() const { return this->sourcecode.length() <= this->currpos.getGlobalIndex(); }

        /* getters and setters */
        const std::string& getSourcecode() const { return this->sourcecode; }

    private:
        /* progress until we get to a non-whitespace character */
        void skipWhitespace();
        /* progress the current position */
        void progressCurrPos() { this->currpos.advance(this->getCurrChar()); }
        /* get current character */
        const char& getCurrChar() const { return this->sourcecode[this->currpos.getGlobalIndex()]; }


        std::string filename;
        std::string sourcecode;

        Position currpos;

};