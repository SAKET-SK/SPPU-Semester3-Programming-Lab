#include<stdio.h>
void Add(int(*)[],int(*)[],int(*)[],int,int);
void Multiply(int(*)[],int(*)[],int(*)[],int,int,int);

int main()
{
  int MatA[3][3],MatB[3][3],MatC[3][3],i,j,k,row1,row2,col1,col2,temp=0,ch,saddle=0;
   printf("Enter NO of rows of Matrix A:");
   scanf("%d",&row1);
   printf("Enter NO of columns of Matrix A:");
   scanf("%d",&col1);
   printf("Enter elemets of Matrix A:\t");
     for(i=0;i<row1;i++)
         for(j=0;j<col1;j++)
             scanf("%d",&MatA[i][j]);
   
   printf("Enter NO of rows of Matrix B:");
   scanf("%d",&row2);
   printf("Enter NO of columns of Matrix B:");
   scanf("%d",&col2);
   printf("Enter elemets of Matrix B:\t");
     for(i=0;i<row2;i++)
         for(j=0;j<col2;j++)
             scanf("%d",&MatB[i][j]);
             
   printf("Entered Matrix A:\n");
     for(i=0;i<row1;i++)
         {
           for(j=0;j<col1;j++)
               printf("%d  ",MatA[i][j]);
           printf("\n");
         }
   printf("Entered Matrix B:\n");
     for(i=0;i<row2;i++)
         {
           for(j=0;j<col2;j++)
               printf("%d  ",MatB[i][j]);
           printf("\n");
         }
         
   do{
       printf("\n\tMENU");
       printf("\n1.Addition of Matrices");
       printf("\n3.Multiplication of Matrices");
       printf("\n4.Saddle point of Matrix");
       printf("\n5.Transpose of Matrix");
       printf("\n6.Exit");
       printf("\nEnter your choise:");
       scanf("%d",&ch);
       
       switch(ch)
       {
        case 1:  
   				if(row1==row2 && col1==col2)
    			  {
    			    printf("Addition of Matrix A and Matrix B:\n");
            	    Add(MatA,MatB,MatC,row1,col1);
      			   for(i=0;i<row1;i++)
      			     {
      			       for(j=0;j<col1;j++)
                		  printf("%d  ",MatC[i][j]);
              		   printf("\n");
          		     }  
                  }
  	    	    else
    			   printf("\nMatrix A and Matrix B cannot be added.\n");  
                break;
                
        case 3:      
    			for(i=0;i<3;i++)
    			   for(j=0;j<3;j++)
           				MatC[i][j]=0; 
       
   				if(col1==row2 || col2==row1)
      			 {
        			if(col1=row2)
          		  	{
            			printf("Multiplication of Matrix A and Matrix B(MatrixA*MatrixB)\n");
                   		Multiply(MatA,MatB,MatC,row1,col2,row2);
            			for(i=0;i<row1;i++)
              			 {
               			  for(j=0;j<col2;j++)
                    		  printf("%d  ",MatC[i][j]);
                 		  printf("\n");
               			 }
          			 }
           
        		 for(i=0;i<3;i++)
            		for(j=0;j<3;j++)
                		MatC[i][j]=0; 
                
        		 
                  
         case 4:
                 for(i=0;i<row1;i++)
                    { 
                      k=MatA[i][0];
                      for(j=0;j<col1;j++)
                          {
                            if(MatA[i][j]<k)
                               k=MatA[i][j];
                          }
                      MatC[0][i]=k;
                    }
                  for(j=0;j<col1;j++)
                     { 
                       k=MatA[0][j];
                       for(i=0;i<row1;i++)
                           {
                             if(MatA[i][j]>k)
                               k=MatA[i][j];
                           }
                       MatC[1][j]=k;
                     }     
                   for(i=0;i<row1;i++)
                       for(j=0;j<col1;j++)
                           if(MatC[0][i]==MatC[1][j] && MatC[0][i]>saddle)
                              saddle=MatC[0][i];
                   printf("\nSaddle point of Matrix A is %d",saddle);
                   
                   saddle=0;
                   for(i=0;i<row2;i++)
                    { k=MatB[i][0];
                      for(j=0;j<col2;j++)
                          {
                            if(MatB[i][j]<k)
                               k=MatB[i][j];
                          }
                      MatC[0][i]=k;
                    }
                  for(j=0;j<col2;j++)
                     { k=MatA[0][j];
                       for(i=0;i<row2;i++)
                           {
                             if(MatB[i][j]>k)
                               k=MatB[i][j];
                           }
                       MatC[1][j]=k;
                     }     
                   for(i=0;i<row2;i++)
                       for(j=0;j<col2;j++)
                           if(MatC[0][i]==MatC[1][j] && MatC[0][i]>saddle)
                              saddle=MatC[0][i];
                   printf("\nSaddle point of Matrix B is %d\n",saddle); 
                   break;
         
         case 5:
                   for(i=0;i<row1;i++)
                       for(j=0;j<col1;j++)
                           MatC[j][i]=MatA[i][j];
                   printf("\nTranspose of Matrix A:\n");
                   for(i=0;i<col1;i++)
                       {
                         for(j=0;j<row1;j++)
                             printf("%d  ",MatC[i][j]);
                         printf("\n");            
                       } 
                   for(i=0;i<row2;i++)
                       for(j=0;j<col2;j++)
                           MatC[j][i]=MatB[i][j];
                   printf("Transpose of Matrix B:\n");
                   for(i=0;i<col2;i++)
                       {
                         for(j=0;j<row2;j++)
                             printf("%d  ",MatC[i][j]);
                         printf("\n");            
                       }
                   break;
          
         case 6:
                   break;
           
         default:
                   printf("\nEntered choise is wrong!\n");                  
                   
          }
      }
}while(ch<7);
           
void Add(int (*A)[3],int (*B)[3],int (*C)[3],int r,int c)
{ 
  int i,j;
  for(i=0;i<r;i++)
     {
       for(j=0;j<c;j++)
         *(*(C+i)+j)=*(*(A+i)+j)+*(*(B+i)+j);
      }

}  
void Multiply(int(*A)[3],int(*B)[3],int(*C)[3],int r1,int c,int r2)
{
  int i,j,k; 
   for(i=0;i<r1;i++)
      for(j=0;j<c;j++)  
          for(k=0;k<r2;k++)
              *(*(C+i)+j)=*(*(C+i)+j)+*(*(A+i)+k) * *(*(B+k)+j);                       	      
}
return 0;
}
