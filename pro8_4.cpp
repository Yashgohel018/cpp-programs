//Yash Gohel-24CE035
//Program No: 8.4
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<pair<string, int>> students;
    string name;
    int score;

    cout << "Enter student names and scores:\n";
    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        students.push_back({name, score});
    }

    cout << "Ranked List:\n";
    for (const auto& student : students) {
        cout << student.first << " : " << student.second << endl;
    }

    return 0;
}

