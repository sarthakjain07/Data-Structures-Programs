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

void Insertion_end(int ele)
{
    
    struct linkedl *nodeptr = (struct linkedl *)malloc(sizeof(struct linkedl));
    nodeptr->data=ele;   
    struct linkedl *ptr = head;
    while (ptr!= NULL)
        ptr = ptr->next;
   printf("s");            
   ptr->next = nodeptr;
   nodeptr->next = NULL;
   printf("%d successfully added at the End\n", ele);
}

void Insertion(int ele)
{
    int choice;
    struct linkedl *nodeptr = (struct linkedl *)malloc(sizeof(struct linkedl));
    nodeptr->data = ele;
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
        Insertion_end(ele);
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