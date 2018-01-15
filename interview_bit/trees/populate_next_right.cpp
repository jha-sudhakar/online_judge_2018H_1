#include<iostream>
#include<vector>
using namespace std;

#if DEBUG
// Definition for binary tree with next pointer.
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution
{
	public:
		void connect(TreeLinkNode* A);

};
#endif

void Solution::connect(TreeLinkNode* A)
{
	if(A == NULL)
		return;

	vector<TreeLinkNode*> *curv = new vector<TreeLinkNode*>;
	vector<TreeLinkNode*> *nextv = new vector<TreeLinkNode*>;

	curv->push_back(A);
	while(curv->size())
	{
		for(unsigned int i=0; i<curv->size(); i++)
		{
			TreeLinkNode* cur_node = curv->at(i);
			if(i+1 <curv->size())
				cur_node->next = curv->at(i+1);
			else
				cur_node->next = NULL;

			if(cur_node->left)
				nextv->push_back(cur_node->left);

			if(cur_node->right)
				nextv->push_back(cur_node->right);
		}
		curv->clear();
		vector<TreeLinkNode*> *tmp_node = curv;
		curv = nextv;
		nextv = tmp_node;
	}
	delete curv;
	delete nextv;
}

