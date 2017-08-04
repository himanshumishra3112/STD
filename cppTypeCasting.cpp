#include <iostream>
#include <typeinfo>
using namespace std;

class student
{
    private:
        int roll;
    public:
        student(int r):roll(r) {}

        void fun() const
        {
            cout << typeid(this).name() << endl;
            ( const_cast <student*> (this) )->roll = 5;
        }

        int getRoll()  { return roll; }
};

class Ram : public student
{
    public:
        Ram(){}
};

int main(){
    // Static
    {
        float fl=3.41;
        cout << "float              : " << fl << endl;
        int in = static_cast <int> (fl);
        cout << "float to int       : " << in << endl;
    }
    // Const
    {
        float f=3.14;
        const float* fl=&f;
        cout << "float                  : " << *fl << endl;
        float& fl2=(const_cast <float&> (*fl));
        fl2=12.443;
        cout << "const to non const     : " << fl2 << endl;
    }
    {
        student s(3);
        cout << "Old roll number: " << s.getRoll() << endl;
        s.fun();
        cout << "New roll number: " << s.getRoll() << endl;

    }
    {
        student* st = new student(100);
        Ram* ram = new Ram();


    }

    // Dynamic
}
