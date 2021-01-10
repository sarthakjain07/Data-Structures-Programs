#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *character_array;
};

int precedence(char a)
{
    if(a=='*' || a=='/')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return 0;        
}

int isOperator(char a)
{
    if(a=='+' || a=='-' || a=='*' || a=='/')
        return 1;
    else
        return 0;    
}

char * postfixConversion(char *e)
{
    int j=0,i=0;
    struct stack *s=(struct stack *) malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->character_array=(char *)malloc(s->size*sizeof(char));
    char *post_expression=(char *)malloc((strlen(e)+1)*sizeof(char));
    while (e[i]!='\0')
    {
        if(!isOperator(e[i]))
        {
            post_expression[j]=e[i];
            i++;
            j++;
        }
        else
        {
            if(s->top==-1)
            {
                s->top++;
                s->character_array[s->top]=e[i];
                i++;
            }
            else if(precedence(e[i])>precedence(s->character_array[s->top]))
            {
                s->top++;
                s->character_array[s->top]=e[i];
                i++;
            }
            else
            {
                while (s->top!=-1)
                {
                    post_expression[j]=s->character_array[s->top];// how to free its memory
                    free(s->character_array[s->top]);
                    s->top--;
                    j++;

                }
                
            }
        
        }

    }
    while (s->top!=-1)
    {
        post_expression[j]=s->character_array[s->top];// how to free its memory
        // free(s->character_array[s->top]);
        s->top--;
        j++;
    }
    post_expression[j]='\0';
    return post_expression;
}

int main()
{
    char *expression="x-y/z-k+d";
    printf("%s",postfixConversion(expression));
    
    return 0;
}