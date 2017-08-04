#include<iostream>
using namespace std;




// A generic smart pointer class
class Test
{
    int val;
    public:
    Test(int p = 0) { val = p; }
    int getVal(){ return val;}
};

template <class T>
class SmartPtr
{
    T *ptr;  // Actual pointer
    public:
    // Constructor
    explicit SmartPtr(T *p = NULL) { ptr = p; }

    // Destructor
    ~SmartPtr() { delete(ptr); }

    // Overloading dereferncing operator
    T & operator * () {  return *ptr; }

    // Overloding arrow operator so that members of T can be accessed
    // like a pointer (useful if T represents a class or struct or
    // union type)
    T * operator -> () { return ptr; }
};

int main()
{
    SmartPtr<int> ptr(new int(100));
    SmartPtr<float> ptr2(new float(100.1121));
    SmartPtr<Test> ptr3(new Test(100.1121));
    *ptr = 20;
    cout << *ptr << endl;
    cout << *ptr2 << endl;
    cout << (*ptr3).getVal() << endl;
    cout << ptr3->getVal() << endl;
    return 0;
}
