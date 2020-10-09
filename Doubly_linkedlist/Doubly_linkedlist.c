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
        int choice,index;
        struct doublyll *node=(struct doublyll*)malloc(sizeof(struct doublyll));
        struct doublyll *ptr=head;
        if(head==NULL)
        {
                node->next=NULL;
                node->previous=NULL;
                head=node;
                printf("%d successfully inserted in the beginning\n,num");
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
                        printf("%d successfully inserted in the beginning\n,num");
                }
                if(choice==2)
                {
                        while (ptr->next!=NULL)
                                ptr=ptr->next;
                        ptr->next=node;
                        node->previous=ptr;
                        node->next=NULL;
                        printf("%d successfully inserted at  the end\n,num");

                }
                if(choice==3)
                {
                        printf("Enter the index after which you want the number to be inserted\n");
                        scanf("%d",&index);
                        while (index!=0)
                        {
                                ptr=ptr->next;
                                index--;
                        }
                        node->next=ptr->next;
                        node->previous=ptr;
                        ptr->next=node;
                        ptr=ptr->next;
                        ptr->previous=node;
                        printf("%d successfully inserted after the index %d\n,num,index");        
                }
                if(choice==4)
                {
                        printf("Enter the index before which you want to store the element\n");
                        scanf("%d",&index);
                        if(index==0)
                        {
                                node->next=head;
                                node->previous=NULL;
                                head->previous=node;
                                head=node;
                                printf("%d successfully inserted before the index %d\n,num,index");
                        }
                        else
                        {
                                index=index-1;
                                while (index!=0)
                                {
                                        ptr=ptr->next;
                                        index--;
                                }
                                node->next=ptr->next;
                                node->previous=ptr;
                                ptr->next=node;
                                ptr=ptr->next;
                                ptr->previous=node;
                                printf("%d successfully inserted before the index %d\n,num,index+1");
                        }
                        
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
