#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){
    list<int> mylist;
    list<int> :: iterator it;
    mylist.push_back(10);
    mylist.push_front(20);

    it = find(mylist.begin(),mylist.end(),20);
    mylist.insert(it,30);
    mylist.insert(it,40);

    for(it=mylist.begin(); it!= mylist.end(); it++){
        cout << *it << endl;
    }
}
