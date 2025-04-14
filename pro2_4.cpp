//Yash Gohel-24CE035
//Program No:2.4
#include <iostream>
#include <string>
using namespace std;

class Store {
    int ID;
    string name;
    int quantity;
    int price;
    int totalPrice;

public:
    // Method to input item data
    void getData() {
        cout << "\nEnter Item ID: ";
        cin >> ID;
        cin.ignore();  
        cout << "Enter Item Name: ";
        getline(cin, name);
        cout << "Enter Quantity Available: ";
        cin >> quantity;
        cout << "Enter Price per Item: ";
        cin >> price;
        totalPrice = quantity * price; 
    }

    // Method to display item details
    void putData() const {
        cout << "\nItem ID: " << ID << endl;
        cout << "Item Name: " << name << endl;
        cout << "Quantity Available: " << quantity << endl;
        cout << "Price per Item: $" << price << endl;
        cout << "Total Value in Stock: $" << totalPrice << endl;
    }

    // Method to process a sale
    void processSale() {
        int soldQuantity;
        cout << "\nEnter Quantity to Sell: ";
        cin >> soldQuantity;

        if (soldQuantity <= 0) {
            cout << "Invalid quantity. Must be greater than zero." << endl;
            return;
        }

        if (soldQuantity > quantity) {
            cout << "Error: Not enough stock to fulfill the sale!" << endl;
        } else {
            quantity -= soldQuantity;
            totalPrice = quantity * price;
            cout << "Sale processed successfully!" << endl;
            cout << "Remaining Quantity: " << quantity << endl;
            cout << "Total Value in Stock: $" << totalPrice << endl;
        }
    }

    // Method to add stock 
    void addStock() {
        int addedQuantity;
        cout << "\nEnter Quantity to Add to Stock: ";
        cin >> addedQuantity;

        if (addedQuantity <= 0) {
            cout << "Invalid quantity. Must be greater than zero." << endl;
            return;
        }

        quantity += addedQuantity;
        totalPrice = quantity * price;
        cout << "Stock updated successfully!" << endl;
        cout << "New Quantity Available: " << quantity << endl;
        cout << "Total Value in Stock: $" << totalPrice << endl;
    }
};

int main() {
    int n;
    cout << "------ Welcome to the Inventory Management System ------" << endl;
    cout << "How many items do you want to enter? ";
    cin >> n;

    Store items[n];

    // Input data for multiple items
    for (int i = 0; i < n; i++) {
        cout << "\nEntering details for Item " << (i + 1) << ":" << endl;
        items[i].getData();
    }

    int choice;
    do {
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. View Item Details\n";
        cout << "2. Process Sale\n";
        cout << "3. Add New Stock\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < n; i++) {
                    cout << "\nItem " << (i + 1) << " Details:";
                    items[i].putData();
                }
                break;
            }

            case 2: {
                int itemIndex;
                cout << "Enter Item Index to Process Sale (1-" << n << "): ";
                cin >> itemIndex;

                if (itemIndex >= 1 && itemIndex <= n) {
                    items[itemIndex - 1].processSale();
                } else {
                    cout << "Invalid item index!" << endl;
                }
                break;
            }

            case 3: {
                int itemIndex;
                cout << "Enter Item Index to Add Stock (1-" << n << "): ";
                cin >> itemIndex;

                if (itemIndex >= 1 && itemIndex <= n) {
                    items[itemIndex - 1].addStock();
                } else {
                    cout << "Invalid item index!" << endl;
                }
                break;
            }

            case 4:
                cout << "Thank you for using the Inventory Management System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
