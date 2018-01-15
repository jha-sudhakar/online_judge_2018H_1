#include<iostream>
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
	int isBalanced(TreeNode* A);
};

#endif

//bool is_valid = true;
int traverse(TreeNode* node, bool& is_valid)
//int traverse(TreeNode* node)
{
	if(node == NULL)
		return 0;

	int left_h = traverse(node->left, is_valid);
	int right_h = traverse(node->right, is_valid);
	
	//int left_h = traverse(node->left);
	//int right_h = traverse(node->right);

	int diff = left_h - right_h;
	if(diff < -1 || diff > 1)
	{
		is_valid = false;
	}
	if(left_h > right_h)
		return 1+left_h;
	else
		return 1+right_h;
}

int Solution::isBalanced(TreeNode* A) 
{
	bool is_valid = true;
	traverse(A, is_valid);
	//traverse(A);
	if(is_valid == false)
		return 0;
	else
		return 1;
}

#if DEBUG
int main()
{
TreeNode *root = new TreeNode(2);
root->right = new TreeNode(1);
Solution obj;
cout << "\nIs Balanced = " <<  obj.isBalanced(root) << endl;;
return 0;
}



#endif
