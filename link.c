#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node * create();
void display(struct node *temp);
void displayReverse(struct node *temp);

struct node * insertStart(struct node *temp);
void insertEnd(struct node *temp);
void insertMiddle(struct node *temp);

struct node * deleteStart(struct node *temp);
void deleteMiddle(struct node *temp);
void deleteEnd(struct node *temp);

int main()
{
	struct node *start;
	int choice;
	char repeat;
	start=create();
	do
	{
		printf("\n1. Display\n2. Insert\n3. Delete\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				{
					printf("\nDisplay list\n1. Forward\n2. Reverse\nEnter your choice: ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
							{
								display(start);
								break;
							}
						case 2:
							{
								displayReverse(start);
								break;
							}
						default:
							{
								printf("\nInvalid selection!");
								break;
							}
					}
					break;
				}
			case 2:
				{
					printf("\nInsert node\n1. Start\n2. Middle\n3. End\nEnter your choice: ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
							{
								start=insertStart(start);
								break;
							}
						case 2:
							{
								insertMiddle(start);
								break;
							}
						case 3:
							{
								insertEnd(start);
								break;
							}
						default:
							{
								printf("\nInvalid selection!");
								break;
							}
					}
					break;
				}
			case 3:
				{
					printf("\nDelete node\n1. Start\n2. Middle\n3. End\nEnter your choice: ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
							{
								start=deleteStart(start);
								break;
							}
						case 2:
							{
								deleteMiddle(start);
								break;
							}
						case 3:
							{
								deleteEnd(start);
								break;
							}
						default:
							{
								printf("\nInvalid selection!");
								break;
							}
					}
					break;
				}
			default:
				{
					printf("\nInvalid selection!");
					break;
				}
		}
		printf("\nDo you want to perform another operation? ");
		scanf(" %c", &repeat);
	}
	while(repeat=='y' || repeat=='Y');
	return 0;
}

struct node * create()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d", &newnode->data);
	newnode->link=NULL;
	return newnode;
}


void display(struct node *temp)
{
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->link;
	}
}

void displayReverse(struct node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	displayReverse(temp->link);
	printf("%d ", temp->data);
}

struct node * insertStart(struct node *temp)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d", &newnode->data);
	newnode->link=temp;
	temp=newnode;
	return temp;
}

void insertEnd(struct node *temp)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d", &newnode->data);
	newnode->link=NULL;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=newnode;
}

void insertMiddle(struct node *temp)
{
	int search;
	printf("Enter element after which you want to insert the node: ");
	scanf("%d", &search);
	while(temp->data!=search)
	{
		temp=temp->link;
	}
	if(temp->data==search)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter data: ");
		scanf("%d", &newnode->data);
		newnode->link=temp->link;
		temp->link=newnode;
	}
	else if(temp->link==NULL)
		printf("\nElement not found!");
}

struct node * deleteStart(struct node *temp)
{
	struct node *p;
	p=temp;
	temp=p->link;
	printf("\nDeleted!");
	return temp;
}

void deleteMiddle(struct node *temp)
{
	struct node *p, *q;
	int del;
	printf("\nEnter element to delete: ");
	scanf("%d", &del);
	p=temp;
	while(p->data!=del)
	{
		q=p;
		p=p->link;
	}
	q->link=p->link;
	free(p);
	printf("\nDeleted!");
}

void deleteEnd(struct node *temp)
{
	struct node *p, *q;
	p=temp;
	while(p->link!=NULL)
	{
		q=p;
		p=p->link;
	}
	q->link=NULL;
	printf("\nDeleted!");
	free(p);
}

