
#if DBG

	#include<stdio.h>
	class Node {
	public:
		int val = NULL;
		Node* prev = NULL;
		Node* next = NULL;
		Node* child = NULL;

		Node() {}

		Node(int _val, Node* _prev, Node* _next, Node* _child) {
			val = _val;
			prev = _prev;
			next = _next;
			child = _child;
		}
	};

#endif

class Solution {
private:
	Node* flatten_private(Node* head);
public:
	//void edit_list(Node* head,
    Node* flatten(Node* head)
    {
		if(head == NULL)
			return head;
		flatten_private(head);
		return head;
	}
};

Node* Solution::flatten_private(Node* head)
{
	while(head->next != NULL)
	{
		while(head->next != NULL && head->child == NULL)
		{
			head = head->next;
		}
		if(head->child != NULL)
		{
			Node* old_next = head->next;
			Node* cur_child = head->child;
			Node* ret_node = flatten_private(head->child);

			ret_node->next = old_next;
			old_next->prev = ret_node;

			head->next = cur_child;
			cur_child->prev = head;
			head->child = NULL;
			head = ret_node;
		}
	}
	Node* ret_node = NULL;
	if(head->child != NULL)
		ret_node = flatten_private(head->child);
	head->next = head->child;
	head->child = NULL;
	if(head->next)
		head->next->prev = head;

	if(ret_node != NULL)
		head = ret_node;

	return head;
}