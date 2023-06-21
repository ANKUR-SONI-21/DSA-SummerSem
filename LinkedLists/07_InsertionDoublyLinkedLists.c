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

struct Node *insertAtFirstNode(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    head = ptr;
    return head;
}

struct Node *insertInbetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    ptr->next = q;
    ptr->prev = p;
    p->next = ptr;
    q->prev = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->prev = p;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct Node *insertAfterGivenPointer(struct Node *head, int data, struct Node *p)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = p->next;
    ptr->prev = p;
    p->next->prev = ptr;
    p->next = ptr;
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
    printf("\nBefore Insertion : \n");
    traversal(head);
    // head = insertAtFirstNode(head, 0);
    // head = insertInbetween(head, 60, 2);
    //head = insertAtEnd(head, 70);
    head = insertAfterGivenPointer(head,80,third);
    printf("\n After Insertion : \n");
    traversal(head);
}