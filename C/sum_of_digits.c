#include <stdio.h>

int main()
{
    int n, digit, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while(n)
    {
        digit = n%10;
        n /= 10;
        sum += digit;
    }
    printf("Sum of digits: %d", sum);
    getch();
    return 0;
}
