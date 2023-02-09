#include <iostream>
using namespace std;

int cnt[1000001];

int main()
{
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	cnt[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		cnt[i] = cnt[i - 1] + 1;
		if (i % 2 == 0) cnt[i] = min(cnt[i], cnt[i / 2] + 1);
		if (i % 3 == 0) cnt[i] = min(cnt[i], cnt[i / 3] + 1);
	}

	cout << cnt[n];
	return 0;
}
