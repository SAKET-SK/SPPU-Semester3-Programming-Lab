#include<stdio.h>
typedef struct bank_dt
{
	int acc_no;
	char cust_name[50];
	int acc_balance;
}bank_dt;
void main()
{
	bank_dt s1[30];
	int i,pos,ch,n,rn,rn1;
	void create(bank_dt[],int);
	void display(bank_dt[],int);
	void add(bank_dt[],int);
	int search(bank_dt[],int,int);
	void modify(bank_dt[],int,int);
	printf("------BANK DATABASE------");
	do
	{
		printf("\n1)Create\n2)Display\n3)Add\n4)Search\n5)Modify\n");
		printf("\nEnter your choice:- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the no of customer:- ");
				scanf("%d",&n);
				create(s1,n);
				break;
				
			case 2:
				display(s1,n);
				break;
				
			case 3:
				add(s1,n);
				n++;
				break;
				
			case 4:
				printf("Enter the customer id to be searched:- ");
				scanf("%d",&rn);
				pos=search(s1,rn,n);
				if(pos==-1)
					printf("Record not found!");
				else
				{
					printf("Element found at location %d",pos+1);
					printf("\n\t%d\t%s\t%d",s1[pos].acc_no,s1[pos].cust_name,s1[pos].acc_balance);
				}
				break;
				
			case 5:
				printf("Enter customer id to be modified:- ");
				scanf("%d",&rn1);
				modify(s1,rn1,n);
				break;
		}
	}while(ch!=6);
}
void create(bank_dt s1[],int n)
{
	int i;
	printf("Enter the data of %d customer(s):- ",n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter customer account no,customer name and account balance:- ");
		scanf("%d%s%d",&s1[i].acc_no,s1[i].cust_name,&s1[i].acc_balance);
	}
}
void display(bank_dt s1[],int n)
{
	int i;
	printf("----THE BANK DATA IS----");
	printf("\n\tACC_NO\tCUST_NAME\t\tBALANCE");
	for(i=0;i<n;i++)
	{
		printf("\n\t%d\t%s\t\t\t%d",s1[i].acc_no,s1[i].cust_name,s1[i].acc_balance);
	}
}
void add(bank_dt s1[],int n)
{
	printf("Enter the data of customer to be added:");
	printf("\nEnter customer id,customer namr and account balance:- ");
	scanf("%d%s%d",&s1[n].acc_no,s1[n].cust_name,&s1[n].acc_balance);
}
int search(bank_dt s1[],int rn,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(rn==s1[i].acc_no)
		{
			return(i);
		}
	}
	return(-1);
}
void modify(bank_dt s1[],int rn1,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(rn1==s1[i].acc_no)
		{
			printf("\nEnter the modified customer name:- ");
			scanf("%s",&s1[i].cust_name);
			printf("\nEnter the modified account balance:- ");
			scanf("%d",&s1[i].acc_balance);
			break;
		}
	}
}




















































































