#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *ptr)
{
    if (ptr->next == NULL)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(struct Node *ptr)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
        return 1;
    else
        return 0;
}

struct Node *push(struct Node *top, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (isFull(top))
    {
        printf("Stack Overflow!");
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    return top;
}

struct Node *pop(struct Node *top)
{
    if (top == NULL)
    {
        printf("Empty Stack!");
    }
    else
    {
        struct Node *p = top;
        top = top->next;
        free(p);
    }
    return top;
}

int peek(struct Node *top, int index)
{
    struct Node *p = top;
    int i = 1;
    while (i != index)
    {
        if (p->next != NULL)
            p = p->next;
        else
            printf("Enter a valid position!");
        i++;
    }
    return p->data;
}

int peekNode(struct Node *top, struct Node *index)
{
    struct Node *p = top;
    while (p != index)
    {
        if (p->next != NULL)
            p = p->next;
        else
            printf("Enter a valid position!");
    }
    return p->data;
}

int stackBottom(struct Node *top)
{
    struct Node *p = top;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}

int main()
{
    struct Node *top = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    top->data = 1;
    top->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    //! isEmpty Operation
    if (isEmpty(top))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack is not empty!\n");
    }

    //! isFull Operation
    if (isFull(top))
    {
        printf("No Heap memeory Left!\n");
    }
    else
    {
        printf("Stack is not Full!\n");
    }

    //! push operation
    top = push(top, 15);
    printf("%d\n", top->data);

    //! pop operation
    top = pop(top);
    printf("%d\n", top->data);

    //! peek operation
    int peekIndex = 5;
    printf("The value at index %d is %d\n", peekIndex, peek(top, peekIndex));

    //! peek [node]
    printf("The value at %s is %d\n", "second", peekNode(top, second));

    //! peek last
    printf("Last Element is : %d", stackBottom(top));
}