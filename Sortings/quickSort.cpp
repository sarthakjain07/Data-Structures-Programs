#include <iostream>
// #include<algorithm>
using namespace std;

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1, j = high, temp;
    do
    {
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);
    // swapping pivot and j finally
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j; // returning partition Index
}

void quickSort(int a[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
}

int main()
{
    int size, i;
    cin >> size;
    int a[size];
    for (i = 0; i < size; i++)
        cin >> a[i];
    quickSort(a, 0, size - 1);
    for (i = 0; i < size; i++)
        cout << a[i] << " ";

    return 0;
}