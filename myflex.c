/* The lexical analyzer returns a double floating point

number on the stack and the token NUM, or the numeric code

of the character read if not a number. It skips all blanks

and tabs, and returns 0 for end-of-input. */

#ifdef LEX_SELF

#include <stdio.h>
#include <ctype.h>

#include "calculator_yacc.h"

int line_no = 0;
char str1[20];
char str2[20];
char str0[20];
int fflag;
int NXQ=1;
int tempnum;
FILE * yyin;

int yylex (void)
{
    int c;

    /* Skip white space. */
    while ((c = fgetc(yyin)) == ' ' || c == '\t') {
        continue;
    }

    // file end
    if (c == EOF) {
        /* Return end-of-input. */
        return 0;
    }

    // ECHO
    if(c != '\n') {
        printf("%c", c);
    }
    
    /* Process numbers. */
    if (isdigit (c)) {
        yylval.number = c - '0';

        while (isdigit (c = fgetc(yyin))) {
            yylval.number = yylval.number * 10 + c - '0';
            printf("%c", c);
        }

        ungetc (c, yyin);

        c = NUM;
    } else if(c == '\n') {
        line_no ++;
    }

    /* Return a single char. */
    return c;
}

#endif
