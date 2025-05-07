//Yash Gohel-24CE035
//Program No: 7.5
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string fileName = "student_report.txt";
    ofstream file(fileName);
    if (!file) {
        cout << "Error: Unable to create file." << endl;
        return 1;
    }

    string name;
    int marks;
    double tuition;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter marks: ";
    cin >> marks;
    cout << "Enter tuition fee: ";
    cin >> tuition;

    file << left << setw(20) << "Name" << setw(10) << "Marks" << setw(15) << "Tuition Fee" << endl;
    file << "--------------------------------------------------------" << endl;
    file << left << setw(20) << name << setw(10) << marks << setw(15) << fixed << setprecision(2) << tuition << endl;

    file.close();
    cout << "Student record saved in file: " << fileName << endl;

    return 0;
}
