#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
vector<int>	card, goal;

int findLeft(int val)
{
	int left = 0, right = n - 1, m;
	while (left < right)
	{
		m = (left + right) / 2;
		if (card[m] < val) left = m + 1;
		else if (card[m] > val) right = m - 1;
		else right = m;
	}
	if (left == right)
	{
		if (card[left] != val) return -1;
		else return left;
	}
	return -1;
}
int findRight(int val)
{
	int left = 0, right = n - 1, m;
	while (left < right)
	{
		m = (left + right) / 2;
		if (card[m] < val) left = m + 1;
		else if (card[m] > val) right = m - 1;
		else
		{
			if (card[m + 1] == val) left = m + 1;
			else return m;
		}
	}
	if (left == right)
	{
		if (card[left] != val) return -1;
		else return left;
	}
	return -1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		card.push_back(tmp);
	}

	sort(card.begin(), card.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		goal.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		int tmp = goal[i];
		int left = findLeft(tmp);
		int right = findRight(tmp);
		if (left == -1 || right == -1) cout << 0 << " ";
		else cout << right - left + 1 << " ";
	}
	return 0;
}
