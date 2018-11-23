#include<functional>
#include<vector>
#include<utility>
#include<queue>
#include<iostream>
using namespace std;

typedef bool (*comp)(pair<int, unsigned int>, pair<int, unsigned int>);
bool compr(pair<int, unsigned int> obj1, pair<int, unsigned int> obj2)
{
	if(obj1.first <= obj2.first)
		return true;
	else
		return false;
}

class Solution
{
	public:


		vector<int> maxSlidingWindow(vector<int>& nums, int k)
		{
			unsigned int start=0, N = nums.size();

			vector<int> max_vec;
			if(k == 0)
				return max_vec;
			else if (k>N)
				k = N;

			priority_queue<pair<int, unsigned int>, vector< pair<int, unsigned int> >, comp >que(compr);
			for(unsigned int i=0; i<k-1; i++)
			{
				pair<int, unsigned int> tmp = make_pair(nums[i], i);
				que.push(tmp);
			}

			pair<int, unsigned int> top_val;

			for(unsigned int i=k-1; i<N; i++)
			{
				pair<int, unsigned int> tmp = make_pair(nums[i], i);
				que.push(tmp);
				while(true)
				{
					top_val = que.top();
					if(top_val.second < start) {
						que.pop();
					}
					else {
						break;
					}
				}
				max_vec.push_back(top_val.first);
				start++;
			}

			return max_vec;
		}
};


int main()
{
	int arr[] = {1,3,-1,-3,5,3,6,7};
	int k = 3;


	vector<int> vec;
	for(unsigned int i=0; i<sizeof(arr)/sizeof(int); i++)
	{
		vec.push_back(arr[i]);
	}

	cout <<"N = " << vec.size() <<", K = " << k << endl;
	cout <<"Input ==> ";
	for(unsigned int i=0; i<vec.size(); i++)
	{
		cout << vec[i] << ", ";
	}
	cout << endl;


	Solution sol;
	vector<int> ret = sol.maxSlidingWindow(vec, k);
	cout <<"Output ==> ";
	for(unsigned int i=0; i<ret.size(); i++)
	{
		cout << ret[i] << ", ";
	}
	cout << endl;

	return 0;
}
