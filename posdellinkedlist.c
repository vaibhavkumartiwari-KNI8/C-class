#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete node from a specified position
struct Node* deleteFromPos(struct Node* head) {
    struct Node *temp, *nextnode;
    int pos, i = 1;

    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    // Deleting first node
    if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    temp = head;
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);

    return head;
}

int main() {
    struct Node *head = NULL, *newnode, *temp;
    int choice = 1, data;

    // Create linked list
    while (choice) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0/1)? ");
        scanf("%d", &choice);
    }

    printf("\nOriginal List: ");
    display(head);

    // Delete from specified position
    head = deleteFromPos(head);

    printf("After Deletion: ");
    display(head);

    return 0;
}
