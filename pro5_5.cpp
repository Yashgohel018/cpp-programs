#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual float Area() = 0;          // Pure virtual function
    virtual void display() = 0;        // Display area
    virtual ~Shape() {}                // Virtual destructor
};

// Rectangle class
class Rectangle : public Shape {
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float Area() override {
        return length * width;
    }

    void display() override {
        cout << "Rectangle Area: " << Area() << endl;
    }
};

// Circle class
class Circle : public Shape {
    float radius;

public:
    Circle(float r) : radius(r) {}

    float Area() override {
        return M_PI * radius * radius;
    }

    void display() override {
        cout << "Circle Area: " << Area() << endl;
    }
};

int main() {
    int n;
    vector<Shape*> shapes;

    cout << "How many shapes do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "\nEnter shape " << (i + 1) << " (1 = Rectangle, 2 = Circle): ";
        cin >> choice;

        if (choice == 1) {
            float l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            shapes.push_back(new Rectangle(l, w));
        } else if (choice == 2) {
            float r;
            cout << "Enter radius: ";
            cin >> r;
            shapes.push_back(new Circle(r));
        } else {
            cout << "Invalid choice, skipping...\n";
        }
    }

    // Display all areas
    cout << "\n=== Shape Areas ===\n";
    for (Shape* s : shapes) {
        s->display();
    }

    // Clean up memory
    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}
