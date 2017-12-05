#include<stdio.h>
#define Max 3

void BFS(int adj[][Max],int visited[],int start)
{
    int q[Max],rear=-1,front=-1,i,j;

    q[rear++]=start;
    visited[start]=1;
    while(rear!=front)
    {
        start=q[++front];
        if(start==4)
            printf("5\t");
        else
            printf("%c",start+65);

        for(i=0;i<Max;i++)
        {
            if(adj[start][i]==1 && visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int i,j;
    int visisted[Max]={0};
    int adj[Max][Max];
    printf("\n Enter the adjacency Matrix : ");
    for(i=0;i<Max;i++)
        for(j=0;j<Max;j++)
        scanf("%d",&adj[i][j]);
    BFS(adj,visisted,0);
    return 0;
}
