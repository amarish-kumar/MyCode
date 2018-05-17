#include <iostream>

using namespace std;

struct node
{
    int val;
    node *link;
};

void push(node *top)
{
    node *ptr;
    ptr = new node;
    if(top == -1)
    {
        top = 0;
    }
    cout << "Enter a value:";
    cin >> ptr->val;
    ptr->link = top;
    top = ptr;
}

int pop(node *top)
{
    if(top == -1)
    {
        cout << "Under flow!";
        return;
    }
    node *ptr;
    ptr = new node;
    ptr = top;
    int val;
    val = ptr->val;
    ptr->link = nullptr;
    top = top->link;
    delete ptr;
    return val;
}

int main()
{

}
