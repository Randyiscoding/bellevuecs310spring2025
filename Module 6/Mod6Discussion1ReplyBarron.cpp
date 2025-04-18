#include <iostream>
#include <string>
#include <bits/stdc++.h> //to use the transform function credit://https://www.geeksforgeeks.org/convert-cpp-string-to-uppercase/
using namespace std;

enum AccessLevel {GUEST, USER, MODERATOR, ADMIN, DEVELOPER};

int main() {
    string input;
    AccessLevel currentUser;

    cout << "Enter your access level (guest, user, moderator, admin): ";
    cin >> input;
    //added below to ensure that users who use sentence case can still access as needed
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);


    //Conversion to enum type
    if (input == "guest" || input == "GUEST") {
        currentUser = GUEST;
    } else if (input == "user" || input == "USER") {
        currentUser = USER;
    } else if (input == "moderator" || input == "MODERATOR") {
        currentUser = MODERATOR;
    } else if (input == "admin" || input == "ADMIN") {
        currentUser = ADMIN;
    } else if (input == "developer" || input == "DEVELOPER") {
        currentUser = DEVELOPER; //Added Developer as an Access Level
    } else {
        cout << "Invalid access level." << endl;
        return 1;
    }

    //switch case to display access
    switch (currentUser) {
        case GUEST:
            cout << "Limited access granted.\n";
        break;
        case USER:
            cout << "User dashboard access granted.\n";
        break;
        case MODERATOR:
            cout << "Moderator tools unlocked.\n";
        break;
        case ADMIN:
            cout << "Admin panel access granted.\n";
        break;
        case DEVELOPER: //added such that switch statement does not cover the whole range of the 'AccessLevel' enumeration used
            cout << "Full Environment Access Granted\n";
        break;
    }
    return 0;
}