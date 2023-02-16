#include <iostream>
using namespace std;

int n, k;
int dp[100001], arr[101];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = arr[i]; j <= k; j++)
		{
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k];
	return 0;
}
