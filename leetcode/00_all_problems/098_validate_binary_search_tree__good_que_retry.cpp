#include<limits.h>

#include<iostream>
using namespace std;

#if DBG

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
#endif

class Solution
{
		bool is_first_leaf;
	public:
		int get_child_val(TreeNode* node, int prev_val, bool& is_bst)
		{
			if( node == NULL)
				return prev_val;
			
			if((is_first_leaf == true) && (node->left == NULL))
			{
				is_first_leaf = false;
			}
			else
			{
				int l_prev_val = get_child_val(node->left, prev_val, is_bst);
				if(l_prev_val >= node->val)
				{
					is_bst = false;
					return node->val;
				}
			}
			return get_child_val(node->right, node->val, is_bst);
			
		}
	
		bool isValidBST(TreeNode* root)
		{
			is_first_leaf = true;
			bool is_bst = true;
			if(root == NULL)
				return is_bst;
			int prev = INT_MIN;
			get_child_val(root, prev, is_bst);
			return is_bst;
		}
};
