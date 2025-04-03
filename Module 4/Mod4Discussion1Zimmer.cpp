/*
Student's Name: Eric Zimmer
Date: 04/01/2025
File Name: M4_Discussion.cpp
Description: This program creates a vector containing numbers that are not sorted.
It prints those numbers, sorts them using Bubble Sort, and then prints the sorted list.
It has errors. Find them. (<-- lmao this felt..threatening hahaha)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // List of numbers to sort
    vector<double> numList = {5, 3, 7, 1, 9, 4, 2, 8, 10, 6};

    // Print list of numbers before sorting
    cout << "List of numbers before sorting: ";
    for (double num : numList) {
        cout << num << ", "; //added comma seperation for asthetics. not needed and with the comma after 6 i understand why you didnt but <shrugs> didn't hurt so.
    }
    cout << endl;

    // Get size of numList
    int n = numList.size();

    // Sort the list of numbers using Bubble Sort
    for (int i = 0; i < n - 1; i++) { //Did not need "==" because you are just initializing an anonymouse variable. Also j was undeclared so I changed it to I because I assume thats what you meant to do here
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) { //forgot the j in j++ to increment j up
            if (numList[j] > numList[j + 1]) {
                double temp = numList[j];
                numList[j] = numList[j + 1];
                numList[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            continue;
        }
    }

    // Print the list of numbers after sorting
    cout << "List of numbers after sorting: ";
    int index = 0;
    while (index < n) { //parenthesis required around expresions
        cout << numList[index];
        if ( index < n - 1) {
            cout << ", ";
        }
        index++;
    }
    cout << endl;

    return 0;
}