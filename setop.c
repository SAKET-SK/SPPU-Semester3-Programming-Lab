#include<stdio.h>
void display(int [],int);
void getdata(int [],int *);
int Union(int [],int [],int [],int,int);
int intersection(int [],int [],int [],int,int);
int symmetric(int [],int [],int [],int,int);

int main()
{
  int SizeA,SizeB,i,j=0,k=0,ch;
  int setA[10],setB[10],setC[10];
   getdata(setA,&SizeA);
   getdata(setB,&SizeB);
 
   printf("Set A: ");
     display(setA,SizeA);
   printf("\nSet B: ");
     display(setB,SizeB);
     
   do{
       printf("\n\tSET OPERATIONS");
       printf("\n1.Union");
       printf("\n2.Intersection");
       printf("\n3.Difference");
       printf("\n4.Symmetric difference");
       printf("\n5.Exit\nEnter your choise : ");
       scanf("%d",&ch);
       
       switch(ch)
       {
        case 1:
              printf("\nUnion of Set A and Set B: "); 
              k=Union(setA,setB,setC,SizeA,SizeB);
              display(setC,k);
              break;
       
        case 2:
            
             printf("\nIntersection of Set A and Set B: ");
             k=intersection(setA,setB,setC,SizeA,SizeB);
             display(setC,k);
             break; 
             
        case 3:
             printf("\nDifference between sets-\nSetA - SetB: ");
             k=difference(setA,setB,setC,SizeA,SizeB);
             display(setC,k);
             printf("\nSetB - SetA: ");
             k=difference(setB,setA,setC,SizeB,SizeA);
             display(setC,k);
             break;
   
        case 4:       
             printf("\nSymmetric difference of Set A and Set B: ");
             k=symmetric(setA,setB,setC,SizeA,SizeB);
             display(setC,k);
          
        case 5:
             break;
             
        default:
             printf("INVALID CHOISE!");
       }
     }while(ch!=5);
}

     
void display(int set[12],int Size)
{
 int i;
 printf("{");
 for(i=0;i<Size;i++)
        printf(" %d,",set[i]); 
 printf("}\n");    
} 
void getdata(int set[10],int *Size)
{
   int i,j;
   printf("Enter number of elements in set : ");
   scanf("%d",Size);
   printf("\nEnter numbers in the set :\n");

  for(i=0; i<*Size; i++)
   {
    scanf("%d",&set[i]);
    for(j=0;j<i;j++)
     { 
       if(set[i]==set[j])
         {
           printf("\nThe element is a duplicate.");
           i--;
           break;
         }
     }
   }
} 
int Union(int setA[10],int setB[10],int setC[10],int SizeA,int SizeB)
{
     int i,j,k,flag;
        for(i=0;i<SizeA;i++)
            setC[k++]=setA[i];
         for(j=0;j<SizeB;j++)
            {  
              flag=0;
              for(i=0;i<k;i++)
                  if(setC[i]==setB[j])
                   { 
                    flag=1;
                    break;
                   }
             if(flag==0)
               setC[k++]=setB[j];
            } 
    return k;        
} 
int intersection(int setA[10],int setB[10],int setC[10],int SizeA,int SizeB)
{
     int i,j,k=0;
        for(j=0;j<SizeB;j++)
           {  
            for(i=0;i<SizeA;i++)
                if(setA[i]==setB[j])
                   setC[k++]=setB[j];
            }
     return k;
}
int difference(int setA[10],int setB[10],int setC[10],int SizeA,int SizeB)
{
     int i,j,k=0,flag;
        for(i=0;i<SizeA;i++)
            {
              flag=0;
              for(j=0;j<SizeB;j++)
              if(setA[i]==setB[j])
                {
                  flag=1;
                  break;
                }
              if(flag==0)
              setC[k++]=setA[i];
            } 
      return k;
}
int symmetric(int setA[10],int setB[10],int setC[10],int SizeA,int SizeB)
{
    int i,j,k=0,flag;
     for(i=0;i<SizeA;i++)
     {
       flag=0;
       for(j=0;j<SizeB;j++)
           if(setA[i]==setB[j])
              {
                flag=1;
                break;
              }
       if(flag==0)
         setC[k++]=setA[i];
      }
     for(j=0;j<SizeB;j++)
     {
       flag=0;
       for(i=0;i<SizeA;i++)
          if(setA[i]==setB[j])
            {
              flag=1;
              break;
            }
       if(flag==0)
         setC[k++]=setB[j];
      }
     return k;
}

