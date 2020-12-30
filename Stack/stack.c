#include <stdio.h>
#include <stdlib.h>

// Structure of the stack
struct stack{
    int size;
    int top;
    int *a;
};

int main()
{
    int choice;
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
        case 2:push(s);
            break;
        case 3:pop(s);
            break;
        case 4:peek(s);
            break;
        case 5:printf("Successfully Exited\n");
            break;               
        default: printf("Enter a valid choice\n");
            break;
        }
    } while (choice!=5);
    
   


    return 0;
}





