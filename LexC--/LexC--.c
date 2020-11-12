// LexC--.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
extern int yylex(void);
extern int yyparse(void);
extern FILE* yyin;
extern int yydebug;
//const char* symbols[] = {
//	"END",
//	"INT",
//	"BOOL",
//	"VOID",
//	"TRUE",
//	"FALSE",
//	"IF",
//	"ELSE",
//	"WHILE",
//	"RETURN",
//	"CIN",
//	"COUT",
//	"CONSTANT",
//	"STRING_LITERAL",
//	"LEFT_BRACE",
//	"RIGHT_BRACE",
//	"LEFT_PARANTHESIS",
//	"RIGHT_PARANTHESIS",
//	"LEFT_BRACKET",
//	"RIGHT_BRACKET",
//	"COMMA",
//	"ASSIGN",
//	"END_OF_INSTRUCTION",
//	"ADD",
//	"SUBSTRACT",
//	"MULT",
//	"DIV",
//	"NOT",
//	"AND",
//	"OR",
//	"EQ",
//	"NOT_EQ",
//	"LESS",
//	"GREATER",
//	"LESS_EQ",
//	"GREATER_EQ",
//	"LEFT_SHIFT",
//	"RIGHT_SHIFT",
//	"BAD_CHARACTER",
//	"IDENTIFIER"
//};
int main()
{
	//int lexUnit = 0;
	yydebug = 1;
	yyin = fopen("input.csrc", "rt");
	if (yyin != NULL)
	{
		int result = yyparse();
		switch (result)
		{
		case 0:
			printf("Parse successfull.\n");
			break;

		case 1:
			printf("Invalid input encountered\n");
			break;

		case 2:
			printf("Out of memory\n");
			break;

		default:
			break;
		}
		/*while ((lexUnit = yylex()) != END)
		{
			printf(" -> TOKEN: %s\n", symbols[lexUnit]);
		}*/
		fclose(yyin);
	}
	else
	{
		printf("Fisier inexistent");
	}
}