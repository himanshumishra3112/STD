#include <iostream>
#include <string>
using namespace std;

class Emp {
    private:
        string _name;
        int _id;
    public:
        Emp(string name, int id):_name(name),_id(id) {}	// Initializer list

        string getName() {
            return this->_name;
        }
        int getId() {
            return this->_id;
        }
};
class SmartPrt {
    private:
        Emp* emp;
    public:
        SmartPrt(Emp *_emp): emp(_emp) {}
        Emp& operator * () {  // To dereference
            return *emp;
        }
        Emp* operator -> () { // To dereference and access a field
            return emp;
        }
};

int main(){
    SmartPrt sp(new Emp("himanshu",3036));
    cout << sp->getName() << " : " << sp->getId() << endl;
    cout << (*sp).getName() << " : " << (*sp).getId() << endl;
}
