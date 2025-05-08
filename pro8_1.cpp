//Yash Gohel-24CE035
//Program No: 8.1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;
    int n, input;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        numbers.push_back(input);
    }

    reverse(numbers.begin(), numbers.end());

    cout << "Reversed sequence: ";
    for (const int& num : numbers) {
        cout << num << " ";
    }

    return 0;
}
