#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main() {
#if 0
	boost::shared_ptr<int> p1;
	std::vector<int> obj (10);
#endif

	shared_ptr<int> p1(new int(10));
	cout << "*p1: " << *p1 << endl;

	shared_ptr<int> p2(move(p1));
	//shared_ptr<int> p2(move(p1)); //behave like unique ptr
	cout << "*p2: " << *p2 << endl;

	if (p1 != nullptr)
		cout << "*p1: " << *p1 << endl;
	else
		cout << "p1 is now nullptr" << endl;

	return 0;
}
