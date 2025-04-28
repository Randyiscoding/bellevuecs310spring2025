/*
Created by Randy Easton for CS310 on 4/21/2025
Assignment Title: Week 7 Discussion - Simple 2D Array Program with Errors
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a 2D array to store 3 students and their 2 test scores
    int testScores[3][2];

    // Loop through students and input scores
    for (int i = 0; i < 3; i++) {
        cout << "Enter test score 1 for student " << i + 1 << ": ";
        cin >> testScores[i][0];

        cout << "Enter test score 2 for student " << i + 1 << ": ";
        cin >> testScores[i][1];
    }

    // Display test scores
    for (int i = 0; i < 3; i++) {
        cout << "Student #" << i + 1 << " scores: ";
        cout << testScores[i][0] << " and " << testScores[i][1] << endl;
    }

    return 0;
}//
// Created by spy__ on 4/23/2025.
//
