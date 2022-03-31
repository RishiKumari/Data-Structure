#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
 
typedef struct CQ
{
	int F, R;
	int data[MAX];
}Q;
 
void create(Q*);
void enqueue(Q *p, int);
int dequeue(Q *p);
void display(Q*);
 
void main()
{
	Q p; int choice,n=0,item,del=0;
	
	create(&p);
 
	printf("1. Insert\n2. Delete\n3. Display\nEnter Your Choice : ");
	scanf("%d", &choice);
	while(n<4)
	{
		switch(choice)
		{
			case 1:
				printf("Enter the Item : ");
				scanf("%d",&item);
				enqueue(&p,item);
			break;
 
			case 2:
				del=dequeue(&p);
				printf("Deleted Element : %d\n", del);
			break;
 
			case 3:
				display(&p);
			break;
 
			default:
				printf("Exit\n");
				exit(0);
			break;
		}
		printf("\nEnter Your Choice : ");
		scanf("%d", &choice);
	}
       //getch();
}
void create(Q *p)
{
	p->R=p->F=-1;
}
 
void enqueue(Q *p, int x)
{
	if(p->R==-1)//insertinh first time
	{
		p->R=p->F=0;
		p->data[p->R]=x;
	}
	else
	{
		if((p->R+1)%MAX==p->F)
		{
			printf("Queue Overflow\n");
			exit(0);
		}
		else
		{
		       p->R=(p->R+1)%MAX;
		       p->data[p->R]=x;
		}
	}
}
int dequeue(Q *p)
{
	int x;
	x=p->data[p->F];
 
	if(p->R==-1||p->F==-1)
	{
		printf("Queue Underflow\n");
		exit(0);
	}
	else
	{
		if(p->R==p->F)
		{
			p->R=p->F=-1;
		}
		else
		{
			p->F=(p->F+1) % MAX;
		}
	}
	return(x);
}
 
void display(Q *p)
{
	int i=p->F;
	while(i!=p->R)
	{
		printf("Queue element : %d\n", p->data[i]);
		i=(i+1)%MAX;
	}
	printf("Last Element : %d\n",p->data[p->R]);
}