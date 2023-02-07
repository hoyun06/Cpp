#include <iostream>
using namespace std;

int arrP[1000001], arrN[1000001];
int myMax = -1000001, myMin = 1000001;
int n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp < 0)
		{
			arrN[-tmp]++;
			if (tmp < myMin) myMin = tmp;
		}
		else
		{
			arrP[tmp]++;
			if (tmp > myMax) myMax = tmp;
		}
	}
	
	for (int i = -myMin; i > 0; i--)
	{
		for (int j = 0; j < arrN[i]; j++)
			cout << -i << "\n";
	}
	for (int i = 0; i <= myMax; i++)
	{
		for (int j = 0; j < arrP[i]; j++)
			cout << i << "\n";
	}
	return 0;
}
