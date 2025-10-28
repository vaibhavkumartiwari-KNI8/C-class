#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete node from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;   // Move head to next node
    free(temp);          // Free old head
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

    // Delete from beginning
    head = deleteFromBeginning(head);

    printf("After Deletion from Beginning: ");
    display(head);

    return 0;
}
