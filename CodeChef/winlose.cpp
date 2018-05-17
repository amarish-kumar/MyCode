#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int tanu = 0;
		int manu = 0;
		int tstreak = 0, mstreak = 0;
		string str;
		cin >> str;

		for(int i = 0; i < str.length(); i++)
		{
			if(str[i] == '1')
			{
				tanu += 5;
				tstreak++;
				mstreak = 0;
			}
			else if(str[i] == '0')
			{
				manu += 5;
				mstreak++;
				tstreak = 0;
			}

			if(tstreak == 5)
			{
				tanu += 10;
				manu -= 5;
			}
			else if(mstreak == 5)
			{
				manu += 10;
				tanu -= 5;
			}
		}

		if(tanu > manu)
			cout << "Tanu" << endl;
		else if(manu > tanu)
			cout << "Manu" << endl;
		else if(tanu == manu)
			cout << "Draw" << endl;
	}
	return 0;
}