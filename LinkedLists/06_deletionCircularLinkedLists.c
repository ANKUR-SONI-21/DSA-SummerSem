#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    struct Node *p = ptr;
    do
    {
        printf("Element is: %d\n", p->data);
        p = p->next;
    } while (p != ptr);
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    head = p->next;
    free(q);
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
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->next != head)
    {
        p = p->next;
        q = q->next;
    }

    q->next = head;
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
    //! if there are only two nodes left
    if (head == p)
    {
        head = q;
    }
    
    free(p);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = head;

    //before deletion from start
    printf("Before : \n");
    traversal(head);
    printf("\nAfter : \n");
    head = deleteFirstNode(head);
    traversal(head);

    // before deletion at given index
    printf("\nBefore : \n");
    traversal(head);
    printf("\nAfter : \n");
    head = deleteAtIndex(head, 3);
    traversal(head);

    // deleting last node
    printf("\nBefore : \n");
    traversal(head);
    printf("\nAfter : \n");
    head = deletelastNode(head);
    traversal(head);

    printf("\n%d\n", second->data);
    // deleting at given index
    printf("\nBefore : \n");
    traversal(head);
    printf("\nAfter : \n");
    head = deleteAtGivenPointer(head, second);
    traversal(head);
}