#include <cstdio>

int main()
{
 long long n, k, a, count = 0;
 scanf("%lld %lld", &n, &k);
 while(n--)
 {
   scanf("%lld", &a);
   if(a%k == 0)
   	count++;
 }
 printf("%lld", count);
 return 0;
}
  	