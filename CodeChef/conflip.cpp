#include <iostream>

using namespace std;

#define lli long long int

void solve()
{
	int i, q;
	lli n;
	cin >> i >> n >> q;
	if(n%2 == 0)
		cout << n/2 << endl;
	else
	{
		if(i == q)
			cout << n/2 << endl;
		else
			cout << n/2+1 << endl;
	}
}

int main()
{
	int t, g;
	cin >> t;
	while(t--)
	{
		cin >> g;
		while(g--)
			solve();
	}
	return 0;
}