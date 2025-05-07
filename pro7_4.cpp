//Yash Gohel-24CE035
//Program No: 7.4
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Function to display student records in a tabular format
void displayReport() {
    ifstream file("students.txt");
    if (!file) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string name;
    int marks;
    char grade;

    cout << left << setw(20) << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << endl;
    cout << "----------------------------------------" << endl;

    while (file >> name >> marks >> grade) {
        cout << left << setw(20) << name << setw(10) << marks << setw(10) << grade << endl;
    }

    file.close();
}

int main() {
    displayReport();
    return 0;
}
