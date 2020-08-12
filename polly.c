#include<stdio.h>
#include<malloc.h>
#include<math.h>
struct poly
{
	int coef,exp;
	struct poly *link;
};
struct poly *insert(struct poly *head,struct poly *newnode)
{
	struct poly *curr,*prev;
	curr=head;
	prev=head;
	if(head == NULL)
	{
		head=newnode;
	}
	else
	{
		while(newnode->exp < curr->exp && curr->link!=NULL)
		{
			prev=curr;
			curr=curr->link;
		}
		if(curr == head)
		{
			if(newnode->exp == curr->exp)
			{
				curr->coef = curr->coef + newnode->coef;
			}
			else
			{
				if(newnode->exp < curr->exp)
				{
					curr->link=newnode;
				}
				else
				{
					newnode->link=curr;
					head=newnode;
				}
			}
		}
		else
		{
			if(curr->link == NULL)
			{
				if(newnode->exp == curr->exp)
				{
					curr->coef=curr->coef + newnode->coef;
				}
				else
				{
					if(newnode->exp < curr->exp)
					{
						curr->link=newnode;
					}
					else
					{
						prev->link=newnode;
						newnode->link=curr;
					}
				}
			}
			else
			{
				if(newnode->exp == curr->exp)
				{
					curr->coef=curr->coef + newnode->coef;
				}
				else
				{
					prev->link=newnode;
					newnode->link=curr;
				}
			}
		}
	}
	return head;
}
struct poly *create(struct poly *head,int n)
{
	int i;
	struct poly *newnode,*curr;
	for(i=0;i<n;i++)
	{
		newnode=(struct poly *)malloc(sizeof(struct poly));
		printf("Enter Exponent and Coeffient:- ");
		scanf("%d%d",&newnode->exp,&newnode->coef);
		newnode->link=NULL;
		head=insert(head,newnode);
	}
	curr=head;
	while(curr->link!=NULL)
	{
		curr=curr->link;
	}
	curr->link=head;
	return head;
}
void display(struct poly *head)
{
	struct poly *p;
	p=head;
	if(p!=NULL)
	{	
		while(p->link!=head)
		{
			printf("%d X ^ %d + ",p->coef,p->exp);
			p=p->link;
		}
		printf("%d X ^ %d ",p->coef,p->exp);
	}
}
struct poly *add(struct poly *headAdd,struct poly *headP1, struct poly *headP2)
{	
	struct poly *curr,*newnode;
	curr=headP1;
	while(curr->link!=headP1)
	{
		newnode=(struct poly *)malloc(sizeof(struct poly));
		newnode->exp=curr->exp;
		newnode->coef=curr->coef;
		newnode->link=NULL;
		headAdd=insert(headAdd,newnode);
		curr=curr->link;
	}
	newnode=(struct poly *)malloc(sizeof(struct poly));
	newnode->exp=curr->exp;
	newnode->coef=curr->coef;
	newnode->link=NULL;
	headAdd=insert(headAdd,newnode);
	curr=headP2;
	while(curr->link!=headP2)
	{
		newnode=(struct poly *)malloc(sizeof(struct poly));
		newnode->exp=curr->exp;
		newnode->coef=curr->coef;
		newnode->link=NULL;
		headAdd=insert(headAdd,newnode);
		curr=curr->link;
	}
	newnode=(struct poly *)malloc(sizeof(struct poly));
	newnode->exp=curr->exp;
	newnode->coef=curr->coef;
	newnode->link=NULL;
	headAdd=insert(headAdd,newnode);
	curr=headAdd;
	while(curr->link!=NULL)
	{	
		curr=curr->link;
	}
	curr->link=headAdd;
	return headAdd;
}
struct poly *mul(struct poly *headMul,struct poly *headP1,struct poly *headP2)
{
	struct poly *curr,*currP1,*currP2,*newnode;
	currP1=headP1;
	currP2=headP2;
	while(currP1->link!=headP1)
	{
		currP2=headP2;
		while(currP2->link!=headP2)
		{
			newnode=(struct poly *)malloc(sizeof(struct poly));
			newnode->coef=currP1->coef * currP2->coef;
			newnode->exp=currP1->exp + currP2->exp;
			newnode->link=NULL;
			headMul=insert(headMul,newnode);
			currP2=currP2->link;
		}
		newnode=(struct poly *)malloc(sizeof(struct poly));
		newnode->coef=currP1->coef * currP2->coef;
		newnode->exp=currP1->exp + currP2->exp;
		newnode->link=NULL;
		headMul=insert(headMul,newnode);
		currP1=currP1->link;
	}
	currP2=headP2;
	while(currP2->link!=headP2)
	{
		newnode=(struct poly *)malloc(sizeof(struct poly));
		newnode->coef=currP1->coef * currP2->coef;
		newnode->exp=currP1->exp + currP2->exp;
		newnode->link=NULL;
		headMul=insert(headMul,newnode);
		currP2=currP2->link;
	}
	newnode=(struct poly *)malloc(sizeof(struct poly));
	newnode->coef=currP1->coef * currP2->coef;
	newnode->exp=currP1->exp + currP2->exp;
	newnode->link=NULL;
	headMul=insert(headMul,newnode);
	curr=headMul;
	while(curr->link!=NULL)
	{
		curr=curr->link;
	}
	curr->link=headMul;
	return headMul;
}
	
int main()
{
	int ch,n;
	struct poly *headP1=NULL, *headP2=NULL, *headAdd=NULL, *headMul=NULL;
	while(ch!=5)
	{
		printf("\n1)Insert Polynomial\n2)Display Polynomial\n3)Addition of Polynomials\n4)Multiplication of Polynomials\n5)Exit");
		printf("\nEnter your choice:- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("How many terms you want to enter for first polynomial:- ");
				scanf("%d",&n);
				headP1 = create(headP1,n);
				printf("How many terms you want to enter for second polynomial:- ");
				scanf("%d",&n);
				headP2 = create(headP2,n);
				break;
				
			case 2:
				display(headP1);
				printf("\n");
				display(headP2);
				break;
				
			case 3:
				headAdd=add(headAdd,headP1,headP2);
				display(headAdd);
				break;
				
			case 4:
				headMul=mul(headMul,headP1,headP2);
				display(headMul);
				break;
		}
	}
}
		
