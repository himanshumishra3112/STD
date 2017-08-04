#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef int ContainedType;
int main(int argc, char **argv)
{
    {
        int *i = new int(10);
        auto_ptr<int> x(i);
        auto_ptr<int> y;

        y = x;

        cout << x.get() << endl; // Print NULL
        cout << y.get() << endl; // Print non-NULL address i
        cout << *y.get() << endl; // value
    }
    {
        auto_ptr<vector<ContainedType> > open_vec(new vector<ContainedType>);

        open_vec->push_back(5);
        open_vec->push_back(3);
        open_vec->push_back(1);
        open_vec->push_back(8); // Can no longer modify

        cout << "open_vec    : " << open_vec.get() << endl;
        // Transfers control, but now the vector cannot be changed:
        auto_ptr<const vector<ContainedType> > closed_vec(open_vec);

        cout << "open_vec    : " << open_vec.get() << endl;
        cout << "closed_vec  : " << closed_vec.get() << endl;
        // closed_vec->push_back(8); // Can no longer modify

        // Safe during the lifetime of the autoptr:
        map<string, const ContainedType *> nmap;

        nmap["First"]  = &closed_vec->at(0);
        nmap["Second"] = &closed_vec->at(1);
        nmap["Third"]  = &closed_vec->at(2);
        nmap["Fourth"]  = &closed_vec->at(3);

        for (map<string,const ContainedType *>::iterator it = nmap.begin(); it != nmap.end(); ++it) {
            cout << it->first << " -> " << *(it->second) << std::endl;
        }
    }

    return 0;
}
