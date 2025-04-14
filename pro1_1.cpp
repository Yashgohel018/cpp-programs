//Yash Gohel-24CE035
//Program No:1.1
#include <iostream>
#include <cstring>
using namespace std;

class BankDetails {
public:
    int accnum;
    double balance;
    char name[20];
};

int main() {
    BankDetails s1;
    int choice;
    double amount;

    // User Input
    cout << "Enter Your Name: ";
    cin.ignore();  
    cin.getline(s1.name, 20);

    cout << "Enter Your Account Number: ";
    cin >> s1.accnum;

    cout << "Enter Your Current Balance: ";
    cin >> s1.balance;

    // Menu Loop
    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit (amount)\n";
        cout << "2. Withdraw (amount)\n";
        cout << "0. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                if (amount > 0) {
                    s1.balance += amount;
                    cout << "Amount after deposit: " << s1.balance << endl;
                } else {
                    cout << "Invalid deposit amount!\n";
                }
                break;

            case 2:
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                if (amount > 0) {
                    if (amount <= s1.balance) {
                        s1.balance -= amount;
                        cout << "Amount after withdrawal: $" << s1.balance << endl;
                    } else {
                        cout << "Error: Insufficient funds!\n";
                    }
                } else {
                    cout << "Invalid withdrawal amount!\n";
                }
                break;

            case 0:
                cout << "Thank you for using our banking system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}