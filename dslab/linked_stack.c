#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int data;
	struct Stack *link;
} stack;

int main()
{
	stack *top;


	int ch, item;
	Stack stack;
	stack.top = -1;

	do
	{
		printf("\n-------------------\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("0. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: printf("Enter an item: ");
					scanf("%d", &item);
					push(top, item);
					break;

			case 2: item = pop(&stack, stack.top);
					if(item != -1)
						printf("Item popped: %d \n", item);
					break;

			case 0: break;

			default:
					printf("Invalid Choice!\n");
		}
	} while(ch != 0);

	return 0;
}