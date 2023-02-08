#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string tmp;

bool check(string a, string b)
{
	return a < b;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	vector<string> v;
	cin >> tmp;

	for (int i = 0; i < tmp.length(); i++) 
		v.push_back(tmp.substr(i, tmp.length() - i));

	sort(v.begin(), v.end(), check);

	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
	return 0;
}
