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
    int inches = 0;
    double cent = 0;
    while (true) {
        if (!(cin >> inches)) {
            cerr << "Invalid input. Please enter a numeric value.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        else {
            try {
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