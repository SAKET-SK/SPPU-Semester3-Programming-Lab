#include<stdio.h>
void quicksort(int[],int,int);
int main()
{
	int i,n;
	int list[20];
	printf("Enter number of elements:- ");
	scanf("%d",&n);
	printf("\nEnter the elemets:- ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
	}
	quicksort(list,0,n-1);
	printf("\nThe sorted list is:- ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",list[i]);
	}
}
void quicksort(int list[],int left,int right)
{
	int i,j,pivot,temp,temp1;
	if(left<right)
	{
		i=left;
		j=right;
		pivot=left;
		while(i<j)
		{
			while(list[i]<=list[pivot])
			{
				i++;
			}
			while(list[j]>list[pivot])
			{
				j--;
			}
			if(i<j)
			{
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}
		}
		temp1=list[pivot];
		list[pivot]=list[j];
		list[j]=temp1;
		quicksort(list,left,j-1);
		quicksort(list,j+1,right);
	}
}
		


