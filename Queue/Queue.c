#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *a;
};

int isFull(struct queue *q)
{
    if(q->rear==(q->size)-1)
        return 1;
    return 0;    
}

int isEmpty(struct queue *q)
{
    if(q->front==q->rear)
        return 1;
    return 0;    
}

void enqueue(struct queue *q,int ele)
{
    if(isFull(q))
        printf("Queue overflow\n");
    else
    {
        q->rear++;
        q->a[q->rear]=ele;
    }
}

void traverse(struct queue *q)
{
    if(isEmpty(q))
        printf("Queue underflow\n");
    else
    {
        printf("Elements of queue are:\n");
        for(int i=(q->front)+1; i<=q->rear;i++)
            printf("%d\n",q->a[i]);
    }
}

void dequeue(struct queue *q)
{
    if(isEmpty(q))
        printf("Queue underflow\n");
    else
    {
        q->front++;
        int *ptr=&(q->front);
        free(ptr);
    }
}

void peek(struct queue *q)
{
    printf("Enter the element to be searched\n");
    int searchEle;
    scanf("%d",&searchEle);
    while (q->a[q->front]!=searchEle)
    {
        q->front++;
    }
    printf("The position of your element in queue is %d\n",q->front);
    
}

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
    printf("Welcome to the program of Queue\nEnter your choice\n1. Traverse\n2. Enqueue\n3. Dequeue\n4. peek\n5. Exit\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1: traverse(q);
                break;
        case 2: printf("Enter the element to be enqueued\n");
                scanf("%d",&ele);
                enqueue(q,ele);
                break;
        case 3: dequeue(q);
                break;
        case 4: peek(q);
                break;
        case 5: printf("Successfully Exited\n");
                break;               
        default:printf("Enter a valid choice\n");
                break;
        }
    } while (choice!=5);
    return 0;
}

