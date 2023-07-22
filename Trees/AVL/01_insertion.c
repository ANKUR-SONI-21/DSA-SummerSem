#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

struct node *createNode(int key)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalanceFactor(struct node *root)
{
    if (root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

struct node *leftRotate(struct node *root)
{
    struct node *newRoot = root->right;
    struct node *newRootLeft = newRoot->left;

    newRoot->left = root;
    root->right = newRootLeft;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

struct node *rightRotate(struct node *root)
{
    struct node *newRoot = root->left;
    struct node *newRootRight = newRoot->right;

    newRoot->right = root;
    root->left = newRootRight;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

struct node *insert(struct node *root, int key)
{
    // Perform the normal BST insertion
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;
    // Update height of this ancestor node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balanceFactor = getBalanceFactor(root);

    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balanceFactor > 1 && key < root->left->key)
        return rightRotate(root);
    // Right Right Case
    if (balanceFactor < -1 && key > root->right->key)
        return leftRotate(root);
    // Left Right Case
    if (balanceFactor > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    if (balanceFactor < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inOrder(struct node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    printf("Inorder traversal of the constructed AVL tree is \n");
    inOrder(root);
    return 0;
}