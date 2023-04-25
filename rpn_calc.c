#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "stack.h"
#include "io.h"



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
            if (check_depth(stack,1))
            //We don't pop an empty stack
            {
                pop(&stack);
            }
        }
        else if (strcmp(input,":q")==0)break;
        else if (strcmp(input,"+")==0)
        {
            if (check_depth(stack,2)) push(&stack,pop(&stack)+pop(&stack));
            else printf("Popeas demasiado\n");
        }
        else if (strcmp(input,"-")==0)
        {
            if (check_depth(stack,2)) push(&stack,-(pop(&stack)-pop(&stack)));
            else printf("Popeas demasiado\n");

        }
        else if (strcmp(input,"*")==0)
        {
            if (check_depth(stack,2)) push(&stack,pop(&stack)*pop(&stack));
            else printf("Popeas demasiado\n");
        }
        else if (strcmp(input,"/")==0)
        {
            if (check_depth(stack,2)) push(&stack,1.0/(pop(&stack)/pop(&stack)));
            else printf("Popeas demasiado\n");
        }
        else push(&stack,atof(input));
       
    


    }
    return 1;

}
