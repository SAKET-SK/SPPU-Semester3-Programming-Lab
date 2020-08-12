#include<stdio.h>
int getdata(char str[]);
void display(char str[]);
int str_len(char str[]);
int str_len1(char *);
void str_cpy(char str1[],char str2[]);
void str_cpy1(char *,char *);
void str_pal(char str[]);
void str_pal1(char *);
void str_com(char str1[],char str2[]);
void str_com1(char *,char *);
void str_rev(char str1[],char str2[]);
void str_rev1(char *,char *);
void str_con(char str1[],char str2[]);
void str_con1(char *,char *);
void str_sub(char str1[],char str2[],int);
void str_sub1(char *,char *,int);

int main()
{
char str1[20],str2[20];
int i,j,length,ch,yn;

do
{
printf("\n1:Length of String \n2:Length of String using pointer \n3:Copy The String \n4:Copy String using pointer \n5:Reverse of String without pointer \n6:Reverse of String with pointer \n7:Concatenation of String \n8:Concatenation of String using pointer \n9:Palindrome of a string \n10:Palindrome using pointer \n11:Compare two strings \n12:Compare using pointer \n13:Substring of String \n14:Substring of string using pointer");
printf("\n Enter your Choice:");
scanf("%d",&ch);

switch(ch)
{
case 1:
	getdata(str1);
	display(str1);
	str_len(str1);
	break;
	
	
case 2:
	getdata(str1);
	display(str1);
	str_len1(str1);
	break;
	

case 3:
	getdata(str1);
	display(str1);
	str_cpy(str1,str2);
	break;
	
	
case 4:
	getdata(str1);
	display(str1);
	str_cpy1(str1,str2);
	break;
	
	
case 5:
	getdata(str1);
	display(str1);
	str_rev(str1,str2);
	break;
	
case 6:
	getdata(str1);
	display(str1);
	str_rev1(str1,str2);
	break;
	
case 7:
	getdata(str1);
	display(str1);
	getdata(str2);
	display(str2);
	str_con(str1,str2);
	break;
	
case 8:
	getdata(str1);
	display(str1);
	getdata(str2);
	display(str2);
	str_con1(str1,str2);
	break;
	
case 9:
	getdata(str1);
	display(str1);
	str_pal(str1);
	break;

case 10:
	getdata(str1);
	display(str1);
	str_pal1(str1);
	break;

case 11:
	getdata(str1);
	display(str1);
	getdata(str2);
	display(str2);
	str_com(str1,str2);
	break;

case 12:
	getdata(str1);
	display(str1);
	getdata(str2);
	display(str2);
	str_com1(str1,str2);
	break;
	
case 13:
	getdata(str1);
	display(str1);
	getdata(str2);
	display(str2);
	length=str_len(str2);
	str_sub(str1,str2,length);
	break;
	
case 14:
	getdata(str1);
	display(str1);
	getdata(str2);
	display(str2);
	length=str_len1(str2);
	str_sub(str1,str2,length);
	break;

default:
	printf("\nWrong Choice");

}

	printf("\n Do you want to continue:\n1:Yes \n2:No");
	printf("\n Enter your Choice:");
	scanf("%d",&yn);
}
while(yn==1);
}


int getdata(char str[20])
{
	printf("\nEnter the String:");
	scanf("%s",str);
	return 0;
}

void display(char str[20])
{
printf("\n%s",str);
}

//length without ptr
int str_len(char str1[20])
{
	int i,length=0;

	for(i=0;str1[i]!='\0';i++)
	{
	length++;
	}
	printf("\n String is:%s",str1);
	printf("\n Length of the String is:%d",length);
	return length;
}

//length using ptr
int str_len1(char *str1)
{
	int i,length=0;
	for(i=0;*(str1+i)!='\0';i++)
	{
	length++;
	}
	printf("\n String is:%s",str1);
	printf("\nLength of string is:%d",length);
	return length;
}

//copy without ptr
void str_cpy(char str1[20],char str2[20])
{
	int i=0;
	for(i=0;str1[i]!='\0';i++)
	{
	str2[i]=str1[i];
	}
	str2[i]='\0';
	printf("\nCopied string is:%s",str2);
}

//copy using ptr
void str_cpy1(char *str1,char *str2)
{
	int i=0;
	for(i=0;(*(str1+i))!='\0';i++)
	{
	(*(str2+i))=(*(str1+i));
	}
	(*(str2+i))='\0';
	printf("\nCopied string is:%s",str2);
}

