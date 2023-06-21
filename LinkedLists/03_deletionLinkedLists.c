#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *p)
{
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *p = head;
    head = p->next;
    free(p);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deletelastNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (q->next != p)
    {
        q = q->next;
    }

    q->next = NULL;
    free(p);
    return head;
}

struct Node *deleteAtGivenPointer(struct Node *head, struct Node *p)
{
    struct Node *q = head;
    while (q->next != p)
    {
        q = q->next;
    }

    q->next = p->next;
    free(p);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    // before deletion from start
    printf("Before : ");
    traversal(head);
    printf("\nAfter : ");
    head = deleteFirstNode(head);
    traversal(head);

    // before deletion at given index
    printf("\nBefore : ");
    traversal(head);
    printf("\nAfter : ");
    head = deleteAtIndex(head, 2);
    traversal(head);

    // deleting last node
    printf("\nBefore : ");
    traversal(head);
    printf("\nAfter : ");
    head = deletelastNode(head);
    traversal(head);

    // deleting at given index
    printf("\nBefore : ");
    traversal(head);
    printf("\nAfter : ");
    head = deleteAtGivenPointer(head, second);
    traversal(head);
}