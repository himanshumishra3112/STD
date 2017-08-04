#include <iostream>
using namespace std;

void fun(int a)
{
	cout << "void fun(int a)" << endl;
}

int fun(int& a)
{
	cout << "int fun(int& a)" << endl;
}

int main()
{
	int a=20;
	fun(30);
	fun(a);
}

// fun(30)- OK
// fun(a) - call is ambiguous 
