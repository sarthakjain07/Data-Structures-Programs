#include <stdio.h>
#include <stdlib.h>

// Structure of the stack
struct stack{
    int size;
    int top;
    int *a;
};

int isEmpty(struct stack *s) 
{
    if(s->top==-1)
        return 1;
    return 0;    
}

int isFull(struct stack *s)
{
    if(s->top==(s->size-1))
        return 1;
    return 0;    
}

void traverse(struct stack *s)
{
    if(isEmpty)
        printf("Stack is empty\n");
    else
    {
        for(int i=0;i<s->size;i++)
            printf("%d\n",s->a[i]);
    }
        
}

void push(struct stack *s,int ele)
{
    if(isFull)
        printf("Stack is full\n");
    else
    {
        s->top++;
        scanf("%d",&s->a[s->top]);
        printf("%dsuccessfully added at position %d of stack\n",ele,s->top);
    }
        
}

int main()
{
    int choice,ele;
    struct stack *s; //allocating memory for stack dynamically in heap using pointer
    s->size=5;
    s->top=-1;
    s->a=(int *)malloc(s->size*sizeof(int));
    printf("Welcome to the program of stack\nEnter your choice\n1. Traverse\n2. Push\n3. Pop\n4. peek\n5. Exit\n");
    scanf("%d",&choice);
    do
    {
        switch (choice)
        {
        case 1:traverse(s);
            break;
        case 2:printf("Enter the number you want to push\n");
            scanf("%d",&ele);
            push(s,ele);
            break;
        // case 3:pop(s);
        //     break;
        // case 4:peek(s);
        //     break;
        case 5:printf("Successfully Exited\n");
            break;               
        default: printf("Enter a valid choice\n");
            break;
        }
    } while (choice!=5);
    
   


    return 0;
}





