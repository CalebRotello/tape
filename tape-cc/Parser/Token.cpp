
#include "Token.h"

void Position::advance(const char& next_char) {
    this->global_index++;
    if (next_char == '\n') {
        this->line_index = 0;
        this->line_no++;
    } else {
        this->line_index++;
    }
}



std::ostream& operator<<(std::ostream& out, const TokenType& value) {
    const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
    switch(value){
        PROCESS_VAL(star);     
        PROCESS_VAL(plus);     
        PROCESS_VAL(dash);
        PROCESS_VAL(fslash);
        PROCESS_VAL(equals);

        PROCESS_VAL(integerliteral);
    }
#undef PROCESS_VAL
    return out << s;
}

std::ostream& operator<<(std::ostream& out, const Token& value) {
    return out << "<" << value.getTokenType() << ":" 
        << value.getPosition().getLineNo() << ":" 
        << value.getPosition().getLineIndex() << ">";
}

std::ostream& operator<<(std::ostream& out, const TokenInt& value) {
    return out << "<" << value.getTokenType() << "(" << value.getValue() << "):" 
        << value.getPosition().getLineNo() << ":" 
        << value.getPosition().getLineIndex() << ">";
}