#include <iostream>
using namespace std;

class Base{
    int num;
    public:
        Base(){num=10;}
        int getBase(){
            return num;
        }
};

class Intermediate1 :  public Base{
};

class Intermediate2 : public Base{
};
class Derived: virtual public Intermediate1, virtual public Intermediate2{
    public :
        void print(){
            int num=getBase();
            cout << num << endl;
        }
};

int main(){
    Derived d;
    d.print();
}


