%{
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "expr.h"

#ifdef LEX_SELF
#include "myflex.h"
#else
#include "calculator_lex.h"
#endif
#include "calculator_yacc.h"


void yyerror(char * msg);
void PreOrder(struct node *root,int tab);
extern void Outputlist();
extern void OutputQ();
extern void UpdateQlist(char *Op,int index1,int index2,int result,int x);
extern int newtemp();
extern int insertNXQ(int no,char *Op,int index1,int index2,int result);
extern void conti_update_Quterlist(int start,int end);
extern void setcontinueflag(int line);
extern void setbreakflag(int line);

extern int line_no;
extern struct node root;
extern int Varcount;
extern char str1[20];
extern char str2[20];
extern char str0[20];
extern int NXQ;
extern int fflag;
extern int tempnum;
%}

%union
{
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
    
};

%start  Program
%left '+' '-'
%left '*' '/'

/*Define const: */
%token <str> IDENT 402
%token NUM 403 
/*Define keywords here:*/
%token <str> INT 404
%token <str> VOID 405
%token <str> BREAK 406
%token <str> CONTINUE 407
%token <str> RETURN 408
%token <str> WHILE 409
%token <str> IF 410
%token <str> ELSE 411
%token <str> OR 422
%token <str> AND 423
%token <str> DDU 424
%token <str> XDU 427
%token <str> DU 428
%token <str> BDU 429
%token <str> INC 436
%token <str> DEC 437

%type <number> NUM
%type <_Type> Program
%type <_Type> Type
%type <_Type_deflist> Def
%type <_Type_deflist> Deflist
%type <_Type> Segment
%type <_Type> Functail
%type <_Type_idtail> Idtail
%type <_Type> Para
%type <_Type_midexpr> Block
%type <_Type_midexpr> Subprogram
%type <_Type_midexpr> Onestatement
%type <_Type_midexpr> Statement
%type <_Type> Emptystat
%type <_Type_midexpr> Breakstat
%type <_Type_midexpr> Continuestat
%type <_Type_defdata> Defdata
%type <_Type_localdef> Localdef
%type <_Type_defdata> Varrdef
%type <_Type> Sononearg
%type <_Type> Onepara
%type <_Type_defdata> Paradata
%type <_Type_defdata> Paradatatail
%type <_Type_defdata> Sonparadatatail
%type <_Type_midexpr> Blockstat
%type <_Type_midexpr> Assignstat
%type <_Type_midexpr> Altexpr
%type <_Type_midexpr> Expr
%type <_Type_midexpr> Assexpr
%type <_Type_itemtail> Asstail
%type <_Type_midexpr> Orexpr
%type <_Type_itemtail> Ortail
%type <_Type_midexpr> Andexpr
%type <_Type_itemtail> Andtail
%type <_Type_midexpr> Cmpexpr
%type <_Type_itemtail> Cmptail
%type <_Type_rop> Cmps
%type <_Type_midexpr> Aloexpr
%type <_Type_itemtail> Alotail
%type <_Type_rop> Addsub
%type <_Type_midexpr> Item
%type <_Type_itemtail> Itemtail
%type <_Type_rop> Muldiv
%type <_Type_midexpr> Factor
%type <_Type_rop> Lop
%type <_Type_midexpr> Val
%type <_Type_rop> Rop
%type <_Type> Incr
%type <_Type> Decr
%type <_Type_defdata> Elem
%type <_Type> Idexpr
%type <_Type_defdata> Literal
%type <_Type> Realarg
%type <_Type> Sonarg
%type <_Type> Arg
%type <_Type> Returnstat
%type <_Type_midexpr> Ifstat
%type <_Type_midexpr> Elsestat
%type <_Type_midexpr> Whilestat
%%
Program :                           /*empty-Segment*/   
        |   Program Segment         /*mulitySegment*/                 
            {
                $$.ast_node=&root;
                $$.ast_node->type=e_program;
                add_son_node(&root,$2.ast_node);
                set_node_val_str(&root,"Program");
            }; 
Segment :   Type Def
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_segment;
                set_node_val_str($$.ast_node, "Segment");
                add_son_node($$.ast_node, $1.ast_node);
                add_son_node($$.ast_node, $2.ast_node);
                
                for (int i=1;i<=$2.length;i++)
                {
                    if ($2.isarray[i]==0) 
                        set_valist_type($2.place[i],$2.place[i],$1.Iv); 
                    else if ($2.isarray[i]==1) 
                            set_valist_type($2.place[i],$2.place[i],2);
                        else if ($2.isarray[i]==2) 
                                set_valist_type($2.place[i],$2.place[i],3);
                }
            };
Type    :   INT
            {
                $$.Iv = 0;
                new_node(&($$.ast_node));
                $$.ast_node->type = e_type_int;
                set_node_val_str($$.ast_node, "Type_INT");
            }
        |   VOID
            {
                $$.Iv = 1;
                new_node(&($$.ast_node));
                $$.ast_node->type = e_type_void;
                set_node_val_str($$.ast_node, "Type_VOID");
            };
