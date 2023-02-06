#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt = 0;
int visit[15][15];

void checkMate(int row, int col, char check)
{
	if (check == '+')
	{
		for (int i = row + 1; i < n; i++)
			visit[i][col]++;

		int i = row, j = col;
		while (true)
		{
			i++; j--;
			if (i >= n || j >= n || i < 0 || j < 0)
				break;
			visit[i][j]++;
		}

		i = row;
		j = col;

		while (true)
		{
			i++; j++;
			if (i >= n || j >= n || i < 0 || j < 0)
				break;
			visit[i][j]++;
		}
	}
	
	else
	{
		for (int i = row + 1; i < n; i++)
			visit[i][col]--;

		int i = row, j = col;
		while (true)
		{
			i++; j--;
			if (i >= n || j >= n || i < 0 || j < 0)
				break;
			visit[i][j]--;
		}

		i = row;
		j = col;

		while (true)
		{
			i++; j++;
			if (i >= n || j >= n || i < 0 || j < 0)
				break;
			visit[i][j]--;
		}
	}
}

void func(int row)
{
	if (row == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[row][i] == 0)
		{
			visit[row][i] = 1;
			checkMate(row, i, '+');
			func(row + 1);
			checkMate(row, i, '-');
			visit[row][i] = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;
	func(0);
	cout << cnt;
	return 0;
}
