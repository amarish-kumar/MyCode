#include <iostream>
#include <conio.h>

using namespace std;

void solve()
{
 int n, temp, fact[500], digits = 1;
 fact[0] = 1;
 cin >> n;
 
 for(int i = n; i > 1; i--)
 {
 	temp = 0;
 	for(int j = 0; j <= digits-1; j++)
 	{
 		temp = i*fact[j] + temp;
 		fact[j] = temp%10;
 		temp /= 10;
 	}
	while(temp)
	{
	 	fact[(++digits)-1] = temp%10;
	 	temp /= 10;
	}
 }	

 for(int i = digits-1; i >= 0; i--)
 {
  cout << fact[i];
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
 getch();
 return 0;
}  
  