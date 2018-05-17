#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

long long int max_mod()
{
    long long int N, a, i, max = 0;
    scanf("%lld", &N);
    std::vector<long long int> arr;
    arr.reserve(N);
    for(i = 0; i < N; i++)
    {
        scanf("%lld", &a);
        arr.push_back(a);
    }
    std::stable_sort(arr.begin(), arr.end());
    i = N;
    while(i != 1)
    {
        if(arr[i-2] != arr[i-1])
        {
            max = arr[i-2]%arr[i-1];
            break;
        }
        i--;
    }
    return max;
}

int main()
{
    int T;
    long long int max;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        max = max_mod();
        printf("%lld\n", max);
    }
    return 0;
}
