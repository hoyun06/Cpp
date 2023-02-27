#include <iostream>
#include <string>
using namespace std;

string expression;

int calc(string& e)
{
	int result = 0;
	string tmp;
	for (int i = 0; i < e.length(); i++)
	{
		if (e[i] == '+')
		{
			result += stoi(tmp);
			tmp.clear();
		}
		else
		{
			tmp += e[i];
			if (i == e.length() - 1)
				result += stoi(tmp);
		}
	}
	return result;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> expression;

	int result = 0;
	bool check = false;
	string tmp;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '-')
		{
			if (check)
			{
				result -= calc(tmp);
				tmp.clear();
			}
			else
			{
				result += calc(tmp);
				check = true;
				tmp.clear();
			}
		}
		else
		{
			tmp += expression[i];
		}
	}

	if (check && !tmp.empty()) result -= calc(tmp);
	else if (!check && !tmp.empty()) result += calc(tmp);

	cout << result;
	return 0;
}
