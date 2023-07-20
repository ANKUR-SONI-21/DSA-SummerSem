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

int checkBinaryTree(struct Node *root)
{
    static int temp = 0;
    if (root != NULL)
    {
        checkBinaryTree(root->left);
        //! we know that inorder traversal of BST
        //! returns an array of ascending items therefore
        //! we are conmparing the previous element with the new one
        //! using static int temp which retains the old info
        if (temp > root->data)
        {
            return 0;
        }
        temp = root->data;
        printf("%d\n", root->data);
        checkBinaryTree(root->right);
    }
    else
    {
        return 1;
    }
}

//! better version
int checkBinaryTree(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!checkBinaryTree(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return checkBinaryTree(root->right);
    }
    else    
        return 0;
}
int main()
{
    //! making a function for it....
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

    if (checkBinaryTree(p))
    {
        printf("YES, the given tree is a Binary Search Tree!\n");
    }
    else
    {
        printf("NO, the given tree is NOT a Binary Search Tree!\n");
    }
    return 0;
}