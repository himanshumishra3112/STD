#include <iostream>
#include <memory>
using namespace std;

class A {
	public:
		int* i;

		A():i(new int(0)) { }

		~A() { 
			if(i) {
				delete i; 
			}
		}

	private:
		// we need to explicitly disable value-copying, as it's not safe!
		A(const A&);
		A& operator=(const A&);
};

//OR

class B {
	public:
		unique_ptr<int> i;

		B():i(new int(0)) { }
};

int main()
{
	B obj1;
	//B obj2 = obj1; // Error:
	return 0;
}

/*
   The destructor is no longer needed, and value-copying will automatically be disabled, as unique_ptr is not copyable. 
   On top of that, this unique_ptr version also gets a move constructor defined automatically, thanks to unique_ptr being 
   moveable (whereas the former would have to additionally define a move constructor to get that).

   This code is not only more concise, but by eliminating the need to remember boilerplate code, it also eliminates two 
   dangers which are common causes of memory leaks and memory corruption:

   1. forgetting to delete all class-member pointers in the destructor.
   2. forgetting to disable value-copying (or to define a suitable copy-constructor + operator= to handle it safely).
 */
