#include <stdio.h>
#include <stdlib.h>

int myarray[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int n = 10, capacity = sizeof(myarray) / sizeof(int); //size of array

void display()
{
    printf("The elements of array are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", myarray[i]);
    }
    printf("\n");
}

void append(int ele)
{
    myarray[n] = ele;
    n++;
    printf("%d successfully appended\n", ele);
}

void insertion(int ele, int po)
{
    if (n >= capacity)
        printf("Array out of memory\n");
    else
    {
        int choice, ap;
        printf("1.Existing data to be shifted\n2Add already existing element at the end\nEnter your choice:\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            for (int i = n - 1; i >= po; i--)
                myarray[i + 1] = myarray[i];
            n++;
        }
        if (choice == 2)
        {
            ap = myarray[po];
            append(ap);
        }
        myarray[po] = ele;
        display();
        printf("Successfully added %d at %d\n", ele, po);
        printf("size of array is updated to %d\n", n);
    }
}

void deletion(int ele, int po)
{
    if (n == 0)
        printf("Array is empty\n");
    else
    {
        for (int i = po; i < n - 1; i++)
            myarray[i] = myarray[i + 1];
        n--;
        display();
        printf("Successfully deleted %d from %d\n", ele, po);
        printf("size of array is updated to %d\n", n);
    }
}

void search(int ele)
{
    int low = 0, high = n - 1, mid;
    if (myarray[low] == ele)
    {
        printf("%d succeessfully found at %d\n", ele, low);
        return;
    }

    if (myarray[high] == ele)
    {
        printf("%d succeessfully found at %d\n", ele, high);
        return;
    }

    while (1)
    {
        mid = (low + high) / 2;
        if (ele == myarray[mid])
        {
            printf("%d succeessfully found at %d\n", ele, mid);
            break;
        }
        else if (ele > myarray[mid])
            low = mid++;
        else if (ele < myarray[mid])
            high = mid--;
        else
            printf("Element not found in array\n");
    }
}

void isSort()
{
    for (int i = 0; i < n; i++)
    {
        if (myarray[i] > myarray[i + 1])
            goto xain;
    }
xain:
    printf("Array is not Sorted\n");
    return;
    printf("Array is sorted");
}

void main()
{
    char choice;
    int append_ele, insert_position, insert_ele, del_ele, del_position, search_ele;
    // printf("Enter the total capacity of array\n");
    // scanf("%d", &capacity);

    // printf("Enter the no. of elements to be stored in array:\n");
    // scanf("%d",&no_of_elem);
    // printf("Enter %d elements in array:\n",no_of_elem);
    // for (int i = 0; i < no_of_elem; i++)
    // {
    //     scanf("%d",&myarray[i]);
    // }
    // display(myarray,no_of_elem);
    printf("Welcome To Operations on Array\n");
    do
    {
        printf("1.Display\n2.Append\n3.Insertion\n4.Deletion\n5.Search\n6.isSorted\n7.Sort\n8.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            printf("Enter the element you want to append\n");
            scanf("%d", &append_ele);
            append(append_ele);
            break;
        case 3:
            printf("Enter the element and position\n");
            scanf("%d %d", &insert_ele, &insert_position);
            insertion(insert_ele, insert_position);
            break;
        case 4:
            printf("Enter the element and position\n");
            scanf("%d %d", &del_ele, &del_position);
            deletion(del_ele, del_position);
            break;
        case 5:
            printf("Enter the element\n");
            scanf("%d", &search_ele);
            search(search_ele);
            break;
        case 6:
            isSort();
            break;
        case 8:
            printf("You are successfully exited\n");
            break;
        default:
            printf("Please Choose a valid option\n");
            break;
        }
    } while (choice != 8);
}