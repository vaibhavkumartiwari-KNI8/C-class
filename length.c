#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;              // Data part
    struct node* next;     // Pointer to next node
};

// Function to calculate length
int getLength(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct node *newnode, *head = NULL, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0/1)?: ");
        scanf("%d", &choice);
    }

    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Call getLength function
    int length = getLength(head);
    printf("Length of linked list is: %d\n", length);

    return 0;
}
