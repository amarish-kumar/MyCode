#include <iostream>
#include <string.h>

using namespace std;

bool isSimilar(char arr1[4][12], char arr2[4][12])
{
	int count = 0;
	for(int i = 0; i < 4; i++)
	{
	  for(int j = 0; j < 4; j++)
	  {
	  	if(strcmp(arr1[i],arr2[j]) == 0)
	  	{
	  		count++;
	  		break;
	  	}	
	  }
	  if(count == 2)
	  	return true;
	}
	return false; 			
}

int main()
{
 char arr1[4][12], arr2[4][12];
 int T;
 cin >> T;
 for(int i = 0; i < T; i++)
 {
 	for(int a = 0; a < 4; a++)
 	{
 		cin >> arr1[a];
 	}	
 	
 	for(int b = 0; b < 4; b++)
 	{
 		cin >> arr2[b];
 	}
 	
 	if(isSimilar(arr1,arr2))
 		cout << "similar\n";
 	else
 		cout << "dissimilar\n";
 }
return 0;
}