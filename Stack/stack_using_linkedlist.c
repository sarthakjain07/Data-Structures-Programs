#include<stdio.h>
#include<stdlib.h>

int size,element_added=0;
struct ll
{
    int data;
    struct ll *next;
};
struct ll * top=NULL;

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

void traverse()
{
    if(isEmpty())
        printf("Stack is Empty\n");
    else
    {
        struct ll *ptr=top;
        while (ptr->next!=NULL)
        {
            printf("d\n",ptr->data);
            ptr=ptr->next;
        }    
    }  
}

void push(int ele)
{

    if(isFull())
        printf("Stack is Full\n");
    else
    {
        struct ll *node=(struct ll *)malloc(sizeof(struct ll));
        printf("Enter the no. to be pushed\n");
        scanf("%d",&ele);
        node->data=ele;
        node->next=top;
        top=node;
        element_added++;
    }
        
}

void pop()
{
    if(isEmpty())
}

int main()
{
    int choice,ele;
    printf("Enter the size of stack\n");
    scanf("%d",&size);
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