#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Test
{
	string _data;
	public:
	Test(string iTest): _data(iTest){}
	string show() const
	{
		return _data;
	}
};

int main()
{
	map<string,vector<Test> > aMap;
	
	Test aTest1("Hello-1");
	Test aTest2("Hello-2");
	Test aTest3("Hello-3");
	vector<Test> aVector;
	aVector.push_back(aTest1);
	aVector.push_back(aTest2);
	aVector.push_back(aTest3);

	aMap["Pax-1"] = aVector;

	Test aTest4("Hello-4");
	Test aTest5("Hello-5");
	Test aTest6("Hello-6");
	vector<Test> aVector2;
	aVector2.push_back(aTest4);
	aVector2.push_back(aTest5);
	aVector2.push_back(aTest6);

	aMap["Pax-2"] = aVector2;
	
	map<string,vector<Test> >::const_iterator aMapItr = aMap.begin();

	for (;aMapItr != aMap.end();++aMapItr)
	{
		vector<Test>::const_iterator aVectorItr = aMapItr->second.begin();
		
		for (;aVectorItr != aMapItr->second.end(); ++aVectorItr)
		{
			cout << aMapItr->first << " - " << aVectorItr->show() << endl;
		}
		cout << endl;		
	}
}
