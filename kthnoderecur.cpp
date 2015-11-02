
#include <bits/stdc++.h> 

using namespace std;

/* Link list node */
struct node
{
int data;
struct node* next;
};

/* Function to get the nth node from the last of a linked list*/
int coun =0;
void printNthFromLast(struct node* head, int n)
{
	if(head==NULL) return;
	printNthFromLast(head->next,n);
	coun++;
	if(coun==n) cout<<head->data<<"\n";
	return;
}

void push(struct node** head_ref, int new_data)
{
/* allocate node */
struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

/* put in the data */
new_node->data = new_data;

/* link the old list off the new node */
new_node->next = (*head_ref);

/* move the head to point to the new node */
(*head_ref) = new_node;
}

/* Drier program to test above function*/
int main()
{
/* Start with the empty list */
struct node* head = NULL;

// create linked 35->15->4->20
push(&head, 20);
push(&head, 4);
push(&head, 15);
push(&head, 35);

printNthFromLast(head, 1);
getchar();
return 0; 
}
