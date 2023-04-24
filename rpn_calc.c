#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    float val;
    struct node *next;
}
node;

// Function prototype
int push(node **n,float x);
int print_stack(node *st,int number_of_rows);
int read_full_stack(node *st);
float pop(node **st);

//End function prototypes


int main (void)
{
    node *stack=NULL;
    
    char input[20];
    while (1)
    
    {
    
        print_stack(stack,4);
            
               
        scanf("%s",input);
        system("clear");
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
                    push(&stack,1.0/pop(&stack)/pop(&stack));
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