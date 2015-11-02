#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  struct node* next;
};

int getIntesectionNode(struct node *head1,struct node *head2)
{
	if(head1==NULL || head2==NULL) return -1;
	int c1=0,c2=0;
	struct node *h1,*h2;
	h1 = head1;
	h2 = head2;
	while(h1!=NULL)
	{
		c1++;
		h1 = h1->next;
	}
	while(h2!=NULL)
	{
		c2++;
		h2 = h2->next;
	}
	if(c1>c2)
	{
		for(int i=0;i<c1-c2;i++)
		{
			head1 = head1->next;
		}
	}
	else if(c1<c2)
	{
		for(int i=0;i<c2-c1;i++)
		{
			head2 = head2->next;
		}
	}
	while(head1!=NULL && head1!=head2)
	{
		head1 = head1->next;
		head2 = head2->next;
	}
	if(head1==NULL) return -1;
	else return head1->data;
}

int main()
{
	struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;
 
  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          getIntesectionNode(head1, head2));
	return 0;
}