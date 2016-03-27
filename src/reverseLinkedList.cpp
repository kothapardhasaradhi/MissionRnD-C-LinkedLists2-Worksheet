/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head)
{
	if (head != NULL)
	{
		struct node *temp, *newnode, *start;
		start = head;
		temp = head;
		while (temp != NULL)
		{

			newnode = (struct node*)malloc(sizeof(struct node));
			newnode->num = temp->num;
			if (temp == start)
				newnode->next = NULL;
			else
				newnode->next = head;
			head = newnode;
			temp = temp->next;
		}
		//start = NULL;
		return head;
	}
	return NULL;
}
