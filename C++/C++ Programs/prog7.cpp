#include<iostream>
using namespace std;
int main()
{
int i;
const int size=5; 
float marks[size];
for(i=0;i<5;i++)
	{ cout<<"Enter marks of student"<<i+1<<":";
	  cin>>marks[i];
	}
for(i=0;i<5;i++)
	cout<<"Marks["<<i<<"]="<<marks[i]<<endl;
}	
	