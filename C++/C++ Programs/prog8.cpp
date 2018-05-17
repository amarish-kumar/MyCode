#include<iostream>
using namespace std;
int main()
{
int n,sum_even=0,sum_odd=0;
cout<<"Enter a natural number:";
cin>>n;
while(n!=0)
{
if(n%2==0)
	sum_even += n;
else
	sum_odd += n;
--n;
}
cout<<endl<<"Sum of even integers is:"<<sum_even;
cout<<endl<<"Sum of odd integers is:"<<sum_odd<<endl;
}


