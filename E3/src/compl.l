%{
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

int yylval;
%}
%option yylineno


INT        [0-9]+
SPACING    [ \n\t\r]*
IDENTIFIER [a-zA-Z][a-zA-Z0-9_]{0,255}
COMMENT    "//".*

CHAR       '([^\\']|\\[0abefnrtvdws\\\'])'
STRING     (\"[^\n"]+\"|\"\")
SYMBOL     [/%!<>=:;,()[\]{}\\]
ERROR      .
 
%%

\n                { }
{COMMENT}         { }
{SPACING}         { }

"for"           { return KEY_FOR; }
"function"      { return KEY_FUNCTION; }
"print"         { return KEY_PRINT; }
"return"        { return KEY_RETURN; }
"if"            { return KEY_IF; }  
"else"          { return KEY_ELSE; }
"while"         { return KEY_WHILE; }

"integer"       { return TYPE_INTEGER; }
"boolean"       { return TYPE_BOOLEAN; }
"char"          { return TYPE_CHAR; }
"string"        { return TYPE_STR; }
"void"          { return TYPE_VOID; }

"true"          { return TRUE; }
"false"         { return FALSE; }
"<="            { return LEQ; }
">="            { return GEQ; }
"=="            { return EQ; }
"!="            { return NEQ; }
"&&"            { return AND; }
"||"            { return OR; }
"+"             { yylval = (int)(yytext[0]); return PLUS; }
"-"             { yylval = (int)(yytext[0]); return MINUS; }
"*"             { yylval = (int)(yytext[0]); return MUL; }
"/"             { yylval = (int)(yytext[0]); return DIV; }
"<"             { yylval = (int)(yytext[0]); return LT; }
">"             { yylval = (int)(yytext[0]); return GT; }
"="             { yylval = (int)(yytext[0]); return ASSIGN; }

{SYMBOL}          { yylval = (int)(yytext[0]); return SYM; }
{CHAR}/\n         { return CHAR; }
{STRING}          { return STR; }
{IDENTIFIER}      { return ID; }
{INT}+            { yylval = atoi(yytext); return NUM; }
{ERROR}           { return ERROR; }

%%

int yywrap() {
    return 1;
}