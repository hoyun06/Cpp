#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
long long arr[100001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	long long sum = 0, cnt = 0, min = 100001;
	int i = 0, j = 0;

	while (i < n && j <= n)
	{
		if (sum < s)
		{
			if (j == n)
			{
				if (min == 100001) cout << 0;
				else cout << min;
				return 0;
			}
			else
			{
				sum += arr[j];
				cnt++;
				j++;
			}
		}
		else
		{
			if (j == n)
			{
				while (i < n && sum >= s)
				{
					if (cnt < min) min = cnt;
					sum -= arr[i];
					cnt--;
					i++;
				}
				if (min == 100001) cout << 0;
				else cout << min;
				return 0;
			}
			else
			{
				if (cnt < min) min = cnt;
				sum -= arr[i];
				cnt--;
				i++;
			}
		}
	}
}
