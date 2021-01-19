#include<iostream>
// #include<stdlib.h>
using namespace std;

int main()
{
    int n,x=0,i;
    cin>>n;
    int a[n];
    for (i = 0; i < n; i++)
        cin>>a[i];
    while(n-x!=1)
    {
        i=0;
        for (int j = i+1; j < n-x; j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            i++;
        }
        x++;    
    }
    for (int  i = 0; i < n; i++)
        cout<<a[i]<<endl;
        

    
    return 0;
}