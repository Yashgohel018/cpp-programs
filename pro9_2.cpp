//Yash Gohel-24CE035
//Program No: 9.2
#include <iostream>
#include <limits>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) {
        balance = (initialBalance < 0) ? 0 : initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    double initialBalance;
    cout << "Enter initial balance: ";
    while (!(cin >> initialBalance)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a numerical value: ";
    }

    BankAccount account(initialBalance);

    int choice;
    double amount;

    do {
        cout << "\nBank System Menu:\n";
        cout << "1. Deposit\n2. Withdraw\n3. Show Balance\n4. Exit\n";
        cout << "Choose an option: ";
        
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid option: ";
        }

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                while (!(cin >> amount)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a numerical value: ";
                }
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                while (!(cin >> amount)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a numerical value: ";
                }
                account.withdraw(amount);
                break;
            case 3:
                account.showBalance();
                break;
            case 4:
                cout << "Thank you for using the banking system!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
