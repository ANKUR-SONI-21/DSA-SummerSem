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
        ptr->next = front;
        front = ptr;
        return front;
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
        struct Node *rear = front->next;
        struct Node *temp = front;
        while (rear->next != NULL)
        {
            rear = rear->next;
            temp = temp->next;
        }
        printf("The Element removed form the queue is %d\n", rear->data);
        temp->next = NULL;
        free(rear);
        return front;
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