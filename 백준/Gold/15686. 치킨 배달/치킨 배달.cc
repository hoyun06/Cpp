#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int n, m, cnt = 0, result = INT_MAX;
int arr[51][51];
queue<pair<int, int>> house;
vector<pair<int, int>> chicken;

int func(bool* chosen)
{
	int resultDist = 0;
	vector<pair<int, int>> check;
	for (int i = 0; i < 14; i++)
	{
		if (chosen[i])
			check.push_back(chicken[i]);
	}
	int size = house.size();
	for (int i = 0; i < size; i++)
	{
		int min_dist = INT_MAX;
		pair<int, int> h = house.front();
		house.pop();
		house.push(h);
		int x = h.first;
		int y = h.second;
		for (int i = 0; i < check.size(); i++)
		{
			int dist = abs(x - check[i].first) + abs(y - check[i].second);
			if (dist < min_dist) min_dist = dist;
		}
		resultDist += min_dist;
	}
	return resultDist;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			
			if (arr[i][j] == 1)
				house.push({ i,j });
			else if (arr[i][j] == 2)
			{
				chicken.push_back({ i,j });
				cnt++;
			}
		}
	}

	int* permu = new int[cnt];

	for (int i = 0; i < cnt; i++)
	{
		if (i < m)
			permu[i] = 0;
		else
			permu[i] = 1;
	}

	do
	{
		int tmp = 0;
		bool chosen[14] = { 0, };
		for (int i = 0; i < cnt; i++)
		{
			if (permu[i] == 0)
			{
				chosen[tmp] = 1;
				tmp++;
			}
			else
				tmp++;
		}
		int tmpResult = func(chosen);
		if (tmpResult < result) result = tmpResult;

	} while (next_permutation(permu, permu + cnt));

	cout << result;

	delete[] permu;
	return 0;
}
