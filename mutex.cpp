#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

struct Complex {
	std::mutex mutex;
	int i;

	Complex() : i(10) {}

	void mul(int x){
		std::lock_guard<std::mutex> lock(mutex);
		i *= x;
		cout << i << endl;
	}

	void div(int x){
		std::lock_guard<std::mutex> lock(mutex);
		i /= x;
		cout << i << endl;
	}

	void both(int x, int y){
		std::lock_guard<std::mutex> lock(mutex);
		mul(x);
		div(y);
	}
};


void f(int i)
{
	Complex complex;
	complex.both(10, 10);
}


int main(){
	std::thread first(f,1);

	first.join();
	return 0;
}


//g++ -g  -std=c++11 mutex.cpp -pthread
