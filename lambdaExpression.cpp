/*
Lambda expression in C++
========================
C++ 11 introduced lambda expression to allow us write an inline function which can be used for short snippets 
of code that are not going to be reuse and not worth naming. In its simplest form lambda expression can be defined as follows:


[ capture clause ] (parameters) -> return-type  
{   
	   definition of method   
} 
Generally return-type in lambda expression are evaluated by compiler itself and we don’t need to specify that explicitly 
and -> return-type part can be ignored but in some complex case as in conditional statement, compiler can’t make out the 
return type and we need to specify that.

A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope. 
We can capture external variables from enclosing scope by three ways :
      Capture by reference
	  Capture by value
	  Capture by both (mixed capture)

	  Syntax used for capturing variables :
	      [&] : capture all external variable by reference
	      [=] : capture all external variable by value
	      [a, &b] : capture a by value and b by reference

	A lambda with empty capture clause [ ] can access only those variable which are local to it.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v1 = {3, 1, 7, 9};
	vector<int> v2 = {10, 2, 7, 16, 9};
	//  access v1 and v2 by reference
	auto pushinto = [&] (int m) -> void
	{
		v1.push_back(m);
		v2.push_back(m);
	};

	// it pushes 20 in both v1 and v2
	pushinto(20);

	// access v1 by copy
	auto print = [v1]()
	{
		for (auto p = v1.begin(); p != v1.end(); p++)
		{
			cout << *p << " ";
		}
		cout << endl;
	};

	print();
	int N = 5;

	// below snippet find first number greater than N
	// [N]  denotes,   can access only N by value
	vector<int>::iterator p = find_if(v1.begin(), v1.end(), [N](int i)
			{
			return i > N;
			});

	cout << "First number greater than 5 is : " << *p << endl;

	// function to count numbers greater than or equal to N
	// [=] denotes,   can access all variable
	int count_N = count_if(v1.begin(), v1.end(), [=](int a)
			{
			return (a >= N);
			});
	cout << "The number of elements greater than or equal to 5 is : "
		<< count_N << endl;
	
	return 0;
}

/*
Output:
======
3 1 7 9 20 
First number greater than 5 is : 7
The number of elements greater than or equal to 5 is : 3
*/
