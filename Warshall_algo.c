#include<stdio.h>

int main()
{
    int m,i,j,k;

    printf("\nEnter no of nodes: ");
    scanf("%d",&m);

    int A[m][m],P[m][m];

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&A[i][j]);
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            P[i][j]=A[i][j];
    }

    for(k=0;k<m;k++)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
                P[i][j]=(P[i][j] || (P[i][k] && P[k][j]));
        }
    }

    printf("\nPath Matrix: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            printf(" %d",P[i][j]);
        printf("\n");
    }

    return 0;
}
