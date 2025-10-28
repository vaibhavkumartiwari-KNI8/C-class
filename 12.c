#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};


    struct node *newnode,*head,*temp;

struct node* insertAtBeg(struct node *head,int val);
newnode->data=data;
newnode->next=head;
head = newnode;
return head;

}
int main()
{
        struct node *head=NULL;
        int choice=1;
        while(choice)
        {

struct node *newnode = (struct node*)malloc(sizeof(struct node));
printf("enter data:");
scanf("%d",&newnode->data);
newnode->next = NULL;
}
if(head == NULL)
{
    head = temp=newnode;
}
else {
    temp->next = newnode;
    temp=newnode;
}

printf("do you want to continue 0/1?:");
scanf("%d",&choice);
        

        int val;
        printf("enter the value to insert in the begiinning :");
        scanf("%d",&val);
        head = insertAtBeg (head,val);

        printf("linked list:");
        temp = head;                    
        while(temp!=NULL)
        {
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
        return 0;

    }
      