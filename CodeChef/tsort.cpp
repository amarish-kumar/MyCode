#include <cstdio>
#include <algorithm>
#include <vector>
//#include <conio.h>

using namespace std;

#define lli long long int

int main()
{
	lli t, a;
	
	scanf("%lld", &t);
	vector<lli> arr;
	for(lli i = 0; i < t; i++)
	{
		scanf("%lld", &a);
		arr.push_back(a);
	}
	stable_sort(arr.begin(), arr.end());
	for(lli i = 0; i < t; i++)
	{
		printf("%lld\n", arr[i]);
	}
	//getch();
	return 0;
}