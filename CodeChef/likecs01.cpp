#include <iostream>
//#include <conio.h>

using namespace std;

int solve(string str)
{
	for(int i = 0; i < str.size(); i++)
	{
		for(int j = i+1; j < str.size(); j++)
		{
			if(str[i] == str[j])
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int t, sol[1000];
	string arr[1000];
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> arr[i];
		sol[i] = solve(arr[i]);
	}
	for(int i = 0; i < t; i++)
	{
		if(sol[i])
			cout << "yes" << endl;
		else 
			cout << "no" << endl;
	}
	//getch();
	return 0;
}