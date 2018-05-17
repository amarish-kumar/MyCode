#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Min and Max of char: %d and %d\n", CHAR_MIN, CHAR_MAX);
    printf("Min and Max of unsigned char: %d and %d\n", 0, UCHAR_MAX);
    printf("Min and Max of int: %d and %d\n", INT_MIN, INT_MAX);
    printf("Min and Max of unsigned int: %d and %lld\n", 0, UINT_MAX);
    printf("Min and Max of long: %d and %d\n", LONG_MIN, LONG_MAX);
    printf("Min and Max of float: %lld and %lld\n", -FLT_MAX, FLT_MAX);
    printf("Min and Max of double: %lld and %lld\n", -DBL_MAX, DBL_MAX);
    printf("Min and Max of long double: %lf and %lf\n", -LDBL_MAX, LDBL_MAX);
    return 0;
}
