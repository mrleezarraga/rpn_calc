#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "stack.h"

// Function prototype
int push( node **n,float x)
{
    //printf("En push\n");
    node *ptr = malloc(sizeof(node));
    if (*n==NULL)
    {
        ptr->val=x;
        ptr->next=NULL;
        *n=ptr;
    }
    else
    {
        ptr->val=x;
        ptr->next=*n;
        *n=ptr;
    }
    
}
int read_full_stack(node *st)

{
    
    if (st==NULL)
    {
        return 0;
    } 
    
    if (st->next==NULL)
    {
        return 0;
    }
    else 
    {
         printf("valor: %f\n",st->val);

        read_full_stack(st->next);
    }
}
float pop(node **st)
{
    node *ptr;
    float output;
    
    ptr = *st;
    *st = ptr->next;
    output=ptr->val;
    free(ptr);
    return output; 
}

int check_depth(node *st, int depth)
/*
Checks whether the stack reaches a certain depth or not
return 0-> not deep enough
return 1 -> reaches depth
Depth=0 -> Empty stack
Depth=1 -> One element
Depth=2 -> Two elements 
... So on ...
*/
{
    int i=0;
    if ( st == NULL ) return 0;
    i=1;

    while (st->next !=NULL && i<depth)
    {
        i++;
        st=st->next;
    }
    if(i<depth) return 0;
    else return 1;
}