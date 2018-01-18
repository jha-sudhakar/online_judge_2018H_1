#include<iostream>
using namespace std;
#if DEBUG

//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 class Solution
 {
	public:
		TreeNode* flatten(TreeNode* A);
}; 
#endif

void flatten_g(TreeNode* tree_node, TreeNode** head, TreeNode** tail)
{
		if(NULL == tree_node)
		{
			return;
		}
		else if(tree_node->left == NULL && tree_node->right == NULL)
		{
			*head = tree_node;
			*tail = tree_node;
			return;
		}
		
		TreeNode *l_head, *l_tail;
		l_head = l_tail = NULL;
		flatten_g(tree_node->left, &l_head, &l_tail);
		
		TreeNode *r_head, *r_tail;
		r_head = r_tail = NULL;
		flatten_g(tree_node->right, &r_head, &r_tail);

		TreeNode *f_head, *f_tail;
		if(l_head == NULL)
		{
			f_head = r_head;
			f_tail = r_tail;
		}
		else if(r_head == NULL)
		{
			f_head = l_head;
			f_tail = l_tail;			
		}
		else
		{
			f_head = l_head;
			l_tail->right = r_head;
			f_tail = r_tail;
		}
		tree_node->right = f_head;
		tree_node->left = NULL;
		*head = tree_node;
		*tail = f_tail;
}

TreeNode* Solution::flatten(TreeNode* A) 
{
	TreeNode *left, *right;
	flatten_g(A, &left, &right);
	return A;
}
