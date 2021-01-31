#include<iostream>
// #include<stdlib.h>
using namespace std;

int main()
{
    int n,x=0,i,isSorted=0;
    cin>>n;
    int a[n];
    for (i = 0; i < n; i++)
        cin>>a[i];
    while(n-x!=1) // decreasing with every x iteration
    {
        isSorted=1;
        for (i=0; i < n-x; i++) // decreasing with every (n-1) iteration
        {
            if(a[i]>a[i+1])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                isSorted=0;
            }
        }
        if(isSorted)
            break;
        x++;    
    }
    for (int  i = 0; i < n; i++)
        cout<<a[i]<<endl;
        

    
    return 0;
}