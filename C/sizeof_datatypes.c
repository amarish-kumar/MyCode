#include <stdio.h>

int main()
{
    printf("Size of char: %d bytes\n", sizeof(char));
    printf("Size of int: %d bytes\n", sizeof(int));
    printf("Size of short: %d bytes\n", sizeof(short));
    printf("Size of signed int: %d bytes\n", sizeof(signed int));
    printf("Size of unsigned int: %d bytes\n", sizeof(unsigned int));
    printf("Size of long int: %d bytes\n", sizeof(long int));
    printf("Size of long long int: %d bytes\n", sizeof(long long int));
    printf("Size of float: %d bytes\n", sizeof(float));
    printf("Size of double: %d bytes\n", sizeof(double));
    printf("Size of long double: %d bytes\n", sizeof(long double));
    return 0;
}
