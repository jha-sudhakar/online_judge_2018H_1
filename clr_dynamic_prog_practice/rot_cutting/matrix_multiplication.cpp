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
		void print_sol_str(int** split, int start, int end);
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
		get_mat_chain_min();
		cout << endl;
		delete [] dim;
	}
}


int Mat::get_mat_chain_min()
{
	const int D = N-1;
	int val[D+1][D+1];
	//int split[D+1][D+1];
	int** split = new int*[D+1];
	for(int i=0; i<D+1; i++)
		split[i] = new int [D+1];
	
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
			int min_index = i;
			for(int p=i; p<j; p++)
			{
				int val1 = val[i][p];
				int val2 = val[p+1][j];
				int val3 = dim[i-1] * dim[p] * dim [j];
				val3 += (val1 + val2);
				if(val3 < min_val)
				{
					min_val = val3;
					min_index = p;
				}
			}
			val[i][j] = min_val;
			split[i][j] = min_index;
		}
	}
	
	
	print_sol_str(split, 1, D);

	for(int i=0; i<D+1; i++)
		delete [] split[i];
	delete [] split;

	return val[1][D];
}


void Mat::print_sol_str(int** split, int start, int end)
{
	if(start > end)
		return;

	//cout<<"start= "<< start <<", end= " << end << endl;
	
	if(start == end)
	{
		char ch = 'A' + start-1;
		cout << ch;
		return;
	}
	else if(start+1 == end)
	{
		char ch1 = 'A'+start-1;
		char ch2 = 'A'+end-1;
	
		cout << "(" << ch1 << ch2 << ")";
		return;
	}
	
	int mid = split[start][end];
	cout <<"(";
	print_sol_str(split, start, mid);
	print_sol_str(split, mid+1, end);
	cout <<")";
}
		
		
int main() {
	Mat obj;
	obj.execute();
	return 0;
}