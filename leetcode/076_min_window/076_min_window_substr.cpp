#include<iostream>
#include<string>
using namespace std;


class Solution
{
	public:
	    string minWindow(string s, string t)
	    {
			string ret = string("");
			if(s.size() < t.size())
				return ret;

			unsigned int unq_chars = 0;
			unsigned int  index[256];
			for(unsigned int i=0; i<256; i++)
				index[i] = 0;
			for(unsigned int i=0; i<t.size(); i++)
				index[t[i]]++;
			for(unsigned int i=0; i<256; i++)
				if(index[i] != 0) unq_chars++;



			unsigned int start_pos = 0;
			int len = 1 + s.size();


			unsigned int start = 0;
			unsigned int cur_unq_chars = 0;
			unsigned int my_index[256];
			for(unsigned int i=0; i<256; i++)
			my_index[i] = 0;
			for(unsigned int end = 0; end <s.size(); end++)
			{
				if(index[s[end]] != 0)
				{
					my_index[s[end]]++;
					if(my_index[s[end]] == index[s[end]])
					{
						cur_unq_chars++;
					}
					if(cur_unq_chars == unq_chars)
					{
						if(1+end-start < len)
						{
							len = 1+end-start;
							start_pos = start;
						}
						while(cur_unq_chars == unq_chars && start <= end)
						{
							if(index[s[start]] != 0)
							{
								my_index[s[start]]--;
								if(1+my_index[s[start]] == index[s[start]])
								{
									cur_unq_chars--;
									start++;
									break;
								}
							}

							start++;

							if(start <= end && 1+end-start < len)
							{
								len = 1+end-start;
								start_pos = start;
							}

						}
					}
				}
			}

			if(len <= s.size())
			{
				ret = s.substr(start_pos, len);
		    }
			return ret;
    	}
};


#if DBG

int main()
{
	Solution obj;
	string S = "ADOBECODEBANC";
	string T = "ABC";
	string ret = obj.minWindow(S, T);
	cout << ret << endl;
}

#endif