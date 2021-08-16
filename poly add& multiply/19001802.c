#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coef;
	int expo;
	struct node *next;
};

//structure - insert
struct node *insert(struct node *start,int co,int ex)
{
	struct node *ptr,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->coef=co;
	tmp->expo=ex;
	//if the list empty
	if(start==NULL )
	{
		tmp->next=start;
		start=tmp;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL )
			ptr=ptr->next;
			tmp->next=ptr->next;
			ptr->next=tmp;
	}
	return start;
}

//structure - create
struct node *create(struct node *start)
{
	int i,n,ex,co;
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter coeficient for term %d : ",i);
		scanf("%d",&co);
		printf("Enter exponent for term %d : ",i);
		scanf("%d",&ex);
		start=insert(start,co,ex);
	}
	return start;
}

//display
void display(struct node *ptr)
{
	if(ptr==NULL)
	{
		printf("Zero polynomial\n");
		return;
	}
	while(ptr!=NULL)
	{
		printf("%dx^%d", ptr->coef,ptr->expo);
		ptr=ptr->next;
		if(ptr!=NULL)
			printf(" + ");
		else
			printf("\n");
	}
}

void poly_add(struct node *p1,struct node *p2)
{
	struct node *start3;
	start3=NULL;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->expo > p2->expo)
	{
		start3=insert(start3,p1->coef,p1->expo);
		p1=p1->next;
	}
	else if(p2->expo > p1->expo)
	{
		start3=insert(start3,p2->coef,p2->expo);
		p2=p2->next;
	}
	else if(p1->expo==p2->expo)
	{
		start3=insert(start3,p1->coef+p2->coef,p1->expo);
		p1=p1->next;
		p2=p2->next;
	}
}
	//if poly2 has finished and elements left in poly1
	while(p1!=NULL)
	{
		start3=insert(start3,p1->coef,p1->expo);
		p1=p1->next;
	}
	//if poly1 has finished and elements left in poly2
	while(p2!=NULL)
	{
		start3=insert(start3,p2->coef,p2->expo);
		p2=p2->next;
	}
	printf("\nAdded polynomial is : ");
	display(start3);
}

//removeduplications
struct node*removedup(struct node*tem){

   struct node* ptr1, *ptr2, *dup;  
    ptr1 = tem;  
  
    /* Pick elements one by one */
   while (ptr1 != NULL && ptr1->next != NULL) 
    {  
		ptr2 = ptr1;  

        // Compare the picked element with rest of the elements  
        while (ptr2->next != NULL)  
        {    
            // If powerer of two elements are same  
            if (ptr1->expo == ptr2->next->expo)  
            {    
                // Add their coefficients and put it in 1st element  
                ptr1->coef = ptr1->coef + ptr2->next->coef;  
                dup = ptr2->next;  
                ptr2->next = ptr2->next->next;  
            }  
            else
                ptr2 = ptr2->next;  
        }  
        ptr1 = ptr1->next;  
    }  
 return(tem);
  
}

void poly_mult(struct node *p1, struct node *p2)
{
	struct node *start3;
	struct node *p2_tem = p2;
	start3=NULL;
	
	if(p1==NULL || p2==NULL)
	{
		printf("Multiplied polynomial is zero polynomial\n");
		return;
	}
	
	while(p1!=NULL)
	{
		p2=p2_tem;
		while(p2!=NULL)
		{
			start3=insert(start3,p1->coef*p2->coef,p1->expo+p2->expo);
			p2=p2->next;
		}
		p1=p1->next;
	}
	printf("\nMultiplied polynomial is : ");
	start3=removedup(start3);
	display(start3);
}

int main( )
{	
	int val;
	struct node *start1=NULL,*start2=NULL;
	printf("Enter polynomial 1 :\n");
	start1=create(start1);
	printf("\nEnter polynomial 2 :\n");
	start2=create(start2);
	printf("\nPolynomial 1 is : ");
	display(start1);
	printf("\nPolynomial 2 is : ");
	display(start2);
	
	printf("\nEnter your operation number :");
	printf("\n\t1.Adding above polynomials");
	printf("\n\t2.Multiplication above polynomials");
	printf("\n\t3.Exit");
	
	printf("\n\nMy choice is : ");
	scanf("%d",&val);
	
	while(val!=3){

		switch(val){
			case 1: poly_add(start1,start2);
					break;
			case 2: poly_mult(start1,start2);
					break;
		
		}
		printf("\nAre there any more choices :");
 		scanf("%d",&val);
	}
 	
}


