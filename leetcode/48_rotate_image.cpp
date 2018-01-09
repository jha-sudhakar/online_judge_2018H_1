#include<iostream>
#include<vector>
using namespace std;
const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;

class Solution
{
	private:
		void get_next_pos(const int start_x, const int start_y, const int x, const int y, int N, int& x_new, int& y_new, const int dir)
		{
			if(dir == RIGHT)
			{
				x_new = x;
				y_new = y+N-1;
				if(y_new >= start_y+N)
				{
					x_new += y_new - (start_y+N-1);
					y_new = start_y+N-1;
				}
			}
			else if(dir == DOWN)
			{
				x_new = x+N-1;
				y_new = y;
				if(x_new >= start_x+N)
				{
					y_new -= x_new - (start_x+N-1);
					x_new = start_x+N-1;
				}
			}
			else if(dir == LEFT)
			{
				y_new  = y-(N-1);
				x_new = x;
				if(y_new < start_y)
				{
					x_new -= (start_y - y_new);
					y_new = start_y;
				}
			}
			else if(dir == UP)
			{
				x_new = x - (N-1);
				y_new = y;
				if(x_new < start_x)
				{
					y_new += (start_x - x_new);
					x_new = start_x;
				}
			}
		}


	public:
    	void rotate(vector< vector<int> >& matrix)
		{
			//void get_next_pos(const int start_x, const int start_y, const int x, const int y, int N, int& x_new, int& y_new, const int dir)
			int offset = 0,start_x = 0, start_y = 0, N = matrix.size();
			int dir = 0;
			while(N > 1)
			{
				for(int i=start_y; i<start_y+N-1; i++)
				{
					int cur_x = start_x, cur_y = i;
					int cur_val = matrix[cur_x][cur_y];
					int next_x, next_y;
					dir = 0;
					for(int j=0; j<4; j++)
					{
						get_next_pos(start_x, start_y, cur_x, cur_y, N, next_x, next_y, dir);
						int next_val = matrix[next_x][next_y];
						matrix[next_x][next_y] = cur_val;

						cur_val = next_val;
						cur_x  = next_x;
						cur_y = next_y;
						dir = (dir+1)%4;
					}

				}
				N -= 2;
				start_x += 1;
				start_y += 1;
			}
    	}
};
