//Yash Gohel-24CE035
//Program No: 7.3
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to add a new item to the inventory file
void addItem() {
    ofstream file("inventory.txt", ios::app);
    if (!file) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;

    file << name << "," << quantity << "," << price << endl;
    file.close();
    cout << "Item added successfully!" << endl;
}

// Function to view all inventory items
void viewInventory() {
    ifstream file("inventory.txt");
    if (!file) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    cout << "Inventory List:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    file.close();
}

// Function to search for an item by name
void searchItem() {
    ifstream file("inventory.txt");
    if (!file) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string searchName, name;
    int quantity;
    double price;
    bool found = false;

    cout << "Enter item name to search: ";
    cin.ignore();
    getline(cin, searchName);

    while (file >> name >> quantity >> price) {
        if (name == searchName) {
            cout << "Item Found:\n";
            cout << "Name: " << name << ", Quantity: " << quantity << ", Price: " << price << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Item not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewInventory(); break;
            case 3: searchItem(); break;
            case 4: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
