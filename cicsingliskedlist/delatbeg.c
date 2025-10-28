#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next;

};

struct node* addToEmpty(int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next =temp;
    return temp;
}

struct node* addAtEnd(struct node* tail, int data)
{
    struct node* newp = malloc(sizeof(struct node));
    newp->data = data;
    newp->next =NULL;

    newp->next = tail->next;
    tail->next = newp;
    tail = tail->next;
    return tail;
}

struct node* createList(struct node* tail)
{
    int i,n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if(n==0)
        return tail;
    printf("Enter the elements: \n");
    scanf("%d",&data);
    tail = addToEmpty(data);

        for(i=1;i<n;i++)
        {
            printf("Enter the element %d:",i+1);
            scanf("%d",&data);
            tail = addAtEnd(tail,data);
            

        }
        return  tail;
    
    
}
void print(struct node* tail)
{
    if(tail==NULL)
    printf("No node in the list");
    else{
        struct node* p=tail->next;
        do
        {
            printf("%d ",p->data);
            p=p->next;
        }while(p!=tail->next);}
        printf("\n");
    
}
//deleting first node
struct node* delFirst(struct node* tail)
{
    if(tail==NULL)
    return tail;
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node* temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
}

int main()
{
    struct node* tail=NULL;
    tail=createList(tail);
    printf("\nList before Deletion:");
    print(tail);
    
    tail=delFirst(tail);
    printf("List after Deletion;");
    print(tail);
    return 0;
}

