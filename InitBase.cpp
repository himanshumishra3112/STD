/* Intitialization of Base class member during derived class object 
 * creation
 * Note: copy Ctor is not called here
 */
#include <iostream>
using namespace std;

class Base {
	int _a;
	public:
		Base(int a);
		Base();
		Base(const Base& a);
		~Base();
};

class Derived : public Base {
	int _b;
	public:
		Derived(int b);
		Derived(int b, int a);
		Derived(const Derived& a);
		~Derived();
};

Base :: Base() { cout << "Base Default Ctor" << endl;}
Base :: Base(int a): _a(a){ cout << "Base Ctor" << endl;}
Base :: Base(const Base& a): _a(a._a) { cout << "Base Copy Ctor" << endl;};

Derived :: Derived(int b): _b(b){ cout << "Derived Ctor" << endl;}
Derived :: Derived(int b, int a): _b(b), Base(a){ cout << "Derived Ctor with Base init" << endl;}
Derived :: Derived(const Derived& d): _b(d._b) { cout << "Derived Copy Ctor" << endl;};

Base :: ~Base() { cout << "Base Dtor" << endl;};
Derived :: ~Derived () { cout << "Derived Dtor" << endl;};

int main() {
	Derived d1(10);
	Derived d2(10,20);
};
