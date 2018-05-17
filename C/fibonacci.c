#include <stdio.h>

int main()
{
    int n, num1, num2, fibo, i;
    printf("Enter the number of fibonacci numbers to display: ");
    scanf("%d", &n);
    num1 = num2 = 1;
    for(i = 0; i < n; i++)
    {
        fibo = num1 + num2;
        if(i == 0 || i == 1)
            fibo = 1;

        printf("%d\n", fibo);

        num1 = num2;
        num2 = fibo;
    }
    return 0;
}
