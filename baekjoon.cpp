#include <iostream>
#include <string>
#include <vector>
using namespace std;
//cin.tie(NULL);
//ios_base::sync_with_stdio(false);


int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    int ind = 0;
    while (true)
    {
        if (v.size() == 1)
        {
            cout << v[0];
            return 0;
        }
        if (ind % 2 == 0)
        {
            ind++;
            if (ind == v.size() - 1) { break; }
        }
        else
        {
            v.push_back(v[ind]);
            ind++;
        }
    }
    cout << v[v.size() - 1];
    return 0;
}	