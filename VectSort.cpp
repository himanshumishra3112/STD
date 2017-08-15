#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool myComp(string i,string j)
{
	return (i<j);
}

class myclass {
	public:
		bool operator() (string i,string j) { return (i<j);}
} myobject;

int main()
{
    vector<string> aVect;
    aVect.push_back("hello1");
    aVect.push_back("hello5");
    aVect.push_back("hello3");
    aVect.push_back("hello4");
    aVect.push_back("hello2");

	for (auto itr = aVect.begin();itr != aVect.end(); itr++)
    {
        cout << *itr << endl;
    }

    cout << "Now sorted ..." << endl;
    sort(aVect.begin(), aVect.end(), myobject);
	// OR
	//bool (*fPtr)(string,string) = myComp;
    //sort(aVect.begin(), aVect.end(), fPtr);

    for (auto itr = aVect.begin(); itr != aVect.end(); itr++)
    {
        cout << *itr << endl;
    }

	return 0;
}

//Third argument is compare: This can either be a function pointer or a function object.