Def     :   '*' IDENT Deflist
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_def_deflist;
                set_node_val_str($$.ast_node, "Def");
                add_son_node($$.ast_node,$3.ast_node);

                $$.length=$3.length+1;
                for (int i=1;i<=$3.length;i++)
                {
                    $$.place[i]=$3.place[i];
                    $$.isarray[i]=$3.isarray[i];
                }
                $$.place[$$.length]=entry(str0);
                $$.isarray[$$.length]=2;
                set_valist_cat($$.place[$$.length],$$.place[$$.length],6);
                fflag=0;
            }
        |    IDENT Idtail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_def_idtail;
                set_node_val_str($$.ast_node, "Def");
                add_son_node($$.ast_node,$2.ast_node);

                $$.length=$2.length+1;
                for (int i=1;i<=$2.length;i++)
                {
                    $$.place[i]=$2.place[i];
                    $$.isarray[i]=$2.isarray[i];
                }
                
                if (strlen(str0)==0) strcpy(str0,str1);
                $$.place[$$.length]=entry(str0);
                    if ($2.varplace==0) $$.isarray[$$.length]=0;
                    else            $$.isarray[$$.length]=1;
                set_valist_cat($$.place[$$.length],$$.place[$$.length],5);
                fflag=0;
            };
Deflist     :   ',' Defdata Deflist
                {
                    new_node(&($$.ast_node));
                    $$.ast_node->type = e_deflist;
                    set_node_val_str($$.ast_node, "Deflist");
                    add_son_node($$.ast_node,$2.ast_node);
                    add_son_node($$.ast_node,$3.ast_node);
                    
                    $$.length=$3.length+1;
                    for (int i=1;i<=$3.length;i++)
                    {
                        $$.place[i]=$3.place[i];
                        $$.isarray[i]=$3.isarray[i];
                    }
                    $$.place[$$.length]=$2.place;
                    $$.isarray[$$.length]=$2.isarray;
                    /*put element's place to an array*/
                    /*unfinished*/
                }
            |   ';'
                {
                    new_node(&($$.ast_node));
                    $$.ast_node->type = e_deflist;
                    set_node_val_str($$.ast_node, "Deflist");
                    $$.length=0;
                };
Varrdef     :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_varrdef_e;
                set_node_val_str($$.ast_node, "Varrdef");
                $$.place=0;
            }
            |   Varrdef '[' NUM ']'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_varrdef;
                set_node_val_str($$.ast_node, "Varrdef");
                add_son_node($$.ast_node,$1.ast_node);

                $$.place=entry(str2);
                /*printf("Vget %d %s\n",$$.place,str2);*/
                set_valist_type($$.place,$$.place,0);
                set_valist_cat($$.place,$$.place,2);
            };
Defdata     :   IDENT Varrdef
            {
                
                new_node(&($$.ast_node));
                $$.ast_node->type = e_defdata_ident;
                set_node_val_str($$.ast_node, "Defdata");
                add_son_node($$.ast_node,$2.ast_node);
                
                fflag=1;
                $$.place = entry(str1);
                if ($2.place!=0) $$.isarray=1; else $$.isarray=0;
                /*printf("Dget %d %s %d\n",$$.place,str1,$$.isarray);*/
                
                /*unfinished*/
            }
            |   '*' IDENT
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_defdata_ident;
                set_node_val_str($$.ast_node, "Defdata*");

                $$.place = entry(str1);
                $$.isarray=2;
                
            };
Idtail  :   Varrdef Deflist
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_idtail;
                set_node_val_str($$.ast_node, "Idtail");
                
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);
                
                $$.length=$2.length;
                for (int i=1;i<=$2.length;i++)
                {
                    $$.place[i]=$2.place[i];
                    $$.isarray[i]=$2.isarray[i];
                }

                $$.varplace=$1.place;/*0=null else num's place*/
                
            }
        |   '(' Para ')' Functail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_idtail;
                set_node_val_str($$.ast_node, "Idtail");
                
                add_son_node($$.ast_node,$2.ast_node);
                add_brother_node($2.ast_node,$4.ast_node);

                $$.length=0;
                $$.varplace=0;
            };
Para    :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_para;
                set_node_val_str($$.ast_node, "Para");   
            }
        |   Onepara Sononearg
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_para;
                set_node_val_str($$.ast_node, "Para");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);
            };
Sononearg   :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_sononearg;
                set_node_val_str($$.ast_node, "Sononearg");
            }
            |   ',' Onepara Sononearg
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_sononearg;
                set_node_val_str($$.ast_node, "Sononearg");
                add_son_node($$.ast_node,$2.ast_node);
                add_son_node($$.ast_node,$3.ast_node);
            };
Onepara :   Type Paradata
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_onepara;
                set_node_val_str($$.ast_node, "Onepara");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);
                
                if ($2.isarray==0)
                        set_valist_type($2.place,$2.place,$1.Iv);
                else if ($2.isarray==1) set_valist_type($2.place,$2.place,2);
                else if ($2.isarray==2) set_valist_type($2.place,$2.place,3);
                
            };
