
#include <iostream>
using namespace std;

int main(){
    static int n=100;
    static int i=0;
    if(i<n)
    {
        cout << i << endl;
        i++;
        main();
    }
}
