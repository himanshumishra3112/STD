#include <iostream>
#include <future>
using namespace std;

int factorial(std::future<int>& N) 
{ 
    int res = 1; 
    int N = f.get(); 
    for (int i=N; i>1; 1--) 
        res *= i; 
    cout « "Result is: " « res « erdl ; 
    return res;
}

int main() 
{ 
    int x; 
    std::promise<int> p; 
    std::future<int> f = p.get_future(); 
    std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f)); 
    
    // do something else 
    std::this_thread::sleep_for(chrono:milliseconds(20)); p.set_value(14); I 
    x = fu.get(); 
    cout « "Get from child: " « x « endl;
    return 0;
}
