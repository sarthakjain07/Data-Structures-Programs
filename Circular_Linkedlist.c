#include <stdio.h>
#include <stdlib.h>

struct circularLL
{
    int data;
    struct circularLL *next;
};

void displayCLL(struct circularLL *head)
{

    struct circularLL *ptr = head;
    if (ptr->next == NULL)
    {
        printf("Circular Linked list is empty\n");
    }
    else
    {
        do
        {
            printf("%d", ptr->data);
            ptr = ptr->next;

        } while (ptr != head);
    }
}

void insertionCLL(struct circularLL *head,int ele)
{
    int choice, inbw_choice;
    struct circularLL *node = (struct circularLL *)malloc(sizeof(struct circularLL));
    node->data = ele;
    struct circularLL *ptr = head;
    printf("Where do u want to store the element\n1.At the beginning\n2.At the end\n3.Add In between\n4.Add after a node\n");
    scanf("%d", &choice);
    if(choice==1)
    {
        


    }

}

void main()
{
    struct circularLL *head = (struct circularLL *)malloc(sizeof(struct circularLL));
    head->next = NULL;
    int choice, insert_ele, search_ele;
    printf("Welcome To Operations on Circular Linked List\n");
    do
    {
        printf("1.Display\n2.Insertion\n3.Deletion\n4.Search\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            displayCLL(head);
            // totalNodes(index);
            break;
        case 2:
            printf("Enter the data to be inserted\n");
            scanf("%d", &insert_ele);
            insertionCLL(head,insert_ele);
            // totalNodes(index);
            break;
        case 3:
            // deletionCLL();
            // totalNodes(index);
            break;
        case 4:
            printf("Enter the element to be searched\n");
            scanf("%d", &search_ele);
            // searchCLL(search_ele);
        case 5:
            printf("Successfully Exited\n");
            break;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    } while (choice != 5);
}
