#include<vector>
#include<iostream>
using namespace std;


#if DEBUG

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution
{
	public:
		ListNode* reverseBetween(ListNode* A, int B, int C);


};


#endif

ListNode* Solution::reverseBetween(ListNode* A, int B, int C)
{
	ListNode* dummy_root = new ListNode(0);
	dummy_root->next = A;

	ListNode *cur = dummy_root, *prev = dummy_root;

	int shift = C-B;
	int index = 0;
	vector<int> val_arr;
	while(index<shift)
	{
		if(index>= B)
			val_arr.push_back(cur->val);
		cur = cur->next;
		index++;
	}
	shift = B;
	while(shift)
	{
		val_arr.push_back(cur->val);
		cur = cur->next;
		prev = prev->next;
		shift--;
	}
	val_arr.push_back(cur->val); // insert the last element as well.

	int pos = 0;
	while(prev != cur)
	{
		prev->val = val_arr[val_arr.size()-1-pos];
		pos++;
		prev = prev->next;
	}
	prev->val = val_arr[val_arr.size()-1-pos];

	delete dummy_root;
	return A;
}

