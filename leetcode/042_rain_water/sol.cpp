#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		int total_water = 0;
		const int N = height.size();
		if(N<3)
			return 0;
		int* rh = new int[N];
		int max_h = height[N-1];

		rh[N-1] = 0;
		for(int i=N-2; i>=0; i--)
		{
			if(height[i] > max_h)
				max_h = height[i];
			rh[i] = max_h;
		}

		max_h = height[0];
		int diff_h;
		for(int i=1; i<N-1; i++)
		{
			diff_h = rh[i];
			if(max_h < diff_h)
				diff_h = max_h;
			//int diff_h = min(max_h, rh[i]);
			if(diff_h > height[i])
				total_water += diff_h-height[i];
			if(height[i] > max_h)
				max_h = height[i];
		}
		delete [] rh;
		return total_water;
    }
};