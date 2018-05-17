#include <iostream>

using namespace std;

void solve()
{
    long long int n, k, btot = 0, bcur = 0, sum = 0, b = 0, i, m;
    cin >> n >> k;
    string str;
    cin >> str;
    for(i = 0; i < n; i++)
    {
        if(str[i]=='b') btot++;
    }
    for(i = 0; i < n; i++)
    {
        if(str[i]=='b') b++;
        if(str[i]=='a')
        {
            bcur = btot - b;
            m = k-1;
            sum += k*bcur + btot*(m*(m+1)/2);
            bcur = 0;
        }
    }
    cout << sum << endl;
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
