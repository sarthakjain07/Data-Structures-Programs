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
    // Selection sort logic
    for ( i = 0; i < size-1; i++)
    {
        for (j = i+1; j < size; j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        
    }
    // printing elements after sorting
    for (i = 0; i < size; i++)
        cout<<a[i]<<" ";
       
    
    return 0;
}