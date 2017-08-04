//http://www.drdobbs.com/cpp/counting-objects-in-c/184403484?pgno=1

#include <iostream>
using namespace std;

template <class T>
class ObjectCount 
{
	static int count;
	protected:
	ObjectCount() {
		count++;
	}
	public:
	void static showCount() {
		cout << count << endl;
	}
};

template <class T>
int ObjectCount<T>::count = 0;


class Employee : public ObjectCount<Employee> 
{
	public:
		Employee(){}
		Employee(const Employee & emp) {}
		void showCount()
		{
			ObjectCount<Employee>::showCount();
		}

};

class Manager : public ObjectCount<Manager>
{
	public:
		Manager(){}
		Manager(const Manager & man) {}
		void showCount()
		{
			ObjectCount<Manager>::showCount();
		}
};

class Director : public ObjectCount<Director>
{
	public:
		Director(){}
		Director(const Director & dir) {}
		void showCount()
		{
			ObjectCount<Director>::showCount();
		}
};

int main()
{
	Employee e[10];
	cout << "Employee's count: ";ObjectCount<Employee>::showCount();
	// or
	cout << "Employee's count: ";e[0].showCount();
	Manager m[5];
	cout << "Manager's count: ";ObjectCount<Manager>::showCount();
	Director d1;
	cout << "Director's count: ";ObjectCount<Director>::showCount();
}
