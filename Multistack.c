#include<stdio.h>
#include<stdlib.h>

#define Max 10
int topA=-1;
int topB=Max;

int stack[Max];

void pushA(int e)
{
    topA++;
    stack[topA]=e;
}
void pushB(int e)
{
    topB--;
    stack[topB]=e;
}
int popA()
{
    int e=stack[topA];
    topA--;
    return e;
}
int popB()
{
    int e=stack[topB];
    topB++;
    return e;
}
void displayA()
{
    int i;
   if(topA==-1)
   {
       printf("\n Stack is Empty!!!");
   }
   else
   {
       printf("\n StackA : \n");
       for(i=topA;i>=0;i--)
       {
           printf("\n %d",stack[i]);
       }
   }
}

void displayB()
{
    int i;
    if(topB==Max)
    {
        printf("\n The Stack is not Empty!!");
    }
    else
    {
        printf("\n Stack B : ");
        for(i=topB;i<Max;i++)
        {
            printf("\n %d",stack[i]);
        }
    }
}

int main()
{
    int ch ,val,e;

    do
    {
         printf("\n----------Multi-stack Stack operations-----------");
        printf("\n 1. PUSH IN STACK A");
        printf("\n 2. PUSH IN STACK B");
        printf("\n 3. POP FROM STACK A");
        printf("\n 4. POP FROM STACK B");
        printf("\n 5. DISPLAY STACK A");
        printf("\n 6. DISPLAY STACK B");
        printf("\n 7. EXIT");
        printf("\n------------------------------------------------");
        printf("\n Enter your choice ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            if(topA==topB-1)
            {
                printf("\n Stack Overflow!!!");
            }
            else
            {
                printf("\n Enter the data in the StackA : ");
                scanf("%d",&e);
                pushA(e);
            }
            break;
        case 2:
            if(topB==topA+1)
            {
                printf("\n Enter the data to be inserted in the stack : ");

            }
            else
            {
                printf("\n Enter the data to be inserted in the Stack B : ");
                scanf("%d",&e);
                pushB(e);
            }
            break;
        case 3:
            if(topA==-1)
            {
                printf("\n The Stack is Empty!!!");
            }
            else
            {
                printf("\n The element pooped out from Stack A is %d",popA());
            }
            break;
        case 4:
            if(topB==Max)
            {
                printf("\n The StackB is Empty!!!");
            }
            else
            {
                printf("\n The element that has popped out from stack B is : %d",popB());

            }
            break;
        case 5:
            displayA();
            break;
        case 6:
            displayB();
            break;
        case 7:
            displayA();
            displayB();
            break;
        default:
            printf("\n Wrong Choice!!!");
        }

    }while(ch!=7);
}
