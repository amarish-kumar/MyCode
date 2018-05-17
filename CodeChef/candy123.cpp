#include <iostream>
#include <cstdio>

void solve()
{
    int a, b, i = 1;
    scanf("%d %d",&a,&b);
    while(1)
    {
        if(i%2)
        {
            a = a-i;
            if(a < 0)
            {
                printf("%s\n","Bob");
                break;
            }
        }
        else
        {
            b = b-i;
            if(b < 0)
            {
                printf("%s\n","Limak");
                break;
            }
        }
        i++;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
