#include <iostream>
using namespace std;

class Test
{
	//auto a;					// error: non-static data member declared ‘auto’
	//static auto x = 10;		// error: ISO C++ forbids in-class initialization of non-const static member ‘Test::x’
	static const auto b = 10; 	//OK		
	//const auto c;				// error: non-static data member declared ‘auto’
};

//auto Test :: b = 10;

int main()
{
	//Test obj(10);
	//auto a;			// error: declaration of ‘auto a’ has no initializer
	auto b = 10;	// OK
	return 0;
}

//NOTE:
// Only "static const" member of class can be declared as "auto".
