#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[100001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n >> m;
	vector<int> v(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	
	arr[1] = v[1]; arr[2] = v[1] + v[2];

	for (int i = 3; i <= n; i++)
	{
		arr[i] = arr[i-1] + v[i];
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << arr[r] - arr[l - 1] << "\n";
	}
	return 0;
}
