
#ifndef __EXPR_H__
#define __EXPR_H__

#define INT_TYPE    0
#define REAL_TYPE   1
#define NULL_NODE_POINTER     500
#define INIT_NODE_SUCCESS     501
#define ADD_SON_NODE_SUCCESS  502
#define SET_NODE_VAL_STR_SUCCESS  503
#define GET_SON_NODE_SUCCESS  504
#define ADD_BROTHER_NODE_SUCCESS  505
#define ADD_BROTHER_TO_NODE_WITHOUT_PARENT  506
#define GET_NEXT_BROTHER_NODE_SUCCESS  507
#define NEW_NODE_SUCCESS  508
#define MEMORY_ALLOC_ERROR  509
#define Maxnumber 100

struct QUATERLIST {
    char op[6];
    char arg1[10];
    char arg2[10];
    char result[10];
    int line;
    int continueflag; /*1 is continue stat*/
    int breakflag;
}Quaterlist[Maxnumber];

struct arr_info 
{
    int Dim;
    int *vector;
};

struct CONTI
{
    int NXQ[Maxnumber];
    int length;
}Contilist[Maxnumber];

struct VALIST
{
    char name[20];
    int type;/*int = 0 void = 1*/
    int addr;
    int cat;/*Defdata=0 Literal number=1 Varrdef number=2*/
    int def;
    struct arr_info *ADDR;
}Valist[Maxnumber];

enum node_type
{
    e_null_node,
    e_program,
    e_type_int,e_type_void,
    e_def_deflist,e_def_idtail,
    e_deflist,
    e_idtail,
    e_para,
    e_functail,
    e_block,
    e_onepara,
    e_sononearg,
    e_paradata,
    e_paradatatail,
    e_son_paradatail,
    e_subprogram,
    e_onestatment_statement,e_onestatment_localdef,
    e_defdata_ident,
    e_localdef,
    e_varrdef_e,e_varrdef,
    e_statement_emptystat,e_statement_breakstat,e_statement_continuestat,e_statement_blockstat,e_statement_assignstat,e_statement_returnstat,e_statement_ifstat,e_statement_whilestat,
    e_emptystat,e_breakstat,e_continuestat,e_blockstat,e_assignstat,e_returnstat,e_ifstat,e_elsestat,e_whilestat,
    e_altexpr,e_expr,e_assexpr,e_asstail,e_orexpr,e_ortail,e_andexpr,e_andtail,e_cmpexpr,e_cmptail,e_cmps,e_aloexpr,e_alotail,e_addsub,e_item,e_itemtail,e_muldiv,e_factor,e_lop
    ,e_rop,e_incr,e_decr,e_elem,e_idexpr,e_literal,e_realarg,e_sonarg,e_arg,e_val,
    e_segment
};

struct node_val
{
    char *str;
};

struct node
{
    enum node_type type;
    struct node_val val;
    struct node *son;
    struct node *parent;
    struct node *next;
};

extern int init_node(struct node *nd);
extern int add_son_node(struct node *parent, struct node *son);
extern int add_brother_node(struct node *last, struct node *new_brother);
extern int set_node_val_str(struct node *nd, char *str);
extern int new_node(struct node **result);
extern struct node* get_last_node(struct node *N);
extern int lookup(char * Name);
extern int enter(char *Name);
extern int entry(char *Name);
extern int set_valist_type(int start,int end,int Iv);
extern int set_valist_cat(int start,int end,int cat);
#endif
