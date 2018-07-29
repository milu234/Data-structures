#include<stdio.h>

int main()
{
    FILE *pf;
    char input[25];

    pf = fopen("milan.txt","w");

    if (pf==NULL)
    {
        printf("Unable to open the file");
    }
    else{
        printf("Enter the string to write the file\n");
        gets(input);
        fputs(input,pf);
        printf("Data has written Successfully");
        fclose(pf);
    }
}
