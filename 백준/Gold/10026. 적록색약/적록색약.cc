#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

char arr[100][100];
int visit_q[100][100];
int visit_p[100][100];

int check_x[4] = { 0,1,0,-1 };
int check_y[4] = { 1,0,-1,0 };

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	int n;
	cin >> n;
	cin.ignore(1);
	
	vector<string> v;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		getline(cin, tmp);
		v.push_back(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = v[i][j];
		}
	}

	queue<pair<int, int>> q, p;

	int cnt_q = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit_q[i][j] == 1) continue;

			q.push({ i, j });
			visit_q[i][j] = 1;
			char c = arr[i][j];
			while (!q.empty())
			{
				pair<int, int> tmp = q.front();
				q.pop();
				int cur_x = tmp.first;
				int cur_y = tmp.second;
				
				for (int k = 0; k < 4; k++)
				{
					int nx = cur_x + check_x[k];
					int ny = cur_y + check_y[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visit_q[nx][ny] != 0) continue;
					if (c == 'B')
					{
						if (arr[nx][ny] != 'B') continue;
						q.push({ nx,ny });
						visit_q[nx][ny] = 1;
					}
					else if (c == 'R')
					{
						if (arr[nx][ny] != 'R') continue;
						q.push({ nx, ny });
						visit_q[nx][ny] = 1;
					}
					else
					{
						if (arr[nx][ny] != 'G') continue;
						q.push({ nx, ny });
						visit_q[nx][ny] = 1;
					}
				}
			}
			cnt_q++;
		}
	}
	
	cout << cnt_q << " ";

	cnt_q = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visit_q[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit_q[i][j] == 1) continue;

			q.push({ i, j });
			visit_q[i][j] = 1;
			char c = arr[i][j];
			while (!q.empty())
			{
				pair<int, int> tmp = q.front();
				q.pop();
				int cur_x = tmp.first;
				int cur_y = tmp.second;

				for (int k = 0; k < 4; k++)
				{
					int nx = cur_x + check_x[k];
					int ny = cur_y + check_y[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visit_q[nx][ny] != 0) continue;
					if (c == 'B')
					{
						if (arr[nx][ny] != 'B') continue;
						q.push({ nx,ny });
						visit_q[nx][ny] = 1;
					}
					else
					{
						if (arr[nx][ny] == 'B') continue;
						q.push({ nx, ny });
						visit_q[nx][ny] = 1;
					}
				}
			}
			cnt_q++;
		}
	}

	cout << cnt_q;
	return 0;
}
