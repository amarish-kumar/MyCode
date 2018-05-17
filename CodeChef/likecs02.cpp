#include <iostream>
//#include <conio.h>

using namespace std;

void solve()
{
	int n;
	float mean;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		mean = (i+i+n-1)/2;
		if(mean >= n-1 && mean <= n+1)
		{
			for(int j = i; j < i+n; j++)
			{
				cout << j << ' ';
			}
			cout << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	//getch();
	return 0;
}