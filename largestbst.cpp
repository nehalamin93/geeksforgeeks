#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
						malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int functions(struct node *root,int &min,int &max,int &max_size,bool &isbst)
{
	if(root==NULL) 
	{
		isbst = 1;
		max = INT_MIN;
		min = INT_MAX;
		return 0;
	}
	bool left= 0,right = 0;
	int ls,rs;
	max = INT_MIN;
	min = INT_MAX;
	ls = functions(root->left,min,max,max_size,isbst);
	if(isbst==1 && root->data>max)
	{
		left = 1;
	} 
	int m1 = min;
	min = INT_MAX;
	max = INT_MIN;
	rs = functions(root->right,min,max,max_size,isbst);
	if(isbst==1 && root->data<min)
	{
		right = 1;
	}
	min = m1;
	if(root->data<m1) min = root->data;
	if(root->data>max) max = root->data;
	if(left && right)
	{
		if(ls+rs+1>max_size) max_size = ls+rs+1;
		return (ls+rs+1);
	}
	else
	{
		isbst = 0;
		return 0;
	}
}

int largestBST(struct node *root)
{
	int min = INT_MAX;
	int max = INT_MIN;
	int max_size = 0;
	bool isbst = false;
	functions(root,min,max,max_size,isbst);
	return max_size;
}


/* Driver program to test above functions*/
int main()
{
		/* Let us construct the following Tree
			50
		/	 \
		10	 60
		/ \	 / \
	5 20 55 70
				/	 / \
			45	 65 80
	*/

	struct node *root = newNode(50);
	root->left	 = newNode(10);
	root->right	 = newNode(60);
	root->left->left = newNode(5);
	root->left->right = newNode(20);
	root->right->left = newNode(55);
	root->right->left->left = newNode(45);
	root->right->right = newNode(70);
	root->right->right->left = newNode(65);
	root->right->right->right = newNode(80);

	/* The complete tree is not BST as 45 is in right subtree of 50.
		The following subtree is the largest BST
			60
		/ \
		55 70
	/	 / \
	45	 65 80
	*/
	printf(" Size of the largest BST is %d", largestBST(root));

	getchar();
	return 0;
}
