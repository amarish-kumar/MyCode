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
		else if(neg == 0)
		{
			lli max = 0;
			for(int i = 0; i < n; i++)
				max += v[i];
			cout << (max*k) << endl;
		}
		else
		{
			lli cur_max = 0, fmax = 0;
			for(int count = 0; count < k; count++)
				for(int i = 0; i < n; i++)
				{
					cur_max += v[i];
					if(fmax < cur_max)
						fmax = cur_max;
					if(cur_max < 0)
						cur_max = 0;
				}

			cout << fmax << endl;
		}
		v.clear();
	}
	return 0;
}