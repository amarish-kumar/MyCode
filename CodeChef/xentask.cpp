#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
 
int calc_time(const vector<long int> &xenny, const vector<long int> &yana, long int N, bool turn)
{
	long int sum = 0;
	for(long int i = 0; i < N; i++)
	{
	  if(turn)
	  	sum = sum + xenny[i];
	  else
	  	sum = sum + yana[i];
	  	
	  turn = !turn;
	}
	return sum; 		
}	
 
int main()
{
int T;
long int N, in, t1, t2;
vector<long int> xenny;
vector<long int> yana;
scanf("%d", &T);
for(int i = 0; i < T; i++)
{
	xenny.clear();
	yana.clear();
	scanf("%ld", &N);
	
	for(long int a = 0; a < N; a++)
	{
		scanf("%ld", &in);
		xenny.push_back(in);

	}	
	for(long int b = 0; b < N; b++)
	{
		scanf("%ld", &in);
		yana.push_back(in);
	}
	
	t1 = calc_time(xenny, yana, N, true);
	t2 = calc_time(xenny, yana, N, false);
	
	if(t1 < t2)
		printf("%ld", t1);
	else
		printf("%ld", t2);
	printf("\n");
}
return 0;
}			