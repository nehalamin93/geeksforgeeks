#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

void head2(struct node **head,int a)
{
	struct node *new1;
	new1 = (struct node *)malloc(sizeof(struct node));
	new1->data = a;
	if(*head==NULL)
	{
		*head = new1;
		return;
	}
	else
	{
		new1->next = *head;
		*head = new1;
		return;
	}
}

void printing(struct node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<' ';
		head = head->next;
	}
}

void removingdup(struct node *head)
{
	if(head==NULL) return;
	if(head->next== NULL) return;
	struct node *first,*next;
	first = head;
	next = head->next;
	while(first && next)
	{
		if(first->data != next->data)
		{
			first = first->next;
			next = next->next;
		}
		else
		{
			first->next = next->next;
			next = next->next;
		}
	}
}

int main()
{
	struct node *head = NULL;
	head2(&head,4);
	head2(&head,3);
	head2(&head,3);
	head2(&head,2);
	head2(&head,1);
	head2(&head,1);
	head2(&head,1);
	printing(head);
	cout<<'\n';
	removingdup(head);
	printing(head);
	return 0;
}