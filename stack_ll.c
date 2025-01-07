#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Function to push an element onto the stack
void push() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed. Stack overflow.\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
}

// Function to pop an element from the stack
void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Underflow condition. Stack is empty.\n");
    } else {
        temp = top;
        printf("Popped element is %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Function to display the top element of the stack
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Function to display all elements of the stack
void display() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        temp = top;
        printf("Elements are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

// Main function to provide menu-driven functionality
int main() {
    int choice;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exited from program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
// implementation of stack using liked list
