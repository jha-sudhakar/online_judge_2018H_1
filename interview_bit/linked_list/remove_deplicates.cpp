#include<iostream>
using namespace std;

#if DEBUG

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution
{
	public:
		ListNode* deleteDuplicates(ListNode* A);
};

#endif

ListNode* Solution::deleteDuplicates(ListNode* A)
{
	if(A == NULL || A->next == NULL)
		return A;

	ListNode* root = new ListNode(A->val + 1); root->next = A;
	ListNode* parent = root;

	ListNode* start = A, *end = A;

	while(parent->next != NULL)
	{
		while(end->next != NULL && end->next->val == start->val)
		{
			end = end->next;
		}
		if(start != end)
		{
			parent->next = end->next;
		}
		else
		{
			parent->next = start;
			parent = start;
		}
		start = end->next;
		end = start;
	}
	A = root->next;
	delete root;
	return A;
}




