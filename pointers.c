#include<stdio.h>

int main()
{
int i = 10;
int* ptr;
int* ptr2;

ptr = &i;
ptr2 = &ptr;
printf("%d\n",i);
printf("%d\n",ptr);
printf("%d\n",ptr2);
printf("%d\n",&i);
printf("%d\n",*ptr);
printf("%d\n",*ptr2);
printf("%d\n",*(&ptr));
}
