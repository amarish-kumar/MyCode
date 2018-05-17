#include<stdio.h>

int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;

}

void main()
{
    int m,i,j,k;

    printf("\nEnter no of nodes: ");
    scanf("%d",&m);

    int W[m][m],Q[m][m];

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&W[i][j]);
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(W[i][j]==0)
                Q[i][j]=3000;
            else
                Q[i][j]=W[i][j];
        }
    }

    for(k=0;k<m;k++)
    {
        for(i=0;i<m;i++)
        {
           for(j=0;j<m;j++)
           {
               Q[i][j]=min(Q[i][j],Q[i][k]+Q[k][j]);
           }
        }
    }

    printf("\nAll-pair-shortest path: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            printf(" %d",Q[i][j]);
        printf("\n");
    }

}
