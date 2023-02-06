#include <iostream>
#include <stack>
#include <string>
using namespace std;

string arr[101];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	int n, cnt = 0;
	cin >> n;
	cin.ignore(1);

	for (int i = 0; i < n; i++)
	{
		getline(cin, arr[i]);
	}
	bool check = true;
	for (int i = 0; i < n; i++)
	{
		stack<char> st;
		string tmp = arr[i];
		check = true;
		for (int j = 0; j < tmp.length(); j++)
		{
			if (tmp[j] == 'A')
			{
				if (!st.empty() && st.top() == 'A')
					st.pop();
				else if (st.empty() || st.top() == 'B')
					st.push('A');
				else
				{
					check = false;
					break;
				}
			}
			else
			{
				if (!st.empty() && st.top() == 'B')
					st.pop();
				else if (st.empty() || st.top() == 'A')
					st.push('B');
				else
				{
					check = false;
					break;
				}
			}
		}
		if (check && st.size() == 0) cnt++;
	}
	cout << cnt;
	return 0;
}
