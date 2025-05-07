#include <iostream>
using namespace std;

int main() {
    int m1, m2;
    cout << "Enter the size of first array: ";
    cin >> m1;
    cout << "Enter the size of second array: ";
    cin >> m2;

    int *ptr1 = new int[m1];
    int *ptr2 = new int[m2];

    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < m1; i++) {
        cin >> ptr1[i];
    }

    cout << "Enter elements of second sorted array:\n";
    for (int j = 0; j < m2; j++) {
        cin >> ptr2[j];
    }

    int *merged = new int[m1 + m2];
    int i = 0, j = 0, k = 0;

    // Merge two sorted arrays correctly
    while (i < m1 && j < m2) {
        if (ptr1[i] < ptr2[j]) {
            merged[k++] = ptr1[i++];
        } else {
            merged[k++] = ptr2[j++];
        }
    }

    // Copy remaining elements
    while (i < m1) {
        merged[k++] = ptr1[i++];
    }
    while (j < m2) {
        merged[k++] = ptr2[j++];
    }

    cout << "Merged sorted array:\n";
    for (int x = 0; x < (m1 + m2); x++) {
        cout << merged[x] << " ";
    }
    cout << endl;

    delete[] ptr1;
    delete[] ptr2;
    delete[] merged;

    return 0;
}
