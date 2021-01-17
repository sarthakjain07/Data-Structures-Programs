#include<stdio.h>
#include<stdlib.h>

struct dq{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct dq *q)
{
    if(q->front==q->rear)
        return 1;
    return 0;    
}

int isFull(struct dq *q)
{
    if(q->rear==(q->size)-1 || q->front==(q->size)-1)
        return 1;
    return 0;    
}

void enqueueRear(struct dq *q,int ele);

int main()
{
    int choice,ele;
    struct dq *q=(struct dq *)malloc(sizeof(struct dq)); 
    q->size=5;
    q->front=-1;
    q->rear=-1;
    q->arr=(int *)malloc(q->size*sizeof(int));
    do
    {
    printf("Welcome to the program of Queue\nEnter your choice\n1. Traverse\n2. Enqueue Rear\n3. Dequeue Front\n4. peek\n5. Enqueue Front\n6. Dequeue Rear\n7. Exit\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1: traverse(q);
                break;
        case 2: printf("Enter the element to be enqueued\n");
                scanf("%d",&ele);
                enqueueRear(q,ele);
                break;
        case 3: dequeueFront(q);
                break;
        case 4: peek(q);
                break;
        case 5: printf("Enter the element to be enqueued\n");
                scanf("%d",&ele);
                enqueueFront(q,ele);
                break;
        case 6: dequeueRear(q);
                break;                
        case 7: printf("Successfully Exited\n");
                break;               
        default:printf("Enter a valid choice\n");
                break;
        }
    } while (choice!=7);
    return 0;
}