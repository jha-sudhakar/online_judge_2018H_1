#if 0
#include<iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
#endif
class Solution
{
	public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
	{
    	ListNode* cur = head, *prev_n = head;
		while(n-- && cur != NULL)
		{
			cur = cur->next;
		}

		if(cur == NULL)
		{
			return head->next;
		}
		while(cur->next != NULL)
		{
			cur = cur->next;
			prev_n = prev_n->next;
		}
		ListNode* tmp = prev_n->next;
		prev_n->next = tmp->next;
		return head;
    }
};
