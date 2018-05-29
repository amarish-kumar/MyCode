#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* link;
} node;

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
	node *head, *head1, *head2;
	head = head1 = head2 = NULL;

	int n, item, i;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("Enter the elements: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &item);
		head = insert_back(head, item);
	}

	node *p = head;
	for(i = 0; i < n; i++)
	{
		if(i % 2 == 0)
			head1 = insert_back(head1, p->data);
		else
			head2 = insert_back(head2, p->data);
		p = p->link;
	}

	display(head1);
	display(head2);

	return 0;
}