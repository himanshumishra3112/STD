#include <iostream>
using namespace std;

class A{
    void f(){
        this = new A();
    }
    void g(){
        delete this;
    }
};

int main{
    A a;
    a.f();
}

