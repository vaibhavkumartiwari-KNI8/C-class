#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *newnode, *temp;

// Function: Insert at Position
struct node* insertAtPos(struct node *head, int pos, int val) {
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    if(pos == 1) {
        newnode->next = head;
        head = newnode;
        return head;
    }

    temp = head;
    int i;
    for(i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid Position. Insertion at end.\n");
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

int main() {
    struct node *head = NULL;
    int choice = 1;

    // Creating Linked List
    while(choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue 0/1?: ");
        scanf("%d", &choice);
    }

    // Insert at Position
    int pos, val;
    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("Enter the value to insert: ");
    scanf("%d", &val);
    head = insertAtPos(head, pos, val);

    // Traversal
    printf("Linked List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}
