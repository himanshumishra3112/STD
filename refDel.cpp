#include <iostream>
using namespace std;

int main()
{
    int& aRef = *(new int(10));
    cout << "int& aRef = " << aRef << endl;
    delete &aRef;
    return 0;
}
// This is how memory can be deallocated throw reference object
