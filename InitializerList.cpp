#include <iostream>
using namespace std;

class State {
    int state;
    public:
        State() {
            cout << "State's Default Ctor called" << endl;
        }
        State(int _state):state(_state) {
            cout << "State's Param Ctor called" << endl;
        }
        State(const State& old) : state(old.state) {
            cout << "State's copy Ctor called" << endl;
        }
        State& operator = (const State& old) {
            state = old.state;
            cout << "State's assignment operator called" << endl;
            return *this;
        }
        ~State() {
            cout << "State's Dtor called" << endl;
        }
};

class Context {
    State oState;
    public:
        Context(State _oState) : oState(_oState) {
            cout << "Context's Param Ctor called" << endl;
        }
        ~Context() {
            cout << "Context's Dtor called" << endl;
        }
};

int main(){
    Context obj(10);
}
