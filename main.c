#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifdef LEX_SELF
#include "myflex.h"
#else
#include "calculator_lex.h"
#endif

#include "calculator_yacc.h"

#ifndef LEX_MAIN
extern struct node root;
extern int Varcount;
extern int init_node(struct node *nd);
extern int yyparse (void);
extern void PreOrder(struct node *root,int tab);
extern void Outputlist();
extern void OutputQ();
extern void UpdateQlist(char *Op,int index1,int index2,int result,int x);
extern int newtemp();
extern int insertNXQ(int no,char *Op,int index1,int index2,int result);
extern void conti_update_Quterlist(int start,int end);
extern void setcontinueflag(int line);

int main(int argc, char *argv[])
{
    yyin = stdin;
    init_node(&root);
    if(argc > 1)
    {
        if((yyin = fopen(argv[1],"r"))==NULL)
        {
            printf("Can't open file %s\n",argv[1]);
            return -1;
        }
    }

    yyparse();
    PreOrder(&root,0);
    Outputlist();
    OutputQ();
    return 0;
}

#else
int main(int argc, char** argv)
{
    int c;
    FILE *pout;

    yyin = stdin;

    if(argc>1) {
        if((yyin=fopen(argv[1],"r"))==NULL) {
            printf("Can't open file %s\n",argv[1]); 
            exit(0);
        }
    }

    pout=fopen("result.dat","w");
    while(c=yylex()) {
        static int i=0;
        fprintf(pout,"(%4d,  %s)\t", c, yytext); i++;
        if( i==i/4*4) fprintf(pout,"\n");
    }
    fprintf(pout,"\n");
    fclose(pout);

    return 0;
}
#endif
