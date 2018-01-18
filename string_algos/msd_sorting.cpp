#include<time.h>
#include<assert.h>
#include<stdlib.h>

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class MSDSort
{
	private:
		vector<string> in_str, stl_str, my_str;
		unsigned int min_len, max_len, size;
		

	public:
		MSDSort();

		void execute(int loop);
		//void read_input(vector<string>& str_arr);
		void sort_and_validate();
		//void sort_string_msd_radix(vector<string>& str_arr);
		void sort_string_msd_radix(vector<string>& input_vec, const int start, const int end, const int index);
};

MSDSort::MSDSort()
{
	srand(time(NULL));
}

void MSDSort::execute(int loop)
{
	min_len = 1;
	max_len = min_len + rand()%5;

	while(loop--)
	{
		size = 1 + rand()%50;
		in_str.clear();
		for(int i=0; i<size; i++)
		{
			string tmp_str;
			max_len = min_len + rand()%20;
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

		cout <<"Size = " << size <<", Completed loop " << loop << endl << endl;
	}
}

void MSDSort::sort_and_validate()
{
	sort(stl_str.begin(), stl_str.end());
	sort_string_msd_radix(my_str, 0, my_str.size()-1, 0);
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

void MSDSort::sort_string_msd_radix(vector<string>& input_vec, const int start, const int end, const int pos)
{
	if(start>=end)
		return;

	vector<string*> buf_str, str_vec;
	int MAX_LEN = 0;
	for(int i=start; i<=end; i++)
	{
		str_vec.push_back(&(input_vec[i]));

		if(input_vec[i].length() > MAX_LEN)
			MAX_LEN = input_vec[i].length();
	}
	buf_str.resize(str_vec.size());
#if DEBUG
	//cout << "\nString max-length = " << MAX_LEN << endl;
#endif
	if(pos>= MAX_LEN)
		return;

	int count[256], ref[256];

	for(int i=0; i<256; i++)
	{
		count[i] = 0;
		ref[i] = 0;
	}
	
	for(int i=0; i<str_vec.size(); i++)
	{
		if(pos < (*str_vec[i]).length())
			count[1+(*str_vec[i])[pos]]++;
		else
			count[1+0]++;
	}
	
	for(int i=1; i<256; i++)
	{
		count[i] += count[i-1];
		ref[i] = count[i];
	}
	for(int i=0; i<str_vec.size(); i++)
	{	
		if(pos < (*str_vec[i]).length())
			buf_str[count[(*str_vec[i])[pos]]++] = str_vec[i];
		else
			buf_str[count[0]++] = str_vec[i];
	}

	str_vec.clear();
	str_vec = buf_str;


	vector<string> out_vec;
	for(int i=start; i<=end; i++)
		out_vec.push_back(*(str_vec[i-start]));

	for(int i=start; i<=end; i++)
		input_vec[i] = out_vec[i-start];

	for(int i=1; i<256; i++)
	{
		if(ref[i] != ref[i-1])
		{
			sort_string_msd_radix(input_vec, start+ref[i-1], start+ref[i]-1, 1+pos);
		}
	}
}




int main(int argc, char* argv[])
{
	for(int i=0; i<argc; i++)
	{
		cout <<"cmd arg " << i <<" ==> " << argv[i] << endl;
	}


	MSDSort obj;
	obj.execute(atoi(argv[1]));
	return 0;
}

