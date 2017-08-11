#include <iostream>
#include <memory>
using namespace std;

int main()
{
	unique_ptr<int> p1(new int(10));
	cout << "*p1: " << *p1 << endl;		//*p1: 10
	
	unique_ptr<int> p2(move(p1));
	cout << "*p2: " << *p2 << endl;		//*p2: 20
	
	if (p1 != nullptr)
		cout << "*p1: " << *p1 << endl;
	else
		cout << "p1 is now nullptr" << endl;	//p1 is now nullptr

	p1 = move(p2);
	cout << "*p1: " << *p1 << endl;	// *p1: 10
	
	if (p2 != nullptr)
		cout << "*p2: " << *p1 << endl;
	else
		cout << "p2 is now nullptr" << endl;	//p2 is now nullptr
	return 0;
}

//output:
//	*p1: 10
//	*p2: 10
//	p1 is now nullptr
//	*p1: 10
//	p2 is now nullptr
