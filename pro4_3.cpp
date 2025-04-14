//Yash Gohel-24CE035
//Program No: 4.3
#include <iostream>
#include <queue>
using namespace std;

class Fuel {
protected:
    string fuelname;
public:
    Fuel(string fn) : fuelname(fn) {}
    void displayfuel() {
        cout << "Fuel: " << fuelname << endl;
    }
};

class Brand {
protected:
    string brandname;
public:
    Brand(string bn) : brandname(bn) {}
    void displaybrand() {
        cout << "Brand: " << brandname << endl;
    }
};

class car : public Fuel, public Brand {
protected:
    string carname;
public:
    car(string fn, string bn, string cn) : Fuel(fn), Brand(bn), carname(cn) {}
    void displaycar() {
        cout << "Car: " << carname << endl;
    }
};

int main() {
    queue<car> Queuecar;
    int n;
    cout << "How many entries do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string fuel, brand, carname;
        cout << "\nEnter the Fuel name: ";
        cin >> fuel;
        cout << "Enter the Brand name: ";
        cin >> brand;
        cout << "Enter the Car name: ";
        cin >> carname;

        car c(fuel, brand, carname);
        Queuecar.push(c); // push the object to the queue
    }

    cout << "\n--- Displaying Cars in Queue ---\n";
    while (!Queuecar.empty()) {
        car c = Queuecar.front(); // get the front car
        c.displaycar();
        c.displaybrand();
        c.displayfuel();
        cout << "-------------------" << endl;
        Queuecar.pop(); // remove from queue
    }

    return 0;
}
