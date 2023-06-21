#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    else
        return 0;
}
int isFull(struct queue *q)
{
    if (q->r + 1 == q->f)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full!\n");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q)
{
    if (isEmpty(q))
        printf("Queue is Empty!\n");
    else
    {
        q->f = q->f + 1;
        int val = q->arr[q->f];
        q->r = q->r - 1;
        return val;
    }
}
int firstVal(struct queue *q)
{
    return q->arr[q->f + 1];
}
int lastVal(struct queue *q)
{
    return (q->arr[q->r]);
}
int peek(struct queue *q, int pos)
{
    if (isEmpty(q))
        printf("Queue is Empty!\n");
    else
    {
        if (pos > q->r + 1 || pos <= q->f)
        {
            printf("invalid position!\n");
        }
        else
        {
            return q->arr[pos - 1];
        }
    }
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = -1;
    q->r = q->f;
    q->arr = (int *)malloc(q->size * sizeof(int));

    //! enqueue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    //! dequeue
    int val = dequeue(q);
    printf("Element %d left the queue!\n", val);

    //! isEmpty
    if (isEmpty(q))
        printf("Queue Underflow!\n");
    else
        printf("Queue is not Empty\n");

    //! isFull
    if (isFull(q))
        printf("Queue Overflow!\n");
    else
        printf("Queue is not Full\n");

    //! firstVal
    int firstval = firstVal(q);
    printf("First value of Queue is : %d\n", firstval);

    //! lastVal
    int lastval = lastVal(q);
    printf("Last value of Queue is : %d\n", lastval);

    //! peek
    int pos = 4;
    printf("Element at position %d is %d\n", pos, peek(q, pos));

    return 0;
}