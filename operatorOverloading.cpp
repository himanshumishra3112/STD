#include <iostream>
using namespace std;

class Time{
    private:
        int hh;
        int mm;
    public:
        Time(int _hh,int _mm):hh(_hh),mm(_mm){}
        Time(){
            hh=0;
            mm=0;
        }
        Time operator+(const Time& old){
            Time temp;
            temp.hh=hh+old.hh;
            temp.mm=mm+old.mm;
            return temp;
        }
        Time& operator=(const Time& old){
            cout << "called" << endl;
            if(this == &old)
            {
                cout << "Self assignment" <<endl;
                return *this;
            }
            hh=old.hh;
            mm=old.mm;
            return *this;
        }
        void print(){
            cout << mm <<" "<< hh << endl;
        }
};

int main(){
    Time t1(10,20);
    Time t2(20,10);
    Time t3;
    t3=t1+t2;
    t3.print();
    t1.print();
}

