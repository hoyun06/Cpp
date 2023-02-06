#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int val[8];

bool visit[10000];

void func(int cnt, int max)
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
		if (visit[arr[i]] == 0 && arr[i] >= max)
		{
			visit[arr[i]] = 1;
			val[cnt] = arr[i];
			if (arr[i] > max)
				func(cnt + 1, arr[i]);
			else
				func(cnt + 1, max);
			visit[arr[i]] = 0;
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

	func(0, arr[0]);
	return 0;
}
