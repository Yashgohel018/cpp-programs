//Yash Gohel-24CE035
//Program No: 7.1
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char paragraph[1000];
    cout << "Enter paragraph: ";
    cin.getline(paragraph, 1000);

    char* words[100];
    int counts[100] = {0};
    int wordCount = 0;

    char* token = strtok(paragraph, " ,.!?");
    while (token) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]); // Convert to lowercase
        }

        int index = -1;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            counts[index]++;
        } else {
            words[wordCount] = new char[strlen(token) + 1];
            strcpy(words[wordCount], token);
            counts[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " ,.!?");
    }

    cout << "Word frequencies:\n";
    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << ": " << counts[i] << endl;
        delete[] words[i]; // Clean up memory
    }

    return 0;
}
