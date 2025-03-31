//
// Created by Randy Easton on 3/31/2025.
// Hint: there are 4 errors, 2 Easy, 1 medium, 1 Hard GL

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Variables
    int num;
    vector<int> numbers;
    string userName;

    // Input
    cout << "Enter your first name: ";
    cin >> userName;

    cout << "Enter a number (enter -1 to stop): ";
    while (num != -1)
        cin >> num;
        numbers.push_back(num);
    }

    cout << "You entered " << numbers.size() << " numbers." << endl;

    // Output numbers using a loop
    cout << "Here are your numbers: ";
    for (int i = 0; i <= numbers.size(); i++) {
        cout << numbers[x] << " ";
    }

    cout << endl;
    return 0;
}