#include<stdio.h>
 struct sparse
 {
 	int rows,cols,values;
 };
 
int accept(int[][5],struct sparse [20]);
int display(struct sparse [20],int);
int add(struct sparse [20],struct sparse [20],struct sparse[20]);
void simpleTranspose(struct sparse [20],struct sparse [20]);
 
 int main()
 {
 	struct sparse s1[20],s2[20],s3[20],s4[20];
 	int k,l,m,st,choice;
 	int MatA[5][5],MatB[5][5];
	do
	{
	  printf("\nCHOOSE THE OPERATION THAT YOU WANT TO PERFORM:\n");
	  printf("1.Accept\n2.Display\n3.Add\n4.Simple Transpose\n5.Exit\n");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	    case 1:
	    k=accept(MatA,s1);
	    l=accept(MatB,s2);
	    break;
	    
	    case 2:
	    display(s1,k);
	    display(s2,l);
	    break;
	    
	    case 3:
	    m=add(s1,s2,s3);
	    display(s3,m);
	    
	    case 4:
	    st=simpleTranspose(a,b);
	    display(s4,st);
	}
	
	}
	while(choice!=5);
 }
 
int accept(int MatA[][5],struct sparse s[10])
 {

 	int r,c;
 	int i,j,k=1,l;
 	printf("\nEnter the number of rows: ");
 	scanf("%d",&r);
 	printf("\nEnter the number of columns: ");
 	scanf("%d",&c);
 	
 	//ACCEPTING NORMAL MATRIX
 	printf("\nEnter the elements: ");
 	for(i=0;i<r;i++)
 		{
 			for(j=0;j<c;j++)
 			{
 				scanf("%d",&MatA[i][j]);
 			}
 		}
 	
 	//CONVERSION INTO SPARSE MATRIX
 		s[0].rows=r;
 		s[0].cols=c;
 	for(i=0;i<r;i++)
 		{
 			for(j=0;j<c;j++)
 			{
 				if(MatA[i][j]!=0)
 					{
 						s[k].rows=i;
 						s[k].cols=j;
 						s[k].values=MatA[i][j];
 						k++;
 					}
 			}
 		}
 		s[0].values=k-1;
return k;
 }

int display(struct sparse s[20],int k)
{
int i;
printf("\nNo.\tRows\tColumns\tValue\n");
for(i=0;i<k;i++)
	{
		printf("\n%d\t%d\t%d\t%d",i,s[i].rows,s[i].cols,s[i].values);
	}
	printf("\n");
}

int add(struct sparse s1[20],struct sparse s2[20],struct sparse s3[20])
{
int i=1,j=1,k=1;
  while(i<=s1[0].values||j<=s2[0].values)
	{
		if(s1[i].rows==s2[i].rows && s1[i].cols==s2[i].cols)
			{
				s3[k].rows=s1[i].rows;
				s3[k].cols=s1[i].cols;
				s3[k].values=s1[i].values+s2[j].values;
				i++;
				j++;
				k++;
			}
		else
		if((s1[i].rows==s2[j].rows && s1[i].cols>s2[j].cols)||(s1[i].rows>s2[j].rows))
			{
				s3[k].rows=s2[j].rows;
				s3[k].cols=s2[j].cols;
				s3[k].values=s2[j].values;
				j++;
				k++;	
			}
				
		else
			{
				s3[k].rows=s1[i].rows;
				s3[k].cols=s1[i].cols;
				s3[k].values=s1[i].values;
				i++;
				k++;	
			}
	}
	s3[0].rows=s1[0].rows;
	s3[0].cols=s1[0].cols;
	s3[0].values=k-1;
	return k;
}
// SIMPLE TRANSPOSE OF SPARSE MATRIX
void simpleTranspose(struct sparse MatA[],struct sparse MatB[])
{
	//TRANSPOSE OF MATRIX A
	struct sparse c[20];
	c[0].row=a[0].col;
	c[0].col=a[0].row;
	c[0].value=a[0].value;
	int i,j,k=1;
	if(a[0].value>0)
	{
		for(i=0;i<a[0].col;i++)
		{
			for(j=1;j<=a[0].value;j++)
			{
				if(a[j].col==i)
				{
					c[k].row=a[j].col;
					c[k].col=a[j].row;
					c[k].value=a[j].value;
					k++;
				}
			}
		}
	}
     printf("\nTranspose of matrix a :\n\n");
	//PRINTING THE TRANSPOSE OF SPARSE MATRIX A
	for(i=1;i<=c[0].value;i++)
	{
		printf("%d\t%d\t%d\n",c[i].row,c[i].col,c[i].value);
	}

    //TRANSPOSE OF MATRIX B
	c[0].row=b[0].col;
	c[0].col=b[0].row;
	c[0].value=b[0].value;
	k=1;
	if(b[0].value>0)
	{
		for(i=0;i<b[0].col;i++)
		{
			for(j=1;j<=b[0].value;j++)
			{
				if(b[j].col==i)
				{
					c[k].row=b[j].col;
					c[k].col=b[j].row;
					c[k].value=b[j].value;
					k++;
				}
			}
		}
	}
     printf("\ntranspose of matrix b :\n\n");
	//PRINTING THE TRANSPOSE OF SPARSE MATRIX B
	for(i=1;i<=c[0].value;i++)
	{
		printf("%d\t%d\t%d\n",c[i].row,c[i].col,c[i].value);
	}

}


