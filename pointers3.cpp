#include <iostream>
using namespace std;

class Test{
	int _a;
	public:
		Test(int a): _a(a){}
		int getValue() {return _a;}
};

int main()
{
	int * ptr1 = NULL;
	delete ptr1;	// No core dump

	int * ptr2 = new int(0);
	*ptr2 = 123;
	delete ptr2;
	//delete ptr2;	// double delete
	ptr2 = NULL;
	delete ptr2;	// No core dump
	//cout << *ptr2 << endl;	// segmentation fault

	{
		Test* aTest = new Test(10);
		cout << "aTest->getValue(): " << aTest->getValue() << endl;
		delete aTest;
		//delete aTest;	// double delete
		aTest = NULL;
		delete aTest;	// No core
		//cout << "aTest->getValue(): " << aTest->getValue() << endl; // 4. segmentation fault
	}
	{
		Test* aTest = new Test(10);
		delete aTest;
		cout << "aTest->getValue(): " << aTest->getValue() << endl; // 3. No core
		aTest = NULL;
		delete aTest;// 4
		delete aTest;
	}
}

//Summary:
//1. delete on pointer initialized to NULL - No core dump
//2. double delete on same pointer - core dump
//3. after delete if not initialized with pointer becomes dangaling pointer i.e will still be able to call deleted objects member functions
//4. after delete if initialized to NULL then if try to access members of call segmentation fault will be raised
//5. Null pointing pointer can be deleted any number of times, no core
