#include <iostream>
#include <string.h>
using namespace std;

class Test {
	int _age;
	char* _name;
	public:
	Test(int age, char* name): _age(age) {
		this->_name = new char[sizeof(name)+1];
		strcpy(this->_name, name);
	}
	~Test() {
		delete [] this->_name;
		this->_name = NULL;
	}
	Test(const Test& iTest) {
		cout << "Copy Ctor" << endl;

		this->_age = iTest._age;
		this->_name = new char[sizeof(iTest._name)+1];
		strcpy(this->_name, iTest._name);

		cout << this->_age << " - " << (this->_name) << endl;
	}
	Test& operator=(const Test& iTest) {
		cout << "Assignment Operator" << endl;
		
		if (this == &iTest) {
			cout << "Self copy" << endl;
			return *this;
		}
		this->_age = iTest._age;
		if (this->_name != NULL) {
			delete [] this->_name;
			this->_name = NULL;
		}
		this->_name = new char[sizeof(iTest._name)+1];
		strcpy(this->_name, iTest._name);
		
		cout << this->_age << " - " << (this->_name) << endl;
	}
};

int main() {
	Test aTest1(28,"Himanshu");
	Test aTest2 = aTest1;

	Test aTest3(28,"Mishra");

	aTest3 = aTest2;

	aTest2 = aTest2;
}
