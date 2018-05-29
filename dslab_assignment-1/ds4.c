#include <stdio.h>

int main()
{
	char str[100];
	printf("Enter a string: \n");
	scanf("%s", str);

	int i, length = 0;
	for(i = 0; str[i] != '\0'; i++);
	length = i;
	
	for(i = 0; i < length/2; i++)
	{
		char temp = str[i];
		str[i] = str[length-i-1];
		str[length-i-1] = temp;
	}

	printf("Reverse of the string is: %s", str);

	return 0;
}