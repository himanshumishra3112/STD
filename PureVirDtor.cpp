#include <iostream>
using namespace std;
class Base
{
	int a;
	public:
		virtual ~Base() = 0; // Pure virtual destructor
};
Base::~Base()
{
	std::cout << "Pure virtual destructor is called";
}

class Derived : public Base
{
	public:
		~Derived()
		{
			std::cout << "~Derived() is executed\n";
		}
};

int main()
{
	Base *b = new Derived();
	cout << "size : " << sizeof(b) << endl; //size : 8 (4 byte for Base::a and 4 bytes for vptr)
	delete b;
	return 0;
}

/*
Can a destructor be pure virtual in C++?
Yes, it is possible to have pure virtual destructor. 
Pure virtual destructor are legal in standard C++ and 
one of the most important thing is that if class contains 
pure virtual destructor it is must to provide a function 
body for the pure virtual destructor. This seems strange 
that how a virtual function is pure if it requires a function body? 
But destructors are always called in the reverse order of the 
class derivation. That means derived class destructor will be 
invoked first & then base class destructor will be called. 
If definition for the pure virtual destructor is not provided 
then what function body will be called during object destruction? 
Therefore compiler & linker enforce existence of function body for 
pure virtual destructor.
*/
