//
// Created by Randy Easton on 4/7/2025.
// Hint: There are 5 errors (3 Easy, 1 Medium, 1 Hard) – Happy Debugging!
//

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

string IRS(double income, double time, double hourlyRate) {
    double billingAmount;

    if (income <= 25000 & time <= 30) {
        billingAmount = 0;
    }
    else if (income <= 25000 & time > 30)
        billingAmount = (hourlyRate * 0.40) * ((time - 30) / 60);
    else if (income > 25000 & time <= 1.20) {
        billingAmount = 0;
    }
    else {
        billingAmount = (hourlyRate * 0.70) * ((time - 2.20) / 60);
    }

    return billingAmount;
}

int main() {
    double income, time, rate;
    double price = IRS(income, time);

    cout << "Enter your hourly consultation rate: $";
    cin >> rate;

    cout << "Enter total consultation time in minutes: ";
    cin >> time;

    cout << "Enter your total income: $";
    cin >> income;


    cout << "You owe the IRS: $" << price << endl;

    return EXIT_SUCCESS;
}