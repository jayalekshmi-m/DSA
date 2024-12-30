#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};


struct node *head = NULL, *current = NULL, *deletenode = NULL;
int size = 0;

void display();
void creation();
int insertion();
int deletion();
void insertBeg();
void insertEnd();
void insertAnyPos();
void deleteBeg();
void deleteEnd();
void delAnyPos();

int main() {
    int op;
    do {
        printf("\nEnter an option:\n1.Create \n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                creation();
                break;
            case 2:
                display();
                break;
            case 3:
                insertion();
                break;
            case 4:
                deletion();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Enter a valid option\n");
                break;
        }
    } while (op != 5);

    return 0;
}

void creation() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data to insert: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            current = newnode;
        } else {
            current->next = newnode;
            current = newnode;
        }
        size++; 
    }
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int insertion() {
    int choice;
    printf("\nWhere do you want to insert?\n1. At Beginning\n2. At End\n3. At a Position: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertAnyPos();
            break;
        default:
            printf("Enter a correct choice among the three!!!\n");
    }
    return 0;
}


void insertBeg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    size++; 
}


void insertEnd() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
    size++;  
}


void insertAnyPos() {
    int position;
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position < 1 || position > size + 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertBeg();
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &newnode->data);

    current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }

    newnode->next = current->next;
    current->next = newnode;
    size++;  
}


int deletion() {
    int choice;
    printf("\nWhere do you want to delete?\n1. At Beginning\n2. At End\n3. At a Position: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            deleteBeg();
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            delAnyPos();
            break;
        default:
            printf("Enter a correct choice.\n");
    }
    return 0;
}


void deleteBeg() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
    size--;  
}


void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        free(current->next);
        current->next = NULL;
    }
    size--; 
}


void delAnyPos() {
    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > size) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteBeg();
        return;
    }

    current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }

    deletenode = current->next;
    current->next = deletenode->next;
    free(deletenode);
    size--;  
}