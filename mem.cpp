#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    {
        char str[] = "himanshumishra";
        cout << str << endl;
        char* ret=(char*)memcpy(str+4,str,10);
        cout << "ret=" << ret << endl;
        cout << str << endl;
    }
    {
        char str[] = "himanshumishra";
        cout << str << endl;
        char* ret=(char*)memmove(str+4,str,10);
        cout << "ret=" << ret << endl;
        cout << str << endl;
    }
    char str[] = "himanshumishra";
    cout << str << endl;
    //memset(str,NULL,sizeof(str));
    bzero(str,NULL);
    cout << str << endl;
}
