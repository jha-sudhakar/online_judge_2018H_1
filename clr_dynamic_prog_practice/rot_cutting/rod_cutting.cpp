#include<limits.h>
#include <iostream>
using namespace std;

class Rod
{
	private:
			//vector<int> arr;
		int N, T;
		int x,y,z;

	public:
		void execute();
		int get_max_count();
};

void Rod::execute()
{
	cin >> T;
	for(int i=0; i<T; i++)
	{
		cin >> N;
		cin >> x >> y >> z;
		//cout <<"Test " << i+1 << ", N= " << N <<", x= " << x <<", y= " << y <<", z= " << z << endl;
		int rod_count = get_max_count();
		cout << rod_count << endl;
	}
}

int Rod::get_max_count()
{
	int min = x;
	if(min > y)
		min = y;
	if(min > z)
		min =z;
	
	if(min > N)
		return 0;
	
	int* arr = new int[N+1];
	for(int i=0; i<=N; i++)
	{
		arr[i] = INT_MIN;
	}
	arr[0] = 0;
	if(x<=N)
		arr[x] = 1;
	
	if(y<=N)
		arr[y] = 1;
	
	if(z<=N)
		arr[z] = 1;

	for(int n=min+1; n<=N; n++)
	{
		int cur_val = INT_MIN;
		if((n-x >= 0) && (arr[n-x] != INT_MIN))
		{
			if( cur_val < 1 + arr[n-x])
				cur_val = 1 + arr[n-x];
		}

		if((n-y >= 0) && (arr[n-y] != INT_MIN))
		{
			if( cur_val < 1 + arr[n-y])
				cur_val = 1 + arr[n-y];
		}
		
		if((n-z >= 0) && (arr[n-z] != INT_MIN))
		{
			if( cur_val < 1 + arr[n-z])
				cur_val = 1 + arr[n-z];
		}
		
		arr[n] = cur_val;
	}
	int ret_val = arr[N];
	delete [] arr;
	return ret_val;
}


int main()
{
	Rod rd;
	rd.execute();
	return 0;
}
