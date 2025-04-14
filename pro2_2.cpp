//Yash Gohel-24CE035
//Program No:2.2
#include<iostream>
#include<string.h>
using namespace std;

class Student {
private:
    int rollNumber;
    char name[50];
    float marks[3];
    
public:
    // Default constructor
    Student():rollNumber(0),name("Unknown") 
    { 
        marks[0] = marks[1] = marks[2] = 0.0;
    }
    
    // Parameterized constructor
    Student(int roll, const char* studentName, float m1, float m2, float m3) {
        rollNumber = roll;
        strcpy(name, studentName);
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
    
    // Function to input student details
    void inputDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Name: ";
        cin>>name;
        cout << "Enter Marks for 3 subjects: ";
        cin >> marks[0] >> marks[1] >> marks[2];
    }
    
    // Function to calculate average marks
    float calculateAverage() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }
    
    // Function to display student details
    void displayDetails() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average Marks: " << calculateAverage() << endl;
    }
};

int main() {
    // Using default constructor
    Student student1;
    student1.inputDetails(); // Collect values from user
    
    // Using parameterized constructor
    Student student2(101, "Yash Gohel", 85, 90, 88);
    
    cout << "\nStudent 1 Details:" << endl;
    student1.displayDetails();
    
    cout << "\nStudent 2 Details:" << endl;
    student2.displayDetails();
    
    return 0;
}
