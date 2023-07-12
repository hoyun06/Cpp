#include <iostream>
#include <set>

using namespace std;

multiset<int> m;
int t, k;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		char tmp;
		int num;

		cin >> k;

		for (int j = 0; j < k; j++)
		{
			cin >> tmp >> num;

			if (tmp == 'D')
			{
				if (m.empty()) continue;
				if (num == 1)
					m.erase(--m.end());
				else
					m.erase(m.begin());
			}
			else
			{
				m.insert(num);
			}
		}

		if (m.empty()) cout << "EMPTY" << "\n";
		else
		{
			cout << (*(--m.end())) << " " << (*m.begin()) << "\n";
			m.clear();
		}
	}
}
