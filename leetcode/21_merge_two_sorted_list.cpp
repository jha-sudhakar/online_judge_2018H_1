#include<string>
#include<iostream>
using namespace std;

#if LOCAL

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
#endif

class Solution 
{
	public:
    	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
		{
			if(l1 == NULL)
				return l2;
			else if(l2 == NULL)
				return l1;

        	ListNode* l_ret = NULL, *l3 = l1;
			if(l2->val < l3->val)
			{
				l3 = l2;
				l2 = l2->next;
			}
			else
			{
				l1 = l1->next;
			}
			
			l_ret=l3;

			while(l1 != NULL && l2 != NULL)
			{
				if(l1->val < l2->val)
				{
					l3->next = l1;
					l1 = l1->next;
				}
				else
				{
					l3->next = l2;
					l2 = l2->next;
				}
				if(l3->next != NULL)
					l3 = l3->next;
			}
			
			if(l1 == NULL)
				l3->next = l2;
			else
				l3->next = l1;

			return l_ret;
    	}
};
