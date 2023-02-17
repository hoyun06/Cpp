#include <iostream>
using namespace std;

int n, k, cnt = 0;
int arr[11];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	while (true)
	{
		int tmp;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > k)
			{
				tmp = arr[i - 1];
				break;
			}
			if (i == n - 1) tmp = arr[i];
		}

		int quot = k / tmp;
		cnt += quot;
		k -= (tmp * quot);
		if (k == 0) break;
	}

	cout << cnt;
	return 0;
}
