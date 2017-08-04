#include<iostream>
class X {
    int a;
    public:
    X(int a):a(this->a){}
    void fun() const {
        //this->a=20;
        // this is passed as hidden argument to fun().
        // Type of this is const X*
    }
};

int main(){
    X obj(10);
    obj.fun();
}

