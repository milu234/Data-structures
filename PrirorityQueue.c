#include<stdio.h>
#include<stdlib.h>


#define Max 10
int front=-1;
int rear=-1;
int e;
struct priority_queue
{
    int key;
    int element;
}pq[Max],temp;

void insert()
{
    int i;

    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear++;

        printf("\n Enter the key");
        scanf("%d",&pq[rear].key);

        printf("Enter the Element : ");
        scanf("%d",&pq[rear].element);
       for(i=rear-1;i>=0;i--)
        {
            temp=pq[i];
            pq[i]=pq[i+1];
            pq[i+1]=temp;
        }


    }
}

int delete_key()
{
    if(front==-1&&rear==-1)
    {
        printf("\n The Queue is Empty!!");
    }
    else
    {
        e=pq[front].element;

        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }

    }
    return e;
}

int minelement()
{
    if(front==-1&&rear==-1)
    {
        printf("\n The Stack is Empty!!!");
        return;
    }

    e=pq[front].element;

    return e;

}

int minkey()
{
    if(front ==-1&&rear==-1)
    {
        printf("\n The Stack is Empty!!!");
        return;
    }
    e=pq[front].key;
    return e;
}

void display()
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("\n The Queue is Empty!!");
        return;
    }
    printf("\n The Queue is : ");
    for(i=front;i<=rear;i++)
    {
        printf("\n %d",pq[i].element);
    }

}

int main()
{
    int choice;
    do
    {
         printf("\n---------- Priority Queue operations-----------");
        printf("\n 1. INSERT ");
        printf("\n 2. DELETE ");
        printf("\n 3. MIN ELEMENT ");
        printf("\n 4. MIN KEY ");
        printf("\n 5. DISPLAY ");
        printf("\n---------------------------------------");
        printf("\n Enter your choice ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            if(rear==Max-1)
            {
                printf("\n Long Live Coloumbia!!");
                break;
            }
            insert();
            break;
        case 2:
            if(front==-1)
            {
                printf("\n Underflow!!!");
                break;
            }
            printf("\n the deleted Element is %d",delete_key());
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n The Min Element Is %d",minelement());
            break;
        case 5:
            printf("\n My Min key is  is %d",minkey());
            break;
        case 6:
            exit(1);

        }
    }while(choice!=8);
}
