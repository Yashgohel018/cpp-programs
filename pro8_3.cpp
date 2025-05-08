//Yash Gohel-24CE035
//Program No: 8.3
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, input;
    set<int> uniqueTransactions;

    cout << "Enter number of transaction IDs: ";
    cin >> n;

    cout << "Enter the transaction IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        uniqueTransactions.insert(input);
    }

    cout << "Unique transaction IDs (sorted): ";
    for (const int& id : uniqueTransactions) {
        cout << id << " ";
    }

    return 0;
}
