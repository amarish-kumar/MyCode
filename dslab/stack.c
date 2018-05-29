#include <stdio.h>

#define MAXSIZE 10

typedef struct
{
	int arr[MAXSIZE];
	int top;
} Stack;

void push(Stack *stack, int &top, int item)
{
	if(top == MAXSIZE-1)
	{
		printf("\nOverflow!\n");
		return;
	}
	
	top += 1;
	stack->arr[top] = item;
}

int pop(Stack *stack, int &top)
{
	if(top == -1)
	{
		printf("\nUnderflow\n");
		return -1;
	}
	int item = stack->arr[top];
	top -= 1;
	return item;
}


int main()
{
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
					push(&stack, stack.top, item);
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