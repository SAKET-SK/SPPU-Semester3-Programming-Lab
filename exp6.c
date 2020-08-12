#include<stdio.h>
#include<string.h>
 

void bubble(char[][10],int);
void selection(char[][10],int);
main()
{
char str[10][10];
int i , ch, num;

{
printf("\n 1)Sorting in Ascending order using BUBBLE SORT");
printf("\n 2)Sorting in Descending order using SELECTION SORT");
printf("\n Enter your choice:- ");
scanf("%d",&ch);
switch(ch)
{
case 1:

printf("enter the nos of elements in string\n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
scanf("%s",str[i]);
}
bubble(str ,num);
break;

case 2:


printf("enter the nos of elements in string\n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
scanf("%s",str[i]);
}
selection(str,num);

break;
}
printf("do you want to continue\n");
scanf("%d",&ch);
}
int k;
printf("do you want to search any element\n");
printf("if you want to search any element plz enter 7\n");
scanf("%d",&k);
if(k==7)
{  
printf("binary search to perform");



}
else{printf("thank you");
}
}


void bubble(char str [10][10],int num)
{
int i,j;
char temp[10];
for(i=0;i<num-1;i++)
{
for(j=0;j<num;j++)
     { 
     if(strcmp(str[j],str[j+1])>0)
     {
     strcpy(temp,str[j]);
     strcpy(str[j],str[j+1]);
     strcpy(str[j+1],temp);
     }}}
     printf("\n string in asending order using bubble sort");
     for(i=0;i<num+1;i++)
{
printf("%s",str[i]);
}
}




void selection(char str[10][10],int num) 
{
int i,j;
char temp[10];
for(i=0;i<num-1;i++)
{
for(j=i+1;j<num;j++)
     { 
     if(strcmp(str[i],str[j])>0)
     {
     strcpy(temp,str[i]);
     strcpy(str[i],str[j]);
     strcpy(str[j],temp);
     }}}
     printf("\n string in desending  order using selection  sort\n");
     for(i=0;i<num+1;i++)
{
printf("%s",str[i]);
}
}


