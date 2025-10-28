#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Traversal
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Insert at position
void insertAtPosition(struct Node** head, int pos, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos-1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete at end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Delete at position
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; i < pos-1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL || temp->next == NULL) return;
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 2, 15);
    printf("Singly Linked List after insertions: \n");
    traverse(head);

    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteAtPosition(&head, 2);
    printf("Singly Linked List after deletions: \n");
    traverse(head);

    return 0;
}
