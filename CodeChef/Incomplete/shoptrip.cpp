#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

float calc_dist(char gotingr[], int lastshop, int pts[][2], string ingr[36], int n, int k)
{
    float ans;
    bool gotall = true;
    for(int i = 0; i < k; i++)
    {
        if(gotingr[i] == '0')
        {
            gotall = false;
            break;
        }
    }
    if(gotall)
    {
        return sqrt( pow(pts[lastshop][0], 2) + pow(pts[lastshop][1], 2) );
    }
    else
    {
        ans = 99999999;
        for(int i = 0; i < n; i++)
        {
            if(i != lastshop)
            {
                float d = sqrt( pow(pts[i][0]-pts[lastshop][0], 2) + pow(pts[i][1]-pts[lastshop][1], 2) );
                long long ingrf;

                long long newingr = (long long) gotingr | ingrf;
                if(newingr != (long long) ingr[i])
                {
                    char newingr_ch[k];
                    memcpy(&newingr, newingr_ch, sizeof(long long));
                    ans = min(ans, calc_dist(newingr_ch, i, pts, ingr, n, k) + d);
                }
            }
        }
        return ans;
    }
}

void solve()
{
   int n, k;
   cin >> n >> k;
   int pts[n][2];
   string ingr[n];
   for(int i = 0; i < n; i++)
   {
       cin >> pts[i][0] >> pts[i][1];
   }
   for(int i = 0; i < n; i++)
   {
       cin >> ingr[i];
   }
   char gotingr[k];
   for(int i = 0; i < k; i++) gotingr[i] == '0';
   int lastshop = 0;
   float ans;
   ans = calc_dist(gotingr, lastshop, pts, ingr, n, k);
   cout << ans << endl;
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
