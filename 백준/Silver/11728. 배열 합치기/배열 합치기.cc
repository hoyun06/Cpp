#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n >> m;

	vector<int> v1 ,v2, v3;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		v2.push_back(tmp);
	}

	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (v1[i] < v2[j])
		{
			v3.push_back(v1[i]);
			i++;
		}
		else
		{
			v3.push_back(v2[j]);
			j++;
		}
	}

	if (i >= n)
	{
		while (j < m)
		{
			v3.push_back(v2[j]);
			j++;
		}
	}
	else
	{
		while (i < n)
		{
			v3.push_back(v1[i]);
			i++;
		}
	}

	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	return 0;
}
