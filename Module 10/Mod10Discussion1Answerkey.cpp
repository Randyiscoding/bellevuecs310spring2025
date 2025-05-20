/*
Created by Randy Easton for CS310
Week 10 Discussion Board – Pointer Errors Example
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
    int people;
    int* numCandidates = &people;
    *numCandidates = 3;  // ❌ ERROR #1: Dereferencing a null pointer — causes segmentation fault

    string* candidateNames = new string[*numCandidates]; // will fail if error #1 not fixed
    int* candidateVotes = new int[*numCandidates];

    string nameInput;
    int voteInput;

    for (int i = 0; i < *numCandidates; ++i) {
        cout << "Enter name for candidate #" << i + 1 << ": ";
        getline(cin, nameInput);
        while (count_vowels(nameInput) == -1) {
            cout << "Invalid name. Try again: ";
            getline(cin, nameInput);
        }

        *(candidateNames + i) = nameInput;

        cout << "Enter votes for " << nameInput << ": ";
        cin >> voteInput;
        cin.ignore(10000, '\n'); //Error 2 Super Hard

        *(candidateVotes + i) = voteInput;
        *(candidateNames + i) = nameInput;
    }

    int totalVotes = 0;
    for (int i = 0; i < *numCandidates; ++i) {  // ❌ ERROR #3: Off-by-one error — will access out-of-bounds memory
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
