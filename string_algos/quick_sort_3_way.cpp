#include<time.h>
#include<assert.h>
#include<stdlib.h>

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Quick3Sort
{
	private:
		vector<string> in_str, stl_str, my_str;
		unsigned int min_len, max_len, size;
		

	public:
		Quick3Sort();

		void execute(int loop);
		//void read_input(vector<string>& str_arr);
		void sort_and_validate();
		//void sort_string_quick3_radix(vector<string>& str_arr);
		void sort_string_quick3(vector<string>& input_vec);
		void sort_string_quick3_v2(vector<string*>& input_vec, const int start, const int end, const int index, const int MAX_LEN);
//		bool is_smaller(string* str1, string*str2, const int start);
};

Quick3Sort::Quick3Sort()
{
	srand(time(NULL));
}

void Quick3Sort::execute(int loop)
{
	min_len = 100;
	max_len = min_len + rand()%5;

	while(loop--)
	{
		size = 30 + rand()%50;
		in_str.clear();
		for(int i=0; i<size; i++)
		{
			string tmp_str;
			max_len = min_len + rand()%50;
			for(int j=0; j<max_len; j++)
			{
				//char ch = 65 + rand()%26;
				char ch = 65 + rand()%5;
				tmp_str.push_back(ch);
			}
			in_str.push_back(tmp_str);
		}
#if DEBUG
		cout <<"Input string array == >\n";
		for(int i=0; i<in_str.size(); i++)
		{
			if(i)
				cout << ", ";
			cout << in_str[i] ;
		}
		cout << endl;
#endif
		stl_str = my_str = in_str;
		sort_and_validate();

		cout <<"Size = " << size <<", Completed loop " << loop << endl << endl;
	}
}

void Quick3Sort::sort_and_validate()
{
	sort(stl_str.begin(), stl_str.end());
	sort_string_quick3(my_str);
	if(stl_str.size() != my_str.size())
	{
		assert(false);
	}

#if DEBUG
	cout <<"stl string array == >\n";
	for(int i=0; i<stl_str.size(); i++)
	{
		if(i)
			cout << ", ";
		cout << stl_str[i] ;
	}
	cout << endl;

	cout <<"jha string array == >\n";
	for(int i=0; i<my_str.size(); i++)
	{
		if(i)
			cout << ", ";
		cout << my_str[i] ;
	}
	cout << endl;
#endif
	for(int i=0; i<stl_str.size(); i++)
	{
		if(stl_str[i] != my_str[i])
		{
			cout << "\n mismatch at index " << i << " ==> stl_str = " << stl_str[i] <<", my_str = " << my_str[i] << endl;
			assert(false);
		}
	}
}

/*
bool Quick3Sort::is_smaller(string* str1, string*str2, const int start)
{
	int index = start;
	while(index)
	{
		if(str1->size()<= index)
			return true;
		else if(str2->size() <= index)
			return false;

		if(str1[index] < str2[index])
			return true;
		else if(str1[index] > str2[index])
			return false;
		else
			index++;
	}
}
*/
void Quick3Sort::sort_string_quick3(vector<string>& input_vec)
{
	int MAX_LEN = 0;

	vector<string*> arg;
	for(int i=0; i<input_vec.size(); i++)
	{
		arg.push_back(&(input_vec[i]));

		if(input_vec[i].size() > MAX_LEN)
			MAX_LEN = input_vec[i].size();
	}
	
	sort_string_quick3_v2(arg, 0, arg.size()-1, 0, MAX_LEN);

	vector<string> buf;
	for(int i=0; i<arg.size(); i++)
	{
		buf.push_back(*(arg[i]));
	}
	
	input_vec.clear();
	for(int i=0; i<buf.size(); i++)
		input_vec.push_back(buf[i]);
}




void Quick3Sort::sort_string_quick3_v2(vector<string*>& input_vec, const int start, const int end, const int pos, const int MAX_LEN)
{
	if(start>=end || (pos>= MAX_LEN))
		return;


	int i=start+1, k=start, j=end;
	const char key = (*input_vec[start])[pos];
	//=========================================
	while(i<=j)
	{
		if((*input_vec[i])[pos] < key)
		{
			string* tmp = input_vec[k];
			input_vec[k] = input_vec[i];
			input_vec[i] = tmp;
			k++;
			i++;
		}
		else if((*input_vec[i])[pos] == key)
		{
			i++;
		}
		else
		{
			if((*input_vec[j])[pos] > key)
				j--;
			else
			{
				string* tmp = input_vec[i];
				input_vec[i] = input_vec[j];
				input_vec[j] = tmp;
			}
		}
	}

	sort_string_quick3_v2(input_vec, start, k-1, pos, MAX_LEN);

#if DEBUG2
	if(pos != 0 && k < i-1)
	{
		cout <<"\npos= " <<  pos << endl;
		for(int p=0; p<=pos-1; p++)
			cout <<"-";
		cout<<"*\n";

		for(int p=k; p<=i-1;p++)
		{
			cout<< (*input_vec[p]) << endl;
		}
		cout<< endl;
	}
#endif

	sort_string_quick3_v2(input_vec, k, i-1, 1+pos, MAX_LEN);
	sort_string_quick3_v2(input_vec, j+1, end, pos, MAX_LEN);
}




int main(int argc, char* argv[])
{
	for(int i=0; i<argc; i++)
	{
		cout <<"cmd arg " << i <<" ==> " << argv[i] << endl;
	}


	Quick3Sort obj;
	obj.execute(atoi(argv[1]));
	return 0;
}

