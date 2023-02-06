#include <iostream>
#include <queue>
using namespace std;

int box[100][100][100];
int check_x[4] = { 0,1,0,-1 };
int check_y[4] = { 1,0,-1,0 };
int check_z[2] = { -1, 1 };

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	int n, m, h;
	queue<pair<pair<int, int>, int>> q;
	cin >> m >> n >> h;

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> box[k][i][j];
			}
		}
	}
	
	int neg = 0;

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (box[k][i][j] == 1)
					q.push({ { k,i }, j });
				else if (box[k][i][j] == -1)
					neg++;
			}
		}
	}

	int cnt = 0;
	while (!q.empty())
	{
		pair<pair<int, int>, int> tmp = q.front();
		q.pop();
		int cur_z = tmp.first.first;
		int cur_x = tmp.first.second;
		int cur_y = tmp.second;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + check_x[i];
			int ny = cur_y + check_y[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (box[cur_z][nx][ny] != 0) continue;
			box[cur_z][nx][ny] = box[cur_z][cur_x][cur_y] + 1;
			q.push({{ cur_z, nx }, ny });
			cnt++;
		}
		for (int i = 0; i < 2; i++)
		{
			int nz = cur_z + check_z[i];
			if (nz < 0 || nz >= h) continue;
			if (box[nz][cur_x][cur_y] != 0) continue;
			box[nz][cur_x][cur_y] = box[cur_z][cur_x][cur_y] + 1;
			q.push({ {nz, cur_x}, cur_y });
			cnt++;
		}
	}

	int mx = 0;
	bool check = true;

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mx = max(mx, box[k][i][j]);
				if (box[k][i][j] == 0)
				{
					check = false;
					break;
				}
			}
		}
	}

	if (check) cout << mx - 1;
	else cout << -1;
	return 0;
}
