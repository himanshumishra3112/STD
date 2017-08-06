#include <iostream>
using namespace std;

class MyClass {
	int* buffer = nullptr;
	string myname;

	private:
	// disable copying
	MyClass(const MyClass&);
	MyClass& operator=(const MyClass&);

	public:
	MyClass(int* iBuffer, string iName): buffer(iBuffer), myname(iName){}
	
	// move constructor
	MyClass(MyClass&& other) {
		buffer = other.buffer;
		other.buffer = nullptr;
		myname = move(other.myname);
	}

	// move assignment operator
	MyClass& operator=(MyClass&& other) {
		if(this != &other) {
			if(buffer) {
				delete buffer;
			}
			buffer = other.buffer;
			other.buffer = nullptr;
			myname = move(other.myname);
		}
	}

	~MyClass() {
		if(buffer) {
			delete buffer;
		}
	}
};


int main()
{
	MyClass obj1(new int(10), "Himanshu");
	MyClass obj2(move(obj1));
	MyClass obj3(new int(20), "Mishra");
	obj3 = move(obj1);
}
/*
   Special member functions

   In old C++, there were four special member functions. Now with C++11's two move semantics functions, there's six:

   1. Default constructor
   2. Destructor
   The two copy special member functions
   		3. Copy constructor
   		4. Copy assignment operator
   The two move special member functions
   		5. Move constructor
   		6. Move assignment operator

*/
