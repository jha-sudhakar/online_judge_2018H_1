
#if DBG
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
#endif

class Solution
{
	private:
		TreeNode* lca;

		bool lowestCommonAncestor_p(TreeNode* root, int p, int q)
		{
			bool ret_l = lowestCommonAncestor_p(root->left, p,q);
			bool ret_r = lowestCommonAncestor_p(root->right, p,q);
			if(ret_l && ret_r)
			{
				if(lca == NULL)
					lca = root;
				return = true;
			}
			else if(ret_l == true)
			{
				if(root->val ==
			}
		}

	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
		{
			lca = NULL;

		}
};