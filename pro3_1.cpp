//Yash Gohel-24CE035
//Program No:3.1
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class employe {
    string name; // Using std::string instead of char array
    double money;
    double bonus;

public:
    employe(const string& m, double bmoney, double bbonus = 500.00) {
        name = m;
        money = bmoney;
        bonus = bbonus;
    }

    inline double total() {
        return money + bonus;
    }

    void display() {
        cout << "Name: " << name << ", Money: " << money << ", Total: " << total() << endl;
    }
};

int main() {
    vector<employe> emp;
    int n;
    string name;
    double m,bm;
    cout<<"Enter how many employee you want: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"\nDetails of employe"<<(i+1);
        cout<<"\nEnter Employe name: ";
        cin>>name;
        cout<<"\nEnter Employe Money: ";
        cin>>m;
        cout<<"\nEnter The Bonus: ";
        cin>>bm;
        emp.emplace_back("name",m,bm);
    }
    for (auto& i : emp) {
        i.display();
    }

    return 0;
}
