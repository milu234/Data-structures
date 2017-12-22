//Singly Linked List
#include<stdio.h>
#include<process.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start= NULL;
struct node *end=NULL ;

void create()
{
    char choice;
    struct node *temp,*ptr,*end;
    do
    {
        printf("\nEnter the data to be inserted: ");
        temp=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&temp->data);
        temp->next=NULL;

        if(start==NULL)
            start=temp;
        else
            end->next=temp;

        end=temp;
        printf("Do you want to add another node? Enter Y for Yes and N for No:  ");
        scanf("%s",&choice);

    }while(choice=='Y' || choice=='y');

}
void insertafter()
{
    int x;
    struct node *temp,*ptr,*end;
    if(start == NULL)
    {
        printf("\nCreate a Linked List.\n");
    }
    else
    {
        printf("\n Enter the value after which the node is to inserted : ");
        scanf("%d",&x);
        ptr=start;
        while(ptr!=NULL && ptr->data!=x)s
            ptr=ptr->next;
        if(ptr==NULL)
            printf("\n The node not found!\n");
        else
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("Enter the value of node to be inserted : ");
            scanf("%d",&temp->data);

            temp->next=ptr->next;
            ptr->next=temp;
            printf("The node inserted Successfully\n");
        }
    }
}

void insertbefore()
{
    int x;
    struct node *temp,*ptr,*end;

    if(start==NULL)
        printf("\nCreate the Linked List.\n");
    else
    {
        printf("\n Enter the value of node before which the data has to be inserted : ");
        scanf("%d",&x);

        ptr=start;
        end=NULL;

        while(ptr!=NULL && ptr->data!=x)
        {
            end=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL)
            printf("Node Not Found.\n");
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("Enter the value of node : ");
            scanf("%d",&temp->data);

            temp->next=end->next;
            end->next=temp;
            printf("Node Inserted successfully\n");
            /*lamlmlmvd;,fmLMF LMLFMMF LLD LML  DLM LMLDMLFADLF*//*ZVP,ZD,,,,*//*DZDZMOMBOM
        }
    }
}

void delete_value()
{
    int x;
    struct node *temp,*ptr,*end;

    if(start == NULL)
        printf("\n The List is Empty!");
    else
    {
        printf("\nEnter the value to be deleted: ");
        scanf("%d",&x);
        ptr=start;
        end=NULL;

        while(ptr!= NULL && ptr->data!=x)
        {
            end=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL)
            printf("Node Not Found.\n");
        else
        {
            if(ptr==start)
                start=start->next;
            else
            end->next=ptr->next;
                free(ptr);

                printf("Node Deleted successfully\n");
        }
    }
}
void delete_position()
{
    int p,i;
    struct node *temp,*ptr;

    if(start==NULL)
        printf("\n The List is Empty.\n");
    else
    {
        printf("\n Enter the position of the node to be deleted: ");
        scanf("%d",&p);
        if(p==0)
        {
            ptr=start;
            start=start->next;
            printf("The deleted element is %d\n",ptr->data);
            free(ptr);
        }
        else
        {
            ptr=start;
            for(i=0;i<p;i++)
            {
                temp=ptr;
                ptr=ptr->next;
                if(ptr==NULL)
                {
                    printf("The Position not found.\n");
                    return;
                }
            }
            temp->next=ptr->next;
            printf("The deleted node is %d\n",ptr->data);
            free(ptr);

            printf("The Node deleted successfully.\n");
        }
    }
}
void insert_position()
{
    struct node *temp,*ptr;
    int p,i,count=0;
    if(start==NULL)
        printf("\nCannot be inserted.");
    else
    {
        printf("\nEnter the position at which data has to be inserted: ");
        scanf("%d",&p);

        ptr=start;
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->next;
        }

        if(p>0 && p<=count+1)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter the data to be inserted: ");
            scanf("%d",&temp->data);
            if(p==1)
            {
                temp->next=start;
                start=temp;
            }
            ptr=start;
            for(i=1;i<=p-2;i++)
                ptr=ptr->next;

            temp->next=ptr->next;
            ptr->next=temp;
            printf("Node insertion done at position\n");
        }
        else
            printf("Position is invalid");
    }
}
void search()
{
     int x;
    struct node *ptr,*end;
    printf("\nEnter the data to be searched: ");
    scanf("%d",&x);
    ptr=start;

    while(ptr!=NULL && ptr->data!=x)
        ptr=ptr->next;

    if(ptr==NULL)
        printf("Node with data %d not found",x);
    else
        printf("Node with %d node found",x);
}
void display()
{
    struct node *ptr;
    if(start==NULL)
        printf("\nLIST IS EMPTY");
    else
    {
        printf("\nLINKED LIST IS:  ");
        ptr=start;

        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}

void insert()
{
    int ch;
    do
    {
        printf("\n1. INSERT BEFORE\n");
        printf("2. INSERT AFTER\n");
        printf("3. INSERT AT POSITION\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                insertbefore();
                break;
            case 2:
                insertafter();
                break;
            case 3:
                insert_position();
                break;
            case 4 :
                printf("EXITING.");
                break;
        }
    }
    while(ch!=4);

}

void deletes()
{
    int ch;
    do
    {
        printf("1. DELETE BY VALUE\n");
        printf("2. DELETE BY POSITION\n");
        printf("3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            delete_value();
            break;
        case 2:
            delete_position();
            break;
        case 3:
            printf("EXITING.");
            break;
        }
    }
    while(ch!=3);

}

void main()
{


int choice;
    do
    {
        printf("\n***** MENU ******\n");
        printf("\n1  CREATE LINKED LIST");
        printf("\n2  INSERT AN ELEMENT");
        printf("\n3  DELETE AN ELEMENT");
        printf("\n4  SEARCH");
        printf("\n5  DISPLAY");
        printf("\n6  EXIT");
        printf("\nEnter your choice:  ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            create();
            break;
        case 2 :
            insert();
            break;
        case 3 :
            deletes();
            break;
        case 4:
            search();
           break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
        default:
            printf("\nInvalid input\n");
            break;
        }

    }while(choice!=6);
}
