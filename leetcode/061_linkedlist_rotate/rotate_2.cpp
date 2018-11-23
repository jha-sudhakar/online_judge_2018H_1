#include<stdio.h>

#if  JHA
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution
{
	public:
		ListNode* rotateRight(ListNode* head, int k)
		{
			unsigned int len = 0;
			ListNode* tmp = head, *last=NULL;
			while(tmp != NULL)
			{
				last = tmp;
				tmp = tmp->next;
				len++;
			}
			if(len == 0)
				return head;

			k = k%len;
			if(k == 0)
				return head;

			ListNode *lc = head, *ln=head;
			unsigned int pos = 1;
			while(pos <= k)
			{
				lc = lc->next;
				pos++;
			}

			while(lc != last)
			{
				lc = lc->next;
				ln = ln->next;
			}

			ListNode* new_head = ln->next;
			ln->next = NULL;
			lc->next = head;

			return new_head;
		}
};