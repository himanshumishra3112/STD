#include <iostream>
#include <memory>
using namespace std;

int main()
{
	unique_ptr<int> p1(new int(10));
	cout << "*p1: " << *p1 << endl;
	
	unique_ptr<int> p2(move(p1));
	cout << "*p2: " << *p2 << endl;
	
	if (p1 != nullptr)
		cout << "*p1: " << *p1 << endl;
	else
		cout << "p1 is now nullptr" << endl;
	
	return 0;
}
