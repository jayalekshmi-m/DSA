#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function prototype
struct node* create();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);


void main() {
    struct node *root;
    root = NULL;
    root = create();
    printf("preorder is:");
    preorder(root);
    printf("inorder is:");
    inorder(root);
    printf("postorder is:");
    postorder(root);
}

// Function to create a binary tree
struct node* create() {
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) { // Corrected condition to match your intention
        return NULL; // No node for -1 input
    }

    newnode->data = x;
    printf("Enter left child of %d:\n", x);
    newnode->left = create();
    printf("Enter right child of %d:\n", x);
    newnode->right = create();

    return newnode;
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else 
    {
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else 
    {
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}
