#include <iostream>
#include <vector>
using namespace std;

int visit[9];
int n, m;

vector<int> v;

void func()
{
	if (v.size() == m)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			v.push_back(i);
			visit[i] = 1;
			func();
			visit[v.back()] = 0;
			v.pop_back();
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
		visit[i] = 1;
		func();
		visit[v.back()] = 0;
		v.pop_back();
	}
	return 0;
}
