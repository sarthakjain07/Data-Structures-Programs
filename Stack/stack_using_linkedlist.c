#include <stdio.h>
#include <stdlib.h>

// Globally defined variables to be used in all functions
int size, element_added = 0;

//Structure of a singly linked list
struct ll
{
    int data;
    struct ll *next;
};
struct ll *top = NULL;

// This function tells if stack is empty
int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

// This function tells if stack is full
int isFull()
{
    if (element_added == size)
        return 1;
    return 0;
}

// This function displays all elements of stack
void traverse()
{
    if (isEmpty())
        printf("Stack is Empty\n");
    else
    {
        struct ll *ptr = top;
        while (ptr->next != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

// This function add the give element at the top of stack
void push(int ele)
{

    if (isFull())
        printf("Stack is Full\n");
    else
    {
        struct ll *node = (struct ll *)malloc(sizeof(struct ll));
        printf("Enter the no. to be pushed\n");
        scanf("%d", &ele);
        node->data = ele;
        node->next = top;
        top = node;
        element_added++;
    }
}

// This function is used to delete the element from top of stack
void pop()
{
    if (isEmpty())
        printf("Stack is Empty\n");
    else
    {
        struct ll *ptr = top;
        top = ptr->next;
        free(ptr);
        printf("Number is poped successfully\n");
        element_added--;

    }
}

// main function controlling all other functions
int main()
{
    int choice, ele;
    printf("Enter the size of stack\n");
    scanf("%d", &size);
    do
    {
        printf("Welcome to the program of stack\nEnter your choice\n1. Traverse\n2. Push\n3. Pop\n4. peek\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            push(ele);
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("Successfully Exited\nThankyou!\n");
            break;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    } while (choice != 5);
    return 0;
}