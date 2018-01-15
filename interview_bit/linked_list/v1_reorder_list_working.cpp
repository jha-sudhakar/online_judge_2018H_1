#include<assert.h>

#include<vector>
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
	  ListNode* reorderList(ListNode* A);
  };

#endif 

ListNode* Solution::reorderList(ListNode* A)
{
	int N=0;
	ListNode* tmp = A;
	vector<ListNode*> node_list;
	while(tmp != NULL)
	{
		N++;
		tmp = tmp->next;
	}
	int n = N/2;
	int count = N-n;
	tmp = A;
	while(count)
	{
		tmp = tmp->next;
		count--;
	}

	while(tmp != NULL)
	{
		node_list.push_back(tmp);
		tmp = tmp->next;
	}
	
	ListNode* head = A;
	int i=0;
	for(i=0; i<N/2; i++)
	{
		//cout <<"index = " << i << " and vec_size = " << node_list.size() << endl;
		if(head->next == node_list[node_list.size()-1-i])
		{
			node_list[node_list.size()-1-i]->next = NULL;
			head = NULL;
			break;
		}
		
		node_list[node_list.size()-1-i]->next = head->next;
		head->next = node_list[node_list.size()-1-i];
		
		//if(head->next && head->next->next)
		head = head->next->next;
	}
	if(i == N/2 && head != NULL)
			head->next = NULL;
	return A;	
}

#if DEBUG
int main()
{
	int ret[] = {92, 85, 10, 32, 9, 29, 8, 38, 55, 61, 11, 23, 4, 60, 50, 64, 80, 87, 1, 89, 84, 42, 73, 2, 100, 83, 52, 69, 71, 65, 35, 76, 54, 24, 33, 79, 26, 15, 25, 93, 68, 16, 49, 34, 21, 91, 86, 81, 53, 3, 59, 70, 5, 19, 36, 20, 88, 31, 78, 7, 39, 12, 22, 57, 96, 95, 62, 56, 101, 97, 72, 30, 98, 90, 46, 99, 94, 77, 51, 66, 27};
	int A[]  = {92, 10, 9, 8, 55, 11, 4, 50, 80, 1, 84, 73, 100, 52, 71, 35, 54, 33, 26, 25, 68, 49, 21, 86, 53, 59, 5, 36, 88, 78, 39, 22, 96, 62, 101, 72, 98, 46, 94, 51, 27, 66, 77, 99, 90, 30, 97, 56, 95, 57, 12, 7, 31, 20, 19, 70, 3, 81, 91, 34, 16, 93, 15, 79, 24, 76, 65, 69, 83, 2, 42, 89, 87, 64, 60, 23, 61, 38, 29, 32, 85};
	int arr_len = sizeof(A)/sizeof(int);
	
	ListNode* root = new ListNode(0);
	ListNode* tmp = root;
	for(int i=0; i<arr_len; i++)
	{
		tmp->next = new ListNode(A[i]);
		tmp = tmp->next;
	}
	Solution obj;
	ListNode* ret_a = obj.reorderList(root->next);
	int i=0;
	while(ret_a != NULL)
	{
		cout<< "expected = " << ret[i] << ", real = " << ret_a->val << endl;
		if(ret[i] != ret_a->val)
		{
			cout << "At index " << i+1 <<"/" << arr_len << endl;
			assert(false);
		}
		i++;
		ret_a = ret_a->next;
	}
	return 0;
}

#endif
