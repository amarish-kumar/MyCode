#include <iostream>
//#include <conio.h>

using namespace std;

int main()
{
	int n, a, b, winner, max = 0, tot1 = 0, tot2 = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		tot1 += a;
		tot2 += b;
		if(max < tot1 - tot2)
		{
			max = tot1 - tot2;
			winner = 1;
		}
		else if(max < tot2 - tot1)
		{
			max = tot2 - tot1;
			winner = 2;
		}
	}

	cout << winner << ' ' << max << endl;
	//getch();
	return 0;
}