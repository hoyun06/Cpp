#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int arr[1000001];
int n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;

	arr[1] = 0;
	map<int, int> m;
	
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			if (i % 3 == 0)
			{
				int tmp = min(arr[i / 2], arr[i / 3]);
				arr[i] = min(arr[i - 1], tmp) + 1;
				if (arr[i] == arr[i - 1] + 1) m.insert({i, -1});
				else
				{
					if (tmp == arr[i / 2]) m.insert({i, 2});
					else m.insert({ i, 3 });
				}
			}
			else
			{
				arr[i] = min(arr[i - 1], arr[i / 2]) + 1;
				if (arr[i] == arr[i - 1] + 1) m.insert({ i, -1 });
				else m.insert({ i, 2 });
			}
		}
		else if (i % 3 == 0)
		{
			arr[i] = min(arr[i - 1], arr[i / 3]) + 1;
			if (arr[i] == arr[i - 1] + 1) m.insert({ i, -1 });
			else m.insert({ i, 3 });
		}
		else
		{
			arr[i] = arr[i - 1] + 1;
			m.insert({ i, -1 });
		}
	}

	cout << arr[n] << "\n";
	int k = n;

	while (true)
	{
		cout << k << " ";
		if (k == 1) break;
		int num = m[k];
		switch (num)
		{
		case 2:
			k /= 2;
			break;
		case 3:
			k /= 3;
			break;
		case -1:
			k -= 1;
			break;
		}
	}
	return 0;
}
