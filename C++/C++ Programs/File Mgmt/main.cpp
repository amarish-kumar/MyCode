#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char name[30];
    int id;
    fstream ptr;
    ptr.open("database", ios::out);
    cout << "Enter name: ";
    cin.getline(name,30);
    cout << "\nEnter id: ";
    cin >> id;
    if(!ptr)
    {
      cout << "Error opening file!";
    }
    ptr << name << id;
    ptr.open("database", ios::in);
    cin.getline(name,30);
    ptr >> id;
    cout << name << '\t' << id;
    return 0;
}
