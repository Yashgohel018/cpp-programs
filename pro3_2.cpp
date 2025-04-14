//Yash Gohel-24CE035
//Program No. 3.2
#include <iostream>
#include <vector>

using namespace std;

// Iterative function to compute sum of array elements
int iterativeSum( vector<int>& arr)
{
    int sum = 0;
    for (int num : arr)
        sum += num;
    return sum;
}

int main()
{
    int n;

    // Taking user input for array size
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);  // Dynamic array allocation using vector

    // Taking user input for array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Compute sum using both methods
    int sum_iterative = iterativeSum(arr);

    // Displaying results
    cout << "\nResults:\n";
    cout << "Iterative Sum: " << sum_iterative << endl;

    return 0;
}
