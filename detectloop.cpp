#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node *next;
};

void push(struct node **head,int a)
{
	struct node *new1;
	new1 = (struct node *)malloc(sizeof(struct node));
	new1->data = a;
	new1->next = *head;
	*head = new1;
}

bool detectloop(struct node *head)
{
	struct node *slow,*fast;
	if(head==NULL) return false;
	slow = head;
	fast = head->next;
	while(fast!=NULL)
	{
		if(fast==slow) return true;
		slow = slow->next;
		fast = fast->next;
		if(fast!=NULL) fast = fast->next;
	}
	return false;
}

int main()
{
	struct node *head = NULL;
	push(&head,20);
	push(&head,4);
	push(&head,15);
	push(&head,10);
	//head->next->next->next->next = head->next;
	cout<<detectloop(head);
	return 0;
}