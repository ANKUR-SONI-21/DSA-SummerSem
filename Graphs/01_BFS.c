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
    if (q->r + 1 == q->size)
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

    // BFS implementation
    //! Adjecency matrix of the graph
    int A[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1, 0, 0},
                   {1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    //! Visited array 
    //* all are marked as unvisited initially!
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    //! Starting node
    int sourceNode = 3;
    //! printing the source node
    printf("%d ", sourceNode);
    //! marking the source node as visited
    visited[sourceNode] = 1;
    //! enqueueing the source node
    enqueue(q, sourceNode); //^enqueue for exploring the neighbours of the source node

    //! Exploring the neighbours of the source node
    while (!isEmpty(q))
    {
        int u = dequeue(q); //^dequeue for exploring the neighbours of the source node
        for (int v = 0; v < 7; v++)
        {   
            //! searching for all the elements that are connected to the source node
            //! and are unvisited
            if (A[u][v] == 1 && visited[v] == 0)
            {
                //! printing the elements connected to node;
                printf("%d ", v);
                //! marking the elements connected to node as visited
                visited[v] = 1;
                //! enqueueing the elements connected to node for exploring their neighbours
                enqueue(q, v); //^enqueue for exploring the neighbours of the source node
                //? this will continue until all the elements connected to the source node are visited
            }
        }
    }



    return 0;
}