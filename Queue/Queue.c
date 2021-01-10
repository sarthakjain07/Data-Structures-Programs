#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *a;
};

int main()
{
    int choice,ele;
    struct queue *q=(struct queue *)malloc(sizeof(struct queue)); 
    q->size=5;
    q->front=-1;
    q->rear=-1;
    q->a=(int *)malloc(q->size*sizeof(int));
    do
    {
    printf("Welcome to the program of stack\nEnter your choice\n1. Traverse\n2. Enqueue\n3. Dequeue\n4. peek\n5. Exit\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1: traverse(q);
                break;
        case 2: printf("Enter the element to be enqueued\n");
                scanf("%d",&ele);
                enqueue(q,ele);
                break;
        // case 3: pop(q);
        //         break;
        // case 4: peek(q);
        //         break;
        case 5: printf("Successfully Exited\n");
                break;               
        default:printf("Enter a valid choice\n");
                break;
        }
    } while (choice!=5);
    return 0;
}

