#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* insertat beg(struct node *head,int data)
{
    struct node newnode=(struct node)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    return head;
}
int main(){
    struct node *head=NULL;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

    }
    if (head==NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    printf("Do you want to continue(0,1):");
    scanf("%d",&choice);
    int val;
    printf("Enter the value to insert at beginning:");
    scanf("%d",&val);
    head=insertatbeg(head,val);
    printf("The linked list is:");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }