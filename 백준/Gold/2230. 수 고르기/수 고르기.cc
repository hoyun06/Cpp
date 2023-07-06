#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;
long long arr[100001];

int binSearch(long long val)
{
	long long target = m + val;

	int left = 0, right = n - 1, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] > target)
		{
			if (left == right)
				return right;
			right = mid;
		}
		else left = mid + 1;
	}
	return -1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	long long min = 2000000001;

	for (int i = 0; i < n; i++)
	{
		long long val = arr[i];
		int ind = binSearch(val);
		if (ind == -1) continue;
		min = ( min > (arr[ind] - val)) ? (arr[ind] - val) : min;
	}

	cout << min;
}
