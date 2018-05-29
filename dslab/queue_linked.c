#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* link;
} node;

node *front = NULL, *rear = NULL;

int qdelete()
{
	if(front == NULL || rear == NULL)
	{
		printf("\nUnderflow!\n");
		front = rear = NULL;
		return -1;
	}
	else
	{
		node *p = front;
		int item = p->data;
		front = front->link;
		free(p);
		return item;
	}
}

void qinsert(int item)
{
	node *tmp = (node*) malloc(sizeof(node));
	tmp->data = item;
	tmp->link = NULL;

	if(rear == NULL)
	{
		front = tmp;
		rear = tmp;
	}
	else
	{
		rear->link = tmp;
		rear = tmp;
	}
}

void display()
{
	if(front == NULL || rear == NULL)
	{
		printf("\nList is empty.\n");
		return;
	}
	else
	{
		node *p = front;
		printf("\nItems are:\n");
		while(p != NULL)
		{
			printf("%d ", p->data);
			p = p->link;
		}
	}
}

int main()
{
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
					qinsert(item);
					break;

			case 2: item = qdelete();
					if(item != -1)
						printf("Item removed: %d \n", item);
					break;

			case 3: display();
					break;

			case 0: break;

			default:
					printf("Invalid Choice!\n");
		}
	} while(ch != 0);
	return 0;
}