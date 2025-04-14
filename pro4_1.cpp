//Yash Gohel-24CE035
//Program No: 4.1
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//Base Class: Generic Shape
class Shape {
protected:
    double circleRadius; 
public:
    Shape(double radius) : circleRadius(radius) {}
};

//Specialized Class: Circle
class Circle : public Shape {
public:
    Circle(double radius) : Shape(radius) {}
    double calculateArea() {
        return M_PI * circleRadius * circleRadius; 
    }
};

//handle multiple circles
class CircleHandler {
private:
    vector<Circle> circleData; // Collection of circles
public:
    void addCircle(double radius) {
        Circle newCircle(radius);
        circleData.push_back(newCircle);
    }

    void displayAreas() {
        for (size_t i = 0; i < circleData.size(); ++i) {
            cout << "Circle " << i + 1 << ": Area = " 
                 << circleData[i].calculateArea() << endl;
        }
    }
};

// Example Usage
int main() {
    CircleHandler hl; 

    hl.addCircle(5.0); // Add a circle with radius 5
    hl.addCircle(10.0); // Add another circle with radius 10
    hl.displayAreas();

    return 0;
}
