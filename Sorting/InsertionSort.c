#include <stdio.h>
#include <stdlib.h>
//! one way of doing this
int *insertionSort(int *arr, int size)
{
    int temp;
    for (int i = 1; i <= size; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    return arr;
}

//! another way
int *insertionSort(int *arr, int size)
{
    int key, j;
    for (int i = 1; i <= size - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    int *sortedArray = insertionSort(arr, size);
    printArr(sortedArray, size);

    return 0;
}