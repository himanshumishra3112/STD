#include <iostream>
using namespace std;

class Base
{ int x;
	public:
		Base(int i)
		{ 	x = i;
			cout << "Base Parameterized Constructor\n";
		}
};

class Derived : public Base
{ int y;
	public:
		Derived(int j) : Base(j)
		{ 	y = j;
			cout << "Derived Parameterized Constructor\n";
		}
};

int main()
{
	Derived d(10) ;
}


/*

1. Whether derived class's default constructor is called or parameterised is called, base class's default constructor is always called inside them.

2. To call base class's parameterised constructor inside derived class's parameterised constructo, we must mention it explicitly while declaring derived class's parameterized constructor.

*/
