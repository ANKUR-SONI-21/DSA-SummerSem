#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isFull(struct Node *front)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
        return 1;
    else
        return 0;
}

int isEmpty(struct Node *front)
{
    if (front == NULL)
    {
        return 1;
    }
    else
        return 0;
}
struct Node *enqueue(struct Node *front, int val)
{
    if (isFull(front))
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = val;
        struct Node *temp = front;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
    }
}

struct Node *dequeue(struct Node *front)
{
    if (isEmpty(front))
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        struct Node *temp = front;
        front = front->next;
        printf("The Element removed form the queue is %d\n", temp->data);
        free(temp);
    }
}
int main()
{
    struct Node *front = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    front->data = 1;
    front->next = second;

    second->data = 1;
    second->next = third;

    third->data = 1;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = fifth;

    fifth->data = 1;
    fifth->next = NULL;

    //! enqueue
    front = enqueue(front, 6);

    //! dequeue
    front = dequeue(front);

    //! isEmpty
    if (isEmpty(front))
        printf("Queue is Empty!\n");
    else
        printf("Queue is not Empty!\n");

    //! isFull
    if (isFull(front))
        printf("Queue is Full!\n");
    else
        printf("Queue is not Full\n");

    return 0;
}