#include<iostream>
using namespace std;
int main()
{
int a,b,c=1;
for(a=1; a<=3; ++a)
 {
	for(b=1; b<=5; ++b)
	 {
		if((a==1&&b==3)||(a==2&&b%2==0)||(a==3&&b%2!=0))
		 {	
			cout<<c;
			c++;
		 }
		else
			cout<<' ';
	 }
	cout<<endl;
 }
}