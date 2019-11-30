#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
   int data;
   struct node *left;
   struct node *right;
};
typedef struct node *NODE;
void postOrder(NODE root)
{
   if(root->left != NULL)
   postOrder(root->left);
   if(root->right != NULL)
   postOrder(root->right);
   printf("\n%d\n",root->data);
}
void inOrder(NODE root)
{
   if(root->left != NULL)
   inOrder(root->left);
   printf("\n%d\n",root->data);
   if(root->right != NULL)
   inOrder(root->right);
}
void preOrder(NODE root)
{
   printf("\n%d\n",root->data);
   if(root->left != NULL)
	preOrder(root->left);
   if(root->right != NULL)
	preOrder(root->right);
}
NODE getNode(int element)
{
   NODE newNode = (NODE)malloc(sizeof(NODE));
   newNode->data = element;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}
NODE insertBST(NODE root,int element)
{
   NODE temp = root;
   if(root == NULL)
   {
	root = getNode(element);
	return root;
}
while(1)
{
   if(element < temp->data)
   {
	if(temp->left == NULL)
	{
		temp->left = getNode(element);
		break;
	}
	else
	temp = temp->left;
   }
   else
   {
   if(temp->right == NULL)
   {
	temp->right = getNode(element);
	break;
   }
   else
	temp = temp->right;
   }
}
return root;
}
void main()
{
   NODE root = NULL;
   int ch,data;
   for(;;)
   {
	printf("1: Insert 2: PreOrder \n");
	printf("3: PostOrder 4: InOrder 5: Exit \n");
	printf("\n Enter your choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("\n Enter the data to be inserted : ");
		scanf("%d",&data);
		root = insertBST(root,data);
		break;
		case 2: printf("\n PreOrder Traversal is : \n");
		preOrder(root);
		printf("\n");
		break;
		case 3: printf("\n PostOrder Traversal is : \n");
		postOrder(root);
		printf("\n");
		break;
		case 4: printf("\n InOrder Traversal is : \n");
		inOrder(root);
		printf("\n");
		break;
		case 5: exit(0);
	}
   }
}
