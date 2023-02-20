#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string line;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> line;

	int arr[2] = { 0,0 };

	for (int i = 1; i < line.length(); i++)
	{
		if (line[i] != line[i - 1]) arr[line[i - 1] -'0']++;
		if (i == line.length() - 1) arr[line[i] - '0']++;
	}

	cout << min(arr[0], arr[1]);
	return 0;
}
