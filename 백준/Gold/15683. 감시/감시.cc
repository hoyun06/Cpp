#include <iostream>
#include <stack>
#include <climits>
using namespace std;

int n, m, cnt = INT_MAX;

int arr[10][10];
int check[10][10];

stack<pair<pair<int, int>, int>> s;

void calc(int x, int y, int cctv, int dir)
{
	int i = x, j = y;
	if (cctv == 1)
	{
		if (dir == 0)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else if (dir == 1)
		{
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else if (dir == 2)
		{
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else
		{
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
	}
	else if (cctv == 2)
	{
		if (dir == 0)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else
		{
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			j = y;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
	}
	else if (cctv == 3)
	{
		if (dir == 0)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else if (dir == 1)
		{
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else if (dir == 2)
		{
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
	}
	else if (cctv == 4)
	{
		if (dir == 0)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			j = y;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else if (dir == 1)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else if (dir == 2)
		{
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			j = y;
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
		else
		{
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			j = y;
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
			i = x;
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) return;
				if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
				arr[i][j] = 7;
				check[i][j]++;
			}
		}
	}
	else
	{
		while (true)
		{
			i--;
			if (i < 0 || arr[i][j] == 6) break;
			if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
			arr[i][j] = 7;
			check[i][j]++;
		}
		i = x;
		while (true)
		{
			i++;
			if (i >= n || arr[i][j] == 6) break;
			if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
			arr[i][j] = 7;
			check[i][j]++;
		}
		i = x;
		while (true)
		{
			j++;
			if (j >= m || arr[i][j] == 6) break;
			if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
			arr[i][j] = 7;
			check[i][j]++;
		}
		j = y;
		while (true)
		{
			j--;
			if (j < 0 || arr[i][j] == 6) return;
			if (arr[i][j] >= 1 && arr[i][j] <= 5) continue;
			arr[i][j] = 7;
			check[i][j]++;
		}
	}
}

void calc_t(int x, int y, int cctv, int dir)
{
	int i = x, j = y;
	if (cctv == 1)
	{
		if (dir == 0)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) return;
				
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else if (dir == 1)
		{
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else if (dir == 2)
		{
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else
		{
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
	}
	else if (cctv == 2)
	{
		if (dir == 0)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else
		{
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			j = y;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
	}
	else if (cctv == 3)
	{
		if (dir == 0)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else if (dir == 1)
		{
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else if (dir == 2)
		{
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
	}
	else if (cctv == 4)
	{
		if (dir == 0)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			j = y;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else if (dir == 1)
		{
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else if (dir == 2)
		{
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			j = y;
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				j++;
				if (j >= m || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
		else
		{
			while (true)
			{
				j--;
				if (j < 0 || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			j = y;
			while (true)
			{
				i++;
				if (i >= n || arr[i][j] == 6) break;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
			i = x;
			while (true)
			{
				i--;
				if (i < 0 || arr[i][j] == 6) return;
				if (arr[i][j] == 7)
				{
					if (check[i][j] == 1)
					{
						arr[i][j] = 0;
						check[i][j]--;
					}
					else
						check[i][j]--;
				}
			}
		}
	}
	else
	{
		while (true)
		{
			i--;
			if (i < 0 || arr[i][j] == 6) break;
			if (arr[i][j] == 7)
			{
				if (check[i][j] == 1)
				{
					arr[i][j] = 0;
					check[i][j]--;
				}
				else
					check[i][j]--;
			}
		}
		i = x;
		while (true)
		{
			i++;
			if (i >= n || arr[i][j] == 6) break;
			if (arr[i][j] == 7)
			{
				if (check[i][j] == 1)
				{
					arr[i][j] = 0;
					check[i][j]--;
				}
				else
					check[i][j]--;
			}
		}
		i = x;
		while (true)
		{
			j++;
			if (j >= m || arr[i][j] == 6) break;
			if (arr[i][j] == 7)
			{
				if (check[i][j] == 1)
				{
					arr[i][j] = 0;
					check[i][j]--;
				}
				else
					check[i][j]--;
			}
		}
		j = y;
		while (true)
		{
			j--;
			if (j < 0 || arr[i][j] == 6) return;
			if (arr[i][j] == 7)
			{
				if (check[i][j] == 1)
				{
					arr[i][j] = 0;
					check[i][j]--;
				}
				else
					check[i][j]--;
			}
		}
	}
}

void func()
{
	if (s.empty())
	{
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0) tmp++;
			}
		}
		if (tmp < cnt) cnt = tmp;
		return;
	}

	pair<pair<int, int>, int> val = s.top();
	s.pop();
	
	int tmp = val.second, range;
	
	if (tmp == 2)
		range = 2;
	else if (tmp == 5)
		range = 1;
	else
		range = 4;
	
	for (int i = 0; i < range; i++)
	{
		calc(val.first.first, val.first.second, val.second, i);
		func();
		calc_t(val.first.first, val.first.second, val.second, i);
	}
	s.push(val);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6)
				s.push({ {i,j}, arr[i][j] });
		}
	}

	func();
	cout << cnt;
	return 0;
}
