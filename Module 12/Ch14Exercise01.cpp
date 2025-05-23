//
// Created by Randy Easton on 5/22/2025.
//

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

template <typename T>
double inches_to_centimeters(T inches) {
    if (inches < 0) {
        throw invalid_argument("Number cannot be negative");
    }

    return inches * 2.54;
}

int main() {
    int input = 0;
    int inches = 0;
    double cent = 0;
    cout << "Welcome and Thank you for using the Converter" << endl;
    cout << "We Will convert length in feet and inches to centimeters" <<endl;
    cout << "First, enter the length in feet *If you only have inches enter ""0"" for feet)" << endl;
    while (true) {
        if (!(cin >> input)) {
            cerr << "Invalid input. Please enter a numeric value.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    inches = input*12;
    cout << "Enter the length in inches" << endl;
    while (true) {
        if (!(cin >> input)) {
            cerr << "Invalid input. Please enter a numeric value.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        else {
            try {
                inches += input;
                cent = inches_to_centimeters(inches);
                cout << fixed << setprecision(2) << cent << " cm" << endl;
                break;
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;

            }
        }
    }

    return EXIT_SUCCESS;
}