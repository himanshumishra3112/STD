#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

struct Complex {
	std::recursive_mutex mutex;
	int i;

	Complex() : i(10) {}

	void mul(int x){
		std::lock_guard<std::recursive_mutex> lock(mutex);
		i *= x;
		cout << i << endl;
	}

	void div(int x){
		std::lock_guard<std::recursive_mutex> lock(mutex);
		i /= x;
		cout << i << endl;
	}

	void both(int x, int y){
		std::lock_guard<std::recursive_mutex> lock(mutex);
		mul(x);
		div(y);
	}
};


void f(int i)
{
	Complex complex;
	complex.both(10, 10);
}


int main()
{
	std::thread first(f,1);
	std::thread second(f,1);

	first.join();
	second.join();
	return 0;
}
