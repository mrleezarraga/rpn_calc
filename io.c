#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "io.h"
// Prints first number of rows elements in the stack

int print_stack(node *st,int number_or_rows)
{
    node *ptr=st;
    char vars[number_or_rows][20];
   
    for (int i=0;i<number_or_rows;i++)strcpy(vars[i],"");
    

    for (int i=0;i<number_or_rows;i++)
    {
        if (ptr==NULL)
        {
            
            i=number_or_rows;
            
        }
        else if (ptr->next ==NULL)
        {
            sprintf(vars[i],"%f",ptr->val);
            
            i=number_or_rows;
        }
        else
        {   
    
            sprintf(vars[i],"%f",ptr->val);
        
            ptr=ptr->next;
        }

    }

    
    for (int i=number_or_rows-1;i>=0;i--)
    {
        printf("[%i]: %s\n",i,vars[i]);
    }
    printf(">?");
    return 0;
}