#include <iostream>
#include <math.h>

typedef long long int lli;

using namespace std;

int main()
{
 lli t, n, i = 1;
 lli count = 0;
 cin >> t;
 while(t--)
 {
   cin >> n;
   while(n/pow(5,i))
   {
     count += n/pow(5,i);
     i++;
   }
   cout << count << endl;
   count = 0;
   i = 1;
 }
 return 0;
}