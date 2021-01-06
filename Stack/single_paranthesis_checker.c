#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *character_array;
};

int paranthesisChecker(char *e)
{
    struct stack *s;
    s->size=20;
    s->top=-1;
    s->character_array=(char *)malloc(s->size*sizeof(char));

    for (int i = 0; e[i]!='\0'; i++)
    {
        if(e[i]=='(')
        {
            s->top++;
            s->character_array[s->top]='(';
        }
        else if (e[i]==')')
        {
            if(s->top==-1)
                return 0;
            else
            {
                char *c;
                c=&(s->character_array[s->top]);
                free(c);
                s->top--;
            } 
        }
    }
    if(s->top==-1)
        return 1;
    else
        return 0;
        
}

int main()
{
    char *expression="3*2-(8+1)";
    if(paranthesisChecker(expression))
        printf("Expression is balanced\n");
    else
        printf("Expression is unbalanced\n");
    return 0;
}

