#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* link;
} node;

node* delete_front(node* head)
{
	node *temp;
	temp = head;

	if(head == NULL)
		printf("\nUnderflow.\n");
	else
	{
		head = head->link;
		temp->link = NULL;
		free(temp);
	}
	return head;
}

node* delete_back(node* head)
{
	node *p, *prev;
	p = head;
	prev = NULL;

	if(head == NULL)
		printf("\nUnderflow.\n");
	else
	{
		while(p->link != NULL)
		{
			prev = p;
			p = p->link;
		}
		if(prev == NULL)
			head = NULL;
		else
			prev->link = NULL;
		free(p);
	}
	return head;
}

node* delete_item(node* head, int data)
{
	node *p, *prev;
	p = head;
	prev = NULL;

	if(head == NULL)
		printf("\nUnderflow.\n");
	else
	{
		if(p->data == data)
		{
			head = head->link;
			p->link = NULL;
			free(p);
		}
		else
		{
			prev = p;
			p = p->link;
			while(p != NULL)
			{
				if(p->data == data)
				{
					prev->link = p->link;
					p->link = NULL;
					free(p);
					break;
				}
				prev = p;
				p = p->link;
			}
			if(p == NULL)
				printf("\nItem not found!\n");
		}
	}
	return head;
}

node* insert_back(node* head, int data)
{
	node *temp, *p;
	temp = (node*) malloc(sizeof(node));
	temp->data = data;
	temp->link = NULL;
	if(head == NULL)
		head = temp;
	else
	{
		p = head;
		while(p->link != NULL)
			p = p->link;

		p->link = temp;
	}
	return head;
}

node* insert_front(node* head, int data)
{
	node *temp = (node*) malloc(sizeof(node));
	temp->data = data;
	temp->link = head;
	head = temp;
	return head;
}

node* insert_pos(node* head, int pos, int data)
{
	node *p, *temp, *prev;
	p = head;
	int count = 1;
	temp = (node*) malloc(sizeof(node));
	temp->data = data;
	temp->link = NULL;

	if(head == NULL)
		if(pos == 1)
			head = temp;
		else
		{
			printf("\nInvalid position for empty list!\n");
			free(temp);
		}
	else
	{
		if(pos == 1)
		{
			temp->link = head;
			head = temp;
		}
		else
		{
			prev = p;
			p = p->link;
			while(p != NULL)
			{
				count++;
				if(count == pos)
				{
					prev->link = temp;
					temp->link = p;
					break;
				}
				prev = p;
				p = p->link;
			}
			if(p == NULL)
			{
				printf("\nInvalid Position!\n");
				free(temp);
			}
		}
	}
	return head;
}

void display(node* head)
{
	node *p;
	p = head;
	if(head == NULL)
		printf("\nThe list is empty.\n");
	else
	{
		printf("\nItems in the list are: \n");
		while(p != NULL)
		{
			printf("%d ", p->data);
			p = p->link;
		}
	}
}

int main()
{
	node* head = NULL;
	int data, n, i;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);

	printf("Enter the values: \n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &data);
		head = insert_back(head, data);
	}

	display(head);

	int ch = 1;
	while(ch != 0)
	{
		printf("\n\n1. Insert.");
		printf("\n2. Delete.");
		printf("\n3. Display.");
		printf("\nEnter 0 to exit.");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: int ch1;
					printf("\n1. Insert at front.");
					printf("\n2. Insert at end.");
					printf("\n3. Insert at a position.");
					printf("\nEnter your choice: ");
					scanf("%d", &ch1);
					switch(ch1)
					{
						case 1: printf("Enter a value: ");
								scanf("%d", &data);
								head = insert_front(head, data);
								display(head);
								break;

						case 2: printf("Enter a value: ");
								scanf("%d", &data);
								head = insert_back(head, data);
								display(head);
								break;

						case 3: int pos;
								printf("Enter position: ");
								scanf("%d", &pos);
								printf("Enter a value: ");
								scanf("%d", &data);
								head = insert_pos(head, pos, data);
								display(head);
								break;

						default:
								printf("Invalid choice!");
					}
					break;

			case 2: int ch2;
					printf("\n1. Delete at front.");
					printf("\n2. Delete at back.");
					printf("\n3. Delete a specific item.");
					printf("\nEnter your choice: ");
					scanf("%d", &ch2);
					switch(ch2)
					{
						case 1: head = delete_front(head);
								display(head);
								break;

						case 2: head = delete_back(head);
								display(head);
								break;

						case 3: printf("Enter an item to delete: ");
								scanf("%d", &data);
								head = delete_item(head, data);
								display(head);
								break;

						default: 
								printf("Invalid Choice!");
					}
					break;

			case 3: display(head);
					break;

			case 0: break;

			default: 
					printf("Invalid choice!");
		}
	}

	return 0;
}