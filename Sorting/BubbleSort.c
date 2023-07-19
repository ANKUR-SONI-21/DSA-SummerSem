#include <stdio.h>
#include <stdlib.h>
int *bubbleSort(int *a, int size)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < size - 1; i++)
    {
        isSorted = 1;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            break;
        }
    }
    return a;
}
void printArr(int *sr, int size)
{
    printf("Sorted Array is as follows : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", sr[i]);
    }
}
int main()
{
    int arr[] = {7, 11, 9, 2, 17, 4};
    int size = sizeof(arr) / sizeof(int);
    // using a pointer that points to the sorted array
    int *sortedArr = bubbleSort(arr, size);
    printArr(sortedArr, size);
    return 0;
}