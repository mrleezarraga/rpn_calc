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