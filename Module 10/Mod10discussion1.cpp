/*
Created by Randy Easton for CS310
Week 10 Discussion Board – Pointer Errors Example
Contains 3 Erros
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function to validate names (same as your original)
int count_vowels(string input) {
    string vowels = "0123456789!@#$%^&*()-_=+\\|[]{};:/?.>";
    for (char charc : input) {
        if (vowels.find(charc) != string::npos) {
            return -1;
        }
    }
    return 0;
}

int main() {
    int* numCandidates = nullptr;
    *numCandidates = 3;

    string* candidateNames = new string[*numCandidates];
    int* candidateVotes = new int[*numCandidates];

    string nameInput;
    int voteInput; //hint 2 things can look the same and not mix

    for (int i = 0; i < *numCandidates; ++i) {
        cout << "Enter name for candidate #" << i + 1 << ": ";
        getline(cin, nameInput);
        while (count_vowels(nameInput) == -1) {
            cout << "Invalid name. Try again: ";
            getline(cin, nameInput);
        }

        *(candidateNames + i) = nameInput;

        cout << "Enter votes for " << nameInput << ": ";
        cin >> *(candidateVotes + i);
    }

    int totalVotes = 0;
    for (int i = 0; i <= *numCandidates; ++i) {
        totalVotes += *(candidateVotes + i);
    }

    cout << "\nElection Results:\n";
    for (int i = 0; i < *numCandidates; ++i) {
        double percent = (double)(*(candidateVotes + i)) / totalVotes * 100;
        cout << setw(20) << *(candidateNames + i)
             << setw(10) << *(candidateVotes + i)
             << setw(10) << fixed << setprecision(2) << percent << "%" << endl;
    }

    delete[] candidateNames;
    delete[] candidateVotes;

    return 0;
}
