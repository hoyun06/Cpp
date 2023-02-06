#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	vector<int> tower;
	stack<pair<int, int>> st;

	int n, seq = 1;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		tower.push_back(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && st.top().second < tower[i])
			st.pop();

		if (st.empty())
			cout << 0 << " ";
		else
			cout << st.top().first << " ";

		st.push(make_pair(i + 1, tower[i]));
	}
	return 0;
}
