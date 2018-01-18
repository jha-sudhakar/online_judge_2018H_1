#include<time.h>
#include<assert.h>
#include<stdlib.h>

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class LSDSort
{
	private:
		vector<string> in_str, stl_str, my_str;
		unsigned int min_len, max_len, size;
		

	public:
		LSDSort();

		void execute(int loop);
		//void read_input(vector<string>& str_arr);
		void sort_and_validate();
		void sort_string_lsd_radix(vector<string>& str_arr);
};

LSDSort::LSDSort()
{
	srand(time(NULL));
}

void LSDSort::execute(int loop)
{
	min_len = 50;
	max_len = min_len + rand()%25;
	size = 20 + rand()%20;

	while(loop--)
	{
		in_str.clear();
		for(int i=0; i<size; i++)
		{
			string tmp_str;
			for(int j=0; j<max_len; j++)
			{
				char ch = 65 + rand()%26;
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

		//cout <<"Completed loop " << loop << endl;
	}
}

void LSDSort::sort_and_validate()
{
	sort(stl_str.begin(), stl_str.end());
	sort_string_lsd_radix(my_str);
	if(stl_str.size() != my_str.size())
	{
		assert(false);
	}

	for(int i=0; i<stl_str.size(); i++)
	{
		if(stl_str[i] != my_str[i])
		{
			cout << "\n mismatch at index " << i << " ==> stl_str = " << stl_str[i] <<", my_str = " << my_str[i] << endl;
			assert(false);
		}
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
}

void LSDSort::sort_string_lsd_radix(vector<string>& input_vec)
{
	vector<string*> buf_str, str_vec;

	for(int i=0; i<input_vec.size(); i++)
		str_vec.push_back(&(input_vec[i]));

	buf_str.resize(str_vec.size());

	int count[256];
	for(int pos = (*str_vec[0]).size()-1; pos >=0; pos--)
	{
		for(int i=0; i<256; i++)
		{
			count[i] = 0;
		}
		
		for(int i=0; i<str_vec.size(); i++)
		{
			count[1+(*str_vec[i])[pos]]++;
		}
		
		for(int i=1; i<256; i++)
		{
			count[i] += count[i-1];
		}
		for(int i=0; i<str_vec.size(); i++)
		{
			buf_str[count[(*str_vec[i])[pos]]++] = str_vec[i];
		}

		str_vec.clear();
		str_vec = buf_str;
	}

	vector<string> out_vec;
	for(int i=0; i<input_vec.size(); i++)
		out_vec.push_back(*(str_vec[i]));

	input_vec = out_vec;
}




int main(int argc, char* argv[])
{
	for(int i=0; i<argc; i++)
	{
		cout <<"cmd arg " << i <<" ==> " << argv[i] << endl;
	}


	LSDSort obj;
	obj.execute(atoi(argv[1]));
	return 0;
}

