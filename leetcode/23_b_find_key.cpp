#include<stdlib.h>
#include<assert.h>
#include<time.h>

#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class FindKey
{
	
	public:
		int search(vector<int>& nums, int key);
		void test_getKey(int loop);
		int find_min_index(vector<int>& nums);
		int binary_search(vector<int>&nums, int start, int end, int key);
		FindKey();
};

FindKey::FindKey()
{
	srand(time(NULL));
}

int FindKey::binary_search(vector<int>&nums, int start, int end, int key)
{
	if(end == -1 || start == -1)
		return -1;

	while(start+1<end)
	{
		int mid = (start+end)/2;
		if(nums[mid] == key)
			return mid;
		if(nums[mid] <key)
			start = mid;
		else 
			end = mid;
	}
	if(nums[start] == key)
		return start;
	else if(nums[end] == key)
		return end;
	else
		return -1;
}


int FindKey::find_min_index(vector<int>& nums)
{
	if(nums.size() == 1)
		return 0;
	
	int s= 0, e = nums.size()-1;
	while(s+1<e)
	{
		int mid = (s+e)/2;
		if(nums[mid] > nums[s] && nums[mid] > nums[e])
			s = mid;
		else if(nums[mid] < nums[s] && nums[mid] < nums[e])
			e = mid;
		else if(nums[s] < nums[e])
			return s;
	}

	if(nums[s] < nums[e])
		return s;
	else
		return e;

}

int FindKey::search(vector<int>& arr, int key)
{
	if(arr.size() == 0)
		return -1;
	else if(arr.size() == 1)
		if(arr[0] == key)
			return 0;
		else
			return -1;
	const int pos = find_min_index(arr);
	int val1 = binary_search(arr, 0, pos-1, key);
	int val2 = binary_search(arr, pos, arr.size()-1, key); 
	if(val1>val2)
		return val1;
	else
		return val2;
}


void FindKey::test_getKey(int loop)
{

	while(loop--)
	{
		int size = 15 + rand()%10;
		vector<int> arr, unq_arr;
		while(size)
		{
			arr.push_back(rand()%100);
			size--;
		}
		sort(arr.begin(), arr.end());
		unq_arr.push_back(arr[0]);
		for(int i=1; i<arr.size(); i++)
		{
			if(arr[i] != arr[i-1])
				unq_arr.push_back(arr[i]);
		}
		size = unq_arr.size();
		const int min_val = unq_arr[0];
		int rotate_pos = rand()%size;
		arr.clear();
		for(int i=0; i<size; i++)
		{
			arr.push_back(unq_arr[(rotate_pos+i)%size]);
		}	

		cout <<"\nRotataed array ==> ";
		for(int i=0; i<arr.size(); i++)
		{
			if(i)
				cout <<", ";
			cout << arr[i];
		}
		//cout << endl;
		const int pos = find_min_index(arr);
		if(min_val != arr[pos])
		{
			cout <<"\nmy min_val = " << arr[pos] <<", expected = " << min_val <<"  ......... so ***** asserting  ******\n";
			assert(false);
		}
		else
		{
			cout <<"\nmy min_val = " << arr[pos] <<", expected = " << min_val <<"\n";
		}		


		int search_type = rand()%2;
		int random_key = rand()%100;
		if(search_type)
			random_key = arr[rand()%arr.size()];
		int random_key_pos = -1;
		for(int i=0; i<arr.size(); i++)
		{
			if(random_key == arr[i])
			{
				random_key_pos = i; 
				break;
			}
		}
		int val1 = binary_search(arr, 0, pos-1, random_key);
		int val2 = binary_search(arr, pos, arr.size()-1, random_key); 
		if(val1 != -1)
		{
			if(val1 != random_key_pos)
				assert(false);
		}
		if(val2 != -1)
		{
			if(val2 != random_key_pos)
				assert(false);
		}
		cout << "\t\t\tsearch_key = " << random_key <<" ==> random_pos = " << random_key_pos <<", val1 = " << val1 <<", val2 = " << val2 << endl;
	}
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
  		FindKey obj;
		return obj.search(nums, target);      
    }
};


#if LOCAL
int main()
{
	FindKey obj;
	obj.test_getKey(10);

}
#endif
