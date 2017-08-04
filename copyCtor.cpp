#include <iostream>
using namespace std;

class Emp{
    private:
        int x;
        int &y;
        int *z;
        int const k;
    public:
		// Intitializer list
        Emp(int _x,int& _y,int* _z,int const _k):x(_x),y(_y),z(_z),k(_k){} 
		
		// Copy Ctor
		Emp(const Emp& old):x(old.x),y(old.y),k(old.k) {
            this->z = new int(*old.z);						//Deep copy
            //*z = *old.z;									//Swallow copy
        }
        void print() {
            cout << this << ": "<< x << " " << y <<" " << *z <<" " << k << endl;
        }
};

int main() {
    int val = 20;
    Emp emp1(10, val, new int(30), 40);	//Para ctor 
    Emp emp2 = emp1;					//Assignment operator
    emp1.print();
    emp2.print();
}
