#include<iostream>
using namespace std;
int main()
{
int a=0;
while(a!=4)
 { cout<<"-----------------------"<<endl; 
  cout<<"Options:"<<endl;
  cout<<"1. Display programmer's name."<<endl;
  cout<<"2. Display programmer's contact info."<<endl;
  cout<<"3. Display programmer's message."<<endl;
  cout<<"4. Exit program."<<endl;
  cout<<"Enter your choice: ";
  cin>>a;
  {switch(a)
	{ case 1: cout<<"Swaraj Hota a.k.a BlueZ"<<endl;
	  	  break;
	  case 2: cout<<"Phone: 9040495344"<<endl;
		  cout<<"Email: swarajhota353@gmail.com"<<endl;
		  break;
	  case 3: cout<<"Winter is coming!"<<endl;
		  break;
	  case 4: break;
	  default: cout<<"Invalid choice."<<endl;
		  break;
	}
  }
 }
}
	
