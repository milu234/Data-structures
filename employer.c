#include<stdio.h>

struct Emp
{
    int eno;
    char ename;
    float esal;
};

void main(){
char* cp;
int* ip;
struct Emp* sep;
printf("Size of the Character pointer is %d\n",sizeof(cp));
printf("Size of the Character pointer is %d\n",sizeof(ip));
printf("Size of the Character pointer is %d\n",sizeof(sep));
}

