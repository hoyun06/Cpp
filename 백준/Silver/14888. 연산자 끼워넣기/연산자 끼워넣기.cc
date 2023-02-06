#include <iostream>
#include <algorithm>
using namespace std;

int n, myMax = -1000000000, myMin = 1000000000;
int arr[12];
int oper[4];

int calc(int x, int y, int op)
{
	switch (op)
	{
	case 0:
		return x + y;
		break;
	case 1:
		return x - y;
		break;
	case 2:
		return x * y;
		break;
	case 3:
		return x / y;
		break;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	int* tmp = new int[n - 1];

	for (int i = 0, k = 0; i < 4; i++)
	{
		for (int j = 0; j < oper[i]; j++)
		{
			tmp[k++] = i;
		}
	}

	do
	{
		int result = calc(arr[0], arr[1], tmp[0]);
		for (int i = 2; i < n; i++)
		{
			result = calc(result, arr[i], tmp[i - 1]);
		}
		if (result > myMax) myMax= result;
		if (result < myMin) myMin = result;

	} while (next_permutation(tmp, tmp + (n - 1)));

	cout << myMax << "\n" << myMin;
	delete[] tmp;
	return 0;
}
