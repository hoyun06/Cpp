#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool visit[8][8];

void func(int cnt)
{
	if (m == cnt)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i][cnt] == 0)
		{
			arr[cnt] = i;
			visit[i][cnt] = 1;
			func(cnt + 1);
			visit[i][cnt] = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n >> m;

	func(0);
	return 0;
}
