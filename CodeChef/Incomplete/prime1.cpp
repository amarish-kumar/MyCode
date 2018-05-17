#include <iostream>
#include <math.h>
//#include <conio.h>

using namespace std;

#define lli long long int

lli primes[100000000];

int main()
{
	lli ranges[11][2];
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> ranges[i][0] >> ranges[i][1];
	}

	for(int i = 0; i < t; i++)
	{
		for(lli a = ranges[i][0]; a <= ranges[i][1]; a++)
			primes[a] = 1;
		primes[0] = primes[1] = 0;
		for(lli a = ranges[i][0]; a <= sqrt(ranges[i][1]); a++)
		{
			if(primes[a] == 1)
			{
				for(lli b = 2; a*b <= ranges[i][1]; b++)
				{
					primes[a*b] = 0;
				}
			}
		}

		for(lli a = ranges[i][0]; a <= ranges[i][1]; a++)
		{
			if(primes[a] == 1)
			{
				cout << a << endl;
			}
		}
		cout << endl;
	}
	//getch();
	return 0;
}