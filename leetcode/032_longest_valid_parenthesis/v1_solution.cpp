#include<string>
#include<iostream>
using namespace std;

class Solution
{
	public:
    	int longestValidParentheses(string s)
    	{
			unsigned int max_len = 0, cur_len=0;
			int count = 0;
			int left_brace_count = 0;
			bool is_left_brace_valid = true;

			for(unsigned int i=0; i<s.size(); i++)
			{
				if(s[i] == '(')
				{
					count++;
					cur_len++;
					continue;
				}
				is_left_brace_valid = false;
				cur_len++;
				count--;
				if(count == 0)
				{
					if(cur_len > max_len)
						max_len = cur_len;
				}
				else if(count <0)
				{
					cur_len = 0;
					count = 0;
				}
			}
			return max_len;
    	}
};