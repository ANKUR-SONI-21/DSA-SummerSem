#include <stdio.h>
#include <stdlib.h>

int *selectionSort(int *arr, int size)
{
    int min, k, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1 ; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
    int size = sizeof(arr) / sizeof(int);
    int *sortedArray = selectionSort(arr, size);
    printArr(sortedArray, size);
    return 0;
}