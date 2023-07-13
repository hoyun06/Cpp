#include <iostream>
#include <queue>
using namespace std;

int n;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	long long sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	
	while (pq.size() > 1)
	{
		int p = pq.top();
		pq.pop();
		int q = pq.top();
		pq.pop();
		sum += (p + q);
		pq.push(p + q);
	}

	cout << sum;
}
