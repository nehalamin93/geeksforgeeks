/*Program to alternatively split a linked list into two halves */
#include <bits/stdc++.h>

using namespace std;
/* Link list node */
struct node
{
	int data;
	struct node* next;
};

void printList(struct node *node)
{
	while(node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
} 


void MoveNode(struct node** destRef, struct node** sourceRef) ;


void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef) 
{
	struct node dummya;
	struct node *taila = &dummya;
	struct node dummyb;
	struct node *tailb = &dummyb;
	struct node *new1 = source;
	while(new1!=NULL)
	{
		cout<<new1->data<<' ';
		MoveNode(&(taila->next),&new1);
		//new1 = new1->next;
		taila = taila->next;
		if(new1!=NULL)
		{
			MoveNode(&(tailb->next),&new1);
			//new1 = new1->next;
			tailb = tailb->next;
		}
	}
	//cout<<"***";
	printList(dummya.next);

	*aRef = dummya.next;
	*bRef = dummyb.next;
}


void MoveNode(struct node** destRef, struct node** sourceRef) 
{
	*destRef = *sourceRef;
	(*sourceRef) = (*sourceRef)->next;
	(*destRef)->next = NULL;
}


void push(struct node** head_ref, int new_data)
{
	struct node* new_node =
				(struct node*) malloc(sizeof(struct node));

	new_node->data = new_data;
	/* link the old list off the new node */
	new_node->next = (*head_ref);	 

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */


/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;
	struct node* a = NULL;
	struct node* b = NULL; 
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);								 
	push(&head, 0); 

	printf("\n Original linked List: ");
	printList(head); 

	/* Remove duplicates from linked list */
	AlternatingSplit(head, &a, &b); 

	printf("\n Resultant Linked List 'a' ");
	printList(a);		 

	printf("\n Resultant Linked List 'b' ");
	printList(b);		 

	getchar();
	return 0;
}
