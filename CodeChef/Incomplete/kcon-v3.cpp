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

		int neg = 0;
		for(int i = 0; i < n; i++)
			if(v[i] < 0)
				neg++;

		if(neg == n)
			cout << *max_element(v.begin(), v.end()) << endl;
		else
		{
			lli cur_max = 0, fmax = INT_MIN;
			for(int i = 0; i < n; i++)
			{
				cur_max += v[i];
				if(fmax < cur_max)
					fmax = cur_max;
				if(cur_max < 0)
					cur_max = 0;
			}

			int lastp, firstp;
			lli neg_sum = 0;
			for(int i = n-1; i >= 0; i--)
				if(v[i] >= 0)
				{
					lastp = i;
					break;
				}

			for(int i = 0; i < n; i++)
				if(v[i] >= 0)
				{
					firstp = i;
					break;
				}

			int i;
			if(lastp == n-1)
				i = 0;
			else
				i = lastp+1;

			while(i != firstp)
			{
				if(v[i] < 0)
					neg_sum += v[i];

				if(i == n-1)
					i = 0;
				else
					i++;
			}

			lli all_max = fmax*k + neg_sum*(k-1);
			if(all_max > fmax)
				cout << all_max << endl;
			else
				cout << fmax << endl;
		}
		v.clear();
	}
	return 0;
}