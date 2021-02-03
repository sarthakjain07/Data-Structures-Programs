#include <iostream>
// #include<algorithm>
using namespace std;

void merge(int a[],int low,int high,int mid)
{
    int i=low,k=low,j=mid+1;
    // creating array b where elements of array a will be merged in a sorting order
    int b[high+1];

    while(i<=mid && j<=high)
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            j++;
            k++;
        }
        else{
            b[k]=a[i];
            i++;
            k++;
        }
    }
    // if elements left in first part of array
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    // if elements left in second part of array
    while(j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }

    // Now copy the elements of array b in a
    for (i = low; i <= high; i++)
    {
        a[i]=b[i];
    }
    

}

void mergeSort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(high+low)/2; // mid point of the array
        // breaking the arrays and merging them recursively
        mergeSort(a,low,mid); 
        mergeSort(a,mid+1,high);
        merge(a,low,high,mid);

    }
}

int main()
{
    int size, i;
    cin >> size;
    int a[size];
    for (i = 0; i < size; i++)
        cin >> a[i];
 
    // calling mergeSort function    
    mergeSort(a, 0, size - 1);

    // printing array after sorting
    for (i = 0; i < size; i++)
        cout << a[i] << " ";

    return 0;
}