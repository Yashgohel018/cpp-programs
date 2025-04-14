//Yash Gohel-24CE035
//Program No:2.5
#include <iostream>
#include <cmath> 
using namespace std;

class Loan {
    int loanID;
    string name;
    double principal, interestRate, emi;
    int tenure;

public:
    // Method to get loan details
    void getData() {
        cout << "\nEnter Loan ID: ";
        cin >> loanID;
        cin.ignore(); 
        cout << "Enter Applicant Name: ";
        getline(cin, name);
        cout << "Enter Principal Amount: ";
        cin >> principal;
        cout << "Enter Annual Interest Rate (in %): ";
        cin >> interestRate;
        cout << "Enter Tenure (in months): ";
        cin >> tenure;

        calculateEMI();
    }

    // Method to display loan summary
    void display() {
        cout << "\nLoan ID: " << loanID << endl;
        cout << "Applicant Name: " << name << endl;
        cout << "Principal Amount: $" << principal << endl;
        cout << "Annual Interest Rate: " << interestRate << "%" << endl;
        cout << "Tenure: " << tenure << " months" << endl;
        cout << "EMI (Monthly Installment): $" << emi << endl;
    }

    // EMI calculation
    void calculateEMI() {
        double monthlyInterestRate = interestRate / 12 / 100;
        if (monthlyInterestRate == 0) {
            emi = principal / tenure;
        } else {
            emi = (principal * monthlyInterestRate * pow(1 + monthlyInterestRate, tenure)) /
                  (pow(1 + monthlyInterestRate, tenure) - 1);
        }
    }
};

int main() {
    Loan loan;
    int choice;

    cout << "------ Loan Management System ------";
    do {
        cout << "\n1. Enter Loan Details\n2. View Loan Summary\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                loan.getData();
                break;
            case 2:
                loan.display();
                break;
            case 3:
                cout << "Thank you for using the Loan Management System!" << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
