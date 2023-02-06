#include <iostream>
#include <string>
using namespace std;

char arr[64][64];
string line;

void func(int len, int x, int y)
{
	int tmp = arr[x][y];
	for (int i = x; i < x + len; i++)
	{
		for (int j = y; j < y + len; j++)
		{
			if (arr[i][j] != tmp)
			{
				line += '(';
				func(len / 2, x, y);
				func(len / 2, x, y + len / 2);
				func(len / 2, x + len / 2, y);
				func(len / 2, x + len / 2, y + len / 2);
				line += ')';
				return;
			}
		}
	}
	if (tmp == 48)
		line += '0';
	else
		line += '1';
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	func(n, 0, 0);

	cout << line;
	return 0;
}
