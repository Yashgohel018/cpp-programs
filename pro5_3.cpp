//Yash Gohel-24CE035
//Program No: 5.3
#include <iostream>
#include <vector>
using namespace std;

// Point class
class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Negation
    Point operator-() const {
        return Point(-x, -y);
    }

    // Addition
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Equality
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Custom stack for undo functionality
class PointStack {
    vector<Point> stack;

public:
    void push(const Point& p) {
        stack.push_back(p);
    }

    Point pop() {
        if (stack.empty()) {
            cout << "Nothing to undo!\n";
            return Point();
        }
        Point top = stack.back();
        stack.pop_back();
        return top;
    }

    bool empty() const {
        return stack.empty();
    }
};

// Main function with user input
int main() {
    Point p1, p2, current;
    PointStack history;
    int choice;

    cout << "Enter coordinates for Point 1 (x y): ";
    cin >> p1.x >> p1.y;

    cout << "Enter coordinates for Point 2 (x y): ";
    cin >> p2.x >> p2.y;

    current = p1;
    history.push(current);

    while (true) {
        cout << "\nCurrent Point: ";
        current.display();
        cout << "Choose an operation:\n";
        cout << "1. Add Point 2\n";
        cout << "2. Negate Current Point\n";
        cout << "3. Undo Last Operation\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                history.push(current);
                current = current + p2;
                break;
            case 2:
                history.push(current);
                current = -current;
                break;
            case 3:
                current = history.pop();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
    