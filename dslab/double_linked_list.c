#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *prev;
	struct Node *next;
	int data;
} node;

node* create_node(int data)
{
	node *temp = (node*) malloc(sizeof(node));
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = data;
	return temp;
}

node* insert_pos(node* head, int pos, int data)
{
	node *temp = create_node(data);
	if(head == NULL)
	{
		if(pos == 1)
			head = temp;
		else
		{
			printf("\nInvalid position for empty list!\n");
			free(temp);
		}
	}
	else
	{
		node *p = head;
		if(pos == 1)
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		else
		{
			int count = 2;
			p = p->next;
			while(p != NULL)
			{
				if(count == pos)
				{
					temp->next = p;
					temp->prev = p->prev;
					p->prev->next = temp;
					p->prev = temp;
					break;
				}
				p = p->next;
				count++;
			}
			if(p == NULL)
			{
				printf("Invalid Position!");
				free(temp);
			}
		}
	}
	return head;
}

node* insert_front(node* head, int data)
{
	node *temp = create_node(data);
	if(head == NULL)
		head = temp;
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	return head;
}

node* insert_back(node* head, int data)
{
	node *temp = create_node(data);
	if(head == NULL)
		head = temp;
	else
	{
		node *p = head;
		while(p->next != NULL)
			p = p->next;

		p->next = temp;
		temp->prev = p;
	}
	return head;
}

node* delete_front(node* head)
{
	if(head == NULL)
		printf("Underflow.");
	else
	{
		node *temp = head;
		head = head->next;
		temp->next = NULL;
		if(head != NULL)
			head->prev = NULL;
		free(temp);
	}
	return head;
}

node* delete_back(node* head)
{
	if(head == NULL)
		printf("Underflow.");
	else
	{
		node *p = head;
		if(p->next == NULL)
		{
			free(p);
			head = NULL;
		}
		else
		{
			while(p->next != NULL)
				p = p->next;

			p->prev->next = NULL;
			p->prev = NULL;
			free(p);	
		}
	}
	return head;
}

node* delete_item(node* head, int data)
{
	node *p = head;
	if(head == NULL)
		printf("Underflow.");
	else
	{
		if(head->data == data)
		{
			head = head->next;
			p->next = NULL;
			if(head != NULL)
				head->prev = NULL;
			free(p);
		}
		else
		{
			p = p->next;
			while(p != NULL)
			{
				if(p->data == data)
				{
					p->prev->next = p->next;
					if(p->next != NULL)
						p->next->prev = p->prev;
					p->next = NULL;
					p->prev = NULL;
					free(p);
					break;
				}
				p = p->next;
			}
			if(p == NULL)
				printf("\nItem not found!\n");
		}
	}
	return head;
}

void display(node* head)
{
	if(head == NULL)
		printf("\nThe list is empty.\n");
	else
	{
		node *p = head;
		printf("\nThe items in the list are: \n");
		while(p != NULL)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
}

void display_rev(node* head)
{
	if(head == NULL)
		printf("\nThe list is empty.\n");
	else
	{
		node *p = head;
		printf("\nThe items in reverse order are: \n");

		while(p->next != NULL)
			p = p->next;

		while(p != NULL)
		{
			printf("%d ", p->data);
			p = p->prev;
		}
	}
}

int main()
{
	node *head = NULL;
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
		printf("\n4. Display Reverse.");
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
								printf("Invalid Choice!");
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

			case 4: display_rev(head);
					break;

			case 0: break;

			default:
					printf("Invalid Choice!");
		}
	}

	return 0;
}