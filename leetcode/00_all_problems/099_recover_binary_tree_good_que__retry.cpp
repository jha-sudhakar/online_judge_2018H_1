#include<iostream>
#include<vector>
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
	public:
	void inorder(TreeNode* node, TreeNode** prev_pat, vector<TreeNode*> &vec)
	{
		if(node->left)
			inorder(node->left, prev_pat,vec);

		if(*prev_pat != NULL)
		{
			TreeNode* prev = *prev_pat;
			if(prev->val > node->val)
			{
				vec.push_back(prev);
				vec.push_back(node);
			}
		}
		*prev_pat = node;

		if(node->right)
			inorder(node->right, prev_pat, vec);
	}

	void recoverTree(TreeNode* root)
	{
		if(root == NULL)
			return;

		TreeNode **prev_node_ptr = new TreeNode*;
		*prev_node_ptr = NULL;
		vector<TreeNode*> vec;

		inorder(root, prev_node_ptr, vec);
		if(vec.size())
		{
			int tval = vec[0]->val;
			vec[0]->val = vec[vec.size()-1]->val;
			vec[vec.size()-1]->val = tval;
		}
	}
};
