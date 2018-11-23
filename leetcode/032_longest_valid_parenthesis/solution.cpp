#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
	public:
		int longestValidParentheses(string s)
		{
			unsigned int max_len = 0;
			unsigned int N = s.size();
			unsigned int* dp = new unsigned int[N+1];
			dp[0] = 0;

			for(long int i=1; i<N; i++)
			{
				if(s[i] == '(')
				{
					dp[i] = 0;
					continue;
				}

				// s[i] equals ')' so rest of the code follows it.
				if(s[i-1] == '(')
				{
					if(i-2>=0)
						dp[i] = dp[i-2] + 2;
					else
						dp[i] = 2;

					if(dp[i] > max_len)
						max_len = dp[i];
					continue;
				}
				else
				{
					int len = dp[i-1];
					if(i-1-len >=0 && s[i-1-len] == '(')
					{
						dp[i] = dp[i-1]+2;
						if(i-1-len-1 >=0)
							dp[i] += dp[i-1-len-1];
					}
					else
						dp[i] = 0;

					if(dp[i] > max_len)
						max_len = dp[i];
				}
			}
			delete [] dp;
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