Paradata    :   '*' IDENT
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_paradata;
                set_node_val_str($$.ast_node, "paradata*");
                
                fflag=1;
                $$.place = entry(str1);
                $$.isarray = 2;
                set_valist_cat($$.place,$$.place,4);
            }
            | IDENT Paradatatail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_paradata;
                set_node_val_str($$.ast_node, "paradata");
                add_son_node($$.ast_node,$2.ast_node);

                fflag=1;
                $$.place = entry(str1);
                $$.isarray = $2.isarray;
                set_valist_cat($$.place,$$.place,4);    
                
            };
Paradatatail    :   '[' ']' Sonparadatatail
                {
                    new_node(&($$.ast_node));
                    $$.ast_node->type = e_paradatatail;
                    set_node_val_str($$.ast_node, "paradatatail");
                    add_son_node($$.ast_node,$3.ast_node);
                    $$.isarray=1;
                }
                |   Sonparadatatail
                {
                    new_node(&($$.ast_node));
                    $$.ast_node->type = e_paradatatail;
                    set_node_val_str($$.ast_node, "paradatatail");
                    add_son_node($$.ast_node,$1.ast_node);

                    $$.isarray=$1.isarray;
                };
Sonparadatatail : 
                {
                    new_node(&($$.ast_node));
                    $$.ast_node->type = e_son_paradatail;
                    set_node_val_str($$.ast_node, "Sonparadatatail");
                    
                }
                |   '[' NUM ']' Sonparadatatail
                {
                    new_node(&($$.ast_node));
                    $$.ast_node->type = e_son_paradatail;
                    set_node_val_str($$.ast_node, "Sonparadatatail");
                    add_son_node($$.ast_node,$4.ast_node);

                    $$.place=entry(str2);
                    set_valist_type($$.place,$$.place,0);
                    set_valist_cat($$.place,$$.place,3);

                    $$.isarray=1;
                };
Functail :  Block
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_functail;
                set_node_val_str($$.ast_node, "Functail");
                add_son_node($$.ast_node,$1.ast_node);
               
            }
        |   ';'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_functail;
                set_node_val_str($$.ast_node, "Functail");
            };
Block   :   '{' Subprogram '}' 
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_block;
                set_node_val_str($$.ast_node, "Block");
                add_son_node($$.ast_node,$2.ast_node);
                
                $$.place=$2.place;
                $$.startNXQ=$2.startNXQ;
                $$.endNXQ=$2.endNXQ;
                /*printf("Bloack : %d %d\n",$2.startNXQ,$2.endNXQ);*/
            };
Subprogram  :                                           /*empty-Subprogram*/
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_subprogram;
                set_node_val_str($$.ast_node, "Subprogram");
                
                $$.startNXQ=0;
                $$.endNXQ=0;
            }
            |   Subprogram Onestatement                 /*mulitySubprogram*/
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_subprogram;
                set_node_val_str($$.ast_node, "Subprogram");
                
                struct node *last=get_last_node($1.ast_node);
                add_brother_node(last,$2.ast_node);
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.place=$1.place;
                if ($$.startNXQ==0) 
                        $$.startNXQ=$2.startNXQ; 
                else    $$.startNXQ=$1.startNXQ;
                if ($2.endNXQ!=0) 
                        $$.endNXQ=$2.endNXQ;
                else    $$.endNXQ=$1.endNXQ;
            };
Onestatement :  Localdef 
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_onestatment_localdef;
                set_node_val_str($$.ast_node, "Onestatement");
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.startNXQ=0;
                $$.endNXQ=0;
            }
            |   Statement
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_onestatment_statement;
                set_node_val_str($$.ast_node, "Onestatement");
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            };
Localdef    :   Type Defdata Deflist
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_localdef;
                set_node_val_str($$.ast_node, "Localdef");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);
                add_son_node($$.ast_node,$3.ast_node);

                $$.startplace=$2.place;
                if ($2.isarray==0)
                        set_valist_type($2.place,$2.place,$1.Iv);
                else if ($2.isarray==1) set_valist_type($2.place,$2.place,2);
                else if ($2.isarray==2) set_valist_type($2.place,$2.place,3);
                for (int i=1;i<=$3.length;i++)
                {
                    if ($3.isarray[i]==0)
                        set_valist_type($3.place[i],$3.place[i],$1.Iv);
                    else if ($3.isarray[i]==1) set_valist_type($3.place[i],$3.place[i],2);
                    else if ($3.isarray[i]==2) set_valist_type($3.place[i],$3.place[i],3);
                    set_valist_cat($$.startplace,$$.endplace,0);
                }
            };
