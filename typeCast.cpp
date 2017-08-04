#include <iostream>
using namespace std;

class Base{
};

class Desrived : public Base{
};

int main(){
    Base bObj;
    Desrived dObj;

    Derived dObj2 = dynamic_cast <Desrived> (bObj);

}
