#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function prototypes
struct node* create();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
struct node* deleteNode(struct node *root, int key);
struct node* findMin(struct node *root);

void main() {
    struct node *root;
    root = NULL;
    root = create();
    printf("Preorder is:\n");
    preorder(root);
    printf("Inorder is:\n");
    inorder(root);
    printf("Postorder is:\n");
    postorder(root);

    int key;
    printf("Enter the value to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    printf("Inorder traversal after deletion is:\n");
    inorder(root);
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

    if (x == -1) { // No node for -1 input
        free(newnode);
        return NULL;
    }

    newnode->data = x;
    printf("Enter left child of %d:\n", x);
    newnode->left = create();
    printf("Enter right child of %d:\n", x);
    newnode->right = create();

    return newnode;
}

// Function to perform preorder traversal
void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to perform inorder traversal
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to perform postorder traversal
void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Function to delete a node in the binary tree
struct node* deleteNode(struct node *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    // Search for the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found
        // Case 1: Node has no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node has one child
        else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node has two children
        else {
            // Find the inorder successor (smallest in the right subtree)
            struct node *temp = findMin(root->right);
            root->data = temp->data; // Replace current node's data with successor's data
            root->right = deleteNode(root->right, temp->data); // Delete the successor
        }
    }
    return root;
}

// Function to find the node with the smallest value in a subtree
struct node* findMin(struct node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
