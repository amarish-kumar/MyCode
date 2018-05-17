#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

using namespace std;

int main()
{
srand(time(NULL));
int val;

while(true)
{
val = rand() % 2;
cout << val;
}

return 0;

}
