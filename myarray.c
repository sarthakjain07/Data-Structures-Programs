//max() and min() functions are to be added and also to be solved array as adt using structure


#include <stdio.h>  // helps to operate standard input output functions
#include <stdlib.h> // standard library header file

int myarray[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // array being used in program
int n = 10;                                         // number of elements in the array
int capacity = sizeof(myarray) / sizeof(int);       // size of array

// This function displays all elements of array by traversing them
void display()
{
    printf("The elements of array are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", myarray[i]);
    }
    printf("\n");
}

// This function adds the passed element after the last element of array
void append(int ele)
{
    myarray[n] = ele;
    n++;
    printf("%d successfully appended\n", ele);
}

// This function adds the element in the given position in array
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

// This function searches the position of given element inside the array
int search(int ele)
{
    int low = 0, high = n - 1, mid;
    if (myarray[low] == ele)
    {
        printf("%d succeessfully found at %d\n", ele, low);
        return low;
    }

    if (myarray[high] == ele)
    {
        printf("%d succeessfully found at %d\n", ele, high);
        return high;
    }

    while (1)
    {
        mid = (low + high) / 2;
        if (ele == myarray[mid])
        {
            printf("%d succeessfully found at %d\n", ele, mid);
            return mid;
        }
        else if (ele > myarray[mid])
            low = mid++;
        else if (ele < myarray[mid])
            high = mid--;
        else
            printf("Element not found in array\n");
    }
}

// This function deletes the element from given position, if position not known we can also search the position of the element by calling search function
void deletion(int ele)
{
    int choice, po;
    if (n == 0)
        printf("Array is empty\n");
    else
    {
        printf("Press 1 If you know the position of element otherwise Press 2\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter the position of element %d\n",ele);
            scanf("%d",&po);
        }
         if(choice==2)
        {
            po=search(ele);
        }
        for (int i = po; i < n - 1; i++)
            myarray[i] = myarray[i + 1];
        n--;
        display();
        printf("Successfully deleted %d from %d\n", ele, po);
        printf("size of array is updated to %d\n", n);
        
    }
}

// This function tells whether the array is sorted or not
void isSort()
{
    if(n==0)
        printf("Array is empty\n");
    else
    {
        for (int i = 0; i < n-1; i++)
    {
        if (myarray[i] > myarray[i + 1])
        {
            printf("Array is not sorted\n");
            break;
        }
        else
        {
            goto xain;
        }
    }
    xain:
        printf("Array is sorted\n");
    } 
}

// This function gives the maximum number from array
void max_array()
{ 
    if (n == 0)
        printf("Array is empty\n");
    else
    {
        int max=0;
    for(int i=1;i<n;i++)
    {
        if(myarray[max]<myarray[i])
            myarray[max]=myarray[i];
    }
    printf("The maximum element of the array is %d\n",myarray[max]);

    }
      
}

// This function gives the minimum number from array
void min_array()
{ 
    if (n == 0)
        printf("Array is empty\n");
    else
    {
        int min=0;
    for(int i=0;i<n;i++)
    {
        if(myarray[min]>myarray[i])
            myarray[min]=myarray[i];
    }
    printf("The minimum element of the array is %d\n",myarray[min]);

    }
      
}

void main()
{
    char choice;
    int append_ele, insert_position, insert_ele, del_ele, search_ele;
    printf("Welcome To Operations on Array\n");
    // Displaying all the operations repeatedly till the one exits using - switch case in a do while loop
    do
    {
        printf("1.Display\n2.Append\n3.Insertion\n4.Deletion\n5.Search\n6.isSorted\n7.Sort\n8.Maximum_Number\n9.Minimum_Number\n10.Exit\n");
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
            scanf("%d", &del_ele);
            deletion(del_ele);
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
            max_array();
            break;     
        case 9:
            min_array();
            break;     
        case 10:
            printf("You are successfully exited\n");
            break;
        default:
            printf("Please Choose a valid option\n");
            break;
        }
    } while (choice != 10);
}