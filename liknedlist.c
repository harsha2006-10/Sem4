#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void delete() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node * temp = head;
        head = head->next;
        free(temp);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        printf("Linked List: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\n4. Insert at Beginning\n5. Delete\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                display();
                break;

            case 3:
                return 0;

            case 4:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 5:
                delete();
                break;

            default:
                printf("Invalid choice\n");
        }
    }
}