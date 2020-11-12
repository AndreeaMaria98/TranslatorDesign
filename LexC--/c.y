%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex(void);
int yyerror(char* s);
%}			    
%token INT
%token BOOL
%token VOID    
%token TRUE    
%token FALSE   
%token IF	    
%token ELSE    
%token WHILE			    
%token RETURN			    
%token CIN				    
%token COUT			    
%token CONSTANT		    
%token STRING_LITERAL	    
%token LEFT_BRACE		    
%token RIGHT_BRACE		    
%token LEFT_PARANTHESIS    
%token RIGHT_PARANTHESIS   
%token LEFT_BRACKET	    
%token RIGHT_BRACKET	    
%token COMMA			    
%token ASSIGN			    
%token END_OF_INSTRUCTION  
%token ADD				    
%token SUBSTRACT		    
%token MULT			    
%token DIV				    
%token NOT				    
%token AND				    
%token OR				    
%token EQ				    
%token NOT_EQ				
%token LESS				
%token GREATER				
%token LESS_EQ				
%token GREATER_EQ			
%token LEFT_SHIFT			
%token RIGHT_SHIFT			
%token BAD_CHARACTER		
%token IDENTIFIER			

%start program
%%
program
 : program varDecl
 | program fnDecl
 | /* empty */
 ;
varDecl
 : type id END_OF_INSTRUCTION
 | type id LEFT_BRACKET CONSTANT RIGHT_BRACKET END_OF_INSTRUCTION
 ;
type
 : INT
 | BOOL
 | VOID
 ;
fnDecl
 : type id parameters block
 ;
parameters
 : LEFT_PARANTHESIS RIGHT_PARANTHESIS
 | LEFT_PARANTHESIS formalsList RIGHT_PARANTHESIS
 ;
formalsList
 : formalDecl
 | formalsList COMMA formalDecl
 ;
formalDecl
 : type id
 ;
block
 : LEFT_BRACE declList stmtList RIGHT_BRACE
 ;
declList
 : declList varDecl
 | /* empty */
 ;
stmtList
 : stmtList stmt
 | /* empty */
 ;
stmt
 : CIN id END_OF_INSTRUCTION
 | CIN id LEFT_BRACKET exp RIGHT_BRACKET END_OF_INSTRUCTION
 | COUT exp END_OF_INSTRUCTION
 | subscriptExpr ASSIGN exp END_OF_INSTRUCTION
 | id ASSIGN exp END_OF_INSTRUCTION
 | IF LEFT_PARANTHESIS exp RIGHT_PARANTHESIS block
 | IF LEFT_PARANTHESIS exp RIGHT_PARANTHESIS block ELSE block
 | WHILE LEFT_PARANTHESIS exp RIGHT_PARANTHESIS  block
 | RETURN exp END_OF_INSTRUCTION
 | RETURN END_OF_INSTRUCTION
 | fnCallStmt END_OF_INSTRUCTION
 ;
exp
 : exp ADD exp
 | exp SUBSTRACT exp
 | exp MULT exp
 | exp DIV exp
 | NOT exp
 | exp AND exp
 | exp OR exp
 | exp EQ exp
 | exp NOT_EQ exp
 | exp LESS exp
 | exp GREATER exp
 | exp LESS_EQ exp
 | exp GREATER_EQ exp
 | SUBSTRACT atom
 | atom
 ;
atom
 : INT
 | STRING_LITERAL
 | TRUE
 | FALSE
 | LEFT_PARANTHESIS exp RIGHT_PARANTHESIS
 | fnCallExpr
 | subscriptExpr
 | id
 | CONSTANT
 ;
fnCallExpr
 : id LEFT_PARANTHESIS RIGHT_PARANTHESIS
 | id LEFT_PARANTHESIS actualList RIGHT_PARANTHESIS
 ;
fnCallStmt
 : id LEFT_PARANTHESIS RIGHT_PARANTHESIS
 | id LEFT_PARANTHESIS actualList RIGHT_PARANTHESIS
 ;
actualList
 : exp
 | actualList COMMA exp
 ;
subscriptExpr
 : id LEFT_BRACKET exp RIGHT_BRACKET
 ;
id
 : IDENTIFIER
 ;
%%
int yyerror(char* s) 
{ 
	printf("%s\n", s);
	return 0;
}