#include<iostream>
#include<vector>
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
		TreeNode* invertTree(TreeNode* A);
};
#endif

void invertTree_local(TreeNode* &A)
{
	if(A == NULL)
		return;
	
	TreeNode* tmp_node = A->left;
	A->left = A->right;
	A->right = tmp_node;

	invertTree_local(A->left);
	invertTree_local(A->right);
	return;
}



TreeNode* Solution::invertTree(TreeNode* A)
{
	if(A == NULL)
		return A;
	invertTree_local(A);
	return A;
}


