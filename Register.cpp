#include <iostream>
#include <map>
using namespace std;

class Base
{
    public:
        Base(int i) : _id(i){
            //cout << "Base Ctor - this " << this << endl;
            getMap()[_id] = this;
        };
        ~Base(){
            //cout << "Base Dtor" << endl;
        };
        static map<int,Base*>& getMap() {
            static map<int,Base*> _map;
            return _map;
        };

    private:
        int _id;
};


class Sing : public Base
{
    public:
        ~Sing(){
            //cout << "Sing Dtor - this "  << this << endl;
        };
    protected:
        Sing(int a): Base(a){
            //cout << "Sing Ctor" << endl;
        };
    private:
        static const Sing _reg;
};

class Sing2 : public Base
{
    public:
        ~Sing2(){
            //cout << "Sing2 Dtor - this "  << this << endl;
        };
    protected:
        Sing2(int a): Base(a){
            cout << "Sing2 Ctor" << endl;
        };
    private:
        static const Sing2 _reg;
};

const Sing Sing::_reg(10);
const Sing2 Sing2::_reg(20);

int main()
{
    map<int,Base*>& aMap = Base::getMap();
    map<int,Base*>::const_iterator itr = aMap.begin();
    for (;itr != aMap.end();itr++)
    {
        cout << itr->first << " - " << itr->second << endl;
    }
}
