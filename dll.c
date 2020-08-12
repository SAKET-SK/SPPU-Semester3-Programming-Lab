#include<stdio.h>
#include<stdlib.h>
struct node
{
	int roll,marks;
	char name[30];
	struct node *prev,*next;
};
struct node* create();
void fDisplay(struct node *s);
void rDisplay(struct node *s);
struct node* insert(struct node *s);
void modify(struct node *s);
struct node* delete(struct node *s);

int main()
{
	struct node *head;
	int choice;
	head=create();
	do
	{
		printf("1)Insert\n2)Display\n3)Modify\n4)Delete\n5)Exit\nEnter your choice:- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					head=insert(head);
					break;
				}
			case 2:
				{
					printf("1)Forward\n2)Reverse\n3)Enter your choice:- ");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1:
							{
								fDisplay(head);
								break;
							}
						case 2:
							{
								rDisplay(head);
								break;
							}
					}
					break;
				}
			case 3:
				{
					modify(head);
					break;
				}
			case 4:
				{
					head=delete(head);
					break;
				}
			case 5:
				break;
			default:
				{
					printf("Invalid Choice!!");
					break;
				}
		}
	}while(choice!=5);
	return 0;
}
struct node* create()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Create Record!!\nEnter roll no:- ");
	scanf("%d",&temp->roll);
	printf("Enter name:- ");
	scanf("%s",temp->name);
	printf("Enter Marks:- ");
	scanf("%d",&temp->marks);
	temp->prev=NULL;
	temp->next=NULL;
	return temp;	
}
void fDisplay(struct node *s)
{
	printf("\n");
	while(s!=NULL)
	{
		printf("\nRoll NO:- %d\nName:- %s\nMarks:- %d\n",s->roll,s->name,s->marks);
		s=s->next;
	}
}
void rDisplay(struct node *s)
{
	struct node *temp;
	temp=s;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=s)
	{
		printf("\nRoll NO:- %d\nName:- %s\nMarks:- %d\n",temp->roll,temp->name,temp->marks);
		temp=temp->prev;
	}
	printf("\nRoll NO:- %d\nName:- %s\nMarks:- %d\n",temp->roll,temp->name,temp->marks);
}
struct node *insert(struct node *s)
{
	struct node *temp,*stemp;
	stemp=s;
	int choice,r;
	printf("\n1)Start\n2)Middle\n3)End ");
	scanf("%d",&choice);
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter Record\nEnter Roll No:- ");
	scanf("%d",&temp->roll);
	printf("Enter Name:- ");
	scanf("%s",temp->name);
	switch(choice)
	{
		case 1:
			{
				temp->prev=NULL;
				temp->next=s;
				s->prev=temp;
				s=temp;
				return s;
				break;
			}
		case 2:
			{
				printf("Enter roll no after which u want to add:- ");
				scanf("%d",&r);
				while(s->roll!=r)
				{
					s=s->next;
				}
				temp->next=s->next;
				s->next->prev=temp;
				temp->prev=s;
				s->next=temp;
				break;
			}
		case 3:
			{
				while(s->next!=NULL)
				{
					s=s->next;
				}
				temp->prev=s;
				temp->next=NULL;
				s->next=temp;
				break;
			}
	}
	return stemp;
}
void modify(struct node *s)
{
	int r,flag=0;
	printf("Enter roll no to modify:- ");
	scanf("%d",&r);
	while(s->roll!=r)
	{
		s=s->next;
	}
	if(s->roll=r)
	{
		flag=1;
		printf("Enter Modified record\nEnter roll no:- ");
		scanf("%d",&s->roll);
		printf("Enter name:- ");
		scanf("%s",s->name);
		printf("Enter marks:- ");
		scanf("%d",&s->marks);
	}
	else if(flag==0)
	{
		printf("Record Not found!!");
	}
}
struct node *delete(struct node *s)
{
	struct node *stemp;
	stemp=s;
	int r,flag=0;
	printf("Enter roll no to delete:- ");
	scanf("%d",&r);
	while(s->roll!=r)
	{
		s=s->next;
	}
	if(s->roll=r)
	{
		flag=1;
		if(s->next==NULL)
		{
			s->prev->next=NULL;
		}
		else
		{
			s->prev->next=s->next;
			s->next->prev=s->prev;
			s->next=NULL;
			s->prev=NULL;
		}
	}
	else if(flag==0)
	{
		printf("Record not found!!");
	}
	return stemp;
}
































































































