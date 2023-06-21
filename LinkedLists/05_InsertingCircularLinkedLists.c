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

struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    // struct Node *p = head->next;
    // struct Node *q = head;
    // while (p != head)
    // {
    //     p = p->next;
    //     q = q->next;
    // }
    // q->next = head;
    // free(p);
    // return head;

    struct Node *p = head->next;
    struct Node *q = head;
    while (p->next != head)
    {
        p = p->next;
        q = q->next;
    }
    ptr->next = p;
    q->next = ptr;
    return head;
}

struct Node *insertAfterPointer(struct Node *head, int data, struct Node *p)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = p->next;
    p->next = ptr;
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
    fourth->next = head;

    // traversal(head);

    // Insertion at beginning
    printf("Before : \n");
    traversal(head);
    printf("\nAfter : \n");
    head = insertAtStart(head, 10);
    traversal(head);

    // insertion in between\n
    printf("\nBefore : \n");
    traversal(head);
    printf("\nAfter : \n");
    head = insertInBetween(head, 20, 3);
    traversal(head);

    // insertion at end
    printf("\nBefore : \n");
    traversal(head);
    printf("\nAfter : \n");
    head = insertAtEnd(head, 30);
    traversal(head);

    // insertion after given pointer
    printf("\nBefore : \n");
    traversal(head);
    printf("\nAfter : \n");
    head = insertAfterPointer(head, 40, second);
    traversal(head);
}