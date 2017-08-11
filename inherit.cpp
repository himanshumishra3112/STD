#include <iostream>
using namespace std;

class B
{
	public:
	void fun(){
		cout << "Base::fun" << endl;
	}
};

//class D: public B, public B // error: duplicate base type ‘B’ invalid
class D: public B
{
};

int main()
{
	D o;
	//D* dPtr = new B; // error: invalid conversion from ‘B*’ to ‘D*’ [-fpermissive]
	D* dPtr = new D;
	dPtr->fun();

	B *bPtr = dynamic_cast<B*> (new D);
	bPtr->fun();
	//B *dPtr2 = dynamic_cast<D*> (new B); // this is only possible when source type is polymorphic
	//bPtr->fun();
	return 0;
}

//Base to derived - downcasting
//derived to base - uncasting

//allocated Object is of type derived:
//	- derived pointer can point it
//	- base pointer can point it (upcasting)
//
//allocated Object is of type base:
//	- derived can not point to it
