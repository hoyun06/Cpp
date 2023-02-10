#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n;
int point[301][3];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;
	vector<int> v(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	if (n == 1)
	{
		cout << v[1];
		return 0;
	}

	point[1][1] = point[1][2] = v[1];
	point[2][1] = v[2];
	point[2][2] = v[1] + v[2];

	for (int i = 3; i <= n; i++)
	{
		point[i][1] = max(point[i - 2][1], point[i - 2][2]) + v[i];

		point[i][2] = point[i - 1][1] + v[i];
	}

	cout << max(point[n][1], point[n][2]);
	return 0;
}
