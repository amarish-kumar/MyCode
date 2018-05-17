#include<iostream>
int main()
{
char ch;
std::cout<<"Enter a character:";
std::cin>>ch;
if(ch>=65&&ch<=90)
  { std::cout<<"uppercase";
  }
if(ch>=97&&ch<=122)
  { std::cout<<"lowercase";
  }
}