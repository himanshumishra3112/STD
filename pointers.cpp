#include <iostream>
using namespace std;

int main(){
    int val=4;
    int val2=5;
    int const * ptrToConstInt;                      // pointer to constant integer value
    int * const ConstptrToInt=&val;                 // constant pointer to integer
    int const * const ConstPtrToConstInt = &val;    // constant pointer to constant integer value

    const int a = 10;                   // OK // constant variable has to be initialized  <error: uninitialized const ‘a’>

    {
        ptrToConstInt = &val;           // OK
        ptrToConstInt = &val2;          // OK
        *ptrToConstInt = 5;             // NOT OK
    }
    {
        *ConstptrToInt = 10;            // OK
        ConstptrToInt++;                // NOT OK
    }

    {
        *ConstPtrToConstInt = 10;       // NOT OK
        ConstPtrToConstInt++;           // NOT OK
        ConstPtrToConstInt = &val2;     // NOT OK
    }
}
