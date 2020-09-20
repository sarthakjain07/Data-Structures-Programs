#include <stdio.h>
#include <stdlib.h>

struct circularLL
{
    int data;
    struct circularLL *next;
};
struct circularLL *head = NULL;

struct circularLL *searchCLL(int ele)
{
    if (head == NULL)
        printf("Circular linked list is empty\n");
    else
    {
        int i = 0;
        struct circularLL *ptr = head;
        while (ptr->data != ele)
        {
            ptr = ptr->next;
            i++;
        }
        printf("%d found at index %d\n", ele, i);
        return ptr;
    }
}

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

int totalNodes(int index)
{
    if (head == NULL)
        index = 0;
    else
    {
        struct circularLL *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
            index++;
        }
    }
    // printf("Currently no. of nodes in linked list are %d\n",index);
    return index;
}

void insertionCLL(int ele)
{

    int choice, index_node = 0, index = 1, indexes = 0, search_ele;
    struct circularLL *node = (struct circularLL *)malloc(sizeof(struct circularLL));
    node->data = ele;
    struct circularLL *ptr = head;
    printf("Where do u want to store the element\n1.At the beginning\n2.At the end\n3.Add after a given node\n4.Add after an element\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        if (head == NULL)
        {
            head = node;
            node->next = head;
            printf("%d successfully added at the first position of list\n", ele);
        }
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
        if (head == NULL)
        {
            head = node;
            node->next = head;
            printf("%d successfully added at the first position of list\n", ele);
        }
        else
        {
            while (ptr->next != head)
                ptr = ptr->next;
            node->next = ptr->next;
            ptr->next = node;
            printf("%d successfully added at the last\n", ele);
        }
    }
    if (choice == 3)
    {
        printf("Enter the no. of node after which the element to be added\n");
        scanf("%d", &index_node);
        indexes = totalNodes(index);
        if ((index_node + 1) > index)
            printf("Node does not exist try a lower no.\n");
        else if (head == NULL)
        {
            head = node;
            node->next = head;
            printf("%d successfully added at the first position of list\n", ele);
        }
        else
        {
            while (index_node != 0)
            {
                index_node--;
                ptr = ptr->next;
            }
            node->next = ptr->next;
            ptr->next = node;
            printf("%d successfully added after node %d", ele, index_node);
        }
    }
    
}



void main()
{
    int choice, insert_ele, search_ele, index = 1;
    printf("Welcome To Operations on Circular Linked List\n");
    do
    {
        printf("1.Display\n2.Insertion\n3.Deletion\n4.Search\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            displayCLL();
            totalNodes(index);
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
            searchCLL(search_ele);
            break;
        case 5:
            printf("Successfully Exited\n");
            break;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    } while (choice != 5);
}
