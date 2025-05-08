//Yash Gohel-24CE035
//Program No: 8.5
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    map<string, vector<string>> directory;
    int choice;
    string folder, file;

    while (true) {
        cout << "\n1. Create folder\n2. Add file to folder\n3. Display directory\n4. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter folder name: ";
            getline(cin, folder);
            directory[folder]; // Creates an empty folder
        } else if (choice == 2) {
            cout << "Enter folder name: ";
            getline(cin, folder);
            cout << "Enter file name: ";
            getline(cin, file);
            directory[folder].push_back(file);
        } else if (choice == 3) {
            cout << "\nDirectory Structure:\n";
            for (const auto& entry : directory) {
                cout << entry.first << ":\n";
                for (const string& file : entry.second) {
                    cout << "  - " << file << endl;
                }
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
