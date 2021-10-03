
%option noyywrap nounput noinput batch debug

%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring>
    #include <string>
    #include "Driver.hh"
    #include "Parser.hh"
%}


Dec     [0-9]
Alpha   [a-zA-Z_]
Hex     [a-fA-F0-9]
Sci     [Ee][+-]?{Dec}+

%{
    #define YY_USER_ACTION loc.columns(yyleng);
%}
%%
%{
    yy::location &loc = driver->loc;
    loc.step();
%}

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] loc.lines(yyleng); loc.step(); 
\/\/(.*)     loc.step(); 

 /*"auto"      { return yy::Parser::make_AUTO      (loc); }
 "break"     { return yy::Parser::make_BREAK     (loc); }
 "case"      { return yy::Parser::make_CASE      (loc); }
 "continue"  { return yy::Parser::make_CONTINUE  (loc); }
 "default"   { return yy::Parser::make_DEFAULT   (loc); } */
"else"      { return yy::Parser::make_ELSE      (loc); }
 /*"enum"      { return yy::Parser::make_ENUM      (loc); } */
"for"       { return yy::Parser::make_FOR       (loc); }
"if"        { return yy::Parser::make_IF        (loc); }
"return"    { return yy::Parser::make_RETURN    (loc); }
 /*"sizeof"    { return yy::Parser::make_SIZEOF    (loc); }
 "static"    { return yy::Parser::make_STATIC    (loc); }
 "struct"    { return yy::Parser::make_STRUCT    (loc); }
 "switch"    { return yy::Parser::make_SWITCH    (loc); }
 "union"	    { return yy::Parser::make_UNION     (loc); } */
"let"       { return yy::Parser::make_LET       (loc); }
"var"       { return yy::Parser::make_VAR       (loc); }
"fn"        { return yy::Parser::make_FN        (loc); }
"while"	    { return yy::Parser::make_WHILE     (loc); }

 /*"void"      { return yy::Parser::make_VOID      (loc); }
 "const"	    { return yy::Parser::make_CONST     (loc); }
 "signed"    { return yy::Parser::make_SIGNED    (loc); }
 "unsigned"  { return yy::Parser::make_UNSIGNED  (loc); }

 "bool"      { return yy::Parser::make_BOOL  (loc); } */
"f32"       { return yy::Parser::make_F32   (loc); }
"f64"       { return yy::Parser::make_F64   (loc); }
"i8"        { return yy::Parser::make_I8    (loc); }
"i16"       { return yy::Parser::make_I16   (loc); }
"i32"       { return yy::Parser::make_I32   (loc); }
"i64"       { return yy::Parser::make_I64   (loc); }
"u_f32"       { return yy::Parser::make_U_F32   (loc); }
"u_f64"       { return yy::Parser::make_U_F64   (loc); }
"u_i8"        { return yy::Parser::make_U_I8    (loc); }
"u_i16"       { return yy::Parser::make_U_I16   (loc); }
"u_i32"       { return yy::Parser::make_U_I32   (loc); }
"u_i64"       { return yy::Parser::make_U_I64   (loc); }

 /*"char"      { return yy::Parser::make_CHAR  (loc); } */

"true"      {  return yy::Parser::make_BOOL_VAL (true, loc); }
"false"     {  return yy::Parser::make_BOOL_VAL (false, loc); }
{Alpha}({Alpha}|{Dec})* { return yy::Parser::make_ID(yytext, loc); }

{Dec}+                  { return yy::Parser::make_INT_VAL   (atoll(yytext), loc);}
{Dec}+\.{Dec}*          { return yy::Parser::make_FLOAT_VAL (atof(yytext), loc);}
\'[^\\']?\'             { return yy::Parser::make_CHAR_VAL  (yytext[1], loc);   }
\"(\\.|[^\\"])*\"       { yytext[yyleng-1] = 0; return yy::Parser::make_STRING_VAL(yytext+1, loc); }

 /*"..."   { return yy::Parser::make_ELLIPSIS(loc); }*/
"+="    { return yy::Parser::make_PLUS_EQ(loc); }
"-="    { return yy::Parser::make_MINUS_EQ(loc); }
">>="   { return yy::Parser::make_RIGHT_EQ(loc); }
"<<="   { return yy::Parser::make_LEFT_EQ(loc); }
"*="    { return yy::Parser::make_STAR_EQ(loc); }
"/="    { return yy::Parser::make_FSLASH_EQ(loc); }
"%="    { return yy::Parser::make_MOD_EQ(loc); }
"^="    { return yy::Parser::make_CARROT_EQ(loc); }
"&="    { return yy::Parser::make_AMP_EQ(loc); }
"|="    { return yy::Parser::make_PIPE_EQ(loc); }
">>"    { return yy::Parser::make_RIGHT(loc); }
"<<"    { return yy::Parser::make_LEFT(loc); }
"++"    { return yy::Parser::make_INCREMENT(loc); }
"--"    { return yy::Parser::make_DECREMENT(loc); }
"->"    { return yy::Parser::make_POINTER(loc); }
"&&"    { return yy::Parser::make_AMP_AMP(loc); }
"||"    { return yy::Parser::make_PIPE_PIPE(loc); }
"<="    { return yy::Parser::make_LT_EQ(loc); }
">="    { return yy::Parser::make_GT_EQ(loc); }
"=="    { return yy::Parser::make_EQ_EQ(loc); }
"!="    { return yy::Parser::make_BANG_EQ(loc); }
"="	    { return yy::Parser::make_EQ (loc); }
";"	    { return yy::Parser::make_SC (loc); }
"{"	    { return yy::Parser::make_LBRACE (loc); }
"}"	    { return yy::Parser::make_RBRACE (loc); }
","	    { return yy::Parser::make_COMMA (loc); }
":"	    { return yy::Parser::make_COLON (loc); }
"("	    { return yy::Parser::make_LPAREN (loc); }
")"	    { return yy::Parser::make_RPAREN (loc); }
"["	    { return yy::Parser::make_LSQUARE (loc); }
"]"	    { return yy::Parser::make_RSQUARE (loc); }
"."	    { return yy::Parser::make_DOT (loc); }
"&"	    { return yy::Parser::make_AMP (loc); }
"!"	    { return yy::Parser::make_BANG (loc); }
"~"	    { return yy::Parser::make_TILDE (loc); }
"-"	    { return yy::Parser::make_MINUS (loc); }
"+"	    { return yy::Parser::make_PLUS (loc); }
"*"	    { return yy::Parser::make_STAR (loc); }
"/"	    { return yy::Parser::make_FSLASH (loc); }
"%"	    { return yy::Parser::make_MOD (loc); }
"@"     { return yy::Parser::make_AT (loc); }
"<"	    { return yy::Parser::make_LT (loc); }
">"	    { return yy::Parser::make_GT (loc); }
"^"	    { return yy::Parser::make_CARROT (loc); }
"|"	    { return yy::Parser::make_PIPE (loc); }
"?"	    { return yy::Parser::make_QUESTION (loc); }

[ \t\r]+ loc.step();
\n          loc.lines(yyleng); loc.step();
.   
<<EOF>>     return yy::Parser::make_YYEOF(loc);

%%

void Driver::scan_start() {
    yy_flex_debug = show_scan;
    if (!(yyin = fopen(fname.c_str(), "r"))) {
        std::cerr << "Error opening " << fname << ": " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Driver::scan_finish() {
    fclose(yyin);
}
