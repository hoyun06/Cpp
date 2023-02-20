#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100001];

bool check(int a, int b)
{
	if (a == b) return false;
	else return a > b;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr+n, check);

	int localMax = arr[0], cnt = 1;

	for (int i = 1; i < n; i++)
	{
		if ((cnt + 1) * arr[i] > localMax)
		{
			cnt++;
			localMax = cnt * arr[i];
		}
		else cnt++;
	}

	cout << localMax;
	return 0;
}
