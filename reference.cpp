// Invalid references
//1) Reference to value at uninitialized pointer.
//2) Reference to a local variable is returned.

#include <iostream>
using namespace std;
int& fun()
{
    int a = 10;
    return a;
}
int main(){
    //int a=20;
    //int *ptr=&a;
    int *ptr;
    int &ref = *ptr;				//#1
    cout << "ref: " << ref << endl;
    int x=fun();					//#2
    cout << "x: " << x << endl;
}
