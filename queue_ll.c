#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    int n, i, value;
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;

        if (front == NULL && rear == NULL) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Underflow condition.\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted element is %d\n", front->data);
    front = front->next;

    // if (front == NULL) {
    //     rear = NULL; // Queue is now empty
    // }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *temp = front;
    printf("Elements in the queue are: \n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty. Underflow condition.\n");
    } else {
        printf("Element at the front is %d\n", front->data);
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
// implementation of queue using linked list