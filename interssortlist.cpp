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

struct node* IntesectionList(struct node *head1,struct node *head2)
{
	struct node* head,*tail;
	head = (struct node *)malloc(sizeof(struct node));
	tail = head;
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data == head2->data)
		{
			tail->next = (struct node*)malloc(sizeof(struct node));
			tail = tail->next;
			tail->data = head1->data;
			tail->next = NULL;
			head1= head1->next;
			head2 = head2->next;
		}
		if(head1->data>head2->data)
		{
			head2 = head2->next;
		}
		else if(head1->data<head2->data)
		{
			head1 = head1->next;
		}
	}
	return head->next;
}

void printing(struct node *abc)
{
	while(abc!=NULL)
	{
		cout<<abc->data<<"->";
	}
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
 
  
  struct node *abc = IntesectionList(head1, head2);
	printing(abc);
	return 0;
}