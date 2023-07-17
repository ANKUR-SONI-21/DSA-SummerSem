#include <stdio.h>
#include <stdlib.h>
int BinarySearch(int arr[], int val, int size)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == val)
        {
            return mid + 1;
        }
        else if (arr[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int LinearSearch(int arr[], int val, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return i + 1;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int size = sizeof(arr) / sizeof(int);
    int b = BinarySearch(arr, 14, size);
    printf("Element is present at %dth position\n", b);
    int l = LinearSearch(arr, 12, size);
    printf("Element is present at %dth position\n", l);
    return 0;
}