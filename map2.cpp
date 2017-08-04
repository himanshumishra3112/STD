#include <iostream>
#include <map>
using namespace std;

int main(){
    std::map<string,int> mymap;
    std::map<string,int>::iterator it = mymap.begin();

    mymap.insert(make_pair("himanshu",1));  //Based on the value type will be decided
    mymap.insert(std::pair<string,int>("itendra",3)); //Normal way of doing
    mymap["Piyush"] = 5;
    mymap.insert(it,make_pair("Naveen",7));

    std::pair<std::map<string,int>::iterator, bool> ret;  // return from insert: pair of iterator and bool
    ret = mymap.insert(make_pair("Rajesh",4));

    cout << "ret.second: " << ret.second << endl;
    cout << "ret.first->first: " << ret.first->first << endl;
    cout << "ret.first->second: " << ret.first->second << endl;

    it=mymap.find("himanshu");
    cout<< "Find himanshu: "  << it->first << " " << it->second << endl;
    for(it=mymap.begin(); it != mymap.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << "\nAfter Erase\n" << endl;
    mymap.erase("himanshu");
    for(it=mymap.begin(); it != mymap.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}
