#include <iostream>

#define lli long long int

using namespace std;

void solve()
{
	lli n, p, arr[501];
	int cw = 0, hard = 0;
	cin >> n >> p;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++)
	{
		if(arr[i] >= p/2)
			cw++;
		if(arr[i] <= p/10)
			hard++;
	}
	if(cw == 1 && hard == 2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}