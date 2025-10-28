
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

// Function to delete node from end (as per your notebook logic)
struct Node* deleteFromEnd(struct Node* head) {
    struct Node *prevnode, *temp;
    temp = head;

    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }

    while (temp->next != NULL) {
        prevnode = temp;
        temp = temp->next;
    }

    if (temp == head) {   // Only one node in list
        head = NULL;
        free(temp);
    } else {
        prevnode->next = NULL;
        free(temp);
    }

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

    // Delete from end
    head = deleteFromEnd(head);

    printf("After Deletion from End: ");
    display(head);

    return 0;
}
