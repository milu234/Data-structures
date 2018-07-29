#include<stdio.h>
#define NUMLETS 50

void merge(int a[],int l1,int u1, int l2, int u2);
void mergesort(int a[],int i,int j);

int main()
{
    int a[NUMLETS],n,i;
    printf("Enter the no of the elements : ");
    scanf("%d",&n);

    printf("Enter the elements of the array : ");

    for(i=0;i<n;i++)
        scanf("%d\n",&a[i]);

    mergesort(a,0,n-1);

    printf("The Sorted elements of the array is : ");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);

}


void mergesort(int a[], int i, int j)
{
    int mid;

    if(i<j)
    {
        mid = (i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }

}


void merge(int a[], int l1, int u1, int l2, int u2)
{
    int aux[NUMLETS];
    int i,j,k;
    i=l1;
    j=l2;
    k=0;

    while(i<=u1 && j<=u2)
    {
        if(a[i]<a[j])
            aux[k++]=a[i++];
        else
            aux[k++]=a[j++];
    }

    while(i<=u1)
        aux[k++]=a[i++];

    while(j<=u2)
        aux[k++]=a[j++];


    for(i=l1,j=0;i<=u2;i++,j++)
        a[i]=aux[j];
}
