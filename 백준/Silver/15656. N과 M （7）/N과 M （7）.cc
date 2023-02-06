#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int val[8];

bool visit[9][10000];

void func(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << val[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[cnt][arr[i]] == 0)
		{
			visit[cnt][arr[i]] = 1;
			val[cnt] = arr[i];
			func(cnt + 1);
			visit[cnt][arr[i]] = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	func(0);
	return 0;
}