Statement   :   Whilestat
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_statement_whilestat;
                set_node_val_str($$.ast_node, "Statement");
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            }
            |   Breakstat
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_statement_breakstat;
                set_node_val_str($$.ast_node, "Statement");
                add_son_node($$.ast_node,$1.ast_node);

                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            }
            |   Continuestat
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_statement_continuestat;
                set_node_val_str($$.ast_node, "Statement");
                add_son_node($$.ast_node,$1.ast_node);

                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            }
            |   Blockstat
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_statement_blockstat;
                set_node_val_str($$.ast_node, "Statement");
                add_son_node($$.ast_node,$1.ast_node);

                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            }
            |   Emptystat
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_statement_emptystat;
                set_node_val_str($$.ast_node, "Statement");
                add_son_node($$.ast_node,$1.ast_node);
                
            }
            |   Assignstat
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_statement_assignstat;
                set_node_val_str($$.ast_node, "Statement");
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            }
            |   Returnstat
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_statement_returnstat;
                set_node_val_str($$.ast_node, "Statement");
                add_son_node($$.ast_node,$1.ast_node);
            }
            |   Ifstat
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_statement_ifstat;
                set_node_val_str($$.ast_node, "Statement");
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            };
Ifstat      :   IF '(' Expr ')' Block Elsestat
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_ifstat;
                set_node_val_str($$.ast_node, "Ifstat");
                add_son_node($$.ast_node,$3.ast_node);
                add_son_node($$.ast_node,$5.ast_node);
                add_son_node($$.ast_node,$6.ast_node);

                if ($6.startNXQ!=0)
                    {
                        insertNXQ($5.startNXQ,"j=",$3.place,'0',$6.startNXQ+2); 
                        insertNXQ($5.endNXQ+2,"j",0,0,NXQ+1);
                    }
                else 
                    {
                        insertNXQ($5.startNXQ,"j=",$3.place,'0',NXQ+1); 
                    }
                $$.startNXQ=$3.startNXQ;
                $$.endNXQ=NXQ-1;
                /*insert newqlist*/
            };  
Elsestat    :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_elsestat;
                set_node_val_str($$.ast_node, "Elsestat");
                
                $$.startNXQ=0;
                $$.endNXQ=0;
            }
            |   ELSE Block
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_elsestat;
                set_node_val_str($$.ast_node, "Elsestat");
                add_son_node($$.ast_node,$2.ast_node);
                
                $$.startNXQ=$2.startNXQ;
                $$.endNXQ=$2.endNXQ;
                
            };
Whilestat   :   WHILE '(' Altexpr ')' Statement
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_whilestat;
                set_node_val_str($$.ast_node, "Whilestat");
                add_son_node($$.ast_node,$3.ast_node);
                add_son_node($$.ast_node,$5.ast_node);

                insertNXQ($5.startNXQ,"j=",$3.place,'0',$5.endNXQ+3);
                insertNXQ($5.endNXQ+2,"j",0,0,$3.startNXQ);
                $$.startNXQ=$3.startNXQ;
                $$.endNXQ=NXQ-1;
                
                conti_update_Quterlist($$.startNXQ,$$.endNXQ);
               
            };
Returnstat  :   RETURN Altexpr ';'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_returnstat;
                set_node_val_str($$.ast_node, "Returnstat");
                add_son_node($$.ast_node,$2.ast_node);
            };
Breakstat   :   BREAK ';'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_breakstat;
                set_node_val_str($$.ast_node, "Breakstat");

                $$.startNXQ=NXQ;
                $$.endNXQ=NXQ;
                insertNXQ(NXQ,"j",0,0,NXQ);
                setbreakflag($$.startNXQ);
            };
Continuestat :  CONTINUE ';'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_continuestat;
                set_node_val_str($$.ast_node, "Continuestat");
                
                $$.startNXQ=NXQ;
                $$.endNXQ=NXQ;
                insertNXQ(NXQ,"j",0,0,NXQ);
                setcontinueflag($$.startNXQ);
            };
Blockstat   :   Block
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_blockstat;
                set_node_val_str($$.ast_node, "Blockstat");
                add_son_node($$.ast_node,$1.ast_node);

                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            };
Emptystat   :   ';'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_emptystat;
                set_node_val_str($$.ast_node, "Emptystat");
                

            };    
Assignstat  :   Altexpr ';'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_assignstat;
                set_node_val_str($$.ast_node, "Assignstat");
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
                /*printf("Assignstat :%d %d\n",$$.startNXQ,$$.endNXQ);*/
            };
Altexpr     :   Expr
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_altexpr;
                set_node_val_str($$.ast_node, "Altexpr");
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            };
Expr        :   Assexpr
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_expr;
                set_node_val_str($$.ast_node, "Expr");
                add_son_node($$.ast_node,$1.ast_node);

                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            };
Assexpr     :   Orexpr Asstail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_assexpr;
                set_node_val_str($$.ast_node, "Assexpr");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);

                $$.place=$1.place;    
                $$.startNXQ=$1.startNXQ;
                for (int i=$2.length;i>=1;i--)
                {
                    $$.endNXQ=NXQ;
                    UpdateQlist($2.op[i],$2.place[i],0,$$.place,2);
                }
            };
