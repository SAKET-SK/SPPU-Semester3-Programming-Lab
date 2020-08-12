#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{

	int roll_no;
	char studname[20];
	float percentage;
	struct node *next;
}node;

node *creat(node *);
node *insert_beg(node*);
node *insert_end(node*);
node *insert_mid(node*);
node *delete_beg(node*);
node *delete_end(node*);
node *delete_mid(node*);
void display(node *);
void display_rev(node*);
main()
{
	node *root=NULL;
	int ch;
	    do{
	      printf("\n Singly Linked List");
	      printf("\n 1. Create  Singly Linked List");
	      printf("\n 2. Insert at begining in Singly Linked List");
   	      printf("\n 3. Insert at end in Singly Linked List");
   	      printf("\n 4. Insert in mid in Singly Linked List");
   	      printf("\n 5. Delete at begining in Singly Linked List");
   	      printf("\n 6. Delete at end in Singly Linked List");
   	      printf("\n 7. Delete in mid in Singly Linked List");
   	      printf("\n 8.Display Singly Linked List in Reverse Direction");
   	      printf("\n Enter the choice");
   	      scanf("%d",&ch);
   	      switch(ch)
   	      {
   	       case 1:     
   	      	root=creat(root);
	        		display(root);
	        break; 
	        case 2:
	        root=insert_beg(root);
	    		display(root);
	        break;
		    case 3:
			root=insert_end(root);
				display(root);
			break;
		    case 4:
			root=insert_mid(root);
				display(root);
			break;
			case 5:	
			root=delete_beg(root);
		    		display(root);
		    break;
		    case 6:
			root=delete_end(root);
					display(root);
			break;
			case 7:
			root=delete_mid(root);
			display(root);			
				break;
				case 8:
				 display_rev(root);
				break;
          }
           printf("\n Do U want to cont");
           scanf("%d",&ch);
           }while(ch!=9);
     
}

node *creat(node *root)
{
	
	node *p,*q;
	int rno,n,i;
	char name[20];
	float per;
	printf("Enter number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	  printf("\n Enter the students details");
	  scanf("%d%s%f",&rno,name,&per);
	  
	  p=(struct node*)malloc(sizeof(node));
	  p->roll_no=rno;
	  strcpy(p->studname,name);
	   p->percentage=per;
	   p->next=NULL;
	  if(root==NULL)
	     {
		root=p;
	      }
	 	else if(root->next==NULL)
	       {
		     root->next=p;
		      p->next=NULL;
	         }
	 	else
				{
				    q=root;
					while(q->next!=NULL)
					q=q->next;
					q->next=p;	
				}
			}
	return root;
}

 node *insert_beg(node*root)
 {
     node * p;
    int rno;
    char name[20];
    float per;
      printf("\n Enter the students details");
	  scanf("%d%s%f",&rno,name,&per);
     p=(struct node*)malloc(sizeof(node));
	  p->roll_no=rno;
	  strcpy(p->studname,name);
	   p->percentage=per;
	   p->next=NULL;
	  if(root==NULL)
	    root=p;
	  else 
	    {
	     p->next=root;
		  root=p;
		}
	return root;	      
}

node *insert_end(node*root)
 {
     node * p,*q;
    int rno;
    char name[20];
    float per;
      printf("\n Enter the students details");
	  scanf("%d%s%f",&rno,name,&per);
     p=(struct node*)malloc(sizeof(node));
	  p->roll_no=rno;
	  strcpy(p->studname,name);
	   p->percentage=per;
	   p->next=NULL;
	  if(root==NULL)
	    root=p;
	  else if(root->next==NULL)
	    {
	     root->next=p;
		}
		
		else
		 {
		   q=root;
		   while(q->next!=NULL)
					q=q->next;
					q->next=p;
		 }
	return root;	      
}

node *insert_mid(node*root)
{
     node * p,*q;
    int rno,pos;
    char name[20];
    float per;
      printf("\n Enter the students details");
	  scanf("%d%s%f",&rno,name,&per);
	   printf("\n Enter the postition");
	   scanf("%d",&pos);
     p=(struct node*)malloc(sizeof(node));
	  p->roll_no=rno;
	  strcpy(p->studname,name);
	   p->percentage=per;
	   p->next=NULL;
	  q=root;
		   while(q->roll_no<pos)
					q=q->next;
					p->next=q->next;
					q->next=p;
		 
	return root;	      
}

node *delete_beg(node*root)
{
 node *p;
 p=root;
 if(root->next==NULL)
   free(root);
    else
    {
     root=root->next;
     free(p);
    }
 return root;
}    

node *delete_end(node*root)
{
 node *p,*q;
 p=root;
 if(root->next==NULL)
   free(root);
    else
    {
          while(p->next!=NULL)
           
            {  q=p;
             p=p->next;
            }
             q->next=NULL;  
    }
 return root;
}   

node *delete_mid(node*root)
{
     node * p,*q;
     int rno;
	   printf("\n Enter the rno");
	   scanf("%d",&rno);
      p=root;
		   while(p->roll_no!=rno)
					{ 
					q=p;
					p=p->next;
					}
					
					q->next=p->next;
					free(p);
		 
	return root;	      
}
void display(node *root)
{
	node *p;
	p=root;
	while(p!=NULL)
	{
		printf("\n %d\t%s\t%f",p->roll_no,p->studname,p->percentage);
		p=p->next;
	}
}

void display_rev(node* root)
{
  node *p,*q,*r;
   p=q=root;
   r=NULL;
   while(p!=NULL)
   {
      q=p;
      p=p->next;
      q->next=r;
       r=q;
   }
   
while(r!=NULL)
	{
		printf("\n %d\t%s\t%f",r->roll_no,r->studname,r->percentage);
		r=r->next;
	}





}
