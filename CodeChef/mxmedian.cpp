#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
 int n, N, a;
 cin >> n;
 N = 2*n;
 vector<int> vec;
 for(int i = 0; i < N; i++)
 {
 	scanf("%d", &a);
 	vec.push_back(a);
 }
 stable_sort(vec.begin(), vec.end());
 cout << vec[(n+N-1)/2] << endl;
 int i = N-1;
 int j = 0;
 while(i > j)
 {
 	printf("%d ", vec[i]);
 	printf("%d ", vec[j]);
 	i--;
 	j++;
 }
 cout << endl;
}

int main()
{
 int t;
 cin >> t;
 while(t--)
 {
 	solve();
 }
 return 0;
}
