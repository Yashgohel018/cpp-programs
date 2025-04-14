//Yash Gohel-24CE035
//Program No: 4.4
#include <iostream>
#include <stack>
using namespace std;

// Base Class: Bank Account
class Bankaccount {
protected:
    string name;
    double balance;

public:
    Bankaccount(string n, double bn) : name(n), balance(bn) {}
    void deposit(double amt) {
        balance += amt;
        cout << "Deposited: " << amt << ", Balance: " << balance << endl;
    }
    int withdraw(double amt) {
        if (balance >= amt) {
            balance -= amt;
            cout << "Withdrawn: " << amt << ", Balance: " << balance << endl;
            return 1;
        } else {
            cout << "Insufficient balance!\n";
            return 0;
        }
    }
    double getbalance() {
        return balance;
    }
};

// Derived Class: Savings Account
class Savingacc : public Bankaccount {
public:
    Savingacc(string n, double bn) : Bankaccount(n, bn) {}
};

// Derived Class: Current Account
class Currentacc : public Bankaccount {
protected:
    double overdraftlimit;

public:
    Currentacc(string n, double bn, double od) : Bankaccount(n, bn), overdraftlimit(od) {}
    int withdraw(double amt) {
        if (balance + overdraftlimit >= amt) {
            balance -= amt;
            cout << "Withdraw: " << amt << ", Balance: " << balance << endl;
            return 1;
        } else {
            cout << "Overdraft limit exceeded!!" << endl;
            return 0;
        }
    }
    double getOverdraftlimit() const {
        return overdraftlimit;
    }
};

// Struct: Transaction
struct Transaction {
    string type;
    double amt;
};

// Helper Function: Show Menu
void showMenu() {
    cout << "\n--- Menu ---" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Undo Last Transaction" << endl;
    cout << "4. Show Balance" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

// Main Function
int main() {
    string type;
    int choice;
    double amt;
    stack<Transaction> History;

    cout << "Enter the type of Account (saving/current): ";
    cin >> type;
    cout << "Enter your Name: ";
    string name;
    cin >> name;
    cout << "Enter Initial Balance: ";
    double bal;
    cin >> bal;

    if (type == "saving") {
        Savingacc save(name, bal);

        do {
            showMenu();
            cin >> choice;

            switch (choice) {
            case 1: // Deposit
                cout << "Enter amount: ";
                cin >> amt;
                save.deposit(amt);
                History.push({"deposit", amt});
                break;

            case 2: // Withdraw
                cout << "Enter amount: ";
                cin >> amt;
                if (save.withdraw(amt)) {
                    History.push({"withdraw", amt});
                }
                break;

            case 3: // Undo Last Transaction
                if (!History.empty()) {
                    Transaction last = History.top();
                    History.pop();

                    if (last.type == "deposit") {
                        save.withdraw(last.amt);
                        cout << "Undid deposit of " << last.amt << endl;
                    } else if (last.type == "withdraw") {
                        save.deposit(last.amt);
                        cout << "Undid withdrawal of " << last.amt << endl;
                    }
                } else {
                    cout << "No transaction to undo." << endl;
                }
                break;

            case 4: // Show Balance
                cout << "Current Balance: " << save.getbalance() << endl;
                break;

            case 5: // Exit
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid Input. Try again!" << endl;
                break;
            }
        } while (choice != 5);
    }

    cout << endl;
    cout << "Thank you!" << endl;

    return 0;
}
