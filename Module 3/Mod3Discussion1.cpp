//
// Created by Randy Easton on 3/27/2025.
// Intentionally doesn't work
//
#include <iostream>

using namespace std;

int main() {
    int number;

    // Prompt user for input
    cout << "Enter a number: ";
    cin >> number;


    if {number > 10}
        cout << "The number is greater than 10." << endl;
    else
        cout << "The number is 10 or less." << endl;

    // Selection control statement using switch
    switch number {
        case 5:
            cout << "You entered five!" << endl;
        break;
        case 10:
            cout << "You entered ten!" << endl;

        default:
            cout << "You entered something else." << endl;
    }

}