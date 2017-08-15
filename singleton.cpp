#include <iostream>
#include <string>
using namespace std;

class Singleton{
    private:
        string 	_name;
        int 	_id;
        static Singleton* inst;				// instance in private section
        Singleton(){						// Ctor in private section
            _name 	= "himanshu";
            _id		= 3036;
        }
        Singleton(const Singleton& obj){	//Copy Ctor also in private section
        }

    public:
        static Singleton* getInst(){
            if(inst == NULL)
                inst = new Singleton();
            return inst;
        }
        string getName(){
            return _name;
        }
        int getId(){
            return _id;
        }
};
Singleton* Singleton :: inst = NULL;

int main(){
    cout << Singleton::getInst()->getName() << endl;
    cout << Singleton::getInst()->getId() << endl;
}
