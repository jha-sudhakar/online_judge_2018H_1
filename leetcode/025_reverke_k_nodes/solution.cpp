#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#if DBG
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

	ListNode* reverse_k(ListNode* par, int& k)
	{
		if(par == NULL || par->next == NULL)
		{
			k = 0;
			return par;
		}

		ListNode* start = par->next;

		ListNode* prev = start;
		ListNode* cur = start->next;
		int count = 1;
		while(count < k)
		{
			if(cur == NULL)
				break;

			ListNode* next_cur = cur->next;
			cur->next = prev;

			prev = cur;
			cur = next_cur;
			count++;
		}

		start->next = cur;
		par->next = prev;
		k = count;
		return start;
	}

    ListNode* reverseKGroup(ListNode* head, int k)
	{
		if(head == NULL || k <= 1) return head;

		ListNode* dummy_parent = new ListNode(0);
		dummy_parent->next = head;
		ListNode* parent = dummy_parent;

		int len = k;
		while(len == k)
		{
			ListNode* next_parent = reverse_k(parent, len);
			if(len != 0 && len != k)
			{
				reverse_k(parent, len);
				break;
			}
			parent = next_parent;
		}
		ListNode* ret_ptr = dummy_parent->next;
		delete dummy_parent;
		return ret_ptr;
    }

};


#if DBG
int main()
{
	ListNode* head = new ListNode(0);
	ListNode* prev = head;

	for(unsigned int i=1; i<=10; i++)
	{
		ListNode* cur = new ListNode(i);
		prev->next = cur;
		prev = cur;
	}

	ListNode* new_head = head->next;
	cout <<"\nOrg list: \n";
	while(new_head != NULL)
	{
		cout << new_head->val;
		new_head = new_head->next;
		if(new_head != NULL)
			cout <<", ";
	}
	cout << "\n\n";

	Solution obj;
	int k=3;

	cout <<"Modified list with k= " << k << "  \n";
	new_head = obj.reverseKGroup(head->next, k);
	while(new_head != NULL)
	{
		cout << new_head->val;
		new_head = new_head->next;
		if(new_head != NULL)
			cout <<", ";
	}
	cout << "\n";
	return 0;
}
#endif