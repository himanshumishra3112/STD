// NEC Technologies
#include <iostream>

using namespace std;

int main()
{
	//char* str1 = "hello";		// warning
	//char str2[6] = "hello";		// warning

	char const * str1 = "hello";		// OK
	char const str2[6] = "hello";		// OK
	//str1[0] = "a";			// error
	str2[0] = "a";				// error
}
