#include <iostream>
#include <vector>

using namespace std;

int main()
{
	{
		int arr[10] = {1,2,3,4,5,6,7,8,9,0};
		std::vector<int> aVec(arr,arr+sizeof(arr)/sizeof(int));

		cout << "aVec size: " << sizeof(aVec) << endl;
		cout << "aVec size: " << aVec.size() << endl;
	}

	// Empty vector
	{
		vector<int> v;
		cout << "Empty vector" << endl;
		cout << "v.size() - "<< v.size() << endl;			// 0
		cout << "v.capacity() - " << v.capacity() << endl;	// 0
		cout << "v.max_size() - " << v.max_size() << endl;	// 4611686018427387903	
	}
}
