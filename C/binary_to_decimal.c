#include <stdio.h>

int main()
{
    int bin, digit, i, decimal;
    i = decimal = 0;
    printf("Enter a binary number: ");
    scanf("%d", &bin);

    while(bin)
    {
        digit = bin%10;
        bin /= 10;
        decimal += digit * pow(2,i);
        i++;
    }

    printf("The number in decimal is: %d", decimal);
    return 0;
}
