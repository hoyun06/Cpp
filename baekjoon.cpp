#include <iostream>
#include <string>
#include <vector>
using namespace std;
//cin.tie(NULL);
//ios_base::sync_with_stdio(false);

class Stack
{
    vector<int> v;
public:
    Stack() {}
    void push(int x) { v.push_back(x); }
    int pop()
    {
        if (v.size() == 0) { return -1; }
        int tmp;
        vector<int>::iterator it;
        it = v.end() - 1;
        tmp = *it;
        it = v.erase(it);
        return tmp;
    }
    int size() { return v.size(); }
    int empty() { if (v.size() == 0) { return 1; } else { return 0; } }
    int top()
    {
        if (v.size() == 0) { return -1; }
        return v[v.size() - 1];
    }
};

int main()
{
    Stack s;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string tmp;
        getline(cin, tmp);
        if (tmp.find("push") != -1)
        {
            int ind = tmp.find(" ") + 1;
            string t = tmp.substr(ind, tmp.length() - ind);
            s.push(stoi(t));
        }
        else if (tmp == "pop")
        {
            cout << s.pop() << "\n";
        }
        else if (tmp == "size")
        {
            cout << s.size() << "\n";
        }
        else if (tmp == "empty")
        {
            cout << s.empty() << "\n";
        }
        else
        {
            cout << s.top() << "\n";
        }
    }
    return 0;
}