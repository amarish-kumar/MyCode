#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* link;
} node;

node* insert(node* head, int data)
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

void display(node* head)
{
	node *p;
	p = head;
	if(head == NULL)
		printf("The list is empty.");
	else
	{
		printf("The values entered are: \n");
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
		head = insert(head, data);
	}

	display(head);

	return 0;
}