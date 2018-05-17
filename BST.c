#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;	
}*ROOT,*PAR;

struct node *LOC;

void find(int ITEM)
{
    struct node *PTR,*SAVE;
    if(ROOT==NULL)
    {
        LOC=NULL;
        PAR=NULL;
        return;
    }

    if(ITEM==ROOT->data)
    {
        LOC=ROOT;
        PAR=NULL;
        return;
    }

    if(ITEM<ROOT->data)
    {
    	PTR=ROOT->left;
    	SAVE=ROOT;
    }

    else
    {
        PTR=ROOT->right;
        SAVE=ROOT;
    }

    while(PTR!=NULL)
    {
        if(ITEM==PTR->data)
        {
            LOC=PTR;
            PAR=SAVE;
            return;
        }

        if(ITEM<PTR->data)
        {
            SAVE=PTR;
            PTR=PTR->left;
        }

        else
        {
            SAVE=PTR;
            PTR=PTR->right;
        }
    }

    LOC=NULL;
    PAR=SAVE;
}

void insert(int ITEM)
{
    struct node *temp;
    find(ITEM);

    if(LOC!=NULL)
        return;

    temp=(struct node*)malloc(sizeof(struct node));
    LOC=temp;
    temp->data=ITEM;
    temp->left=temp->right=NULL;

    if(PAR==NULL)
        ROOT=temp;
    else
    {
        if(ITEM<PAR->data)
            PAR->left=temp;
        else
            PAR->right=temp;
    }

}

void in_order(struct node *node)
{
    if(node==NULL)
        return;

    in_order(node->left);
    printf(" %d",node->data);
    in_order(node->right);
}


int main()
{
    ROOT=NULL, PAR=NULL;
    int i, n, data;

    printf("\nEnter no of items to be inserted: ");
    scanf("%d",&n);
    int arr[n];

    for(i=0;i<n;i++)
    {
        printf("\nEnter info: ");
        scanf("%d",&arr[i]);
        insert(arr[i]);
    }

    in_order(ROOT);

    return 0;
}
