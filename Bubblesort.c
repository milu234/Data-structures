#include<stdio.h>
#include<conio.h>

int main()
{
    int a[100],i,n;

    printf("\n Enter the no. of inputs : ");
    scanf("%d",&n);

    printf("\n Please Enter the Inputs.......one by one");

    for(i=0;i<n;i++)
    {
        printf("\n The %d Element is : ",i+1);
        scanf("%d",&a[i]);
    }

    Bubble(a,n);

    printf("\n The Sorted list of elements is ");

    for( i=0;i<n;i++)
    {
        printf("\n %d",a[i]);
    }
}

void Bubble(int x[],int n)
{
    int i,temp,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(x[j]>x[j+1])
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
}
