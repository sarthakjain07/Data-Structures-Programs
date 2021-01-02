#include<stdio.h>
#include<stdlib.h>

int size,element_added=0;
struct LL
{
    int data;
    struct LL *next;
};
struct LL * top=NULL;

int isEmpty()
{
    if(top==NULL)
        return 1;
    return 0;    
}

int isFull()
{
    if(element_added==size)
        return 1;
    return 0;    
}





int main()
{
    printf("Enter the size of stack\n");
    scanf("%d",&size);
    int choice,ele;
     do
    {
    printf("Welcome to the program of stack\nEnter your choice\n1. Traverse\n2. Push\n3. Pop\n4. peek\n5. Exit\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1: traverse();
                break;
        case 2: push(ele);
                break;
        case 3:pop();
            break;
         case 4:peek();
             break;
        case 5: printf("Successfully Exited\n");
            break;               
        default: printf("Enter a valid choice\n");
            break;
        }
    } while (choice!=5);
    return 0;
}