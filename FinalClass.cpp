//http://www.geeksforgeeks.org/simulating-final-class-in-c/
/* A program with compilation error to demonstrate that Final class cannot 
   be inherited */

/*
	It makes use of private constructor, virtual inheritance and friend class. 
*/
#include<iostream>
using namespace std;

class Final;  // The class to be made final

class MakeFinal // used to make the Final class final
{
	private:
		MakeFinal() { cout << "MakFinal constructor" << endl; }
		friend class Final;
};

class Final : virtual MakeFinal
{
	public:
		Final() { cout << "Final constructor" << endl; }
};

class Derived : public Final // Compiler error
{
	public:
		Derived() { cout << "Derived constructor" << endl; }
};

int main(int argc, char *argv[])
{
	Derived d;
	return 0;
}

/*
	Note that MakeFinal is  also a  virtual base class.
	The reason for this is to call  the constructor of 
	MakeFinal through the  constructor of Derived, not 
	Final (The constructor  of a virtual base class is 
	not called  by  the  class that  inherits  from it, 
	instead the constructor is called by the constructor 
	of the concrete class.
*/
