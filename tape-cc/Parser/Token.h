
// imports for printing
#include <ostream>
//#include <string>


enum TokenType {
    star,
    plus,
    dash,
    fslash,
    equals,

    integerliteral,
};



class Position {
    public:
        Position() : global_index(0), line_index(0), line_no(0) {}

        /* advance
            add to the position, compensating for newline
        */
        void advance(const char& next_char);

        /* getters and setters
        */
        const unsigned long long& getGlobalIndex() const { return this->global_index; }
        const unsigned long long& getLineIndex() const { return this->line_index; }
        const unsigned long long& getLineNo() const { return this->line_no; }

    private:
        // TODO if we impose better limits on file size, we save memory here
        // TODO include the filename in this (with only one pointer)
        unsigned long long global_index; // nth char in file 
        unsigned long long line_index;   // nth char in curr line
        unsigned long long line_no;      // nth line number
};


// TODO and NOTE we have to upcast the derived classes, so behavior later on will need to expect different derived classes
class Token {
    public:
        Token(TokenType toktype, Position pos) : toktype(toktype), pos(pos) {}

        /* getters and setters
        */
        const Position& getPosition() const { return this->pos; }
        const TokenType& getTokenType() const { return this->toktype; }

        //virtual const int& getValue() const { return 0; };

    protected:
        TokenType toktype;
        Position pos;
};

class TokenInt: public Token {
    public:
        TokenInt(TokenType toktype, Position pos, int value) : Token(toktype, pos), value(value) {}

    /* getters and setters
    */
    const int& getValue() const { return this->value; }

    protected:
        int value;
};




/* print TokenType
*/
std::ostream& operator<<(std::ostream& out, const TokenType& value);

/* print Token
*/
std::ostream& operator<<(std::ostream& out, const Token& value);

/* print TokenInt
*/
std::ostream& operator<<(std::ostream& out, const TokenInt& value);