Asstail     :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_asstail;
                set_node_val_str($$.ast_node, "Asstail");

                $$.length=0;
            }
            |   '=' Assexpr Asstail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_asstail;
                set_node_val_str($$.ast_node, "Asstail");
                add_son_node($$.ast_node,$2.ast_node);
                add_son_node($$.ast_node,$3.ast_node);

                $$.length=$3.length+1;
                strcpy($$.op[$$.length],"=");
                $$.place[$$.length]=$2.place;

                for (int i=1;i<=$3.length;i++)
                {
                    strcpy($$.op[i],$3.op[i]);
                    $$.place[i]=$3.place[i];
                }
            };
Orexpr      :   Andexpr Ortail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_orexpr;
                set_node_val_str($$.ast_node, "Orexpr");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);

                $$.place=$1.place;    
                $$.startNXQ=$1.startNXQ; 
                for (int i=$2.length;i>=1;i--)
                {
                    int newplace=newtemp();
                    $$.endNXQ=NXQ;
                    UpdateQlist($2.op[i],$$.place,$2.place[i],newplace,2);
                    $$.place=newplace;
                }
            };
Ortail      :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_ortail;
                set_node_val_str($$.ast_node, "Ortail");

                $$.length=0;
            }
            |   OR Andexpr Ortail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_ortail;
                set_node_val_str($$.ast_node, "Ortail");
                add_son_node($$.ast_node,$2.ast_node);
                add_son_node($$.ast_node,$3.ast_node);

                $$.length=$3.length+1;
                strcpy($$.op[$$.length],"||");
                $$.place[$$.length]=$2.place;

                for (int i=1;i<=$3.length;i++)
                {
                    strcpy($$.op[i],$3.op[i]);
                    $$.place[i]=$3.place[i];
                }
            };
Andexpr     :   Cmpexpr Andtail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_andexpr;
                set_node_val_str($$.ast_node, "Andexpr");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);

                $$.place=$1.place;   
                $$.startNXQ=$1.startNXQ; 
                for (int i=$2.length;i>=1;i--)
                {
                    int newplace=newtemp();
                    $$.endNXQ=NXQ;
                    UpdateQlist($2.op[i],$$.place,$2.place[i],newplace,2);
                    $$.place=newplace;
                }
            };
Andtail     :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_andtail;
                set_node_val_str($$.ast_node, "Andtail");
                
                $$.length=0;
            }
            |   AND Cmpexpr Andtail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_andtail;
                set_node_val_str($$.ast_node, "Andtail");
                add_son_node($$.ast_node,$2.ast_node);
                add_son_node($$.ast_node,$3.ast_node);
                
                $$.length=$3.length+1;
                strcpy($$.op[$$.length],"&&");
                $$.place[$$.length]=$2.place;

                for (int i=1;i<=$3.length;i++)
                {
                    strcpy($$.op[i],$3.op[i]);
                    $$.place[i]=$3.place[i];
                }
            };
Cmpexpr     :   Aloexpr Cmptail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_cmpexpr;
                set_node_val_str($$.ast_node, "Cmpexpr");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);

                $$.place=$1.place;    
                $$.startNXQ=$1.startNXQ;
                for (int i=$2.length;i>=1;i--)
                {
                    int newplace=newtemp();
                    $$.endNXQ=NXQ;
                    UpdateQlist($2.op[i],$$.place,$2.place[i],newplace,2);
                    $$.place=newplace;
                }
            };
Cmptail     :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_cmptail;
                set_node_val_str($$.ast_node, "Cmptail");
                
                $$.length=0;
            }
            |   Cmps Aloexpr Cmptail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_cmptail;
                set_node_val_str($$.ast_node, "Cmptail");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);
                add_son_node($$.ast_node,$3.ast_node);

                $$.length=$3.length+1;
                strcpy($$.op[$$.length],$1.op);
                $$.place[$$.length]=$2.place;

                for (int i=1;i<=$3.length;i++)
                {
                    strcpy($$.op[i],$3.op[i]);
                    $$.place[i]=$3.place[i];
                }
            };
Cmps        :   DDU
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_cmps;
                set_node_val_str($$.ast_node, "Cmps");

                strcpy($$.op,">=");
            }
            |   '>'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_cmps;
                set_node_val_str($$.ast_node, "Cmps");

                strcpy($$.op,">");
            }
            |   '<'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_cmps;
                set_node_val_str($$.ast_node, "Cmps");

                strcpy($$.op,"<");
            }
            |   XDU
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_cmps;
                set_node_val_str($$.ast_node, "Cmps");

                strcpy($$.op,"<=");
            }
            |   DU
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_cmps;
                set_node_val_str($$.ast_node, "Cmps");

                strcpy($$.op,"==");
            }
            |   BDU
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_cmps;
                set_node_val_str($$.ast_node, "Cmps");

                strcpy($$.op,"!=");
            };
