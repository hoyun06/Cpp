#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class House
{
private:
	int r, g, b;
public:
	House()
	{
		r = g = b = 0;
	}
	House(int r, int g, int b): r(r),g(g),b(b) {}
	int getR() { return r; }
	int getG() { return g; }
	int getB() { return b; }
};

int arr[1001][3];
int n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;

	vector<House> v(n + 1);

	for (int i = 1; i <= n; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		v[i] = House(r,g,b);
	}

	arr[1][0] = v[1].getR(); arr[1][1] = v[1].getG(); arr[1][2] = v[1].getB();
	
	for (int i = 2; i <= n; i++)
	{
		arr[i][0] = min(v[i].getR() + arr[i - 1][1], v[i].getR() + arr[i - 1][2]);
		arr[i][1] = min(v[i].getG() + arr[i - 1][0], v[i].getG() + arr[i - 1][2]);
		arr[i][2] = min(v[i].getB() + arr[i - 1][0], v[i].getB() + arr[i - 1][1]);
	}

	int tmp = min(arr[n][0], arr[n][1]);
	cout << min(tmp, arr[n][2]);
	return 0;
}
