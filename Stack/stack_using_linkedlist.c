#include<stdio.h>
#include<stdlib.h>

struct LL
{
    int data;
    int size;
    struct LL *next;
};
struct LL *top=NULL;



int main()
{
     do
    {
    printf("Welcome to the program of stack\nEnter your choice\n1. Traverse\n2. Push\n3. Pop\n4. peek\n5. Exit\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1: traverse(s);
                break;
        case 2: push(s,ele);
                break;
        case 3:pop(s);
            break;
         case 4:peek(s);
             break;
        case 5: printf("Successfully Exited\n");
            break;               
        default: printf("Enter a valid choice\n");
            break;
        }
    } while (choice!=5);
    return 0;
}