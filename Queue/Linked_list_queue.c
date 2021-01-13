#include <stdio.h>
#include <stdlib.h>

typedef struct ll{
    int data;
    struct ll next;
}linkl;

//global variables
linkl * front = NULL;
linkl * rear = NULL;

void enqueue(ele)
{
    linkl *node=(linkl *)malloc(sizeof(linkl));
    if(node==NULL)//condition when memory goes out of space happens rarely
        printf("Queue Overflow");
    else 
    {
        node->data=ele;
        node->next=rear;
        if(front==NULL)
            front=rear=node;
        else
            rear=node;    
    }
        
}

int main()
{
    int choice,ele;
    do
    {
    printf("Welcome to the program of Queue\nEnter your choice\n1. Traverse\n2. Enqueue\n3. Dequeue\n4. peek\n5. Exit\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1: traverse();
                break;
        case 2: printf("Enter the element to be enqueued\n");
                scanf("%d",&ele);
                enqueue(ele);
                break;
        case 3: dequeue();
                break;
        case 4: peek();
                break;
        case 5: printf("Successfully Exited\n");
                break;               
        default:printf("Enter a valid choice\n");
                break;
        }
    } while (choice!=5);
    return 0;
    return 0;
}