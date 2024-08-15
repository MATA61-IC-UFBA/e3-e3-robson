// main.c for T1 - Lexical Analysis for compL

#include <stdio.h>
#include <stdlib.h>
#include "token.h"

/* interface to lexer */

extern int yylineno; /* from lexer */
extern char *yytext;
extern int yylex();
extern int yylval;

int main(int argc, char **argv) {
	token_t token;

	extern FILE *yyin;
	extern FILE *yyout;

	if (argc > 2) {
		if(!(yyin = fopen(argv[1], "r"))) {
			fprintf(stderr,"erro na abertura do arquivo de entrada %s\n",argv[1]);
			return (1);
		}
		if(!(yyout = fopen(argv[2], "w"))) {
			fprintf(stderr,"erro na criacao do arquivo de saida %s\n",argv[2]);
			return (1);
		}
	}
	else {
		fprintf(stderr,"erro no número de argumentos de entrada\n");
		return (1);
	}

	while ((token = yylex())) {
		switch (token) {
			case ERROR:
				// printf("(%d,ERROR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,ERROR,\"%s\")\n", yylineno, yytext);
				break;
			case ID:
				// printf("(%d,ID,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,ID,\"%s\")\n", yylineno, yytext);
			    break;
			case NUM:
				// printf("(%d,NUM,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,NUM,\"%s\")\n", yylineno, yytext);
			    break;
			case CHAR:
				// printf("(%d,CHAR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,CHAR,\"%s\")\n", yylineno, yytext);
			    break;
			case STR:
				// printf("(%d,STR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,STR,\"%s\")\n", yylineno, yytext);
			    break;
            case LEQ:
            case GEQ:
            case EQ:
            case NEQ:
            case AND:
            case OR:
				// printf("(%d,%d,\"%s\")\n", yylineno, token, yytext);
				fprintf(yyout, "(%d,%d,\"%s\")\n", yylineno, token, yytext);
			    break;
            case KEY_IF:
            case KEY_ELSE:
            case KEY_PRINT:
            case KEY_FOR:
            case KEY_WHILE:
            case KEY_FUNCTION:
            case TYPE_INTEGER:
            case TYPE_BOOLEAN:
            case FALSE:
            case TRUE:
            case KEY_RETURN:
            case TYPE_CHAR:
            case TYPE_STR:
            case TYPE_VOID:
				// printf("(%d,%d,\"%s\")\n", yylineno, token, yytext);
				fprintf(yyout, "(%d,%d,\"%s\")\n", yylineno, token, yytext);
			    break;
			default:
				// printf("(%d,%d,\"%s\")\n", yylineno, yylval, yytext);
				fprintf(yyout, "(%d,%d,\"%s\")\n", yylineno, yylval, yytext);
        }
	}
	fclose(yyout);
}

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

