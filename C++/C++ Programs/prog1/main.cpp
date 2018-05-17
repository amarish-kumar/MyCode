#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void decrypt(char (&dd)[50], char c)
{
    for(int a=0; dd[a] != '\0'; a++)
    {
        dd[a] = dd[a]-c;
    }
    cout << "Decrypted message is: " << dd;
}

void encrypt(char (&nn)[50], char i)
{
    for(int a=0; nn[a] != '\0'; a++)
    {
        nn[a] = nn[a]+i;
    }
}

int main()
{
    char mm[50]; int i; char nn[50];
    mm[0]='\0';
    cout << "Enter your message: ";
    cin.getline(mm,50);
    cout << "Enter a character as key: ";
    i = getche();
    cout << endl;
    encrypt(mm,i);
    cout << "Your message is successfully encrypted." << endl;
    cout << "Encrypted message is: " << mm << endl;
    cout << "------------" <<endl;
    strcpy(nn,mm);
    while(i != 0)
    {
        cout << endl;
        cout << "Enter key to decrypt: ";
        i = getche();
        cout << endl;
        decrypt(mm,i);
        strcpy(mm,nn);
    }
    return 0;
}
