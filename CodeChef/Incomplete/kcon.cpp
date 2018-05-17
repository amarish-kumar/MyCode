#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	int t, n, k;
	vector<lli> v;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}

		int neg = 0, pos = 0;
		for(int i = 0; i < n; i++)
			if(v[i] < 0)
				neg++;
			else
				pos++;

		if(neg == n)
			cout << *max_element(v.begin(), v.end()) << endl;
		else if(pos == n)
		{
			lli max = 0;
			for(int i = 0; i < n; i++)
				max += v[i];
			cout << (max*k) << endl;
		}
		else
		{
			lli max = 0, fmax = 0;
			for(int i = 0; i < n; i++)
			{
				while(i != n && v[i] >= 0)
				{
					max += v[i];
					if(i == n-1)
					{
						int j = 0;
						while(v[j] >= 0)
							max += v[j++];
						i = n;
					}
					else 
						i++;
				}

				if(max > fmax)
					fmax = max;

				max = 0;
			}
			cout << fmax << endl;
		}
		v.clear();
	}
	return 0;
}