#include <cstdio>

#define lli long long int

lli store[10000001] = {0};

lli max(lli n)
{
	if(n <= 11) return n; 
	
	if(n < 10000000 && store[n] != 0) return store[n];
		
	lli sum = max(n>>1) + max(n/3) + max(n>>2);

	if(n < 10000000) store[n] = sum;

	return sum;
}

int main()
{
	lli n;
	while(scanf("%lld", &n) == 1)
	{
		printf("%lld\n", max(n));
	}
	return 0;
}