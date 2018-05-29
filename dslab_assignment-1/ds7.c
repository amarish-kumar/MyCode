#include <stdio.h>
#include <stdlib.h>

void printClosest(int arr1[], int arr2[], int n1, int n2, int x)
{
    int diff = 9999999;
    int loc_l, loc_r;
    int l = 0, r = n2-1;

    while (l < n1 && r >= 0)
    {
       if (abs(arr1[l] + arr2[r] - x) < diff)
       {
           loc_l = l;
           loc_r = r;
           diff = abs(arr1[l] + arr2[r] - x);
       }
       if (arr1[l] + arr2[r] > x)
           r--;
       else  
           l++;
    }
    printf("%d and %d", arr1[loc_l], arr2[loc_r]);
}

int main()
{
    int n1, n2;
    printf("Enter the no. of elements for array 1 & 2: ");
    scanf("%d %d", &n1, &n2);

    int arr1[n1], arr2[n2], i;
    printf("Enter elements for array 1: \n");
    for(i = 0; i < n1; i++)
      scanf("%d", &arr1[i]);

    printf("Enter elements for array 2: \n");
    for(i = 0; i < n2; i++)
      scanf("%d", &arr2[i]);

    int x;
    printf("Enter the number x: ");
    scanf("%d", &x);

    printClosest(arr1, arr2, n1, n2, x);
    return 0;
}
