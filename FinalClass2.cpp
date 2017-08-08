/* A program without any compilation error to demonstrate that instances of 
   the Final class can be created */
#include<iostream>
using namespace std;

class Final;

class MakeFinal
{
	private:
		MakeFinal() { cout << "MakeFinal constructor" << endl; }
		friend class Final;
};

class Final : virtual MakeFinal
{
	public:
		Final() { cout << "Final constructor" << endl; }
};

int main(int argc, char *argv[])
{
	Final f;
	return 0;
}
