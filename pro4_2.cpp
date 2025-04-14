//Yash Gohel-24CE035
//Program No: 4.2
#include<iostream>
#include<string>
#include<map>
using namespace std;

class person {
protected:
    int agenum;
    string name;
public:
    // Function to read data
    person(int n,string n1):agenum(n),name(n1){};
    void get() {
        cin >> agenum;
        cin >> name;
    }

    // Function to print data
    void put() {
        cout << agenum << " " << name << endl;
    }
};

class employee : public person {
    int employeId;
    public:
    employee(int n,string n1,int i1):person(n,n1),employeId(i1){};
    void getId(){
        cin>>employeId;
    }
    void putId(){
        cout<<employeId;
    }
};

class manager : public employee{
    string managerDep;
    public:
    manager(int n,string n1,int i1,string d1):employee(n,n1,i1),managerDep(d1){};
    void getdep(){
        cin>>managerDep;

    }
    void putdep(){
        cout<<managerDep;
    }

};


int main() {
    map<int, manager>Managers;

    Managers[101]=manager(101,"Yash Gohel",18,"HR");
    Managers[102]=manager(102,"Devuuuu",58,"Finance");
    Managers[103]=manager(103,"Meet Ghori",68,"IT");

    for (const auto& m : Managers)
    {
        cout<<"Manager ID "<<m.first;
        
    }
    
    return 0;
}
