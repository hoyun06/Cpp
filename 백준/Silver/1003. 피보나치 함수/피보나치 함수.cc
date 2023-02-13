#include <iostream>
#include <vector>
using namespace std;

int n, t;
pair<int,int> arr[41];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> t;
	arr[0] = { 1, 0 }; arr[1] = { 0, 1 };
	for (int i = 2; i <= 40; i++)
	{
		arr[i] = { arr[i - 1].first + arr[i - 2].first, arr[i - 1].second + arr[i - 2].second };
	}

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << arr[n].first << " " << arr[n].second << "\n";
	}
	return 0;
}
