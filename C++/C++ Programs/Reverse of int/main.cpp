#include <iostream>

using namespace std;

int main()
{
    int val, valr = 0, k = 0;
    cout << "Enter an integer: ";
    cin >> val;
    while(val!=0)
    {
        valr = valr*10;
        k = val%10;
        valr = valr+k;
        val = val/10;
    }
    cout << "Reverse of the integer is: " << valr;
    return 0;
}
