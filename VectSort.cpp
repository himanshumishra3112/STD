
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class myclass {
  bool operator() (int i,int j) { return (i<j);}
}myobject;

int main()
{

    vector<string> aVect;
    aVect.push_back("hello1");
    aVect.push_back("hello5");
    aVect.push_back("hello3");
    aVect.push_back("hello4");
    aVect.push_back("hello2");
    vector<string>::const_iterator itr = aVect.begin();
    for (;itr != aVect.end(); itr++)
    {
        cout << *itr << endl;
    }

    cout << "Now sorted ..." << endl;
    //sort(aVect.begin(), aVect.end());
    sort(aVect.begin(), aVect.end(), myobject);
    for (itr = aVect.begin(); itr != aVect.end(); itr++)
    {
        cout << *itr << endl;
    }
    return 0;
}
