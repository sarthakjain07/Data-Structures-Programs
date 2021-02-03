#include<iostream>
using namespace std;

int minPosition(int *a, int size)
{
    int min=INT_MAX,min_po;
    for (int i = 0; i < size; i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            min_po=i;
        }
    }
    return min_po;
}

void xainSort(int *a, int size)
{
    int min_po,i;
    int *b=(int *)malloc(size*sizeof(int));
    for (i = 0; i < size; i++)
    {
        min_po=minPosition(a,size);
        b[i]=a[min_po];
        a[min_po]=INT_MAX;
    }
    for (i = 0; i < size; i++)
        a[i]=b[i];
    

}

int main()
{
    int size, i;
    cin >> size;
    int *a=(int *)malloc(size*sizeof(int));
    for (i = 0; i < size; i++)
        cin >> a[i];
    // logic for xain special technique
    xainSort(a,size);


    for (i = 0; i < size; i++)
        cout << a[i] << " ";
    return 0;
}