#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

struct Node *connectNode(struct Node *root, struct Node *l, struct Node *r)
{
    root->left = l;
    root->right = r;
    return root;
}

int search(struct Node *root, int data)
{
    if (root != NULL)
    {
        if (root->data == data)
        {
            return 1;
        }
        else if (root->data > data)
        {
            search(root->left, data);
        }
        else
        {
            search(root->right, data);
        }
    }
}

struct Node *insertElement(struct Node *root, int data)
{
    struct Node *temp = root;
    while (root != NULL)
    {
        if (root->data == data)
        {
            printf("Duplicate Not Allowed!\n");
            return temp;
        }
        else if (root->data > data)
        {
            if (root->left == NULL)
            {
                struct Node *newNode = createNode(data);
                root = connectNode(root, newNode, root->right);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else if (root->data < data)
        {
            if (root->right == NULL)
            {
                struct Node *newNode = createNode(data);
                root = connectNode(root, root->left, newNode);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return temp;
}

void print(struct Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf(" %d\n", root->data);
        print(root->right);
    }
}
int main()
{
    struct Node *p = createNode(9);
    struct Node *p1 = createNode(4);
    struct Node *p2 = createNode(11);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(7);
    struct Node *p5 = createNode(5);
    struct Node *p6 = createNode(8);
    struct Node *p7 = createNode(15);
    struct Node *p8 = createNode(16);

    p = connectNode(p, p1, p2);
    p1 = connectNode(p1, p3, p4);
    p2 = connectNode(p2, NULL, p7);
    p4 = connectNode(p4, p5, p6);
    p7 = connectNode(p7, NULL, p8);

    insertElement(p, 1);
    print(p);
    return 0;
}