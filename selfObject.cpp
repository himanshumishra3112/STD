// A class can have a static member of self type\
// A class can have a pointer to self type
// A class cannot have non-static object(s) of self type.
// Size of an empty class is not zero. It is 1 byte generally. It is nonzero to ensure that the two different objects will have different addresses.
#include <iostream>
using namespace std;

class Test {
    static Test self;  // works fine
    /* other stuff in class*/
};

int main()
{
    Test t;
    cout << sizeof(t) << endl;

    Test t1,t2;
    cout << "t1: " << &t1 << "   t2: " << &t2 << endl;
    return 0;
}
