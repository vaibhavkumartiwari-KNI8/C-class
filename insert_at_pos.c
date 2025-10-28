void insertAtPos()
{
    struct node *newnode, *temp;
    int pos, i=1 , l;
    printf("enter the position to insert :");
    scanf("%d",&pos);
    l = getLength();
    if(pos<0 || pos>l)
    {
        printf("invalid posiition \n");
        return ;

    }
    else if (pos ==1)
    {
        insertAtBeg();
        return ;

    }

    else {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter data want to insert at position :");
        scanf("%d", &newnode->data);
            temp = end->next;
            while(i<pos-1){
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
    }
}

int main()
{
    createCLL();
    displayCLL();
    
}