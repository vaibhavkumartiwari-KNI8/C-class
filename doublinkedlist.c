#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode;

void create()
{
    head = 0;
    struct node *temp;
    int choice = 1;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data = ");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do you want to continue (1/0): ");
        scanf("%d", &choice);
    }
}

void display()
{
    struct node *temp;
    temp = head;

    printf("Doubly Linked List elements are:\n");
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    create();
    display();
    return 0;
}