Aloexpr     :   Item Alotail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_aloexpr;
                set_node_val_str($$.ast_node, "Aloexpr");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);

                $$.place=$1.place;   
                $$.startNXQ=$1.startNXQ; 
                for (int i=$2.length;i>=1;i--)
                {
                    int newplace=newtemp();
                    $$.endNXQ=NXQ;
                    UpdateQlist($2.op[i],$$.place,$2.place[i],newplace,3);
                    $$.place=newplace;
                }
            };
Alotail     :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_alotail;
                set_node_val_str($$.ast_node, "Alotail");

                $$.length=0;
            }
            |   Addsub Item Alotail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_alotail;
                set_node_val_str($$.ast_node, "Alotail");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);
                add_son_node($$.ast_node,$3.ast_node);
                
                $$.length=$3.length+1;
                strcpy($$.op[$$.length],$1.op);
                $$.place[$$.length]=$2.place;

                for (int i=1;i<=$3.length;i++)
                {
                    strcpy($$.op[i],$3.op[i]);
                    $$.place[i]=$3.place[i];
                }
            };
Addsub      :   '+'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_addsub;
                set_node_val_str($$.ast_node, "Addsub");

                strcpy($$.op,"+");
            }
            |   '-'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_addsub;
                set_node_val_str($$.ast_node, "Addsub");
                
                strcpy($$.op,"-");
            };
Item        :   Factor Itemtail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_item;
                set_node_val_str($$.ast_node, "Item");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);

                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;    
                for (int i=$2.length;i>=1;i--)
                {
                    int newplace=newtemp();
                    //printf("Item : %d %s %d %d %d",i,$2.op[i],$$.place,$2.place[i],newplace);
                    $$.endNXQ=NXQ;
                    UpdateQlist($2.op[i],$$.place,$2.place[i],newplace,4);
                    $$.place=newplace;
                }
            };
Itemtail    :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_itemtail;
                set_node_val_str($$.ast_node, "Itemtail");
                
                $$.length=0;

            }
            |   Muldiv Factor Itemtail
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_itemtail;
                set_node_val_str($$.ast_node, "Itemtail");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);
                add_son_node($$.ast_node,$3.ast_node);
                
                $$.length=$3.length+1;
                strcpy($$.op[$$.length],$1.op);
                $$.place[$$.length]=$2.place;
                
                for (int i=1;i<=$3.length;i++)
                {
                    strcpy($$.op[i],$3.op[i]);
                    $$.place[i]=$3.place[i];
                }
                
            };
Muldiv      :   '*'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_muldiv;
                set_node_val_str($$.ast_node, "Muldiv");

                strcpy($$.op,"*");
            }
            |   '/'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_muldiv;
                set_node_val_str($$.ast_node, "Muldiv");

                strcpy($$.op,"/");
            };
Factor      :   Lop Factor 
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_factor;
                set_node_val_str($$.ast_node, "Factor");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);

                $$.place=newtemp();
                $$.startNXQ=$2.startNXQ;
                $$.endNXQ=NXQ;
                UpdateQlist($1.op,$2.place,0,$$.place,5);
                
            }
            |   Val
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_factor;
                set_node_val_str($$.ast_node, "Factor");
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.place=$1.place;
                $$.startNXQ=$1.startNXQ;
                $$.endNXQ=$1.endNXQ;
            };
Lop         :   '!' 
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_lop;
                set_node_val_str($$.ast_node, "Lop");
                
                strcpy($$.op,"!");
                
            }
            |   '-'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_lop;
                set_node_val_str($$.ast_node, "Lop");

                strcpy($$.op,"-");
            }
            |   '&'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_lop;
                set_node_val_str($$.ast_node, "Lop");

                strcpy($$.op,"&");
            }
            |   '*'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_lop;
                set_node_val_str($$.ast_node, "Lop");

                strcpy($$.op,"*");
            }
            |   Incr
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_lop;
                set_node_val_str($$.ast_node, "Lop");
                add_son_node($$.ast_node,$1.ast_node);

                strcpy($$.op,"++");
            }
            |   Decr
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_lop;
                set_node_val_str($$.ast_node, "Lop");
                add_son_node($$.ast_node,$1.ast_node);

                strcpy($$.op,"--");
            };
Val         :   Elem 
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_val;
                set_node_val_str($$.ast_node, "Val");
                add_son_node($$.ast_node,$1.ast_node);
                
                $$.place=$1.place;
                $$.startNXQ=NXQ;
                $$.endNXQ=0;
            }
            |   Elem Rop
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_val;
                set_node_val_str($$.ast_node, "Val");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);
                
                if (Valist[$1.place].cat==1) $$.place=newtemp();
                else $$.place=$1.place;
                $$.startNXQ=NXQ;
                $$.endNXQ=NXQ;
                UpdateQlist($2.op,$1.place,0,$$.place,6);
                
            };
