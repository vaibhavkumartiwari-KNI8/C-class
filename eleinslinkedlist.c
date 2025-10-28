#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node* next;
};
struct node *newnode, *temp;
// Function: Insert at Beginning
struct node* insertAtBeg(struct node *head, int val) {
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = val;
newnode->next = head;
head = newnode;
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
// Insert at Beginning
int val;
printf("Enter the value to insert at beginning: ");
scanf("%d", &val);
head = insertAtBeg(head, val);
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