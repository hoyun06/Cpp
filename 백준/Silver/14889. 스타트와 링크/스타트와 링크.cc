#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, result = INT_MAX;
int arr[22][22];

int calcStart(bool* visit)
{
	int tmp = 0;

	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 1)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (visit[j] == 1)
				{
					tmp += (arr[i][j] + arr[j][i]);
				}
			}
		}
	}

	return tmp;
}

int calcLink(bool* visit)
{
	int tmp = 0;

	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (visit[j] == 0)
				{
					tmp += (arr[i][j] + arr[j][i]);
				}
			}
		}
	}

	return tmp;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int* val = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
		{
			val[i] = 0;
		}
		else
			val[i] = 1;
	}

	do
	{
		int cnt = 0;
		bool visit[22] = { 0, };
		for (int i = 0; i < n; i++)
		{
			if (val[i] == 0)
			{
				visit[cnt] = 1;
				cnt++;
			}
			else
				cnt++;
		}

		int start = calcStart(visit);
		int link = calcLink(visit);
		int tmp = (start - link >= 0) ? (start - link) : (link - start);
		if (tmp < result) result = tmp;

	} while (next_permutation(val, val + n));

	cout << result;
	delete[] val;
	return 0;
}
