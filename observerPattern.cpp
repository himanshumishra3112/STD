#include <iostream>
#include <vector>
using namespace std;

class Observer;
class Subject {
        public: Subject(){}
                ~Subject(){}
                void attach(Observer* obs);
                void detach(Observer* obs);
                void Notify();
                void activity();
        private:
                vector <Observer*> _observers;
};

class Observer {
        public: Observer(){}
                ~Observer(){}
                virtual void update(Subject* sub) = 0;
};

class ConcreteSubject : public Subject {
        public: ConcreteSubject();
                ~ConcreteSubject();
};

class ConcreteObserver1 : public Observer {
        public: ConcreteObserver1(){};
                ~ConcreteObserver1(){};
                void update(Subject* sub);
};

class ConcreteObserver2 : public Observer {
        public: ConcreteObserver2(){};
                ~ConcreteObserver2(){};
                void update(Subject* sub);
};
void ConcreteObserver1 :: update(Subject* pSub){
        cout << "Notification Received at observer - 1 !!!" << endl;
}
void ConcreteObserver2 :: update(Subject* pSub){
        cout << "Notification Received at observer - 2 !!!" << endl;
}

void Subject :: attach(Observer* pObs){
        _observers.push_back(pObs);
}

void Subject :: activity() {
        int ch = 0;
        do{
                cout << "press 1 - 9" << endl;
                cin>> ch;
                if(ch > 0 && ch <= 9)
                        Notify();
                else
                        break;
        }while(1);
}

void Subject :: Notify() {
        int size = _observers.size();
        for(int i = 0 ; i<size; i++){
                (_observers[i])->update(this);
        }
}

int main() {
        Subject* pSub = new Subject();
        ConcreteObserver1* pCObj1 = new ConcreteObserver1();
        Observer* pObs = pCObj1;
        pSub->attach(pObs);
        ConcreteObserver2* pCObj2 = new ConcreteObserver2();
        pObs = pCObj2;
        pSub->attach(pObs);
        pSub->activity();
        delete pSub;
        delete pCObj1;
        delete pCObj2;
};
