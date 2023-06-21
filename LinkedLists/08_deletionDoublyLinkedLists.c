#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    p->next = NULL;
    q->prev = NULL;
    head = q;
    free(p);
    return head;
}

struct Node *deleteInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return head;
}

struct Node *deleteLastNode(struct Node *head)
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    q->next = NULL;
    free(p);
    return head;
}

struct Node *DeleteAtGivenPointer(struct Node *head, struct Node *p)
{
    struct Node *q = head->next;
    while (q->next != p)
    {
        q = q->next;
    }
    q->next = p->next;
    p->next->prev = q;
    free(p);
    return head;
}
int main()
{
    // creating a DLL
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 40;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->data = 50;
    fifth->next = NULL;

    printf("Printing the doubly linked list : \n");
    traversal(head);

    //! inserting at first Node
    printf("\nBefore Deletion : \n");
    traversal(head);
    // head = deleteFirstNode(head);
    // head = deleteInBetween(head, 2);
    // head = deleteLastNode(head);
    head = DeleteAtGivenPointer(head, fourth);
    printf("\n After Deletion : \n");
    traversal(head);
}