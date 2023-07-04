#include <iostream>
using namespace std;


long long arr[10001];

int main()
{
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	int n, k;
	cin >> k >> n;

	long long min = 1, max = -1;
	for (int i = 0; i < k; i++)
	{
		long long tmp;
		cin >> tmp;
		arr[i] = tmp;
		if (tmp > max)
			max = tmp;
	}
	while (true)
	{
		long long mid = (max + min) / 2;
		if (mid == min)
		{
			long long sum = 0;
			for (int i = 0; i < k; i++)
			{
				sum += arr[i] / (mid + 1);
			}
			if (sum >= n)
				cout << mid + 1;
			else
				cout << min;
			return 0;
		}
		long long sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += arr[i] / mid;
		}
		if (sum >= n)
			min = mid;
		else
			max = mid;
	}
	return 0;
}
