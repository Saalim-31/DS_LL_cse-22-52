#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};
struct node *head=NULL, *tail=NULL, *trav=NULL;


//Creating Linked List
void create()
{
    int n;
    struct node *temp;

    printf("Enter the Number of Nodes to Insert : ");
    scanf( "%d",&n);

    for(int i=0; i<n; i++)
    {
        temp = (struct node *) malloc(sizeof(struct node));
        
       prinntf( "Enter the Elements : ");
        scanf("%d",&temp -> data);

        temp -> next = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else {
            tail -> next = temp;
            tail = temp;
        }
    }
}

//View Linked List
void view()
{
    struct node *trav;

    trav = head;

    while(trav != NULL)
    {
      printf( "%d",trav -> data ) ;
        trav = trav -> next;
    }
}

//Inster Element in Linked List
void insert()
{
    int value;
    struct node *trav, *temp;
    temp = (struct node *) malloc (sizeof(struct node));

    temp -> next = NULL;

    printf( "Enter the Value you want to Insert : ");
    scanf( "%d",&temp -> data);

    printf( "Enter the Value After which you want to Insert : ");
    scanf("%d",  &value);

    trav = head;

    while (trav -> data != value)
    {
        trav = trav -> next;
    }
    temp -> next = trav -> next;
    trav -> next = temp;
}

//Delete any Element from Linked List
void Delete()
{
    int item;
    struct node *temp;
    printf( "Enter the Node to Delete : ");
    scanf("%d", &item);

    //Deleting Head
    if(head -> data == item)
    {
        temp = head -> next;
        free(temp);
    }
    else
    {
        trav = head;
        while (trav -> next ->data != item)
        {
            trav = trav -> next;
            temp = trav -> next;
        }

        if(trav -> next == tail)
        {
            trav -> next = NULL;
            free(temp);
        }
        else
        {
            trav -> next = trav -> next -> next;
            free(temp);
        }
        
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf( "Enter the Choice\n1 for create\n2 for View\n3 for Insert\n4 for Delete\n5 for Exit\nEnter the Choice : ");
        scanf("%d", &ch);

        if(ch == 1) create();
        if(ch == 2) view();
        if(ch == 3) insert();
        if(ch == 4) Delete();
        if(ch == 5) break;
    }
}
