//Yash Gohel-24CE035
//Program No: 6.4
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }

    virtual ~Base() { 
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[100];  
        cout << "Derived constructor: Allocated memory" << endl;
    }

    ~Derived() override {
        delete[] data;  
        cout << "Derived destructor: Released memory" << endl;
    }
};

int main() {
    Base* obj = new Derived();  
    delete obj;                 

    return 0;
}
