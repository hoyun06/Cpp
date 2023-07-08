#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool check(string& s1, string& s2)
{
	return s1 >= s2;
}

int n;
unordered_set<string>  s;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	string name, status;

	for (int i = 0; i < n; i++)
	{
		cin >> name >> status;
		
		if (status == "enter") s.insert(name);
		else s.erase(name);
	}

	vector<string> v;

	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		v.push_back((*iter));
	}

	sort(v.begin(), v.end(), check);

	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
}
