D			[0-9]
L			[a-zA-Z_]
			
%{
#include <stdio.h>
#include "symbols.h"

void count();
%}

%%
"//"			{ comment(); }
"#"			    { comment(); }

"int"			{ count(); return(INT); }
"bool"			{ count(); return(BOOL); }
"void"			{ count(); return(VOID); }
"true"			{ count(); return(TRUE); }
"false"		    { count(); return(VOLATILE); }
"if"			{ count(); return(IF); }
"else"			{ count(); return(ELSE); }
"while"			{ count(); return(WHILE); }
"return"		{ count(); return(RETURN); }
"cin"		    { count(); return(CIN); }
"cout"		    { count(); return(COUT); }

{L}({L}|{D})*	{ count(); return(check_type()); }
0{D}+			{ count(); return(CONSTANT); }
{D}+			{ count(); return(CONSTANT); }

L?\"(\\\"|\\'|\\\\|\\t|\\n|[^"\\\n])*\" { count(); return(STRING_LITERAL); }

"{"         { count(); return(LEFT_BRACE); }
"}"         { count(); return(RIGHT_BRACE); }
"("         { count(); return(LEFT_PARANTHESIS); }
")"         { count(); return(RIGHT_PARANTHESIS); }
"["         { count(); return(LEFT_BRACKET); }
"]"         { count(); return(RIGHT_BRACKET); }
","         { count(); return(COMMA); }
"="			{ count(); return(ASSIGN); }
";"			{ count(); return (END_OF_INSTRUCTION); }
"+"			{ count(); return(ADD); }
"-"			{ count(); return(SUBSTRACT); }
"*"         { count(); return(MULT); }
"/"         { count(); return(DIV); }
"!"         { count(); return(NOT); }
"&&"        { count(); return(AND); }
"||"        { count(); return(OR); }
"=="        { count(); return(EQ); }
"!="        { count(); return(NOT_EQ); }
"<"         { count(); return(LESS); }
">"         { count(); return(GREATER); }
"<="        { count(); return(LESS_EQ); }
">="        { count(); return(GREATER_EQ); }
"<<"        { count(); return(LEFT_SHIFT); }
">>"        { count(); return(RIGHT_SHIFT); }

[ \t\n ]	{ count(); }
.			{ count(); return(BAD_CHARACTER); }

%%

yywrap()
{
	return(1);
}


comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}


int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type()
{
	return(IDENTIFIER);
}