Rop         :   Incr
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_rop;
                set_node_val_str($$.ast_node, "Rop");
                add_son_node($$.ast_node,$1.ast_node);
                strcpy($$.op,"++");
                /*printf("ROP2 : %s\n",$$.op);*/
            }
            |   Decr
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_rop;
                set_node_val_str($$.ast_node, "Rop");
                add_son_node($$.ast_node,$1.ast_node);
                strcpy($$.op,"--");
                /*printf("ROP3 : %s\n",$$.op);*/
            };
Incr        :   INC
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_incr;
                set_node_val_str($$.ast_node, "Incr");
            };
Decr        :   DEC
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_decr;
                set_node_val_str($$.ast_node, "Decr");
            };
Elem        :   IDENT Idexpr
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_elem;
                set_node_val_str($$.ast_node, "Elem");
                add_son_node($$.ast_node,$2.ast_node);

                $$.place=entry(str1);
            }
            |   '(' Expr ')'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_elem;
                set_node_val_str($$.ast_node, "Elem");
                add_son_node($$.ast_node,$2.ast_node);

               
            }
            |   Literal
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_elem;
                set_node_val_str($$.ast_node, "Elem");
                add_son_node($$.ast_node,$1.ast_node);

                $$.place=$1.place;

            };
Idexpr      :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_idexpr;
                set_node_val_str($$.ast_node, "Idexpr");
            }
            |   '[' Expr ']'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_idexpr;
                set_node_val_str($$.ast_node, "Idexpr");
                add_son_node($$.ast_node,$2.ast_node);
            }
            |   '(' Realarg ')'
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_idexpr;
                set_node_val_str($$.ast_node, "Idexpr");
                add_son_node($$.ast_node,$2.ast_node);
            };
Literal     :   NUM
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_literal;
                set_node_val_str($$.ast_node, "Literal");
                
                $$.place=entry(str2);
                set_valist_type($$.place,$$.place,0);
                set_valist_cat($$.place,$$.place,1);
            };
Realarg     :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_realarg;
                set_node_val_str($$.ast_node, "Realarg");
            }
            |   Arg Sonarg
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_realarg;
                set_node_val_str($$.ast_node, "Realarg");
                add_son_node($$.ast_node,$1.ast_node);
                add_son_node($$.ast_node,$2.ast_node);
            };
Sonarg      :   
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_sonarg;
                set_node_val_str($$.ast_node, "Sonarg");
            }
            |   ',' Arg Sonarg
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_sonarg;
                set_node_val_str($$.ast_node, "Sonarg");
                add_son_node($$.ast_node,$2.ast_node);
                add_son_node($$.ast_node,$3.ast_node);
            };
Arg         :   Expr
            {
                new_node(&($$.ast_node));
                $$.ast_node->type = e_arg;
                set_node_val_str($$.ast_node, "Arg");
            };
%%

void yyerror(char * msg)
{
    printf("Line(%d): %s\n", line_no, msg);
}

void PreOrder(struct node *root,int tab)
{
    int i = 0;
    struct node *son = root ->son;
    if (root != NULL)
    {
        for (i = 0; i < tab - 1; ++i) {
			printf("|\t");
		}
		if (i == tab - 1) {
			printf("|-----");
		}
		printf("<%s>\n", root->val.str);
		++tab;
		while (son != NULL) {
			PreOrder(son, tab);
			son = son->next;
		}
    }
}

void Outputlist()
{
    int i=1;
    printf(" No.\t name \t\t   type\t\t cat\t\n");
    if (i>=Varcount)
    {
        printf("Symbol Table is Null!\n");
    }
    for (i=1;i<Varcount;i++)
    {
        printf("%4d\t%6s\t\t",i,Valist[i].name);
		if(Valist[i].type==0)
        {
            printf(" INTEGER\t");
		}
		else if (Valist[i].type==1)
        {
            printf(" VOID\t");
		}
        else if (Valist[i].type==2) 
            printf("INTARRAY\t"); 
            else if (Valist[i].type==3)
                printf("POINTER\t\t"); 
        else
         printf("NULL\t");
		if(Valist[i].cat==0)
            printf(" Defdata \n");
        else if (Valist[i].cat==1)
            printf("Literal Number\n");
            else if (Valist[i].cat==2)
             printf("Varrdef Number\n");
             else if (Valist[i].cat==3)
              printf("Sonparadatail\n");
                else if (Valist[i].cat==4)
                 printf("Paradata\n");
                  else if (Valist[i].cat==5)
                   printf("Def Idtail\n");
                    else if (Valist[i].cat==6)
                     printf("Def Deflist\n");
        else printf(" UNKOWN \n");
    }
}

