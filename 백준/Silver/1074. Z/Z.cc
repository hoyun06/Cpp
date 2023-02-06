#include <iostream>
#include <cmath>
using namespace std;

int func(int n, int r, int c)
{
	if (r == 0 && c == 0)
		return 0;
	else if (r == 0 && c == 1)
		return 1;
	else if (r == 1 && c == 0)
		return 2;
	else if(r == 1 && c == 1)
		return 3;
	else
	{
		int tmp = pow(2, n) - 1;
		int calc = ((tmp + 1) / 2) * ((tmp + 1) / 2);
		if (r <= tmp / 2 && c > tmp / 2)
		{
			return calc + func(n - 1, r , c - ((tmp + 1) / 2));
		}
		else if (r > tmp / 2 && c <= tmp / 2)
		{
			return calc * 2 + func(n - 1, r - ((tmp + 1) / 2), c );
		}
		else if (r > tmp / 2 && c > tmp / 2)
		{
			return calc * 3 + func(n - 1, r - ((tmp + 1) / 2), c - ((tmp + 1) / 2));
		}
		else
		{
			return func(n - 1, r, c);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
	return 0;
}
