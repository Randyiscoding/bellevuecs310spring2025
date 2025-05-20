//
// Created by Randy Easton on 05/19/2025.
//

#include <iostream>
#include <iomanip>
#include <random>

using namespace std;
int main() {
    //Shout-out to me for using this in week 8's assignment lol
    //Seed the random number generator
    random_device rd;
    mt19937 seed(rd());
    int min_val = 10; //floor number to pick
    int max_val = 100; //ceiling number to pick

    // Create a uniform distribution within the range
    uniform_int_distribution<int> dist(min_val, max_val);

    for (int x = 0; x < 25; x++) {
        // Generate and print the random number
        int random_number = dist(seed);
        cout << random_number << endl;
    }


    return EXIT_SUCCESS;
}