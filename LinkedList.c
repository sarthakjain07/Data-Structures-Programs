#include <stdio.h>
#include <stdlib.h>

struct linkedl
{
    int data;
    struct linkedl *next;
};
struct linkedl *head = NULL;

void displayLL()
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

// This function helps in inserting data in Linked List using various methods
void insertionLL(int ele)
{
    int choice,inbw_choice;
    struct linkedl *nodeptr = (struct linkedl *)malloc(sizeof(struct linkedl));
    nodeptr->data = ele;
    struct linkedl *ptr = head;
    printf("Where do u want to store the element\n1.At the beginning\n2.At the end\n3.Add In between\n4.Add after a node\n");    
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

//This function helps in deleting the elements from Linked List using various methods


void deletionLL()
{
    int choice=0,deleted_data=0,index=1,i=1;
    struct linkedl *ptr1 = head;
    struct linkedl *ptr2 = head->next;
    printf("From Where do u want to delete the element\n1.From the beginning\n2.From the end\n3.From the given index in between the Linkedlist\n4.First occurence of given value\n");    
    scanf("%d", &choice);
    if (choice == 1)
    {
        deleted_data=head->data;
        head=head->next;
        free(ptr1);
        printf("%d successfully deleted from the beginning\n",deleted_data);
    }
    if (choice == 2)
    {
        while (ptr2->next!=NULL)
        {
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
        deleted_data=ptr2->data;
        ptr1->next=NULL;
        free(ptr2);
        printf("%d successfully deleted from the end\n",deleted_data);
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
            displayLL();
            break;
        case 2:
            printf("Enter the data to be inserted\n");
            scanf("%d", &insert_ele);
            insertionLL(insert_ele);
            break;
        case 3:
            deletionLL();
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