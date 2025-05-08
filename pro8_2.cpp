//Yash Gohel-24CE035
//Program No: 8.2
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string text;
    cout << "Enter a sentence: ";
    getline(cin, text);

    map<string, int> wordFrequency;
    stringstream ss(text);
    string word;

    while (ss >> word) {
        wordFrequency[word]++;
    }

    cout << "Word Frequency Distribution:\n";
    for (const auto& entry : wordFrequency) {
        cout << entry.first << " : " << entry.second << endl;
    }

    return 0;
}
