/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_CALCULATOR_YACC_H_INCLUDED
# define YY_YY_CALCULATOR_YACC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 402,
    NUM = 403,
    INT = 404,
    VOID = 405,
    BREAK = 406,
    CONTINUE = 407,
    RETURN = 408,
    WHILE = 409,
    IF = 410,
    ELSE = 411,
    OR = 422,
    AND = 423,
    DDU = 424,
    XDU = 427,
    DU = 428,
    BDU = 429,
    INC = 436,
    DEC = 437
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "calculator.y"

    struct node *ast_node; 
    int number;
    char str[20];
    struct { int Iv; struct node *ast_node;} _Type; /*int 0 void 1*/
    struct { int place; int isarray; struct node *ast_node;} _Type_defdata;
     /* place means ident's no. in varlist 
        isarray means is array 1 or not 0    2 means '*' ident */
    struct { int startplace; int endplace; struct node *ast_node;} _Type_localdef;
    struct { int place[20];int isarray[20]; int length; struct node *ast_node;} _Type_deflist;
    struct { int place[20]; int varplace; int isarray[20]; int length; struct node *ast_node;} _Type_idtail;
    /**/
    struct { int Iv; char op[5]; struct node *ast_node;} _Type_rop;
    struct { int length; int place[20]; char op[20][5]; struct node *ast_node;} _Type_itemtail;
    struct { int place; int startNXQ; int endNXQ; struct node *ast_node;} _Type_midexpr;
    /* */
    

#line 97 "calculator_yacc.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALCULATOR_YACC_H_INCLUDED  */
