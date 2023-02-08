#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
	string name;
	int kor, eng, math;
public:
	Student(string name, int kor, int eng, int math) : name(name),kor(kor),eng(eng),math(math) {}
	int getKor() { return kor; }
	int getEng() { return eng; }
	int getMath() { return math; }
	string getName() { return name; }
};

bool check(Student& s1, Student& s2)
{
	if (s1.getKor() != s2.getKor())
	{
		return s1.getKor() > s2.getKor();
	}
	else
	{
		if (s1.getEng() != s2.getEng())
			return s1.getEng() < s2.getEng();
		else
		{
			if (s1.getMath() != s2.getMath())
				return s1.getMath() > s2.getMath();
			else
				return s1.getName() < s2.getName();
		}
	}
}

int n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	
	vector<Student> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		v.push_back(Student(name, kor, eng, math));
	}

	sort(v.begin(), v.end(), check);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].getName() << "\n";
	return 0;
}
