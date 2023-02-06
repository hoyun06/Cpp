#include <iostream>
#include <queue>
using namespace std;

int arr[50][50];
int visit[50][50];

int check_x[4] = { 0,1,0,-1 };
int check_y[4] = { 1,0,-1,0 };

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		queue<pair<int, int>> q;
		int cnt = 0;

		int m, n, k;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				if (arr[a][b] == 0) continue;
				else if (visit[a][b] == 1) continue;

				q.push({ a,b });
				visit[a][b] = 1;

				while (!q.empty())
				{
					pair<int, int> tmp = q.front();
					q.pop();
					int cur_x = tmp.first;
					int cur_y = tmp.second;

					for (int j = 0; j < 4; j++)
					{
						int nx = cur_x + check_x[j];
						int ny = cur_y + check_y[j];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (visit[nx][ny] != 0 || arr[nx][ny] != 1) continue;
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
				}
				cnt++;
			}
		}
		cout << cnt << "\n";
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				visit[a][b] = 0;
				arr[a][b] = 0;
			}
		}
	}
	return 0;
}
