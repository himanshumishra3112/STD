#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int> v1;	//size 0

	for(int i=0; i<5; i++) {
		v1.push_back(10);	//allocation order 0, 1, 2, 4, 8, 16, ...
	}

	cout << "size of v1 = " << v1.size() << endl;
	cout << "capacity of v1 = " << v1.capacity() << endl;

	vector<int> v2{10,10,10}; // Allocates exactly numbers of blocks required during intialization (3*sizeof(int))
	cout << "size of v2 = " << v2.size() << endl;
	cout << "capacity of v2 = " << v2.capacity() << endl;

	return 0;
}

/*
	for(int i=0; i<0; i++)
		size of v1 = 0
		capacity of v1 = 0

	for(int i=0; i<1; i++)
		size of v1 = 1
		capacity of v1 = 1

	for(int i=0; i<2; i++)
		size of v1 = 2
		capacity of v1 = 2

	for(int i=0; i<3; i++)
		size of v1 = 3
		capacity of v1 = 4

*/
