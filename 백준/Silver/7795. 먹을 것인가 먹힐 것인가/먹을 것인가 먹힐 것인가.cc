#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, a, b;

bool check(int a, int b)
{
	return a > b;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	
	vector<int> A, B;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		int tmp;
		for (int j = 0; j < a; j++)
		{
			cin >> tmp;
			A.push_back(tmp);
		}
		for (int j = 0; j < b; j++)
		{
			cin >> tmp;
			B.push_back(tmp);
		}
		sort(A.begin(), A.end(), check);
		sort(B.begin(), B.end(), check);

		int cnt = 0;
		int j = 0, k = 0;
		while (j < a && k < b)
		{
			if (A[j] > B[k])
			{
				cnt += B.size() - k;
				j++;
			}
			else
				k++;
		}
		cout << cnt << "\n";
		A.clear(); B.clear();
	}
	return 0;
}
