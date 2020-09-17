#include <stdio.h>
#include <stdlib.h>

struct circularLL
{
    int data;
    struct circularLL *next;
};
struct circularLL *head = NULL;
void displayCLL()
{

    struct circularLL *ptr = head;
    if (head == NULL)
    {
        printf("Circular Linked list is empty\n");
    }
    else
    {
        printf("The Elements in the list are:\n");
        do
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

void insertionCLL_first(int ele)
{
    struct circularLL *node = (struct circularLL *)malloc(sizeof(struct circularLL));
    node->data = ele;
    struct circularLL *ptr = head;
    head = node;
    node->next = head;
    printf("%d successfully added at the first position of list\n", ele);

}

void insertionCLL(int ele)
{

    int choice, inbw_choice;
    struct circularLL *node = (struct circularLL *)malloc(sizeof(struct circularLL));
    node->data = ele;
    struct circularLL *ptr = head;
    printf("Where do u want to store the element\n1.At the beginning\n2.At the end\n3.Add In between\n4.Add after a node\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        if (head == NULL)
            insertionCLL_first(ele);
        else
        {
            while (ptr->next != head)
                ptr = ptr->next;
            ptr->next = node;
            node->next = head;
            head = node;
            printf("%d successfully added at the beginning\n", ele);
        }
    }
    if (choice == 2)
    {
        if(head==NULL)
            insertionCLL_first(ele);
        else
        {
            while (ptr->next != head)
                ptr = ptr->next;
            node->next = ptr->next;
            ptr->next = node;
            printf("%d successfully added at the last\n", ele);



        }
    }   


}

void main()
{
    int choice, insert_ele, search_ele;
    printf("Welcome To Operations on Circular Linked List\n");
    do
    {
        printf("1.Display\n2.Insertion\n3.Deletion\n4.Search\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            displayCLL();
            // totalNodes(index);
            break;
        case 2:
            printf("Enter the data to be inserted\n");
            scanf("%d", &insert_ele);
            insertionCLL(insert_ele);
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
