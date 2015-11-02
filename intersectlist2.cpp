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

map<struct node *,int> hmap;

int getIntesectionNode(struct node *head1,struct node *head2)
{
	if(head1==NULL || head2==NULL) return -1;
	while(head1!=NULL)
	{
		hmap[head1] = 1;
		head1 = head1->next;
	}
	while(head2!=NULL)
	{
		if(hmap.find(head2)==hmap.end())
		{
			hmap[head2] =1 ;
			head2= head2->next;
		}
		else break;
	}
	return head2->data;
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