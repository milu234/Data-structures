#include<stdio.h>
struct node *temp,*ptr;
struct node *front =NULL;
struct node *rear=NULL;

int e,c=0;

#define Max 10

struct node
{
    int data;
    struct node *next;
};

struct node *newnode()
{
    return(struct node *)malloc(sizeof(struct node));
};

void deletenode(struct node *ptr)
{
    ptr->next=NULL;
    free(ptr);
}

int main()
{
    int ch;
    do
    {
        printf("\n----------Linear Queue operations-----------");
        printf("\n 1. INSERT ");
        printf("\n 2. DELETE ");
        printf("\n 3. PEEK FRONT ");
        printf("\n 4. DISPLAY ");
        printf("\n 5. EXIT ");
        printf("\n---------------------------------------");
        printf("\n Enter your choice ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            if(c==Max)
            {
                printf("\n Queue is not Empty!!!");
                break;

            }
            printf("\n Enter the data to  be entered : ");
            scanf("%d",&e);
            insert_q(e);
            break;
        case 2:
        if(front==NULL)
        {
            printf("\n The Queue is empty!!");
            break;
        }
            printf("\nThe Deleted element from the queue is : %d",delete_q());
            break;
        case 3:
            printf("\n The element in the front is : %d",peek());
            break;
        case 4:
            printf("\n The elements of the Queue are as follows: ");
            display();
            break;
        }
    }while(ch!=5);
}

void insert_q(int e)
{
    temp=newnode();
    temp->data=e;
    temp->next=NULL;

    if(front==NULL && rear==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    c++;
}

int delete_q()
{

    if(front==NULL && rear==NULL)
    {
        printf("\n theQueue is Empty !!!");
        return;
    }
    e=front->data;

    if(front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->next;
    }
    return e;
}

void display()
{
    if(front ==NULL && rear==NULL)
    {
        printf("\n The Queue is Empty !!!");
        return;
    }
    ptr=front;
    while(ptr!=NULL)
    {
        printf("\n %d",ptr->data);
        ptr=ptr->next;
    }
}

int peek()
{
    int e=front->data;
    return e;
}
