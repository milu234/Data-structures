#include<stdio.h>

int main()
{
    char data[25] = "Learning Lad";
    int length =strlen(data);
    int counter;
    FILE *Fpointer;
    Fpointer = fopen("milan.txt","w");

    if(Fpointer==NULL){
        printf("unable to create file");

    }else{
    for(counter = 0; counter<length; counter++){
        printf("Writing the character %c \n",data[counter]);
        fputc(data[counter], Fpointer);
    }
    printf("File opened successfully");
    }

    fclose(Fpointer);

}
