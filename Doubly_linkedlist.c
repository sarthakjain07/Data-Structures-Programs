#include <stdio.h>
#include <stdlib.h>

struct doublyll
{
    int data;
    struct doublyll *next;
    struct doublyll *previous;
};
struct doublyll *head=NULL;

void searchDLL(int num)
{

}

void insertionDLL(int num)
{
        int choice;
        struct doublyll *node=(struct doublyll*)malloc(sizeof(struct doublyll));
        struct doublyll *ptr=head;
        if(head==NULL)
        {
                node->next=NULL;
                node->previous=NULL;
                head=node;
        }
        else
        {
                printf("Where do you want to store the Element\n1. In the Beginning\n2. At the End\n 3. After The given index\n4. Before the given index\n5. After a given value\n6. Before a given value\n");
                scanf("%d",&choice);

                if(choice==1)
                {
                        node->next=head;
                        node->previous=NULL;
                        head->previous=node;
                        head=node;
                }
        }
        

}

void deletionDLL()
{

}

void displayDLL()
{
    
}

int main()
{
    int choice,insert_num,search_num;
    printf("welcome to the program of Dounly Linked list\n");
    printf("Enter your choice\n");
    printf("1.Insertion\n2.Deletion\n3.Display\n4.Search\n5.Exit\n");
    scanf("%d",&choice);
    do
    {
        switch (choice)
        {
        case 1: printf("Enter the no. to be inserted\n");
                scanf("%d",&insert_num);
                insertionDLL(insert_num);
                break;
        case 2: deletionDLL();
                break;        
        case 3: displayDLL();
                break;        
        case 4: printf("Enter the no. to be searched\n");
                scanf("%d",&search_num);
                searchDLL(search_num);
                break;        
        case 5: printf("Successfully Exited\n");
                break;        
        default:printf("Enter a valid choice\n");
                break;
        }
    } while (choice!=5);
    
    return 0;
}
