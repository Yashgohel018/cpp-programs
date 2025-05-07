//Yash Gohel-24CE035
//Program No: 6.2
#include <iostream>
using namespace std;

class Point {
private:
    double x, y;

public:
    
    Point(double x = 0, double y = 0) {
        
    }

    // Input coordinates from the user
    Point* input() {
        cout << "Enter x and y coordinates: ";
        cin >> x >> y;
        return this; // Enables method chaining
    }

    // Shift the point by dx and dy
    Point* shift(double dx, double dy) {
        x += dx;
        y += dy;
        return this; // Enables method chaining
    }

    // Print coordinates
    Point* print() {
        cout << "Current coordinates: (" << x << ", " << y << ")" << endl;
        return this;
    }
};

int main() {
    double dx, dy;

    Point p;
    p.input()->print();

    cout << "Enter shift values (dx dy): ";
    cin >> dx >> dy;

    p.shift(dx, dy)->print();

    return 0;
}
