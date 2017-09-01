//List insersion techniques

#include <iostream>
#include <list>
#include <memory>
#include <algorithm>
using namespace std;


class Test
{
	public:
		int _a;
		Test(int a) : _a(a) {}
		Test(const Test& other)
		{
			_a = other._a;
			cout << "Copy Ctor" << endl;
		}
};

int main()
{
	{
		list<Test> t1;
		{
			Test* p1 = new Test(10);
			t1.push_back(*p1);				//Call to copy Ctor
			delete p1;
		}

		for (auto it = t1.begin(); it != t1.end(); it++)
		{
			cout << it->_a << endl;
		}
	}
	{
		list<shared_ptr<Test>> t1;
		{
			shared_ptr<Test> p1 = make_shared<Test> (20);
			shared_ptr<Test> p2 = make_shared<Test> (30);
			t1.push_back(p1);
			t1.push_back(p2);
			cout << (p1).use_count() << endl;			//2
			cout << (p2).use_count() << endl;			//2
		}
		for (auto it = t1.begin(); it != t1.end(); it++)
		{
			cout << (*it)->_a << endl;					//20 30
			cout << (*it).use_count() << endl;			//1
		}
	}

	{
		list<Test*> t1;
		{
			Test* p1 = new Test(40);
			Test* p2 = new Test(50);
			t1.push_back(p1);
			t1.push_back(p2);
			delete p1;
			delete p2;
			p1=nullptr;
			p2=nullptr;
		}
		cout << "size: " << t1.size() << endl;				//2
		for (auto it = t1.begin(); it != t1.end(); it++)
		{
			cout << (*it)->_a << endl;						//garbage values
		}
	}
	return 0;
}
