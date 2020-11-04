/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_C_TAB_H_INCLUDED
# define YY_YY_C_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    BOOL = 259,                    /* BOOL  */
    VOID = 260,                    /* VOID  */
    TRUE = 261,                    /* TRUE  */
    FALSE = 262,                   /* FALSE  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    WHILE = 265,                   /* WHILE  */
    RETURN = 266,                  /* RETURN  */
    CIN = 267,                     /* CIN  */
    COUT = 268,                    /* COUT  */
    CONSTANT = 269,                /* CONSTANT  */
    STRING_LITERAL = 270,          /* STRING_LITERAL  */
    LEFT_BRACE = 271,              /* LEFT_BRACE  */
    RIGHT_BRACE = 272,             /* RIGHT_BRACE  */
    LEFT_PARANTHESIS = 273,        /* LEFT_PARANTHESIS  */
    RIGHT_PARANTHESIS = 274,       /* RIGHT_PARANTHESIS  */
    LEFT_BRACKET = 275,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 276,           /* RIGHT_BRACKET  */
    COMMA = 277,                   /* COMMA  */
    ASSIGN = 278,                  /* ASSIGN  */
    END_OF_INSTRUCTION = 279,      /* END_OF_INSTRUCTION  */
    ADD = 280,                     /* ADD  */
    SUBSTRACT = 281,               /* SUBSTRACT  */
    MULT = 282,                    /* MULT  */
    DIV = 283,                     /* DIV  */
    NOT = 284,                     /* NOT  */
    AND = 285,                     /* AND  */
    OR = 286,                      /* OR  */
    EQ = 287,                      /* EQ  */
    NOT_EQ = 288,                  /* NOT_EQ  */
    LESS = 289,                    /* LESS  */
    GREATER = 290,                 /* GREATER  */
    LESS_EQ = 291,                 /* LESS_EQ  */
    GREATER_EQ = 292,              /* GREATER_EQ  */
    LEFT_SHIFT = 293,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 294,             /* RIGHT_SHIFT  */
    BAD_CHARACTER = 295,           /* BAD_CHARACTER  */
    IDENTIFIER = 296               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_H_INCLUDED  */
