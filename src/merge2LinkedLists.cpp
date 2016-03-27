/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	if (head1 == NULL&&head2 == NULL)
		return NULL;
	else
	{
		struct node *ans, *temp, *temp1, *temp2, *newnode;
		int i = 0;
		ans = (struct node*)malloc(sizeof(struct node));
		//ans = NULL;
		temp = ans;
		temp1 = head1;
		temp2 = head2;
		
		if (head1 == NULL)
		{
			return head2;
		}
		else
		if (head2 == NULL)
		{
			return head1;
		}

		while (temp1 != NULL || temp2 != NULL)
		{
			if (temp1 == NULL || temp2 == NULL)
			{
				if (temp1 == NULL)
				{
					newnode = (struct node*)malloc(sizeof(struct node));
					newnode->num = temp2->num;
					newnode->next = NULL;
					temp2 = temp2->next;
					if (i == 0)
					{
						temp = newnode;
						ans = temp;
						i = 1;
					}
					else
					{
						temp->next = newnode;
						temp = temp->next;
					}

				}
				else
				if (temp2 == NULL)
				{
					newnode = (struct node*)malloc(sizeof(struct node));
					newnode->num = temp1->num;
					newnode->next = NULL;
					temp1 = temp1->next;
					if (i == 0)
					{
						temp = newnode;
						ans = temp;
						i = 1;
					}
					else
					{
						temp->next = newnode;
						temp = newnode;
					}
				}
			}
			else
			{
				if (temp1->num < temp2->num)
				{
					newnode = (struct node*)malloc(sizeof(struct node));
					newnode->num = temp1->num;
					newnode->next = NULL;
					temp1 = temp1->next;
					if (i == 0)
					{
						temp = newnode;
						ans = temp;
						i = 1;
					}
					else
					{
						temp->next = newnode;
						temp = newnode;
					}
				}
				else
					//if (temp1->num > temp2->num) || temp1 == NULL)
				{
					newnode = (struct node*)malloc(sizeof(struct node));
					newnode->num = temp2->num;
					newnode->next = NULL;
					temp2 = temp2->next;
					if (i == 0)
					{
						temp = newnode;
						ans = temp;
						i = 1;
					}
					else
					{
						temp->next = newnode;
						temp = temp->next;
					}

				}

			}
		}
		return ans;
	}
	return NULL;
}
