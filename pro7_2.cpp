//Yash Gohel-24CE035
//Program No: 7.2
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {

  // ifstream()

    ifstream file("type.txt");

    if (!file) {
        cerr << "Error: Cannot open file.\n";
        return 1;
    }

    string line;
    size_t lineCount = 0, wordCount = 0, charCount = 0;

    while (getline(file, line)) {
        ++lineCount;
        charCount += line.length() + 1; // +1 for the newline character

        istringstream ss(line);
        string word;
        while (ss >> word) {
            ++wordCount;
        }
    }

    file.close();

    cout << "\n--- File Statistics ---\n";
    cout << "Lines     : " << lineCount << "\n";
    cout << "Words     : " << wordCount << "\n";
    cout << "Characters: " << charCount << "\n";

    return 0;
}