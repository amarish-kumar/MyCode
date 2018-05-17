#include <iostream>
#include <cstdio>

using namespace std;

int solve()
{
 int n;
 cin >> n;
 int arr[n];
 for(int i = 0; i < n; i++)
 {
 	scanf("%d", &arr[i]);
 }
 int count = 1;
 int k = 0;
 for(int i = n-1; i >= 0; i--)
 {
	if(arr[i] > k) k = arr[i];

 	if(arr[i] == i || k == i) return count;
 	else count++;
 }

}

int main()
{
 int t, ans;
 cin >> t;
 while(t--)
 {
 	ans = solve();
	cout << ans << endl;
 }
 return 0;
}
