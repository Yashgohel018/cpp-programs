//Yash Gohel-24CE035
//Program No: 5.4
#include <iostream>
#include <queue>
using namespace std;

// Forward declaration
class Fahrenheit;

class Celsius {
    float temp;

public:
    Celsius(float t = 0) : temp(t) {}

    // Conversion to Fahrenheit
    operator Fahrenheit();

    float getTemp() const {
        return temp;
    }

    // Compare with Fahrenheit (returns 1 if equal, 0 otherwise)
    int isEqual(Fahrenheit f);
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit(float t = 32) : temp(t) {}

    // Conversion to Celsius
    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    float getTemp() const {
        return temp;
    }

    // Compare with Celsius (returns 1 if equal, 0 otherwise)
    int isEqual(Celsius c) {
        float fTemp = c.getTemp() * 9 / 5 + 32;
        return (temp == fTemp) ? 1 : 0;
    }
};

// Define conversion from Celsius to Fahrenheit
Celsius::operator Fahrenheit() {
    return Fahrenheit(temp * 9 / 5 + 32);
}

// Define equality check from Celsius side
int Celsius::isEqual(Fahrenheit f) {
    float cTemp = (f.getTemp() - 32) * 5 / 9;
    return (temp == cTemp) ? 1 : 0;
}

int main() {
    queue<Fahrenheit> tempQueue;

    float c;
    cout << "Enter temperature in Celsius: ";
    cin >> c;

    Celsius cObj(c);
    Fahrenheit fObj = cObj;  // Convert Celsius to Fahrenheit

    // Store in queue
    tempQueue.push(fObj);

    cout << "\nConverted to Fahrenheit: " << fObj.getTemp() << "F" << endl;

    // Convert back
    Celsius c2 = fObj;
    cout << "Converted back to Celsius: " << c2.getTemp() << "C" << endl;

    // Check equality without using bool
    if (cObj.isEqual(fObj) == 1)
        cout << "Temperatures are equal after conversion.\n";
    else
        cout << "Temperatures are NOT equal after conversion.\n";

    // Process queue
    cout << "\nProcessing temperature queue:\n";
    while (!tempQueue.empty()) {
        Fahrenheit f = tempQueue.front();
        tempQueue.pop();
        cout << f.getTemp() << "F processed.\n";
    }

    return 0;
}
