#include <stdio.h>
#include <stdlib.h>

// structure of a linked list
typedef struct ll{
    int data;
    struct ll * next;
}linkl;

//global variables
linkl * front = NULL;
linkl * rear = NULL;


// This function is used to enter the element in our queue
void enqueue(int ele)
{
    linkl *node=(linkl *)malloc(sizeof(linkl));
    if(node==NULL)//condition when memory goes out of space happens rarely
        printf("Queue Overflow\n");
    else 
    {
        node->data=ele;
        if(front==NULL)
        {
            printf("First node\n");
            front=rear=node;
            node->next=NULL;
        }        
        else
        {
            printf("Not First node\n");
            node->next=rear->next;
            rear->next=node;
            rear=node;
        }
                
    }
        
}

//  This function displays all the elements of queue if present
void display()
{
    if(front==NULL)
        printf("Queue underflow\n");
    else
    {
        linkl *ptr=front;
        printf("The elements are:\n");
        // printf("%d\n",ptr->data);
        while (ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
        
    }
        
}

// This function is used to delete the element from our queue
void dequeue()
{
    if(front==NULL)
        printf("Queue underflow or empty\n");
    else
    {
        linkl * ptr=front;
        if(front->next==NULL)
        {
            free(ptr);
            front=NULL;
        }
        else
        {
            front=front->next;
            free(ptr);
        }
        
    }
        
}

// This function tells the position of the element you are searching
void peek()
{
    if(front==NULL)
        printf("Queue Empty\n");
    else
    {
        int position,i=1;
        linkl * ptr=front;
        printf("Enter the position where number to be searched\n");
        scanf("%d",&position);
        if(position==1)
            printf("The element is %d\n",ptr->data);
        else
        {
            while (i<position)
            {
                ptr=ptr->next;
                i++;    
            }
            if(ptr==NULL)
                printf("NO such element at the required position\n");
            else
                printf("The element is %d\n",ptr->data);
        }
    }
        
}

// This function controls all the other functions
int main()
{
    int choice,ele;
    do
    {
    printf("Welcome to the program of Queue\nEnter your choice\n1. Traverse\n2. Enqueue\n3. Dequeue\n4. peek\n5. Exit\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1: display();
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