//reverse without ptr
void str_rev(char str1[20],char str2[20])
{
	int i=0,j=0;
	while(str1[i]!='\0')
	{
	i++;
	}
	i=i-1;
	while(i>=0)
	{
	str2[j]=str1[i--];
	j++;
	}
	str2[j]='\0';
	printf("\n Reverse of String is:%s",str2);
}

//reverse using ptr
void str_rev1(char *str1,char *str2)
{
	int i=0,j=0;
	while((*(str1+i))!='\0')
	{
	i++;
	}
	i=i-1;
	while(i>=0)
	{
	(*(str2+j))=(*(str1+i--));
	j++;
	}
	(*(str2+j))='\0';
	printf("\n Reverse of String is:%s",str2);
}

//concatenate without ptr
void str_con(char str1[20],char str2[20])
{
	int i=0,j=0;
	
	for(i=0;str1[i]!='\0';i++);
	for(j=0;str2[j]!='\0';j++)
	{
	str1[i++]=str2[j];
	}
	str1[i]='\0';
	printf("\nConcatenated string is:%s",str1);
	
}

	
//concatenate using ptr
void str_con1(char *str1,char *str2)
{
	int i=0,j=0;
	
	for(i=0;(*(str1+i)!='\0');i++);
	for(j=0;(*(str2+j)!='\0');j++)
	{
	(*(str1+i++))=(*(str2+j));
	}
	(*(str1+i))='\0';
	printf("\nConcatenated string is:%s",str1);
	
}
	
//palindrome without ptr	
void str_pal(char str1[20])
{

  int i=0,j=0,flag=0;
  while(str1[i]!='\0')
  		{
        i++;
        }
        i--;
        while(str1[j]!='\0')
          {
           if(str1[i--]!=str1[j])
              {
               flag=1;
               break;
              }
              j++;
              }
           if(flag==1)
           printf("\nThe String '%s' is not Palindrome",str1);
           else
           printf("\nThe String '%s' is Palindrome",str1);
                
}

//palindrome using ptr
void str_pal1(char *str1)
{
  int i=0,j=0,flag=0;
  while(*(str1+i)!='\0')
  {
       i++;
  }
       i--;
       while(*(str1+j)!='\0')
          {
            if(*(str1+(i--))!=(*(str1+j)))
             {
              flag=1;
              break;
             }
             j++;
          }
          if(flag==1)
          printf("\nThe String '%s' is not Palindrome",str1);
          else
          printf("\nThe String '%s' is Palindrome",str1);
                
}

//compare without ptr
void str_com(char str1[20],char str2[20])
{
		int i=0,flag=0;
        while(str1[i]!='\0'|| str2[i]!='\0')
           {
            if(str1[i]==str2[i])
            flag=1;
            else
			{
			flag=0;
            break;
            }
                       
            i++;
           }
           if(flag==1)
           printf("\nBoth Strings are Equal");   
           else
           printf("\nBoth Strings are not Equal");   
}        

//compare using ptr
void str_com1(char *str1,char *str2)
{
		int i=0,flag=0;
         while(*(str1+i)!='\0'|| (*str2+i)!='\0')
          {
            if(*(str1+i)==(*(str2+i)))
            flag=1;
            else
            {
             flag=0;
             break;
            }
            i++;
          }
          if(flag==1)
          printf("\nBoth Strings are Equal");   
          else
          printf("\nBoth Strings are not Equal");   
}            
    

//substring without ptr
void str_sub(char str1[20],char str2[20],int length)
{
	int i,j,k,count=0;
	for(i=0;str1[i]!='\0';i++)
	{
	j=0,k=i;
	while(str1[k]==str2[j] && str2[j]!='\0')
	{
	k++;
	j++;
	}
	if(j==length)
	{
	count+=1;
	}
	}
	if(count>0)
	{
	printf("\nNumber of subtring prsent is:");
	printf("%d",count);
	printf("\nSecond string is substring of first");
	}
	
	if(count==0)
	{
	printf("\nSecond string is not substring of first");
	}
}


//substring using ptr
void str_sub1(char *str1,char *str2,int length)
{
	int i,j,k,count=0;
	for(i=0;(*(str1+i))!='\0';i++)
	{
	j=0,k=i;
	while((*(str1+k))==(*(str2+j)) && (*(str2+j))!='\0')
	{
	k++;
	j++;
	}
	if(j==length)
	{
	count+=1;
	}
	}
	if(count>0)
	{
	printf("\nNumber of subtring prsent is:");
	printf("%d",count);
	printf("\nSecond string is substring of first");
	}
	
	if(count==0)
	{
	printf("\nSecond string is not substring of first");
	}
}






















