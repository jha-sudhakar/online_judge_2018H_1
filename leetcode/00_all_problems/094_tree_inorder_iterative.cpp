

#if DEBUG

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif

struct ele
{
	TreeNode* node;
	bool is_left_done;

	ele(TreeNode* _node, bool _is_left_done)
	{
		node=_node;
		is_left_done = _is_left_done;
	}
};
class Solution
{
	public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ret_arr;
		vector<ele> stk;
		stk.push_back(ele(root, false));

		while(stk.size())
		{
			if(stk[stk.size()-1].node == NULL)
			{
				stk.pop_back();
			}
			else if(stk[stk.size()-1].is_left_done == false)
			{
				stk[stk.size()-1].is_left_done = true;
				TreeNode* left = (stk[stk.size()-1].node)->left;
				stk.push_back(ele(left, false));
			}
			else if(stk[stk.size()-1].is_left_done == true)
			{
				ret_arr.push_back((stk[stk.size()-1].node)->val);
				TreeNode* right = (stk[stk.size()-1].node)->right;
				stk.pop_back();
				stk.push_back(ele(right, false));
			}
		}
        return ret_arr;

	}
};