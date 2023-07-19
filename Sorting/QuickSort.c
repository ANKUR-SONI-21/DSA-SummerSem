#include <stdio.h>
#include <stdlib.h>
int partition(int *arr, int low, int high)
{
    int temp;
    int pivot = arr[low];
    //! pivot is chosen to be the first element here
    int i = low + 1;
    int j = high;

    do
    {
        //! on checking from left till we find an element which is greater than pivot
        while (arr[i] <= pivot)
        {
            i++;
        }
        //! finding element which is lower than pivot
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (j > i);

    //! swapping pivot element
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}
int *quickSort(int *arr, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  //! sort left subarray
        quickSort(arr, partitionIndex + 1, high); //! sort right subarray
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
    int *sortedArray = quickSort(arr, 0, 4);
    printArr(sortedArray, 5);
    return 0;
}