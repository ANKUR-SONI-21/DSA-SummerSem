#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int low, int mid, int high)
{
    int i, j, k, B[high - low + 1];
    i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            B[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        k++;
        j++;
    }
    for (int i = low; i < high + 1; i++)
    {
        arr[i] = B[i];
    }
}
int *mergeSort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    return arr;
}

void printArr(int *arr, int size)
{
    printf("Sorted Array is as follows : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int arr[] = {7, 12, 3, 4, 1};
    int *sortedArray = mergeSort(arr, 0, 4);
    printArr(sortedArray, 5);
    return 0;
}