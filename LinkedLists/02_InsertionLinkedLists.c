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
struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

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

    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
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
    //*creating pointers
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //*intialising all nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //*linking all nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    // Insertion at beginning
    printf("Before : ");
    traversal(head);
    printf("\nAfter : ");
    head = insertAtStart(head, 10);
    traversal(head);

    // insertion in between
    printf("\nBefore : ");
    traversal(head);
    printf("\nAfter : ");
    head = insertInBetween(head, 20, 2);
    traversal(head);

    // insertion at end
    printf("\nBefore : ");
    traversal(head);
    printf("\nAfter : ");
    head = insertAtEnd(head, 30);
    traversal(head);

    // insertion after given pointer
    printf("\nBefore : ");
    traversal(head);
    printf("\nAfter : ");
    head = insertAfterPointer(head, 40, second);
    traversal(head);
}