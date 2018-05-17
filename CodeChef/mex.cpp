#include <bits/stdc++.h>

using namespace std;

int mex()
{
	int n, k, a, count = 0;
	cin >> n >> k;
	vector<int> v;
	vector<int> c;

	for(int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	
	stable_sort(v.begin(), v.end());

	for(int i = 0; i != v[0]; i++)
		c.push_back(i);

	for(int i = 0; i < n-1; i++)
	{
		if(v[i]+1 < v[i+1])
		{
			if(k == 0 && v[0] == 0) 
				return (v[i]+1);
			
			for(int j = v[i]+1; j < v[i+1]; j++)
			{
				count++;
				c.push_back(j);
			}
		}
	}

	if(count+v[0] <= k)
		return (v[n-1]+(k-count-v[0])+1);
	else
		return (c[k]);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		cout << mex() << endl;
	return 0;
}