// LexC--.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "symbols.h" 
extern int yylex(void);
extern FILE* yyin;
const char* symbols[] = {
	"END",
	"INT",
	"BOOL",
	"VOID",
	"TRUE",
	"FALSE",
	"IF",
	"ELSE",
	"WHILE",
	"RETURN",
	"CIN",
	"COUT",
	"CONSTANT",
	"STRING_LITERAL",
	"LEFT_BRACE",
	"RIGHT_BRACE",
	"LEFT_PARANTHESIS",
	"RIGHT_PARANTHESIS",
	"LEFT_BRACKET",
	"RIGHT_BRACKET",
	"COMMA",
	"ASSIGN",
	"END_OF_INSTRUCTION",
	"ADD",
	"SUBSTRACT",
	"MULT",
	"DIV",
	"NOT",
	"AND",
	"OR",
	"EQ",
	"NOT_EQ",
	"LESS",
	"GREATER",
	"LESS_EQ",
	"GREATER_EQ",
	"LEFT_SHIFT",
	"RIGHT_SHIFT",
	"BAD_CHARACTER",
	"IDENTIFIER"
};
int main()
{
	int lexUnit = 0;
	yyin = fopen("input.csrc", "rt");
	if (yyin != NULL)
	{
		while ((lexUnit = yylex()) != END) {
			if (lexUnit == BAD_CHARACTER) {
				printf("-> WARNING! %s \n", symbols[lexUnit]);
			}
			else {
				printf("-> TOKEN: %s \n", symbols[lexUnit]);
			}
		}
		fclose(yyin);
	}
	else {
		printf("Fisier inexistent");
	}
}