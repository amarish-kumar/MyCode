#include<iostream>
int main()
{
int day,months,weeks,remd;
std::cout<<"Enter days:";
std::cin>>day;
months=day/30;
weeks=(day%30)/7;
remd=day-((months*30)+(weeks*7));
std::cout<<"Days:"<<day<<std::endl;
std::cout<<"Months:"<<months<<std::endl;
std::cout<<"Weeks:"<<weeks<<std::endl;
std::cout<<"Remaining days:"<<remd;
}