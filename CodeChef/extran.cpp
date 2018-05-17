#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long int find_extra(const vector<long int> &seq)
{
	for(int i = 0; i < seq.size()-1; i++)
	{
		if(seq[i] == seq[i+1])
			return seq[i];
	}			
	if(seq[0] != seq[1]-1)
		return seq[0];
	else
		return seq[seq.size()-1];		
}

int main()
{
int T;
long int N, a, extra;
vector<long int> seq;
scanf("%d", &T);
for(int i = 0; i < T; i++)
{
	seq.clear();
	scanf("%ld", &N);
	for(long int j = 0; j < N; j++)
	{
		scanf("%ld", &a);
		seq.push_back(a);
	}
	
	stable_sort(seq.begin(), seq.end());
	
	extra = find_extra(seq);
	printf("%ld\n", extra);
}	
return 0;
}