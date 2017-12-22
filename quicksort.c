#include<stdio.h>

int partition( int x[], int lb, int ub)
{
    int up,down,a,temp;

    a=x[lb];

    up=ub;
    down=lb;

    while(down <up)
    {
        while(x[down]<=a && down<ub)
            down++;

        while(x[up]>a)
            up--;

            if(down<up)
        {
            temp=x[down];
            x[down]=x[up];
            x[up]=temp;
        }
    }
    x[lb]=x[up];
    x[up]=a;
    return up;
}

void quick(int x[],int lb, int ub)
{
    int pivot;
    if(lb>=ub)
        return;

        pivot=partition(x,lb,ub);

        quick(x,lb,pivot-1);
        quick(x,pivot+1,ub);
}


void main()
{
	int i,n;
	int a[100];
	printf("\n\nHOW MANY NUMBERS ARE THERE : \t");
	scanf("%d",&n);

	printf("\n\nENTER NUMBERS ONE BY ONE ....");
	for(i=0;i<n;i++)
	{
		printf("\nENTER NUMBER %d : ",i+1);
		scanf("%d",&a[i]);
	}

	quick(a,0,n);
	printf("\n\nSORTED USING QUICK SORT ...\n\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
}
