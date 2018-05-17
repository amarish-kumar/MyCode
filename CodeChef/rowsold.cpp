#include <iostream>

using namespace std;

long long int output()
{
	long long int N, i, sum, ones, zeros;
	sum = ones = zeros = i = 0;
	string str;
	cin >> str;
	N = str.length();
	while(str[i] != '1')
    {
        i++;
        if(i == N) break;
    }
	while(i < N)
    {
            while(str[i] != '0')
            {
                ones++;
                i++;
                if(i == N) return sum;
            }
            while(str[i] != '1')
            {
                zeros++;
                i++;
                if(i == N) break;
            }
            sum += ones*(zeros+1);
            zeros = 0;
    }
    return sum;
}

int main()
{
 int T;
 long long int sum;
 cin >> T;
 for(int i = 0; i < T; i++)
 {
 	sum = output();
 	cout << sum << '\n';
 }
return 0;
}
