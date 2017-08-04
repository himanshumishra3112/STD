#include <iostream>
using namespace std;

class Base1{
    public:
        virtual void common(){
            cout << "BASE-1" << endl;
        }
};

class Base2{
    public:
        virtual void common(){
            cout << "BASE-2" << endl;
        }
};

class Derived: public Base1,public Base2{
    public :
#if 1
        void common(){
            cout << "Derived" << endl;
        }
#endif
};

int main(){
#if 1
    Base1* bObj = new Derived();
    bObj->common();
#endif
#if 0
    Derived* dObj= new Derived();
    dObj->common();
#endif
#if 0
    Base1* bObj=new Base1();
    bObj->common();
#endif
}
