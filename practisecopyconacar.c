#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start1=NULL;
struct node *start2=NULL;

void create(int flag)
{
    struct node* start=NULL;
    struct node *temp,*ptr;
    int ch;
    do
    {
        printf("\n Enter the data : ");
        temp=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&temp->data);

        temp->next=NULL;

        if(start==NULL)
            {start=temp;

            }
        else
        {
            ptr->next=temp;

        }
         ptr=temp;

        if(flag==1)
            start1=start;
        if(flag==2)
            start2=start;


        printf("\n Do you want to continue ! : ");
        scanf("%d",&ch);
    }while(ch==1);

    printf("\n LLLLLLLLLLLLLLLLLLLLLLLL");
}

void reverse()
{
   /* struct node *ptr,*ahead,*follow;

    follow=ahead=NULL;

    while(ptr!=NULL)
    {
        ahead=ptr->next;
        ptr->next=follow;
        follow=ptr;
        ptr=ahead;

    }
    start1=follow;*/
    struct node *prev,*current=start1,*next1;
    prev=NULL;
    while(current->next!=NULL)
    {
        next1 = current->next;
        current->next = prev;
        prev = current;
        current=next1;
        //prev=current;
    }
    start1=current;
    //next1=NULL;
    //current->next = NULL;
}

void display(int flag)
{

    struct node *ptr,*start;
    if(flag==1)
        start=start1;
    if(flag==2)
        start=start2;

    while(ptr!=NULL)
    {
        printf("\n \t%d",ptr->data);
        ptr=ptr->next;
    }

}

void main()
{
    create(1);
    reverse();
    display(1);

}
