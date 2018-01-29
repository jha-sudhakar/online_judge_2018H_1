#include<iostream>
#include<vector>
using namespace std;

#if DEBUG

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
	public:
	
		vector<TreeNode*> build_tree(int start, int end)
		{
			vector<TreeNode*> ret_vec;
			if(start>end)
			{
				ret_vec.push_back(NULL);
				return ret_vec;
			}
				
			for(int key=start; key<=end; key++)
			{
				vector<TreeNode*> left_tree = build_tree(start,key-1);
				vector<TreeNode*> right_tree = build_tree(key+1, end);
				
				for(int i=0; i<left_tree.size(); i++)
				{
					for(int j=0; j<right_tree.size(); j++)
					{
						TreeNode* node = new TreeNode(key);
						node->left = left_tree[i];
						node->right = right_tree[j];
						ret_vec.push_back(node);
					}
				}
			}			
			return ret_vec;
		}

		vector<TreeNode*> generateTrees(int n)
		{
			vector<TreeNode*> ret_arr;
			if(n<1)
				return ret_arr;
			ret_arr = build_tree(1, n);
			return ret_arr;
		}
};
