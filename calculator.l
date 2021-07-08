%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "calculator_yacc.h"

#define		ERRORCHAR	600
#define     MAXSTR 20
char str1[MAXSTR];/*for ident*/
char str2[MAXSTR];/*for num*/
char str0[MAXSTR];/*for def save first str*/
int line_no=1;
int fflag=0;
int NXQ=1;
int tempnum=0;
%}
/************************************
*	MACRO DEFINITION	*
*************************************/
letter		[A-Za-z]
alnum		[A-Za-z0-9]
d			[0-9]
white		[\t\040]
white_line  [\n]

/*****************************************
*	RECOGNIION RULES	         *
*****************************************/
%%
[Ii][Nn][Tt]                        {ECHO;return INT;}
[Vv][Oo][Ii][Dd]                    {ECHO;return VOID;}
[Bb][Rr][Ee][Aa][Kk]                {ECHO;return BREAK;}
[Cc][Oo][Nn][Tt][Ii][Nn][Uu][Ee]    {ECHO;return CONTINUE;}
[Rr][Ee][Tt][Uu][Rr][Nn]            {ECHO;return RETURN;}
[Ww][Hh][Ii][Ll][Ee]                {ECHO;return WHILE;}
[Ii][Ff]                            {ECHO;return IF;}
[Ee][Ll][Ss][Ee]                    {ECHO;return ELSE;}
{d}+		{
                ECHO;
                strcpy(str2,yytext);
                yylval.number = (int)strtol(yytext, (char **)NULL, 10);
                return NUM;
            }
"++"        {ECHO;return INC;}
"--"        {ECHO;return DEC;}
">="        {ECHO;return DDU;}
">"         {ECHO;return '>';}
"<="        {ECHO;return XDU;}
"<"         {ECHO;return '<';}
"=="        {ECHO;return DU ;}
"!="        {ECHO;return BDU;}
"("			{ECHO;return '(';}
")"			{ECHO;return ')';}
";"         {ECHO;return ';';}
"\."        {ECHO;return '.';}
"*"			{ECHO;return '*';}
"+"			{ECHO;return '+';}
"-"			{ECHO;return '-';}
"/"			{ECHO;return '/';}
"%"			{ECHO;return '%';}
","         {ECHO;return ',';}
"["			{ECHO;return '[';}
"]"			{ECHO;return ']';} 
"{"         {ECHO;return '{';}
"}"         {ECHO;return '}';}
"="         {ECHO;return '=';}
"||"        {ECHO;return OR;}
"&&"        {ECHO;return AND;}
"!"         {ECHO;return '!';}
"&"         {ECHO;return '&';}
{letter}{alnum}*    {
                    ECHO;
                    if (fflag==0) strcpy(str0,str1); /*Def use to save first str*/
                    strcpy(str1,yytext); 
                    return IDENT;
                    }
{white}+		{/* ECHO; */}
{white_line}    {
                    ECHO;
                    line_no++;
                }

.			{
                printf("Invalid char %s\n",yytext);
                return ERRORCHAR;
            }

%%

#ifndef yywrap
int yywrap()
{
    /*
     * 1) returns 1 to quit parsing
     * 2) set yyin to another file and returns 0 to continues parsing the newly added file.
     */
    return 1;
}
#endif
