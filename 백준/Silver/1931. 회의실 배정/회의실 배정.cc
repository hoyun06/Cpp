#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt;
vector<pair<int, int>> v;

bool check(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end(), check);

	int finish = v[0].second;
	cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i].first >= finish)
		{
			cnt++;
			finish = v[i].second;
		}
	}

	cout << cnt;
	return 0;
}
