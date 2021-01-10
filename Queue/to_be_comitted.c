// void traverse(struct queue *q)
// {
//     if(isEmpty(q))
//         printf("Queue underflow\n");
//     else
//     {
//         printf("Elements of queue are:\n");
//         for(int i=0; i<=q->rear;i++)
//             printf("%d\n",q->a[i]);
//     }
// }


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