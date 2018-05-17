#include <iostream>

using namespace std;

bool isPossible()
{
    int c, e, s;
    c = e = s = 0;
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'C')
        {
            c++;
            if(e != 0 || s != 0) return false;
        }
        if(str[i] == 'E')
        {
            e++;
            if(s != 0) return false;
        }
        if(str[i] == 'S') s++;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        if(isPossible())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
