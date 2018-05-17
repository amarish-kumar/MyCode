#include <iostream>

using namespace std;

void show(int* p, int n)
{
    *p = *p + 1;
    cout << p << endl;
    cout << *p << endl;
}

int main()
{
    int n = 5;
    int* ptr = &n;
    show(ptr, n);
    cout << *ptr;
    cout << n;
    return 0;
}
