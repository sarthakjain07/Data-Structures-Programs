#include<iostream>
// #include<algorithm>
using namespace std;

int main()
{
    int size,i,j,temp;
    cin>>size;
    int a[size];
    for (i = 0; i < size; i++)
        cin>>a[i];
    // Insertion sort logic
    for ( i = 1; i < size; i++)
    {
        int temp=a[i];
        j=i-1;
        while (a[j]>temp && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    // printing elements after sorting
    for (i = 0; i < size; i++)
        cout<<a[i]<<" ";
       
    
    return 0;
}