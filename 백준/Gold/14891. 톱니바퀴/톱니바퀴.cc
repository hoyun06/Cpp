#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int result = 0;
deque<int> d[5];
vector<pair<int, int>> v;

void check(bool* check)
{
	if (d[1][2] != d[2][6])
		check[0] = true;
	else
		check[0] = false;

	if (d[2][2] != d[3][6])
		check[1] = true;
	else
		check[1] = false;

	if (d[3][2] != d[4][6])
		check[2] = true;
	else
		check[2] = false;
}
void rotate(int num, int dir)
{
	if (dir == 1)
	{
		d[num].push_front(d[num].back());
		d[num].pop_back();
	}
	else
	{
		d[num].push_back(d[num].front());
		d[num].pop_front();
	}
}

void func(int num, int dir)
{
	bool c[3] = { 1, };
	check(c);
	if (num == 1)
	{
		rotate(1, dir);
		if (c[0])
		{
			rotate(2, -dir);
			if (c[1])
			{
				rotate(3, dir);
				if (c[2])
					rotate(4, -dir);
			}
		}
	}
	else if (num == 2)
	{
		rotate(2, dir);
		if (c[0]) rotate(1, -dir);
		if (c[1])
		{
			rotate(3, -dir);
			if (c[2])
				rotate(4, dir);
		}
	}
	else if (num == 3)
	{
		rotate(3, dir);
		if (c[2]) rotate(4, -dir);

		if (c[1])
		{
			rotate(2, -dir);
			if (c[0])
				rotate(1, dir);
		}
	}
	else
	{
		rotate(4, dir);
		if (c[2])
		{
			rotate(3, -dir);
			if (c[1])
			{
				rotate(2, dir);
				if (c[0])
					rotate(1, -dir);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	for (int i = 1; i <= 4; i++)
	{
		string tmp;
		getline(cin, tmp);
		for (int j = 0; j < 8; j++)
		{
			d[i].push_back(tmp[j] - '0');
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < k; i++)
	{
		func(v[i].first, v[i].second);
	}

	if (d[1].front() ==  1)
		result += 1;
	if (d[2].front() == 1)
		result += 2;
	if (d[3].front() == 1)
		result += 4;
	if (d[4].front() == 1)
		result += 8;

	cout << result;
	return 0;
}
