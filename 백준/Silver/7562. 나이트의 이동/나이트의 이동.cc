#include <iostream>
#include <queue>
using namespace std;

int board[300][300];

int check_x[8] = {-2,-2,-1,1,2,2,1,-1};
int check_y[8] = {-1,1,2,2,1,-1,-2,-2};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	int t, size;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int start_x, start_y, dest_x, dest_y;
		
		cin >> size;
		cin >> start_x >> start_y;
		cin >> dest_x >> dest_y;

		if (start_x == dest_x && start_y == dest_y)
		{
			cout << 0 << "\n";
			continue;
		}

		queue<pair<int, int>> q;
		q.push({ start_x, start_y });
		board[start_x][start_y] = 1;
		
		bool check = false;
		
		while (!q.empty())
		{
			pair<int, int> tmp = q.front();
			q.pop();
			int cur_x = tmp.first;
			int cur_y = tmp.second;

			for (int j = 0; j < 8; j++)
			{
				int nx = cur_x + check_x[j];
				int ny = cur_y + check_y[j];

				if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;

				if (nx == dest_x && ny == dest_y)
				{
					cout << board[cur_x][cur_y] << "\n";
					check = true;
					break;
				}

				if (board[nx][ny] != 0) continue;
				q.push({ nx, ny });
				board[nx][ny] = board[cur_x][cur_y] + 1;
			}
			if (check) break;
		}
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				board[j][k] = 0;
			}
		}
	}
	return 0;
}
