#include <iostream>
#include <algorithm>
using namespace std;

int a[51], b[51];
int n;

bool check(int a, int b)
{
	if (a != b) return a > b;
	else return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a, a + n);
	sort(b, b + n, check);

	int result = 0;
	for (int i = 0; i < n; i++)
		result += (a[i] * b[i]);

	cout << result;
	return 0;
}
