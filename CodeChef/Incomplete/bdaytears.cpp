#include <iostream>

using namespace std;

long min_tears()
{
    string s;
    cin >> s;
    long N, l, u, c, mid, sublen, tears = 0;
    long leftc, rightc;
    N = s.length();
    l = 0; u = N-1;
    leftc = 1; rightc = 1; c = 1;
    sublen = N/2;
    for(long i = 0; i < N-1; i++)
    {
        if(s[i] == s[i+1])
            c++;
    }
    if(c == N) return tears;
    if(N % 2 != 0) return -1;
    while(l <= u)
    {
        mid = l+u/2;
        for(long i = l; i < mid; i++)
        {
            if(s[i] == s[i+1])
                leftc++;
        }
        for(long i = mid+1; i < u-1; i++)
        {
            if(s[i] == s[i+1])
                rightc++;
        }
        tears++;
        if(leftc == sublen || rightc == sublen) return tears;
        sublen = sublen/2;
        leftc = rightc = 1;
        if(leftc > 1)
        {
            u = mid+1;
        }
        else if(rightc > 1)
        {
            l = mid+1;
        }
        else return -1;
    }
    return -1;
}

int main()
{
    int T;
    long tears;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        tears = min_tears();
        cout << tears << '\n';
    }
    return 0;
}
