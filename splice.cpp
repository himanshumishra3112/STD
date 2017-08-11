//void splice (const_iterator position, list&& x, const_iterator first, const_iterator last);

//	position 	− Position in the list where new element to be inserted.
//	x 			− Another list object of same type.
//	first 		− Input iterator to the initial position in range
//	last 		− Input iterator to the final position in range

#include <iostream>
#include <list>

using namespace std;

int main(void) {
	list<int> l1 = {1, 2};
	list<int> l2 = {3, 4, 5};

	l1.splice(l1.end(), move(l2), l2.begin(), l2.end());
	//l1.splice(l1.begin(), move(l2), l2.begin(), l2.end());

	cout << "Contents of list l1 after splice operation" << endl;

	for (auto it = l1.begin(); it != l1.end(); ++it)
		cout << *it << endl;

	return 0;
}
