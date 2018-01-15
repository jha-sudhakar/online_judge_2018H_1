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



TreeNode* Solution::invertTree(TreeNode* A)
{
	if(A == NULL)
		return A;

	vector<TreeNode*> *curv = new vector<TreeNode*>;	
	vector<TreeNode*> *nextv = new vector<TreeNode*>;	
	curv->push_back(A);
	while(curv->size())
	{
		for(unsigned int i=0; i<curv->size(); i++)
		{
			if(2*i >= curv->size()-1)
				break;
			int buf = curv->at(i)->val;
			curv->at(i)->val = curv->at(curv->size()-1-i)->val;
			curv->at(curv->size()-1-i)->val = buf;

		}
		
		for(unsigned int i=0; i<curv->size(); i++)
		{
			TreeNode* tmp_node = curv->at(i);
			if(tmp_node->left)
				nextv->push_back(tmp_node->left);

			if(tmp_node->right)
				nextv->push_back(tmp_node->right);
		}
		curv->clear();
		vector<TreeNode*> *buf_vec_ptr = curv;	
		curv = nextv;
		nextv = buf_vec_ptr;
	}
	delete curv;
	delete nextv;
	return A;
}


