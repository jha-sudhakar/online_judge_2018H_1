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

			ListNode *prev, *cur;
			prev = cur = head;
			unsigned int pos = 1;
			while(pos<=k)
			{
				cur = cur->next;
				pos++;
			}

			while(cur != last)
			{
				cur = cur->next;
				prev = prev->next;
			}

			ListNode* new_head = prev->next;
			prev->next = NULL;
			last->next = head;
			return new_head;
		}
};