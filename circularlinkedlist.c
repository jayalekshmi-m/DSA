#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = newNode;  // Point to itself (circular)
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertBegin(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        // Traverse to the last node to link it back to the new head
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;  // Update head to new node
    }
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);
    if (position == 1) {
        insertBegin(head, value);
        return;
    }
    
    struct Node* temp = *head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
        if (temp == *head) break;  // If the list is shorter than position
    }

    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Position is out of bounds!\n");
    }
}

// Function to delete a node from the circular linked list by value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;

    // Case 1: If the node to be deleted is the head
    if (temp->data == value) {
        if (temp->next == *head) {
            free(temp);  // Only one node in the list
            *head = NULL;
            return;
        }
        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        // Make the last node point to the next of head
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }

    // Case 2: Node to be deleted is not the head
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
        if (temp == *head) break;  // If we've looped through the entire list
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", value);
    } else {
        printf("Node with value %d not found.\n", value);
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we complete the circle

    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;  // Start with an empty list
    int option, value, position, n;

    while (1) {
        // Display the menu options
        printf("\nEnter an option:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Display Circular Linked List\n");
        printf("3. Insert Node\n");
        printf("4. Delete Node by Value\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Create Circular Linked List
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &value);
                    insertEnd(&head, value);
                }
                break;

            case 2:
                // Display Circular Linked List
                printf("Linked List: \n");
                display(head);
                break;

            case 3:
                // Insert Node
                printf("Choose an option for insertion:\n");
                printf("1. Insert at the Beginning\n");
                printf("2. Insert at the End\n");
                printf("3. Insert at a Specific Position\n");
                printf("Enter your choice: ");
                int insertOption;
                scanf("%d", &insertOption);

                switch (insertOption) {
                    case 1:
                        // Insert at the Beginning
                        printf("Enter value to insert at the beginning: ");
                        scanf("%d", &value);
                        insertBegin(&head, value);
                        break;

                    case 2:
                        // Insert at the End
                        printf("Enter value to insert at the end: ");
                        scanf("%d", &value);
                        insertEnd(&head, value);
                        break;

                    case 3:
                        // Insert at a Specific Position
                        printf("Enter position to insert at: ");
                        scanf("%d", &position);
                        printf("Enter value to insert at position %d: ", position);
                        scanf("%d", &value);
                        insertAtPosition(&head, value, position);
                        break;

                    default:
                        printf("Invalid option. Returning to the main menu.\n");
                        break;
                }
                break;

            case 4:
                // Delete Node by Value
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 5:
                // Exit the program
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
