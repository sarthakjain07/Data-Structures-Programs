#include<stdio.h>
#include<stdlib.h>

int a=0,b=0,c=0;
struct stack{
    int top;
    int size;
    char *arr;
};

void checkParanthesis(char e[])
{
    struct stack *s;
    s->top=-1;
    s->size=20;
    s->arr=(char *)malloc(s->size*sizeof(char));
    for (int i = 0; e[i] != '\0'; i++)
    {
        if(e[i]=='(')
        {
            a++;
            s->top++;
            s->arr[s->top]==1;
        }
        else if(e[i]==')')
        {
            if(s->top==-1)
                c++;
            b++;  
            free(s->arr[s->top]);
            s->top--;
        }
            
    }
    if(s->top==-1)
        printf("Balanced in %d push and %d pops\n",a,b);
    else if(c)
        printf("Unbalanced in %d push and %d pop\n",a,b);
    else
        printf("Unbalanced in %d push and %d pop\n",a,b);
}

int main()
{
    char expression[50];
    printf("Enter the expression\n");
    gets(expression);
    // printf("tom\n");
    printf("Condition of paranthesis is : ");
    checkParanthesis(expression);

    return 0;
}