#include<stdio.h>
//#include<conio.h>

void insert (int *);
void insertAtPos (int *);
void search (int *);
void reverse (int *);
void delete (int *);
void display (int *);

int size;
int
main ()
{
  int x;
  int ar[10];
  printf ("Please select anyone from the choice:");
  printf ("\n 1.Insertion ");
  printf ("\n 2.Insert at position ");
  printf ("\n 3.Deletion ");
  printf ("\n 4.Searching ");
  printf ("\n 5.Reverse ");
  printf ("\n 6.Display ");
  scanf ("%d", &x);
  while (x < 7)
    {
      switch (x)
    	{
    	    case 1:
	                insert (ar);
	                    break;
	            case 2:
	                  insertAtPos (ar);
	                  break;
	            case 3:
	                   delete (ar);
	                  break;
            	case 4:
	                  search (ar);
	                  break;
	            case 5:
	                 reverse (ar);
                     break;

	           case 6:
	                 display (ar);
	                 break;
	          default:
	             printf ("\nPlease select the correct choice.\n");
        }
             printf ("\nEnter the next choice. ");
             scanf ("%d", &x);
     }
    }
void insert (int *ar)
{
    int i;
  printf ("Enter the size of array : ");
  scanf ("%d ", &size);
  printf ("Enter the elements of array :");
  for (i = 0; i < size; i++)
    {    
      scanf ("%d", &ar[i]);
    }
    
}
//Check it ones 
void insertAtPos (int *ar)
{
  //int num;
  //int pos;
 // printf ("\nEnter the position at which you want to insert an element : \n ");
  //scanf ("%d", &pos);
  //printf ("Enter the element,which you want to insert  :\n ");
  //scanf ("%d", &num);
  //for (int i =size-1; i >0; i--)
    //{
      //  if(i>=pos){
        //         ar[i] = ar[i - 1];
          //             ar[i] = num;

        //}
    //}
       // printf ("The number %d is inserted at %d\n ", num, pos);
       int pos,b,i;

printf("Enter the Location");

scanf("%d", &pos);

if(pos<size)

{

printf("Enter the element");

scanf("%d", &b);

size=size+1;

for(i=size; i>=pos; i--)

{

ar[i+1]=ar[i];

}

ar[pos]=b;

}

else

printf("Location out of the array size");

}


//Check it ones 
void delete (int *ar)
{
int i, pos;
printf("Enter the deleting element position in ARRARY");
scanf("%d",&pos);
for(i=pos; i<size; i++)
{
ar[i-1]=ar[i];
ar[i]=0;
//ar[pos-1]=0;
}
size = size-1;
}

void search (int *ar)
{
  int i, num;
printf("Enter the searching element");
scanf("%d", &num);
for(i=0;i<size; i++)
{
if(ar[i]==num)
{
printf("The element %d is present at %dth position.\n\n", num, i+1);
return;
}

}

if(i==size){
 printf("The element %d is not prsent in the array.\n\n",num);
}
}

void reverse (int *ar)
{
  int i;
for(i=0;i<size/2; i++)

{

int temp=ar[i];
ar[i]=ar[size-1-i];
ar[size-1-i]=temp;

}

}

void display (int *ar)
{
int i;

for(i=0;i<size; i++)

printf("%d\t",ar[i]);

}



