#include<stdio.h>
int main()
{
    int t;

    scanf("%d",&t);
    while(t--)
    {
        char a[100];
        int i,vow = 0;

        scanf("%s",a);

        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='a' || a[i]=='A' || a[i]=='e' || a[i]=='E' || a[i]=='i' || a[i]=='I' || a[i]=='o' || a[i]=='O' || a[i]=='u' || a[i]=='U')
            {
                vow = vow+1;

            }



        }
        printf("%d\n",vow);



    }
    return 0 ;

}

