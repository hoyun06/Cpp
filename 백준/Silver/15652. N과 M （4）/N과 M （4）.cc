#include <iostream>
using namespace std;

int n, m;
int arr[8];
bool visit[10][10];

void func(int cnt, int max)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[cnt][i] == 0 && i >= max)
		{
			arr[cnt] = i;
			visit[cnt][i] = 1;
			if (i > max)
				func(cnt + 1, i);
			else
				func(cnt + 1, max);
			visit[cnt][i] = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n >> m;

	func(0, 1);
	return 0;
}
