#include <iostream>
#include <future>
#include <thread>
using namespace std;

int factorial(int N)
{
    int ret = 1;
    for (int i=N; i>1l; i--)
    {
        ret *= i;
    }
    return ret;
}

int main()
{
    std::future<int> fu = async(std::launch::async, factorial, 4);
    int x = fu.get();
    return 0;
}

//g++ -g -std=c++11 c++11_future.cpp
