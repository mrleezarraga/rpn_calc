#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "stack.h"

// Function prototype
int print_stack(node *st,int number_of_rows);

//End function prototypes


int main (void)
{
    node *stack=NULL;
    
    char input[20];
    while (1)
    
    {
    
        system("clear");
        print_stack(stack,4);
            
               
        scanf("%s",input);

        if (strcmp(input,"pop")==0)

        {
            if (stack!=NULL)
            //We don't pop an empty stack
            {
                pop(&stack);
            }
        }
        else if (strcmp(input,":q")==0)break;
        else if (strcmp(input,"+")==0)
        {
            if (stack!=NULL)
            {
                if (stack->next!=NULL)
                {
                    push(&stack,pop(&stack)+pop(&stack));
                }else printf("Popeas demasiado\n");

            }else printf("Popeas demasiado\n");
        }
        else if (strcmp(input,"-")==0)
        {
            if (stack!=NULL)
            {
                if (stack->next!=NULL)
                {
                    push(&stack,-(pop(&stack)-pop(&stack)));
                }else printf("Popeas demasiado\n");

            }else printf("Popeas demasiado\n");

        }
        else if (strcmp(input,"*")==0)
        {
            if (stack!=NULL)
            {
                if (stack->next!=NULL)
                {
                    push(&stack,pop(&stack)*pop(&stack));
                }else printf("Popeas demasiado\n");

            }else printf("Popeas demasiado\n");
        }
        else if (strcmp(input,"/")==0)
        {
            if (stack!=NULL)
            {
                if (stack->next!=NULL)
                {
                    push(&stack,1.0/(pop(&stack)/pop(&stack)));
                }else printf("Popeas demasiado\n");

            }else printf("Popeas demasiado\n");
        }
        else if (strcmp(input,"")==0)printf("kk\n");
        else push(&stack,atof(input));
       
    


    }
    return 1;

}

// Prints first elements in the stack

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
