//Find factorial of given number using recursion
#include <iostream>
using namespace std;


long long int factorial(int iNum)
{
	if (iNum == 2)
		return 2;
	else
		return iNum * factorial(iNum-1);
}

int main()
{
	cout << factorial(5) << endl;
	cout << factorial(4) << endl;
	return 0;
}
