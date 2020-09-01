#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	int data;
	struct tnode *left;
	struct tnode *right;
}*root=NULL;
struct tnode * createnode(int x)
{
	struct tnode *newnode;
	newnode=(struct tnode *)malloc(sizeof(struct tnode));
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	return (newnode);
}
void insertion(struct tnode **node,int data)
{
	if(!*node)
	{
		*node=createnode(data);
	}
	else
	{
		if(data<((*node)->data))
		{
			insertion(&(*node)->left,data);
		}
		else
		{
			if(data>((*node)->data))
			{
				insertion(&(*node)->right,data);
			}
		}
	}
}
void inorder(struct tnode *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->data);
        Inorder(root->right);
    }
}
void postorder(struct tnode *node)
{
	if(node)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d\n",node->data);
	}
	return;
}
void preorder(struct tnode *node)
{
	if(node)
	{
		inorder(node->left);
		printf("%d",node->data);
		inorder(node->right);
	}
	return;
}
int main()
{
	int data,ch;
	while(1)
	{
		printf("\n1.Insertion\n2.Preorder\n3.Postorder\n4.Inorder\n5.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter your data: ");
				scanf("%d",&data);
				insertion(&root,data);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				postorder(root);
				break;
			case 4:
				inorder(root);
				break;
			case 5:exit(0);
			default:
				printf("Invalid choice\n");
				break;
		}
	}
	return 0;
}
