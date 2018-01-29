#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

vector <int> longestCommonSubsequence(vector <int> a, vector <int> b)
{
	const int N = a.size()-1;
	const int M = b.size()-1;
	
	int table[N+1][M+1];
	for(unsigned int i=0; i<=N; i++)
		for(unsigned int j=0; j<=M; j++)
			table[i][j] = 0;
	
	for(int n=1; n<=N; n++)
	{
		for(int m=1; m<=M; m++)
		{
			if(a[n] == b[m])
			{
				table[n][m] = 1 + table[n-1][m-1];
			}
			else
			{
				int val1 = table[n-1][m];
				int val2 = table[n][m-1];
				int val = val1;
				if(val2 > val)  val = val2;
				table[n][m] = val;
			}
		}
		
		//cout << "At N= " << n <<" ==> max-len = " << table[n][M] << endl;
	}

	//cout << "max-len = " << table[N][M] << endl;

	vector<int> ret_vec;
	int n=N, m=M;
	while(n>0 && m>0)
	{
		if(table[n][m] == table[n-1][m])
		{
			n--;
		}
		else if(table[n][m] == table[n][m-1])
		{
			m--;
		}
		else if(table[n][m] == 1+table[n-1][m-1])
		{
			ret_vec.push_back(a[n]);
			//cout <<"selected " << a[n] << " at n= " << n <<", m= " << m << endl;
			n--; m--;
		}
		//else assert(false);
	}
	
	vector<int> ret_vec_rev;
	for(int i=0; i<ret_vec.size(); i++)
		ret_vec_rev.push_back(ret_vec[ret_vec.size()-1-i]);
	
	return ret_vec_rev;
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n+1);
	a[0] =0;
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[1+a_i];
    }
    vector<int> b(m+1);
    b[0] = 0;
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[1+b_i];
    }
    vector <int> result = longestCommonSubsequence(a, b);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
