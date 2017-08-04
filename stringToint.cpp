#include <iostream>
using namespace std;

int main()
{
	string s;
	cin>>s;

	int v = 0;
	int i = 0;
	while(s[i] != '+')
	{
		v=v*10+s[i] - '0';
		i++;
	}
	cout << v << endl;
}
