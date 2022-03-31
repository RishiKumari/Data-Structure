#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct BSTnode
{
	struct BSTnode *left;
	int data;
	struct BSTnode *right;
} BSTnode;

BSTnode *create();
BSTnode *insert(BSTnode*, int);
BSTnode *find(BSTnode*, int);
BSTnode *find_min(BSTnode*);
BSTnode *find_max(BSTnode*);
BSTnode *deletee(BSTnode*, int);
BSTnode *inOrder(BSTnode*);

void main()
{
	int i, f, d;
	BSTnode *T;
	T = create();
	printf("1. Find\n2. Find Minimum Node\n3. Find Maximum Node\n4. Deletion\n5. Print\n6. Exit\nEnter Your Choice : ");
	scanf("%d", &i);
	while(i<6)
	{
		switch(i)
		{
			case 1:
				printf("Enter the Searching Node : ");
				scanf("%d", &f);
				find(T, f);
				break;
			case 2:
				find_min(T);
				printf("The minimum node is %d",T);
				break;
			case 3:
				find_max(T);
				printf("The maximum node is %d",T);
				break;
			case 4:
				printf("Enter the Deleting Node : ");
				scanf("%d", &d);
				deletee(T, d);
				break;
			case 5:
				inOrder(T);
				break;
		}
		printf("Enter Your Choice : ");
		scanf("%d", &i);
	}
}

BSTnode *create()
{
	int n,x,i;
	BSTnode *root;
	root = NULL;
	printf("Binary Search Tree Creation : \n");
	printf("Enter no. of Nodes : ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("Enter the Elements : ");
		scanf("%d", &x);
		root = insert(root, x);
	}
	return(root);
}

BSTnode *insert(BSTnode *T, int x)
{
	if(T==NULL)
	{
		T = (BSTnode *)malloc(sizeof(BSTnode));
		T->data = x;
		T->left = T->right = NULL;
		return(T);
	}
	if(x > T->data)
	{
		T->right = insert(T->right, x);
		return(T);
	}
	if(x <= T->data)
	{
		T->left = insert(T->left, x);
		return(T);
	}
	return 0;
}

BSTnode *find(BSTnode *T, int x)
{
	while(T != NULL)
	{
		if(x==T->data)
		{
			return(T);
		}
		if(x > T->data)
		{
			T = T->right;
		}
		if(x < T->data)
		{
			T = T->left;
		}
	}
	if(T == NULL)
	{
		printf("Node not found!!");
	}
	return(T);
}

BSTnode *find_min(BSTnode *T)
{
	while(T->left != NULL)
	{
		T = T->left;
	}
	return(T);
}

BSTnode *find_max(BSTnode *T)
{
	while(T->right != NULL)
	{
		T = T->right;
	}
	return(T);
}

BSTnode *deletee(BSTnode *T, int x)
{
	BSTnode *temp;
	if(T == NULL)
	{
		printf("Node not found!! OR Tree does not exists!!");
		return(T);
	}
	if(x > T->data)
	{
		T->right = deletee(T->right, x);
		return(T);
	}
	if(x < T->data)
	{
		T->left = deletee(T->left, x);
		return(T);
	}
	if(T->left == NULL && T->right == NULL)
	{
		temp = T;
		free(temp);
		return(T);
	}
	if(T->left == NULL)
	{
		temp = T;
		T = T->right;
		free(temp);
		return(T);
	}
	if(T->right == NULL)
	{
		temp = T;
		T = T->left;
		free(temp);
		return(T);
	}
	temp = find_min(T->right);
	T->data = temp->data;
	T->right = deletee(T->right, temp->data);
	return T;
}

BSTnode *inOrder(BSTnode *root) {
	// Base case
	if (root == NULL) {
		return 0;
	}
	// Travel the left sub-tree first.
	inOrder(root->left);
	// Print the current node value
	printf("%d ", root->data);
	// Travel the right sub-tree next.
	inOrder(root->right);
	return 0;
}