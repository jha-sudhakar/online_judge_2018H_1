#include<stdio.h>
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example:
	Input: head = 1->4->3->2->5->2, x = 3
	Output: 1->2->2->4->3->5
*/

#if JHA
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
#endif

class Solution
{
	public:
		ListNode* partition(ListNode* head, int x)
		{
			if(head == NULL)
			{
				return NULL;
			}

			ListNode* l_head = new ListNode(0);
			ListNode* h_head = new ListNode(0);

			ListNode* l_cur = l_head ;
			ListNode* h_cur = h_head ;


			while(head != NULL)
			{
				if(head->val < x)
				{
					l_cur->next = head;
					l_cur = l_cur->next;
					head = head->next;
				}
				else
				{
					h_cur->next = head;
					h_cur = h_cur->next;
					head = head->next;
				}
			}
			h_cur->next = NULL;
			l_cur->next = h_head->next;
			return l_head->next;
    	}
};