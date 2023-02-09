#include <iostream>
using namespace std;

int t, n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int arr[12] = { 0, };
		cin >> n;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;
		for (int j = 4; j <= n; j++)
		{
			arr[j] = arr[j - 3] + arr[j - 2] + arr[j - 1];
		}
		cout << arr[n] << "\n";
	}

	return 0;
}
