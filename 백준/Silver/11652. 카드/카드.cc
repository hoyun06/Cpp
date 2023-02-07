#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long tmp;

bool myCheck(long long a, long long b)
{
	return a < b;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	vector<long long> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int mCnt = 0, cnt = 1;
	long long val = v[0];

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1])
		{
			cnt++;
			if (i == v.size() - 1)
			{
				if (cnt > mCnt)
					val = v[i];
			}
		}
		else
		{
			if (cnt > mCnt)
			{
				mCnt = cnt;
				val = v[i - 1];
			}
			cnt = 1;
		}
	}

	cout << val;
	return 0;
}
