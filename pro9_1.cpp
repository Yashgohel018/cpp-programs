//Yash Gohel-24CE035
//Program No: 9.1
#include <iostream>
#include <limits>

using namespace std;

double calculateRatio(double loanAmount, double annualIncome) {
    if (annualIncome == 0) {
        cout << "Error: Annual income cannot be zero. Please enter a valid amount.\n";
        return -1; // Indicate an error
    }
    return loanAmount / annualIncome;
}

int main() {
    double loanAmount, annualIncome;

    cout << "Enter loan amount: ";
    while (!(cin >> loanAmount)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a numerical value for the loan amount: ";
    }

    cout << "Enter annual income: ";
    while (!(cin >> annualIncome)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a numerical value for the annual income: ";
    }

    double ratio = calculateRatio(loanAmount, annualIncome);
    
    if (ratio != -1) {
        cout << "Loan-to-Income Ratio: " << ratio << endl;
    }

    return 0;
}
