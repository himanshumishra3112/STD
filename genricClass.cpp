#include <iostream>
#include <string>
using namespace std;

template <typename T, typename N>
class Test{
    T data;
    N name;
    public:
        Test(T _data,T _name): data(_data),name(_name) {}
        void display(){
            cout << "data: " << data << endl;
            cout << "name: " << name << endl;
        }
};

int main(){
    Test <int,std::string> obj(10,"himanshu");
    obj.display();
    //Test <std::string,int> obj2("himanshu", 20);
    //obj2.display();
}
