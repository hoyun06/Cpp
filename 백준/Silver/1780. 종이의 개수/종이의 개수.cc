#include <iostream>
using namespace std;

#define N 2187

int arr[N][N];
int check[3];
int n;

void func(int x, int y, int num)
{
	int tmp = arr[x][y];

	for (int i = x; i < x + num; i++)
	{
		for (int j = y; j < y + num; j++)
		{
			if (arr[i][j] != tmp)
			{
				func(x, y, num / 3);
				func(x, y + 1 * num / 3, num / 3);
				func(x, y + 2 * num / 3, num / 3);
				func(x + 1 * num / 3, y , num / 3);
				func(x + 1 * num / 3, y + 1 * num / 3, num / 3);
				func(x + 1 * num / 3, y + 2 * num / 3, num / 3);
				func(x + 2 * num / 3, y, num / 3);
				func(x + 2 * num / 3, y + 1 * num / 3, num / 3);
				func(x + 2 * num / 3, y + 2 * num / 3, num / 3);
				return;
			}
		}
	}
	check[tmp + 1]++;
	return;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	func(0,0,n);

	for (int i = 0; i < 3; i++) cout << check[i] << "\n";
	return 0;
}
