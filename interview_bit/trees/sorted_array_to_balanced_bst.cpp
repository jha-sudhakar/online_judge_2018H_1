#include<vector>
#include<iostream>
using namespace std;

#if DEBUG

// * Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution
{
	public:
		TreeNode* sortedArrayToBST(const vector<int> &A);
}; 
#endif

void buildTree(TreeNode* &node, const vector<int> &A, const int start, const int end)
{
	if(start > end)
		return;

	int mid = (start+end)/2;
	node = new TreeNode(A[mid]);
	buildTree(node->left, A, start, mid-1);
	buildTree(node->right, A, mid+1, end);

}
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A)
{

	TreeNode* root;
	buildTree(root, A, 0, A.size()-1);
	return root;
}







