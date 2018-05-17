#include<iostream>
using namespace std;
int main()
{ 
int side1,side2,side3;
cout<<"Enter sides of the triangle: ";
cin>>side1>>side2>>side3;
if(side1>side2&&side1>side3)
  { if(side2+side3>side1)
      cout<<"Valid triangle";
    else
      cout<<"Invalid triangle";
  }
else if(side2>side3)
	{ if(side1+side3>side2)
		cout<<"Valid triangle";
	  else
		cout<<"Invalid triangle";
	}
else
	{ if(side1+side2>side3)
		cout<<"Valid triangle";
	  else
		cout<<"Invalid triangle";
	}
}