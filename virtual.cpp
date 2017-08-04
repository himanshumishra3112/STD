#include <iostream>
using namespace std;

class Animal {
	public:
		Animal();
		int weight;
		virtual int getWeight() {};
};

Animal::Animal(){
	weight=70;
}

class Tiger: public Animal {
	public:
		Tiger();
		int weight;
		int height; 
		int getWeight() {return weight;};
		int getHeight() {return height;};
};

Tiger::Tiger(){
	weight=60;
	height=3;
}
int main(){	
	Tiger t1;
	/* below, an Animal object pointer is set to point
	 * to an object of the derived Tiger class  */
	Animal *a1 = &t1; 
	/* below, how does this know to call the 
	 * definition of getWeight in the Tiger class, 
	 * and not the definition provided in the Animal 
	 * class  */
	a1 -> getWeight(); 
}			

