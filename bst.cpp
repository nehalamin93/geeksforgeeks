#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *left,*right;
};

struct node *insert(struct node *root,int a)
{
	struct node *x = (struct node *)malloc(sizeof(struct node));
	x->left = NULL;
	x->right = NULL;
	x->data = a;
	if(root==NULL) return x;
	struct node *p = root;
	struct node *q = NULL;
	while(p!=NULL)
	{
		q = p;
		if(p->data>a)
		{
			p = p->left;
		}
		else
			p = p->right;
	}
	if(q->data>a)
		q->left = x;
	else q->right = x;
	return root;
}

void inorder(struct node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<' ';
	inorder(root->right);
}

bool search(struct node *root,int n)
{
	if(root ==NULL) return false;
	if(root->data==n) return true;
	while(root!=NULL && root->data!=n)
	{
		if(root->data>n) root= root->left;
		else root = root->right;
	}
	if(root==NULL) return false;
	else return true;
}

struct node* min(struct node *root)
{
	if(root==NULL) return NULL;
	while(root->left!=NULL)
	{
		root= root->left;
	}
	return root;
}

struct node *delete1(struct node *root,int key)
{
	if(root==NULL) return NULL;
	if(root->data>key) root->left = delete1(root->left,key);
	else if(root->data<key) root->right = delete1(root->right,key);
	else
	{
		struct node *temp;
		if(root->left == NULL)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			temp = min(root->right);
			root->data = temp->data;
			root->right = delete1(root->right,temp->data);
			return root;
		}
	}
	return root;
}

void successor(struct node *root,int &s,int key)
{
	if(root==NULL) return;
	struct node *y;
	y = root;
	struct node *p;
	while(root!=NULL && root->data!=key)
	{
		y = root;
		if(root->data>key){p = root; root= root->left; }
		else root = root->right;
	}
	//cout<<y->data<<' '<<root->data;
	if(root==NULL) return;
	if(root->right == NULL && p!=NULL)
	{
		s = p->data;
	}
	else
	{
		s = min(root->right)->data;
	}
}

void predisesor(struct node *root,int &p,int key)
{
	if(root==NULL) return;
	if(root->data == key)
	{
		if(root->left !=NULL)
		{
			struct node *tmp = root->left;
			while(tmp->right) tmp = tmp->right;
			p = tmp->data;
			
		}
		return;
	}
	if(root->data>key)
	{
		predisesor(root->left,p,key);
	}
	else 
	{
		p = root->data;
		predisesor(root->right,p,key);
	}
}

void kthsmallest(struct node *root,int k,int &num)
{
	static int w = 0;
	if(root ==NULL) return ;
	kthsmallest(root->left,k,num);
	w++;
	if(w==k) num = root->data;
	kthsmallest(root->right,k,num);
}

int main()
{
	int a = 1,b,n,i;
	struct node *root = NULL;
	/*while(a==1)
	{
		cout<<"Enter number:\n";
		cin>>b;
		root = insert(root,b);
		cout<<"Enter 1 to insert more:\n";
		cin>>a;
	}*/
	root = insert(root,50);
	root = insert(root,30);
	root = insert(root,20);
	root = insert(root,40);
	root = insert(root,70);
	root = insert(root,60);
	root = insert(root,80);
	inorder(root);
	cout<<"Enter k:\n";
	cin>>n;
	int num;
	kthsmallest(root,n,num);
	cout<<num<<'\n';
	//cout<<"successor of n?:\n";
	//cin>>n;
	//int succ = -1;
	//successor(root,succ,n);
	//predisesor(root,succ,n);
	//cout<<succ<<'\n';
	/*cout<<"\nEnter number to search:\n";
	cin>>n;
	cout<<search(root,n)<<'\n';
	cout<<"Enter number to delete:\n";
	cin>>n;
	delete1(root,n);
	inorder(root);
	cout<<'\n';
	cout<<min(root)->data<<"\n";*/
	return 0;
}