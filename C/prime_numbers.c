#include <stdio.h>

int main()
{
    int N, i, j, count = 0;
    printf("Enter the number upto which prime numbers will be shown: ");
    scanf("%d", &N);
    for(i = 2; i <= N; i++)
    {
        for(j = 1; j <= i; j++)
        {
            if(i%j == 0)
                count++;
        }
        if(count == 2)
            printf("%d\n", i);
        count = 0;
    }
    return 0;
}
