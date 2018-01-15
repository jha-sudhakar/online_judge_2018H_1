
#include<iostream>
using namespace std;

#if DEBUG

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
	public:
		int kthsmallest(TreeNode* A, int B);
};

#endif

void in_order(TreeNode* A, int& k, int& val)
{
	if( A == NULL)
		return;

	in_order(A->left, k, val);
	k--;
	if(k == 0)
	{
		val = A->val;
		return;
	}

	in_order(A->right, k, val);
}

int Solution::kthsmallest(TreeNode* A, int B)
{
	if(A == NULL)
		return -1;

	int val=0;
	in_order(A, B, val);
	return val;
}

