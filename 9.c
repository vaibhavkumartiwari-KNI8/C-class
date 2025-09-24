#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int main()
{
    struct node *newcode,*head =NULL,*temp;
    int choice=1;
    while(choice)
    {
        newcode=(struct node*)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newcode->data);
        newcode->next=NULL;
        if(head==NULL)
        {
            head=newcode;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newcode;
        }
        printf("do you want to continue(0,1)");
        scanf("%d",&choice);

    }
    printf("the linked list is\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }               
