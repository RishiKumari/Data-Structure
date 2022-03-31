/*
-----TOWERS OF HANOI------
  A=BEG   or starting tower
  B=AUX  or helping tower
  C=END or destination tower
  
  */
#include<stdio.h>
void TOH(int,char,char,char);

int main()
{
    int n;
    char A,B,C;
    printf("Enter the number of disk:  ");
    scanf("%d",&n);
     TOH(n,'A','C','B');

}
void TOH(int n,char A,char B,char C)
    {
        if(n>=1)
        {
            TOH(n-1,'A','B','C');
            printf(" Move disk %d from %c to %c\n",n,A,C);
            TOH(n-1,'B','C','A');
            
        }
    }

