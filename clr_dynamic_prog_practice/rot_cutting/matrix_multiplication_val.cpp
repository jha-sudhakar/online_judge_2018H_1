#include<limits.h>

#include <iostream>
using namespace std;

class Mat
{
	private:
		int N, T;
		int* dim;
		
	public:
		void execute();
		int get_mat_chain_min();
};

void Mat::execute()
{
	cin >> T;
	for(int i=0; i<T; i++)
	{
		cin >> N;
		dim = new int[N];
		for(int j=0; j<N; j++)
		{
			cin >> dim[j];
		}
		cout << get_mat_chain_min() << endl;
		delete [] dim;
	}
}


int Mat::get_mat_chain_min()
{
	const int D = N-1;
	int val[D+1][D+1];
	
	for(int i=1; i<=D; i++)
		val[i][i] = 0;
		
	for(int i=1; i<D; i++)
		val[i][i+1] = dim[i-1] * dim[i] * dim[i+1];
		
	for(int k=2; k<D; k++)	
	{
		for(int i=1; i<D; i++)	
		{
			if(i+k >D)
				break;

			int j = i+k;

			int min_val = INT_MAX;
			for(int p=i; p<j; p++)
			{
				int val1 = val[i][p];
				int val2 = val[p+1][j];
				int val3 = dim[i-1] * dim[p] * dim [j];
				val3 += (val1 + val2);
				if(val3 < min_val)
					min_val = val3;
			}
			val[i][j] = min_val;
		}
	}
	
	return val[1][D];
}


int main() {
	Mat obj;
	obj.execute();
	return 0;
}