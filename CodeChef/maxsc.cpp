#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli max_sum()
{
	int n;
	cin >> n;
	vector<vector <lli>> v;
	vector<lli> temp;
	lli a;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a;
			temp.push_back(a);
		}
		v.push_back(temp);
		temp.clear();
	}

	for(int i = 0; i < n; i++)
		sort(v[i].begin(), v[i].end());

	lli max = 0, prev = 9999999999;
	for(int i = n-1; i >= 0; i--)
	{
		int j;
		for(j = n-1; j >= 0; j--)
		{
			if(v[i][j] < prev)
			{
				max += v[i][j];
				prev = v[i][j];
				break;
			}
		}
		if(j < 0)
			return -1;
	}
	return max;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		cout << max_sum() << endl;
	return 0;
}