#include<string>
#include<iostream>
using namespace std;

class Solution
{
public:
    bool isValid(string s) 
	{
		const unsigned int len = s.size();
		char ch[len];
		int pos = -1;
		for(unsigned int i=0; i<s.size(); i++)
		{
			if(s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				pos++;
				ch[pos] = s[i];
			}
			else if(s[i] == ')')
			{
				if(pos>=0 && ch[pos] == '(')
				{
					pos--;
				}
				else 
					return false;
			}
			else if(s[i] == ']')
			{
				if(pos>=0 && ch[pos] == '[')
				{
					pos--;
				}
				else 
					return false;
			}
			else if(s[i] == '}')
			{
				if(pos>=0 && ch[pos] == '{')
				{
					pos--;
				}
				else 
					return false;
			}
		}
 
		if(pos == -1)
			return true;
		else
			return false;
    }
};
