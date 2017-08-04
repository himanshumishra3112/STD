#include <iostream>
#include <map>
using namespace std;

int main()
{
	{
		map<int, string> aMap;
		aMap[0] = "hello";
		aMap[1] = "world";

		string a = aMap[0];
		cout << a << endl;

		cout << aMap[5] << endl;
	}
	{
		map<int, int> aMap;
		aMap[0] = 10;
		aMap[1] = 20;

		int a = aMap[1];
		cout << a << endl;

		cout << aMap[3] << endl;
	}
}
