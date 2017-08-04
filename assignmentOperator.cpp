#include <iostream>
using namespace std;

class Emp {
    private:
        string name;
        int* id;
    public:
        Emp(string _name,int* _id):name(_name),id(_id) {}
        //void operator=(const Emp& old){  		// this is also fine
        Emp& operator = (const Emp& old) {    	// if we have assinment operator chaining
            if(this == &old)
            {
                cout << "Self assignment" <<endl;
                return *this;
            }
            this->name = old.name;
			if (this->id != NULL)
				delete id;
            this->id=new int(*old.id);
            return *this;
        }
        void print() {
            cout << name <<" "<< *id << endl;
        }
        ~Emp() {
            if(id) {
                delete id;
                id=NULL;
            }
        }
};
int main() {
    Emp emp1("himanshu", new int(3036));
    Emp emp2("gautam", new int(3037));
    Emp emp3("aamir", new int(3038));
    emp1.print();
    emp2.print();
    emp3.print();
    emp3 = emp2 = emp1;
    emp1.print();
    emp2.print();
    emp3.print();
}
