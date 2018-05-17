#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

class student
{
    char s_name[30], f_name[30];
    float p_marks, c_marks, m_marks, e_marks, cs_marks;
    float total;
    char grade;
    float percentage;

public:
    int roll;
    void getdata()
    {
        cout << "\nEnter roll number: ";
        cin >> roll;
        cout << "\nEnter Student name: ";
        gets(s_name);
        cout << "\nEnter Father's name: ";
        gets(f_name);
        cout << "\nEnter Physics, Chemistry, Maths, English, Computer Science marks: ";
        cin >> p_marks >> c_marks >> m_marks >> e_marks >> cs_marks;
        calculate();
    }
    void calculate()
    {
        total = p_marks+c_marks+m_marks+e_marks+cs_marks;
        percentage = total/5.0;
        if(percentage >= 80)
            grade = 'A';
        else if(percentage >= 65 && percentage < 80)
            grade = 'B';
        else if(percentage >= 50 && percentage < 65)
            grade = 'C';
        else
            grade = 'D';
    }
    void showdata()
    {
        cout << "\nRoll Number: " << roll;
        cout << "\nStudent Name: " << s_name;
        cout << "\nFather's Name: " << f_name;
        cout << "\nPhysics Marks: " << p_marks;
        cout << "\nChemistry Marks: " << c_marks;
        cout << "\nMaths Marks: " << m_marks;
        cout << "\nEnglish Marks: " << e_marks;
        cout << "\nComputer Science Marks: " << cs_marks;
        cout << "\nTotal Marks: " << total;
        cout << "\nPercentage: " << percentage;
        cout << "\nGrade: " << grade;
    }
};

void menu()
{
    student obj[100];
    int i;
    int ch;
    int rnum;
    for(int a = 1; ch != 3;)
    {
        cout << "STUDENT DATABASE";
        cout << "\n-------------------------------";
        cout << "\n\t1. Receive Student Data";
        cout << "\n\t2. Display Student Data";
        cout << "\n\t3. Exit";
        cout << "\nEnter your choice(1-3): ";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1:
                obj[a].getdata();
                a++;
                system("cls");
                break;
            case 2:
                cout << "\nEnter roll no.: ";
                cin >> rnum;
                for(i = 0; i < a; i++)
                {
                    if(obj[i].roll == rnum)
                    {
                        obj[i].showdata();
                        break;
                    }
                };
                if(i == a)
                    cout << "\nRoll number not found!";
                    cout << "\nPress any key to return to main menu...";
                    getch();
                system("cls");
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice!";
                cout << "Press any key to enter again...";
                getch();
        }
    }

}

int main()
{
    menu();
    return 0;
}
