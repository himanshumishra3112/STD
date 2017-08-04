#include <iostream>
#include <stdio.h>

using namespace std;
class cat{
	public:
		void walk(){
			printf("cat is walking \n");
		}
};


int main(){
	cat bigCat;
	void (cat::*pcat)();
	pcat = &cat::walk;
	(bigCat.*pcat)();
	return 0;
}
