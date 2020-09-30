#include <stdio.h>
#include <stdlib.h>

// This is a structure of every node of Circular linked list
struct circularLL
{
    int data;
    struct circularLL *next;
};

// Initialization of head pointer or starting pointer of list
struct circularLL *head = NULL;

// This function searches the given number and tell its index and also returns its address
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


// This functions prints all the elements of the circular linked list
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
        printf("%d\n",ptr->data);
        ptr=ptr->next;
        while (ptr!=head)
        {
        printf("%d\n",ptr->data);
        ptr=ptr->next;    
        } 
        

    }
}


// This function tells the total number of nodes present in list and return the value
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


// This function inserts the given number in various places inside the list
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
            printf("%d successfully added after node %d\n", ele, index_node);
        }
    }
    if(choice==4)
    {
        
        if(head==NULL)
        {
            head = node;
            node->next = head;
            printf("%d successfully added at the first position of list\n", ele);
        }
        else
        {
            printf("Enter the element after which u want the data to be inserted\n");
            scanf("%d",&search_ele);
            struct circularLL * ptr=searchCLL(search_ele);
            node->next=ptr->next;
            ptr->next=node;
            printf("%d successfully added after %d\n",ele,search_ele);
            
        }
    }
    else
        printf("Enter a valid choice\n");
    
}


// This function deletes a complete node from various places inside the list
void deletionCLL()
{
    int index_node=0, ele;
    if(head==NULL)
        printf("Circular linked is empty\n");        
    else if(head->next==head)
    {
        struct circularLL * ptr=head;
        head=NULL;
        free(ptr);
        printf("The only node in the linked is deleted\n");
    }
    else
    {
        int choice = 0, deleted_data = 0, deletion_index = 0, i = 1;
        struct circularLL *ptr1 = head;
        struct circularLL *ptr2 = head->next;
        printf("From Where do u want to delete the element\n1.From the beginning\n2.From the end\n3.From the given index in between the Linkedlist\n4.First occurence of given value\n");
        scanf("%d", &choice);
        if(choice==1)
        {        
            while(ptr2->next!=head)
                ptr2=ptr2->next;
            head=ptr1->next;
            ptr2->next=head;
            deleted_data=ptr1->data;
            free(ptr1);
            printf("%d successfully deleted from beginning\n",deleted_data);
        }
        if(choice==2)
        {
            while (ptr2->next!=head)
            {
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            ptr1->next=head;
            deleted_data=ptr2->data;
            free(ptr2);
            printf("%d successfully deleted from the end\n",deleted_data);
        }
        if(choice==3)
        {
            printf("Enter the index no. of node to be deleted\n");
            scanf("%d",&index_node);
            if(index_node==0)
            {
            while(ptr2->next!=head)
            ptr2=ptr2->next;
            head=ptr1->next;
            ptr2->next=head;
            deleted_data=ptr1->data;
            free(ptr1);
            printf("%d successfully deleted from beginning\n",deleted_data);
            }
            else
            {
                while (index_node!=1)
                {
                    ptr1=ptr1->next;
                    ptr2=ptr2->next;
                    i--;   
                }
                ptr1->next=ptr2->next;
                deleted_data=ptr2->data;
                free(ptr2);
                printf("%d successfully deleted from index number %d\n",deleted_data,index_node);

            }
        }
        if(choice==4)
        {
            printf("Enter the element to be deleted\n");
            scanf("%d",&ele);
            if(ptr1->data==ele)
            {
            while(ptr2->next!=head)
            ptr2=ptr2->next;
            head=ptr1->next;
            ptr2->next=head;
            deleted_data=ptr1->data;
            free(ptr1);
            printf("%d successfully deleted from beginning\n",deleted_data);   
            }
            else
            {
                while (ptr2->data!=ele)
                {
                    ptr1=ptr1->next;
                    ptr2=ptr2->next;
                }
                ptr1->next=ptr2->next;
                deleted_data=ptr2->data;
                free(ptr2);
                printf("First position of %d is successfully deleted\n",deleted_data);
            }
            

        }

    }    
    
}


// This functions operate all the other functions of circular linked list
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
            deletionCLL();
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
