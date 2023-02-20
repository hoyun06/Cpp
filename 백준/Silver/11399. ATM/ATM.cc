#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int result = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		result += sum;
	}

	cout << result;
	return 0;
}
