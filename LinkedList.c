#include <stdio.h>
#include <stdlib.h>

struct linkedl
{
    int data;
    struct linkedl *next;
};
struct linkedl *head = NULL;

void display()
{
    if (head == NULL)
        printf("Linked list is empty\n");
    else
    {
        struct linkedl *ptr = head;
        printf("The elements in the list are:\n");
        while (ptr!= NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}


void Insertion(int ele)
{
    int choice,inbw_choice;
    struct linkedl *nodeptr = (struct linkedl *)malloc(sizeof(struct linkedl));
    nodeptr->data = ele;
    struct linkedl *ptr = head;
    printf("Where do u want to store the element\n1.At the beginning\n2.At the end\n3.In between\n4.After a node\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        nodeptr->next = head;
        head = nodeptr;
        printf("%d successfully added at the beginning\n", ele);
    }
    if (choice == 2)
    {
    while (ptr!= NULL)
        ptr = ptr->next;
    printf("s");            
    ptr->next = nodeptr;
    nodeptr->next = NULL;
    printf("%d successfully added at the End\n", ele);
    }
    if (choice == 3)
    {
        int i=1;
        printf("Enter the index after which node to be inserted\n");
        scanf("%d",&inbw_choice);
        while (i!=inbw_choice)
            ptr=ptr->next;
        nodeptr->next=ptr->next;
        ptr->next=nodeptr;
        printf("%d successfully added after the index %d\n", ele,inbw_choice);

    }
    if (choice == 4) 
    {
        struct linkedl *address;
        nodeptr->next=address->next;
        address->next=ptr;
        printf("%d successfully after the node\n", ele);        
    }
}

void main()
{
    int choice, insert_ele;
    printf("Welcome To Operations on Linked List\n");
    do
    {
        printf("1.Display\n2.Insertion\n3.Deletion\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            printf("Enter the data to be inserted\n");
            scanf("%d", &insert_ele);
            Insertion(insert_ele);
            break;
        case 6:
            printf("Successfully Exited\n");
            break;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    } while (choice != 6);
}