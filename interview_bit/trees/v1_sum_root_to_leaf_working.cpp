#include<iostream>
using namespace std;

#if DBG
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
		//void sum_tree(TreeNode* A);
		int sumNumbers(TreeNode* A);
};

#endif

void sum_tree(TreeNode* node, int& g_sum, int cur_sum)
{
	if(node == 	NULL)
		return;

	cur_sum = (cur_sum * 10) + node->val;
	cur_sum = cur_sum % 1003;
	sum_tree(node->left, g_sum, cur_sum);
	sum_tree(node->right, g_sum, cur_sum);

	if(node->left == NULL && node->right == NULL)
	{
		g_sum += cur_sum;
		g_sum = g_sum % 1003;
	}
}


int Solution::sumNumbers(TreeNode* A)
{
	int g_sum = 0, cur_sum = 0;
	sum_tree(A, g_sum, cur_sum);
	return g_sum;
}

