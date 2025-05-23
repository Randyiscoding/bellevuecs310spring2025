//
// Created by Randy Easton on 5/22/2025.
//

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;
class negativeNumber : public exception {
    const char* what() const noexcept override {
        return "Number cannot be negative.";
    }
};

class nonNumber : public exception {
    const char* what() const noexcept override {
        return "Input must be a numeric value.";
    }
};
template <typename T>
double inches_to_centimeters(T inches) {
    if (inches < 0) {
        throw negativeNumber();
    }

    return inches * 2.54;
}

int main() {
    int input = 0;
    int inches = 0;
    double cent = 0;
    cout << "Welcome and Thank you for using the Converter" << endl;
    cout << "We Will convert length in feet and inches to centimeters" <<endl;

    while (true) {
        try {
            cout << "First, enter the length in feet *If you only have inches enter ""0"" for feet)" << endl;
            if (!(cin >> input)) {
                cin.clear();
                cin.ignore(10000, '\n');
                throw nonNumber();
            }
            if (input < 0) throw negativeNumber();
            inches = input * 12;
            break;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    while (true) {
        try {
            cout << "Enter the length in inches" << endl;
            if (!(cin >> input)) {
                cin.clear();
                cin.ignore(10000, '\n');
                throw nonNumber();
            }
            if (input < 0) {
                throw negativeNumber();
            }
            inches += input;
            cent = inches_to_centimeters(inches);
            cout << fixed << setprecision(2) << cent << " cm" << endl;
            break;
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return EXIT_SUCCESS;
}