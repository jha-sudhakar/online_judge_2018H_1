#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
	public:
		int longestValidParentheses(string s)
		{
			s = string(")") + s;
			unsigned int max_len = 0, N=s.size();
			unsigned int* arr = new unsigned int[N+1];
			unsigned int size = 0;
			arr[0] = 0;
			size++;
			for(unsigned int i = 1; i<N; i++)
			{
				if(s[i] == '(')
				{
					arr[size] = i;
					size++;
				}
				else
				{
					if(s[arr[size-1]] == '(')
					{
						size--;
					}
					else
					{
						arr[size] = i;
						size++;
					}
				}
			}
			arr[size] = N;
			size++;
			unsigned int start=0, end=0, diff=0;;
			for(unsigned int i=0; i<size; i++)
			{
				end = arr[i];
				diff = end-start;
				start = end;

				if(diff > max_len)
					max_len = diff;
			}
			if(max_len != 0)
				max_len--;
			delete [] arr;
			return max_len;
		}

};



#if DBG
	int main()
	{
		vector<string> in_vec;

		string in_str;
		in_str = "(()";
		in_vec.push_back(in_str);

		in_str = "))))";
		in_vec.push_back(in_str);

		in_str = ")()()())()()()()())";
		in_vec.push_back(in_str);

		in_str = "((((";
		in_vec.push_back(in_str);

		in_str = "()))))()()()";
		in_vec.push_back(in_str);

		Solution obj;
		for(unsigned int i=0; i<in_vec.size(); i++)
		{
			int ret_val = obj.longestValidParentheses(in_vec[i]);
			cout <<"\n Input = " << in_vec[i] << "\n Max len = " << ret_val << endl;
		}
		return 0;
	}

#endif