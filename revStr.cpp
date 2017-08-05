//With only one string
#include <iostream>
using namespace std;

int main()
{
	string input;
	cout << "Enter a String: " << endl;
	cin >> input;
	int size = input.size();

	for (int i=0, j=size-1; i<(size/2); i++,j--)
	{
		char temp = input.at(i);
		input[i] = input[j];
		input[j] = temp;
	}
	cout << "Reverse: " << input << endl;

	return 0;
}
