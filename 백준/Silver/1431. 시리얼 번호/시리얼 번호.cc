#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;

int getTotal(string& s)
{
	int total = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]))
			total += s[i] - '0';
	}
	return total;
}

bool check(string& a, string& b)
{
	if (a.length() != b.length())
		return a.length() < b.length();
	else
	{
		int totalA = getTotal(a), totalB = getTotal(b);
		if ( totalA != totalB)
		{
			return totalA < totalB;
		}
		else
		{
			return a < b;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	
	vector<string> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), check);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	return 0;
}
