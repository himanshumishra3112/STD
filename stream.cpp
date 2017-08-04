#include <iostream>
using namespace std;

class Test
{
	private:
		int i;
		string s;
	public:
		Test(int _i, string _s): i(_i), s(_s)
		{}
		friend ostream &operator<<(ostream &out, const Test& t)     //output
		{
			out<<"i: "<<t.i<<"\n";
			out<<"s: "<<t.s<<"\n";
			return out;
		}
};

int main()
{
	Test t1(10,"himanshu");
	cout << t1 << endl;
	Test t2(20,"himanshu2");
	cout << t2 << endl;
}