void OutputQ()
{
    int i=1;
    if (i>=NXQ) printf("no quater exists!\n");
    for (i=1;i<NXQ;i++)
    {
        printf("(%3d) ",i);
        if (strcmp(Quaterlist[i].result,"_")==0)
            printf("(%s,  %s,  %s,  %d)\n",Quaterlist[i].op, Quaterlist[i].arg1, Quaterlist[i].arg2,Quaterlist[i].line);
        else 
            printf("(%s,  %s,  %s,  %s)\n",Quaterlist[i].op, Quaterlist[i].arg1, Quaterlist[i].arg2,Quaterlist[i].result);
    }
    
}
void UpdateQlist(char *Op,int index1,int index2,int result,int x)
{
    /*printf("\n%s %d\n",Op,x);*/
    if(strcmp(Op,"++")==0)
    {
        strcpy(Quaterlist[NXQ].op, "+");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "1");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"--")==0)
    {
        strcpy(Quaterlist[NXQ].op, "-");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "1");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"!")==0)
    {
        strcpy(Quaterlist[NXQ].op, "!");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "_");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"-")==0)
    {
        strcpy(Quaterlist[NXQ].op, "-");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        if (index2==0) 
            strcpy(Quaterlist[NXQ].arg2, "_");/*for lop '-' */
        else
            strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);/*for muldiv '-' */
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"*")==0)
    {
        strcpy(Quaterlist[NXQ].op, "*");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        if (index2==0) 
            strcpy(Quaterlist[NXQ].arg2, "_"); /*for lop '*' */
        else 
            strcpy(Quaterlist[NXQ].arg2, Valist[index2].name); /*for muldiv '*' */
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"&")==0)
    {
        strcpy(Quaterlist[NXQ].op, "&");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "_");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"/")==0)
    {
        strcpy(Quaterlist[NXQ].op, "/");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"+")==0)
    {
        strcpy(Quaterlist[NXQ].op, "+");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,">=")==0)
    {
        strcpy(Quaterlist[NXQ].op, ">=");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,">")==0)
    {
        strcpy(Quaterlist[NXQ].op, ">");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"<=")==0)
    {
        strcpy(Quaterlist[NXQ].op, "<=");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"<")==0)
    {
        strcpy(Quaterlist[NXQ].op, "<");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"==")==0)
    {
        strcpy(Quaterlist[NXQ].op, "==");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"!=")==0)
    {
        strcpy(Quaterlist[NXQ].op, "!=");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"&&")==0)
    {
        strcpy(Quaterlist[NXQ].op, "&&");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"||")==0)
    {
        strcpy(Quaterlist[NXQ].op, "||");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, Valist[index2].name);
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
    if(strcmp(Op,"=")==0)
    {
        strcpy(Quaterlist[NXQ].op, "=");
        strcpy(Quaterlist[NXQ].arg1, Valist[index1].name);
        strcpy(Quaterlist[NXQ].arg2, "_");
        strcpy(Quaterlist[NXQ].result, Valist[result].name);
        NXQ++;
    }
}

int newtemp()/*create new temo*/
{
    tempnum++;
    char ss[5]="t";
    int t=tempnum,length=0;
    int a[4];
    while (t>0) 
    {
        a[length]=t%10;
        t=t/10;
        length++;
    }
    for (int i=length;i>0;i--)
    {
        ss[length-i+1]=(char)(48+a[i-1]);
    }
    return entry(ss);
}

int insertNXQ(int no,char *Op,int index1,int index2,int line)
{
    //insertNXQ($5.startNXQ,"j=",$3.place,'0',$6.startNXQ+1); 
    /*printf("%d %s %d %d %d\n",no,Op,index1,index2,line);*/
    OutputQ();
    /*test*/
    
    for (int i=NXQ;i>no;i--)
    {
        Quaterlist[i]=Quaterlist[i-1];
        if  (strcmp(Op,"j")==0 || strcmp(Op,"j=")==0) Quaterlist[i].line++;
    }
    if(strcmp(Op,"j=")==0)
    {
        strcpy(Quaterlist[no].op, "j=");
        strcpy(Quaterlist[no].arg1, Valist[index1].name);
        strcpy(Quaterlist[no].arg2, "0");
        strcpy(Quaterlist[no].result,"_");
        Quaterlist[no].line=line;
        Quaterlist[no].continueflag=0;
        Quaterlist[no].breakflag=0;
        NXQ++;
    }
    if(strcmp(Op,"j")==0)
    {
        strcpy(Quaterlist[no].op, "j");
        strcpy(Quaterlist[no].arg1, "_");
        strcpy(Quaterlist[no].arg2, "_");
        strcpy(Quaterlist[no].result,"_");
        Quaterlist[no].line=line;
        Quaterlist[no].continueflag=0;
        Quaterlist[no].breakflag=0;
        NXQ++;
    }
}
void setcontinueflag(int line)
{
    Quaterlist[line].continueflag=1;
}
void setbreakflag(int line)
{
    Quaterlist[line].breakflag=1;
}
void conti_update_Quterlist(int start,int end)
{
    for (int i=start;i<=end;i++)
    {
        if (Quaterlist[i].continueflag==1) Quaterlist[i].line=start;
        if (Quaterlist[i].breakflag==1) Quaterlist[i].line=end+1;
        Quaterlist[i].continueflag=0;
        Quaterlist[i].breakflag=0;
    }
}
