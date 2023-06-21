#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}
int main()
{
    //* implementing Stack
    struct Stack *S;
    S->size = 10;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));
    //! similar to c :
    // int * arr ;
    // arr = new int [80];

    // * pushing alements manually
    S->arr[0] = 1;
    S->top++;

    //* isEmpty and isFull Operations
    if (isEmpty(S))
        printf("Empty!");
    else
        printf("Not Empty");
    printf("\n");
    if (isFull(S))
        printf("Full!");
    else
        printf("Not Full");
}