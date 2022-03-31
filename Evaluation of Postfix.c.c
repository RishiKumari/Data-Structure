#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 20

typedef struct stack
{
    int data[MAX];
    int top;
}s, stack;

int init(stack*);
int empty(stack*);
int full(stack*);
int push(stack*, int);
int pop(stack*);
int peak(stack*);
int display(stack*);
int eval(char, int, int);

int main()
{
    struct stack s;
    char *postfix;
    postfix=(char*)malloc(100*sizeof(char));
    char x1;
    int x, n, i, operator1, operator2, value;
    init(&s);
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. PEAK\n");
    printf("4. DISPLAY\n");
    printf("5. Postfix Evaluation\n");
    printf("6. Exit\n");
    printf("Enter Your Choice : ");
    scanf("%d", &x);
    
    while(x<6)
    {
        switch(x)
        {
            case 1: 
                if(!full(&s))
                {
                    printf("Enter the Element : ");
                    scanf("%d", &n);
                    push(&s,n);
                }
                else 
                {
                    printf("\n Stack Overflow");
                    exit(0);
                }
                break;
            case 2: 
                if(!empty(&s))
                {
                    x = pop(&s);
                    printf("Deleted Element = %d\n", x);
                }
                break;
            case 3:
                peak(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("\nEnter Postfix Expression : ");
		        scanf("%s", postfix);
	            while((x1=postfix[i++])!='\0')
	            {         
	                if(isdigit(x1))
		                push(&s, x1-48);
	                else
	                {
		                operator2=pop(&s);
		                operator1=pop(&s);
		                value=eval(x1, operator1, operator2);
		                push(&s, value);
	                }
	            }
	            value=pop(&s);
	            printf("\nValue of Postfix Expression : %d\n", value);
	            break;
            default:
                printf("Wrong Input!!");
                break;
        }
        printf("\n");
        printf("Enter Your Choice : ");
        scanf("%d", &x);
    }

    return 0;
}

int init(stack *s)
{
    s->top=-1;
    return 0;
}

int empty(stack *s)
{
    if(s->top==-1)
    {
        return(1);
    }
    return 0;
}

int full(stack *s)
{
    if(s->top==MAX-1)
    {
        return (1);
    }
    return 0;
}

int push(stack *s, int p)
{
    s->top = s->top+1;
    s->data[s->top]=p;
    return 0;
}

int pop(stack *s)
{
    int x;
    x = s->data[s->top];
    s->top = s->top-1;
    return x;
}

int peak(stack *s)
{
    int i;
    if(s->top==-1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top Element of Stack : %d\n", s->data[s->top]);
    }
    return 0;
}

int display (stack *s)
{
    int i;
    if(s->top==-1)
    {
        printf("Stack is Empty\n");
    }
    else
      {
            printf ("\nStatus of elements in stack : \n");
            for (i = s->top; i >= 0; i--)
            {
                  printf ("%d\n", s->data[i]);
            }
      }  
      return 0;
}

int eval(char x, int operator1, int operator2)
{
	if(x=='+')
		return(operator1+operator2);
	if(x=='-')
		return(operator1-operator2);
	if(x=='*')
		return(operator1*operator2);
	if(x=='/')
		return(operator1/operator2);
	if(x=='%')
		return(operator1%operator2);
	if(x=='^')
		return(pow(operator1, operator2));
	
}
