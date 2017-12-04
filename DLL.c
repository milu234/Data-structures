#include<stdio.h>
#include<process.h>
#include<stdlib.h>
int c=0;
struct node
{
    int data;
    struct node*next;
    struct node*pre;
};
struct node *start=NULL;
struct node *temp,*ptr,*ptrbefore;

struct node *newnode()
{
    return(struct node *)malloc(sizeof(struct node));
};

void deletenode(struct node *ptr)
{
    ptr->next=NULL;
    ptr->pre=NULL;
    free(ptr);
}

void create()
{
    char choice;
    struct node *temp,*end;
    end=NULL;
    do
    {

        printf("\n Enter the data to be inserted : ");
         temp=newnode();
        scanf("%d",&temp->data);

        temp->next=NULL;
        temp->pre=NULL;

        if(start==NULL)
        {
            start=temp;
        }
        else
        {
           end->next=temp;
           temp->pre=end;
        }
        end=temp;
        c++;

        printf("\n Do You want to Insert more data? : ");
        scanf("%s",&choice);


    }while(choice=='y'||choice=='Y');
    printf("\n The No. of Nodes Created = %d \n",c);
}

void displayl()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\n Create a List!!!!");
    }
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
              printf("\t%d",ptr->data);
            ptr=ptr->next;

        }
    }
}

void insert_at_pos()
{
    int p,i;
    struct node *temp,*ptr;

    if(start==NULL)
    {
        printf("\n Create A New !!!");
    }
    else
    {
        printf("\n Enter the position : ");
        scanf("%d",&p);

        temp=newnode();
        printf("\n Enter the data to be inserted : ");
        scanf("%d",&temp->data);

        if(p==1)
        {
            temp->next=start;
            temp->pre=NULL;
            start->pre=temp;
            start=temp;
        }
        else
        {
            ptr=start;
            for(i=1;i<=p-2;i++)
            {
                ptr=ptr->next;
            }
            temp->pre=ptr;
            temp->next=ptr->next;
            ptr->next=temp;
            if(temp->next!=NULL)
            {
                temp->next->pre=temp;
            }

        }
    }
}

void insert_before_value()
{
    struct node *ptr,*temp,*ptrbefore;
    int num;

    if(start==NULL)
    {
        printf("\n Create A New List!!!");
    }
    else
    {
        printf("\n enter the value before which you want to insert the value : ");
        scanf("%d",&num);
        ptr =start;

        while(ptr->next!=NULL && ptr->data!=num)
        {
            ptr=ptr->next;
        }

        if(ptr->data==num)
        {
            temp=newnode();
            printf("\n Enter the data you want to insert : ");
            scanf("%d",&temp->data);


            if(ptr==start)

            {
                temp->next=start;
                temp->pre=start->pre;
                start->pre=temp;
                start=temp;
            }
            else
            {
                temp->next=ptr;
                temp->pre=ptr->pre;
                ptr->pre=temp;
                if(temp->pre!=NULL)
                {
                    temp->pre->next=temp;
                }
                else
                {
                    start=temp;
                }

            }
        }
        else
        {
            printf("\n Element not Found!!!");
        }
    }

}

void insert_after_value()
{

    int num;
    struct node *ptr,*temp;
    if(start==NULL)
    {
        printf("linked list not created");
    }
    else
    {
        printf("\nenter the value after which to be inserted");
        scanf("%d",&num);

        ptr=start;
        int pos=1;
        while(ptr->data!=num&&ptr->next!=NULL)
        {
            ptr=ptr->next;
            pos++;

        }
        if((ptr->data)==num)
        {
            printf("\nelement found at %d",pos);
            temp=newnode();
            printf("\n enter the data = ");
            scanf("%d",&temp->data);
            temp->next=ptr->next;
            temp->pre=ptr;
            ptr->next=temp;
            if(temp->next!=NULL)
            {
                temp->next->pre=temp;
            }

        }
        else
        {
            printf("\nelement not found");
            return;
        }





    }
}

void delete_by_value()
{
    struct node *temp,*ptr;
    int num;

    if(start==NULL)
    {
        printf("\n Create a new List !!!");
    }
    else
    {
        printf("\n Enter the value to be deleted : ");
        scanf("%d",&num);

        ptr=start;
        while(ptr->data!=num && ptr->next!=NULL)
        {
            ptr=ptr->next;
        }

        if(ptr->data==num)
        {
            printf("\n Value found");
        }
        if(ptr->next!=NULL)
        {
            ptr->next->pre=ptr->pre;
        }
        if(ptr->pre!=NULL)
        {
            ptr->pre->next=ptr->next;
        }
        if(ptr==start)
        {
            if(ptr->next==NULL)
            {
                start=NULL;
            }
            else
            {
                start=start->next;
            }
            deletenode(ptr);

            printf("\n Deleted Successfully!!!");
        }






    }
}

void delete_by_pos()
{
    int p,i;
    struct node *temp,*ptr;

    if(start==NULL)
    {
        printf("\n Create a New List!!!");
    }
    else
    {
        printf("\n enter the position  from where the data has to be deleted :   ");
        scanf("%d",&p);

        ptr=start;

        for(i=1;i<=p-1;i++)
        {
            ptr=ptr->next;
        }
        printf("\nThe value just got deleted is  %d\n",ptr->data);

        if(ptr->next!=NULL)
        {
            ptr->next->pre=ptr->pre;
        }
        if(ptr->pre!=NULL)
        {
            ptr->pre->next=ptr->next;
        }
        if(ptr==start)
        {
            if(ptr->next==NULL)
            {
                start=NULL;
            }
            else
            {
                start=start->next;
            }
        }
        deletenode(ptr);
    }
}

void search()
{
    struct node *ptr;
    int num;

    if(start==NULL)
    {
        printf("\n Create a New list !!!");
    }
    else
    {
        printf("\n Enter the data to be searched : ");
        scanf("%d",&num);

        ptr=start;
        int pos =1;
        int flag=0;

        while(ptr!=NULL)
        {
            if(ptr->data==num)
            {
                printf("\n The value is found at Position %d",pos+1);
                flag=1;
                break;
            }
            else
            {
                ptr=ptr->next;
            }
            pos++;
        }
        if(flag=0)
        {
            printf("\n Value is not found!!1");

        }


    }

}

void main()
{
    create();
    displayl();
   insert_at_pos();
    displayl();
    insert_before_value();
    displayl();
    insert_after_value();
    displayl();
    delete_by_value();
    displayl();
    delete_by_pos();
    displayl();
    search();


}

