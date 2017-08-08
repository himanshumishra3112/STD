#include <iostream>
using namespace std;

#define RECU 0
#define DYN  0
#define SUM  1

#if DYN 
int fibonacci(int iNum)
{
	int aFibTbl[iNum+1];
	aFibTbl[0] = 0;
	aFibTbl[1] = 1;

	for (int i=2; i<=iNum; i++)
	{
		aFibTbl[i] = aFibTbl[i-1] + aFibTbl[i-2];
	}

	return aFibTbl[iNum];
}
#elif RECU
int fibonacci(int iNum)
{
	if (iNum == 0)
		return 0;
	else if (iNum == 1)
		return 1;
	else
		return (fibonacci(iNum-1) + fibonacci(iNum - 2));
}
#elif SUM
int fibonacci(int iNum)
{
	int a = 0;
	int b = 1;
	int sum = 0;
	
	for (int i = 2; i<=iNum; i++)
	{
		sum = a+b;	
		a = b;
		b = sum;
	}
	return sum;
}
#endif

int main()
{
	cout << fibonacci(40) << endl;;
	return 0;	
}



/*
1. Recursion:
============
himanshu@himanshu-VirtualBox:~/git/STD$ g++ -g  DynamicProgramming.cpp
himanshu@himanshu-VirtualBox:~/git/STD$ time ./a.out 
102334155

real	0m1.060s
user	0m1.044s
sys	0m0.000s

2. Dynamic:
==========
himanshu@himanshu-VirtualBox:~/git/STD$ vim DynamicProgramming.cpp
himanshu@himanshu-VirtualBox:~/git/STD$ g++ -g  DynamicProgramming.cpp
himanshu@himanshu-VirtualBox:~/git/STD$ time ./a.out 
102334155

real	0m0.002s
user	0m0.000s
sys	0m0.000s

3.Summation:
==============
himanshu@himanshu-VirtualBox:~/git/STD$ vim DynamicProgramming.cpp
himanshu@himanshu-VirtualBox:~/git/STD$ g++ -g  DynamicProgramming.cpp
himanshu@himanshu-VirtualBox:~/git/STD$ time ./a.out 
102334155

real	0m0.003s
user	0m0.000s
sys	0m0.000s

*/
