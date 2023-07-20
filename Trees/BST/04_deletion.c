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

struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    //!we want the largest element to replace the deleted element
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deleteElement(struct Node *root, int data)
{
    struct Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    //! condition for leaf node
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    //! searching for the Node
    if (data < root->data)
    {
        root->left = deleteElement(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteElement(root->right, data);
    }
    //! when data is same
    else
    {
        //! finding the next predecessor
        iPre = inOrderPredecessor(root);
        //! copying its data
        root->data = iPre->data;
        //! using recusrsion to copy all the nodes one by one until root==null
        root->left = deleteElement(root->left, iPre->data);
    }
    return root;
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

    p = deleteElement(p, 4);
    print(p);
    return 0;
}