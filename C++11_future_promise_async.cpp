#include <iostream>
#include <future>
#include <chrono>
using namespace std;

int factorial(std::future<int>& f)
{
    int res = 1;
    int N = f.get();
    for (int i=N; i>1; i--)
        res *= i;
    cout << "Result is: " << res << endl;
    return res;
}

int main()
{
    int x;
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f));

    // do something else
    std::this_thread::sleep_for(chrono::milliseconds(20));
    p.set_value(4);
    x = fu.get();
    cout << "Get from child: " << x << endl;
    return 0;
}


// future and promise object can not be copied (but can be moved just like unique_ptr).
// shared_future can be copied and it is used for broadcast kind of scenario where multiple asyncs are called.
