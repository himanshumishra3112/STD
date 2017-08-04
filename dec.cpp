#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ofstream myfile;
    myfile.open ("example.txt");
    //myfile << hex << 15 << ",";
    myfile <<hex<<  ">12";
    myfile.close();
    return 0;
}
