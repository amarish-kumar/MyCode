#include <stdio.h>

#define MAXSIZE 10

void insert(int *queue, int &front, int &rear, int item)
{
	if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = item;
		return;
	}
	
	if(rear == MAXSIZE-1)
	{
		printf("\nOverflow!\n");
		return;
	}
	
	queue[++rear] = item;
}

int qdelete(int *queue, int &front, int &rear)
{
	if(front == -1 && rear == -1 || front > rear)
	{
		printf("\nUnderflow!\n");
		return -1;
	}

	int item = queue[front++];
	return item;
}

void display(int *queue, int &front, int &rear)
{
	if(front == -1 && rear == -1 || front > rear)
	{
		printf("\nThe list is empty.\n");
		return;
	}

	int i;
	printf("\nThe items are: \n");
	for(i = front; i <= rear; i++)
		printf("%d ", queue[i]);
	return;
}

int main()
{
	int front = -1, rear = -1;
	int queue[MAXSIZE+1];
	int ch, item;

	do
	{
		printf("\n-------------------\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("0. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: printf("Enter an item: ");
					scanf("%d", &item);
					insert(queue, front, rear, item);
					break;

			case 2: item = qdelete(queue, front, rear);
					if(item != -1)
						printf("Item removed: %d \n", item);
					break;

			case 3: display(queue, front, rear);
					break;

			case 0: break;

			default:
					printf("Invalid Choice!\n");
		}
	} while(ch != 0);

	return 0;
}