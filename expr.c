#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "expr.h"

struct node root;
int Varcount = 1;

int init_node(struct node *nd)
{
    if (NULL==nd)
        return NULL_NODE_POINTER;
    else 
    {
        nd->type=e_null_node;
        nd->val.str=NULL;
        nd->son=NULL;
        nd->parent=NULL;
        nd->next=NULL;
    }
    return INIT_NODE_SUCCESS;
}

int add_son_node(struct node *parent,struct node *son)
{
    if (NULL!=parent && NULL!=son)
    {
        if (parent->son==NULL)
        {
            parent->son=son;
            son->parent=parent;
        }
        else /*parent has son already*/
        {
            struct node *tmp_node=parent->son;
            while (NULL!=tmp_node->next)
            {
                tmp_node=tmp_node->next;
            }
            tmp_node->next=son;
            son->parent=parent;
        }
        return ADD_SON_NODE_SUCCESS;
    }
    else 
    {
        return NULL_NODE_POINTER;
    }
}

int add_brother_node(struct node *last,struct node *new_brother)
{
    if (NULL!=last && NULL!=new_brother)
    {
        last->next=new_brother;
        new_brother->parent=last->parent;
        return ADD_BROTHER_NODE_SUCCESS;
    }
    else
    {
        return NULL_NODE_POINTER;
    }
}
int set_node_val_str(struct node *nd, char *str)
{
    if (NULL==nd || NULL==str) return NULL_NODE_POINTER;
    else
    {
        if(NULL!=nd->val.str)
            free(nd->val.str);
        nd->val.str=(char *)malloc(strlen(str)+1);
        strcpy(nd->val.str,str);
        return SET_NODE_VAL_STR_SUCCESS;
    }
}
int new_node(struct node **result)
{
    if(NULL!=result)
    {
        *result=(struct node *)malloc(sizeof(struct node));
        if(init_node(*result)==INIT_NODE_SUCCESS)
            return NEW_NODE_SUCCESS;
        else
            return MEMORY_ALLOC_ERROR;
    }
    else
    {
        return NULL_NODE_POINTER;
    }
    return NEW_NODE_SUCCESS;
}
struct node* get_last_node(struct node *N)
{
	struct node *tmp = N;
	if (N == NULL) {
		return NULL;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	return tmp;
}

/*valist reference*/
int lookup(char * Name)
{
    int index = -1;
    int i;
    for (i=0;i<Varcount;i++)
    {
        if (strcmp(Valist[i].name,Name)==0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int enter(char *Name)
{
    strcpy(Valist[Varcount].name,Name);
    Varcount++;
    return Varcount-1;/*return element's no.*/
}

int entry(char *Name)/*put one element into list*/
{
    int i=-1;
    i = lookup(Name);
    if (i!=-1) return i;
    else return enter(Name);
}
int set_valist_type(int start,int end,int Iv)
{
    for (int i=start;i<=end;i++)
    {
        Valist[i].type=Iv;
    }
}
int set_valist_cat(int start,int end,int cat)
{
    for (int i=start;i<=end;i++)
    {
        Valist[i].cat=cat;
    }
}