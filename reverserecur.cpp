#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
};
void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
  
    /* put in the data  */
    new_node->data  = new_data;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);   
  
    /* move the head to pochar to the new node */
    (*head_ref)    = new_node;
} 

void printReverse(struct node *head)
{
	if(head==NULL)
	{
		//cout<<head->data<<"->";
		return;
	}
	printReverse(head->next);
	cout<<head->data<<"->";
}

int main()
{
	struct node* head = NULL;
     
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
   
  printReverse(head);

	return 0;
}