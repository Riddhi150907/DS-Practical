
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void deleteBeginning() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    printf("Deleted node: %d\n", temp->data);
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted node: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    struct Node *last = temp->next;
    printf("Deleted node: %d\n", last->data);

    temp->next = NULL;
    free(last);
}

void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, value;

    do {
        printf("\n--- SINGLY LINKED LIST DELETION ---\n");
        printf("1. Insert at End (for testing)\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 2:
                deleteBeginning();
                break;

            case 3:
                deleteEnd();
                break;

            case 4:
                display();
                break;

            case 0:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
