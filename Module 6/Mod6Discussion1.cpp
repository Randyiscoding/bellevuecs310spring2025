/*
Created by Randy Easton for CS310 on 4/14/2025
Assignment Title: Module 6: Discussion Board
There are 4 errors in this code. Two will prevent Compiling
CMake file in root folder. Makefile currently unavailable.
 */

#include <algorithm>
#include <iostream>

using namespace std;

 vowel_level
    LOW = 7,
    MEDIUM = 14,
    HIGH = 21,
    DANGER = 28
};

int count_vowels(string input) {
    /*
    Function checks each character in the input, looks for each character in the input in the list of vowels
    returns "npos" if no character is found (characters that are npos are not vowels) and, adds them to a string
      */
    int adjusted = 0;
    string vowels = "aeiouAEIOU";
    for (char charc : input) {
        if (vowels.find(charc) != npos) {
            adjusted += 1;
        }
    }
    return adjusted;
}

string get_vowel_level(int count) {
    /*
    Determines the vowel level based on the number of vowels.
    */
    if (count < LOW) return "Very Low";
    else if (count < MEDIUM) return "Low";
    else if (count < HIGH) return "Medium";
    else if (count < DANGER) return "High";
    else return "DANGER";
}

int main() {
    string strInput;
    cout << "Enter a string: " << endl;
    getline(cin, strInput);
    string vowel_count = count_vowels(strInput);
    string level = get_vowel_level(vowel_count);

    cout << "\nYour string contains " << vowel_count << " vowels." << endl;
    cout << "Vowel Level: " << level << endl;

    cout << count_vowels(strInput) << endl;


}