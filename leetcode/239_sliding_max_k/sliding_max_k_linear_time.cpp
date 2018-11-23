#include<list>
#include<vector>
#include<iostream>
using namespace std;

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

			list<int> que;
			for(unsigned int i=0; i<N; i++)
			{
				que.push_back(i);
				std::list<int>::iterator itr = que.end();
				itr--;
				int last_index = *itr;
				while(que.size() > 1)
				{
					itr--;
					if(nums[*itr] <= nums[last_index])
					{
						que.erase(itr);
					}
					else
					{
						last_index = *itr;
					}

					if(itr == que.begin())
					{
						break;
					}

				}
				if(i >= k-1)
				{
					while(1)
					{
						int index = que.front();
						if(index >= 1+i-k)
							break;
						else
							que.pop_front();
					}
					max_vec.push_back(nums[que.front()]);
				}

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
