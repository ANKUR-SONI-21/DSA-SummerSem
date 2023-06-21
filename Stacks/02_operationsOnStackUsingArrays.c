#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int data)
{
    if (isFull(ptr))
        printf("Stack Overflow!");
    else
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = data;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
        printf("Stack is Underflow!");
    else
    {
        //! initioalizing a pointer to the top most element is mandatory
        //! but freeing up space can be beneficial
        int *p = &ptr->arr[ptr->top];
        int val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        free(p);
        return val;
    }
}

int peek(struct stack *ptr, int index)
{
    if (ptr->top - index + 1 < 0)
    {
        printf("Not a valid position");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - index + 1];
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("\nstack has been created!\n");

    //! isFull operation
    if (isFull(s))
        printf("Stack is Full!");
    else
        printf("Stack is Not Full!");

    printf("\n");

    //! isEmpty operation
    if (isEmpty(s))
        printf("Stack is Empty!");
    else
        printf("Stack is Not Empty!");

    printf("\n");

    //! push operation
    push(s, 1);
    push(s, 2);
    push(s, 3); 
    push(s, 4);
    push(s, 5);
    printf("%d", s->arr[s->top]);
    printf("\n");

    //! pop operation
    int val = pop(s);
    printf("Popped %d from the stack\n", val);

    //! peek operation
    int peekIndex = 3;
    printf("TYhe value at index %d is %d", peekIndex, peek(s, peekIndex));
}