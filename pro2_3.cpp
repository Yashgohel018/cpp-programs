//Yash Gohel-24CE035
//Program No:2.3
#include <iostream>
#include <cstring>
using namespace std;

class BankDetails {
    int banknum;
    char name[200];
    double money; // Current balance

public:
    // Constructor
    BankDetails(int bank = 0, char m[] = "", double mon = 0.0) {
        banknum = bank;
        strcpy(name, m);
        money = mon;
    }

    // Method to get data
    void getData() {
        cout << "Enter Your Account Number: ";
        cin >> banknum;
        cout << "Enter Your Name: ";
        cin.ignore(); // Clear newline from previous input
        cin.getline(name, 200);
        cout << "Enter Your Current Balance: ";
        cin >> money;
    }

    // Method to display data
    void putData() {
        cout << "Your Account Number is: " << banknum << endl;
        cout << "Your Name is: " << name << endl;
        cout << "Your Current Balance is: $" << money << endl;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            money += amount;
            cout << "Amount deposited successfully!\n";
            cout << "New Balance: $" << money << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= money) {
            money -= amount;
            cout << "Amount withdrawn successfully!\n";
            cout << "New Balance: $" << money << endl;
        } else if (amount > money) {
            cout << "Error: Insufficient funds!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Getter for account number (optional)
    int getAccountNumber() {
        return banknum;
    }
};

int main() {
    BankDetails B1;
    int choice;

    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int banknum;
                char name[200];
                double money;
                cout << "Enter Your Account Number: ";
                cin >> banknum;
                cout << "Enter Your Name: ";
                cin.ignore();
                cin.getline(name, 200);
                cout << "Enter Your Current Balance: ";
                cin >> money;

                B1 = BankDetails(banknum, name, money);  // Assigning the new account to B1
                cout << "Account created successfully!\n";
                break;
            }

            case 2: {
                double amount;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                B1.deposit(amount);
                break;
            }

            case 3: {
                double amount;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                B1.withdraw(amount);
                break;
            }

            case 4:
                B1.putData();
                break;

            case 5:
                cout << "Thank you for using the banking system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
