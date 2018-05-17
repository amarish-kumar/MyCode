#include <bits/stdc++.h>

#define lli long long int

using namespace std;

bool comp(int i, int j)
{
	return abs(i) < abs(j);
}

lli fact(lli n)
{
	if(n == 0)
		return 1;
	else
		return n*fact(n-1);
}

int main()
{
	vector<lli> v;
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;

		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}

		if(n == 1 || n == 2)
		{
			cout << 0 << endl;
			v.clear();
			continue;
		}


		sort(v.begin(), v.end(), comp);

		lli count = fact(n)/(fact(n-3)*6);
		for(int i = 0; i < n/2; i++)
		{
			if(abs(abs(v[i])-abs(v[n-i-1])) <= k)
				break;
			else
				count -= 2*(fact(n-i-1)/(fact(n-i-1-2)*2));
		}

		cout << abs(count) << endl;
		v.clear();
	}
	return 0;
}