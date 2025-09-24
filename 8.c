/*
 singly linkedlist 
in form of nodes pehla node ka address 100
head pointer points to first node 
first node contains data column and next  column 
points to 7 in data 
next pe 200 
dusre node ka address 200
dusre node me data column me 8 hoga 
pr pehle ke next column me 200 store hoga 
and this on and on and on
first se last tk traverse kr skte h 

doubly linked list 
TWO WAY POINTERSW 
 head -- pre/data/next ---pre/data/next---pre/data/next---NULL
 first pre me null rhega 
 head to last transversal and also vice versa 


*/

/*
advantages of linked list
1. Dynamic size that can grow and shrink as needed
2. Efficient insertions and deletions without shifting elements
3. Better memory utilization for unpredictable data sizes ,
no  memory wastage due to dynamic alloacation
4.flexible memory usage with non contiguous storage
5. suotable for implementing structures like stacks, queues.
6. easily supports complex data structures like  circular and doubly linked lists (graphs and hash tables)


disadvantages of linked list
1. Increased memory usage due to storing pointers
2. sequencial access only no direct indexing 
3. cannot perform random access on elements 
4. more complex to implement and manage pointers 
5. traversing the list can be slower duw to pointer chasing and lack of locality 

*/

/*
data 
this part holds the actual information or value of the node 
it can be any type of data like integer, float, character, or even complex structures.

pointer 
this part stores the address of the next node in the linkedlist
in a singly linked list there is one pointer to the next node 
in a doubly linked list there are two pointers 
one pointing to the next node and another pointing to the previous node 
*/

/*
 struct node {
    int data;
    struct node* next;
}
    use malloc to allocate memory for new nodes

    new node=(struct node*)(malloc(sizeof(struct node)))
    printf("enter data")
    scanf("%d",&new node->data)

    newnode nest =o

    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
    */