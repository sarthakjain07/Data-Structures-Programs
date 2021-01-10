#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *character_array;
};

int match(char a,char b)
{
    if(a=='(' && b==')')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='[' && b==']')
        return 1;
    return 0;            
}

int paranthesisChecker(char *e)
{
    struct stack *s; // stack of name s is created dynamically inside heap memory 
    s->size=20; // size of stack
    s->top=-1; // condition of empty styck
    s->character_array=(char *)malloc(s->size*sizeof(char));// allocating memory for character array in which expression will be stored and checked

    for (int i = 0; e[i]!='\0'; i++)
    {
        if(e[i]=='(' || e[i]=='[' || e[i]=='{') // condition for checking paranthesis
        {
            s->top++;
            s->character_array[s->top]='('; // pushed in to the stack
        }
        else if (e[i]==')' || e[i]==']' || e[i]=='}')
        {
            if(s->top==-1)
                return 0; // unbalnced condition if poping in empty stack
            else if(!match(s->character_array[s->top],e[i]))
            {
                printf("%c\n",s->character_array[s->top]);
                printf("%c\n",e[i]);
                return 0;
            }
                
            else
            {
                char *c;
                c=&(s->character_array[s->top]); // storing the address of poped element so that it's memory can be deleted
                free(c);
                s->top--;

            } 
        }
    }
    if(s->top==-1) // if stack is empty after all the operations than expression is balanced 
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