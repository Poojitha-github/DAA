#include <stdio.h>
#include <stdlib.h>
void bfs(int A[10][10],int n,int visited[10],int source)
{
    int Q[10],rear=-1,front=0,i,delnode;
    visited[source]=1;
    Q[++rear]=source;
    while (front<=rear)
    {
        delnode=Q[front++];
        for(i=1;i<=n;i++)
        {
            if(A[delnode][i]==1&&visited[i]==0)
            {
                Q[++rear]=i;
                visited[i]=1;
            }

        }

    }
}
int main()
{
    int n,A[10][10],i,j,visited[10],count=0;
    printf("\n Enter a number of nodes \n");
    scanf("%d",&n);
    printf("\n Read the adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            bfs(A,n,visited,i);
            count++;
        }

    }
    if(count==1)
        printf("\n Graph is connected\n");
    else
        printf("\n Graph is not connected,%d component",count);
    return 0;
}
