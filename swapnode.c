// Two nodes in the BST's swapped, correct the BST.
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node *left, *right;
};

// A utility function to swap two integers
void swap( int* a, int* b )
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void function(struct node *root,struct node **first,struct node **middle,struct node **last,struct node **pre)
{
	if(root==NULL) return;
    function(root->left,first,middle,last,pre);
    if(root)
    {
        if(*pre && (*pre)->data>root->data)
        {
            if(!*first)
            {
                *first = *pre;
                *middle = root;
            }
            else
                *last = root;
        }
        *pre = root;
    }
    function(root->right,first,middle,last,pre);
}

void correctBST( struct node* root )
{
    struct node *first=NULL,*middle=NULL,*last=NULL,*pre=NULL;
    function(root,&first,&middle,&last,&pre);
    if(first && last)
    {
        int a;
        a = first->data;
        first->data = last->data;
        last->data  = a;
    }
    else
    {
        int a ;
        a = first->data;
        first->data = middle->data;
        middle->data = a;
    }
}

/* A utility function to print Inoder traversal */
void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

/* Driver program to test above functions*/
int main()
{
	/* 6
		/ \
	10 2
	/ \ / \
	1 3 7 12
	10 and 2 are swapped
	*/

	struct node *root = newNode(6);
	root->left	 = newNode(10);
	root->right	 = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(12);
	root->right->left = newNode(7);

	printf("Inorder Traversal of the original tree \n");
	printInorder(root);

	correctBST(root);

	printf("\nInorder Traversal of the fixed tree \n");
	printInorder(root);

	return 0;
}
