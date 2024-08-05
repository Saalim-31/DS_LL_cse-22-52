#include<stdio.h>
#include<stdlib.h>

 struct node{
    char Name[100];
    int roll_no;
    float marks;

    struct node *next;
} Node;

Node *Head = NULL, *Tail = NULL;


void Create()
{
    int n;
    Node *temp;

    cout << "Enter the Number of Students : ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        temp = (Node *) malloc(sizeof(Node));

       printf( "--------------------------------------" endl);

         printf( "Enter the Name of Student : ");
        scanf("%d", &temp->Name);

        printf( "-------------------------------------- /n" );

         printf( "Enter the Roll No of Student : ");
       scanf("%d", &temp -> roll_no);

         printf( "--------------------------------------/n");

        printf( "Enter the Total Marks of student : ");
       scanf("%d", &temp -> marks);

        temp -> next = NULL;

        if(Head == NULL)
        {
            Head = temp;
            Tail = temp;
        }
        else{
            Tail -> next = temp;
            Tail = temp;
        }
        }

}

void View()
{
    Node *trav = Head;

    while(trav != NULL)
    {
       printf("--------------------------------------") ;
       printf( "Name : %d \n" , trav -> Name );
       printf( "Roll No : %d \n", trav -> roll_no );
       printf("Marks : %d \n"  ,trav -> marks );
        printf "--------------------------------------" << endl;

        trav = trav -> next;
    }

}

//Students whose Marks are Less than 50 ..
void Find()
{
    Node *trav = Head;

    while(trav != NULL)
    {
        if(trav ->marks < 50)
        {
            printf ("--------------------------------------" ;
           printf ("Name : %D" ,trav -> Name );
            printf ("Roll No %d: ", trav -> roll_no) ;
           printf( "Marks : %d"  trav -> marks );
           printf("--------------------------------------") ;

        }
        trav = trav -> next;
    }
}


//Get Students whose Marks are Above Given Number ..
void Greatest()
{
    Node *trav = Head;
    int n;

   printf( "Enter the Range from which you want to Get : ");
    scanf("%d", &n);

    while(trav != NULL)
    {
        if(trav -> marks > n)
        {
           printf("--------------------------------------" );
           printf ("Name : %d" ,trav -> Name );
            printf ("Roll No %d: ",trav -> roll_no );
            printf("Marks : &d",trav -> marks );
            printf("--------------------------------------" );
        }
        trav = trav -> next;
    }
}

//Get Student by Roll No ..
void Get_by_Roll()
{
    Node *trav = Head;

    int roll;
    printf( "Enter the Roll No of Student you want to get : ");
    scanf("%d", &roll);

    while(trav != NULL)
    {
        if(trav -> roll_no == roll)
        {
           printf ("--------------------------------------" );
            printf ("Name : %d", trav -> Name );
            printf ("Roll No %d: ", trav -> roll_no );
           printf("Marks : %d" , trav -> marks);
            printf("--------------------------------------" );
        }
        trav = trav -> next;
    }
}

int main()
{
    int choice;
    
    while(1)
    {
        printf("1 for Create Student Data\n2 for View Student Data\n3 for Students < 50 Marks\n4 for Greatest Marks\n5 for Get Student by Roll No\n6 for EXIT\nEnter your choice : ");
       scanf("%d", &choice);

        if(choice == 1)
            Create();
        if(choice == 2)
            View();
        if(choice == 3)
            Find();
        if(choice == 4)
            Greatest();
        if(choice == 5)
            Get_by_Roll();
        if(choice == 6)
            break;
    }

    return 0;
}
