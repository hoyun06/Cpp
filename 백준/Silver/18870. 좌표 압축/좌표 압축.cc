#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
vector<int> v1, v2;
map<int, int> m;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
		v2.push_back(tmp);
	}
	sort(v1.begin(), v1.end());

	int cnt = 0, val = v1[0];

	for (int i = 1; i < n; i++)
	{
		if (i != n - 1)
		{
			if (val == v1[i]) continue;
			m.insert({ val,cnt });
			val = v1[i];
			cnt++;
		}
		else
		{
			if (val == v1[i])
				m.insert({ val,cnt });
			else
			{
				m.insert({ val,cnt });
				m.insert({ v1[i], cnt + 1 });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << m[v2[i]] << " ";
	}
	return 0;
}
