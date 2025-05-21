// Name: Norman Cervantes
// Course: CS 310
// Assignment: Module 10 Discussion, Buggy

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <cstring>
#include <cstdio>

using namespace std;

bool is_vowel(char c) {
    if (tolower(c) == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {return true;}
    return false; //consolidated code for clarity
}

template <typename T>
struct vowel_counter {
    int count(const T input) {
        //removed & operator
        if (input.size() == 0) {throw runtime_error("Empty string");}
        int vowel_count = 0;
        for (size_t i = 0; i < input.size(); ++i) {
            if (is_vowel(input[i])) {vowel_count++;}
            //if (i == input.size()) {return vowel_count;} unneeded and in wrong place
        } //Made sure everything was inside for loop and for loop iterated properly
        if (vowel_count == 0) {throw runtime_error("No vowels");} // Needed to be not outside of for lop to properly work
        else{return vowel_count;}
    }
};

    template <typename T2>
    struct vowel_counter2 {
        int count(T2 input) {
            if (input == nullptr) {
                throw runtime_error("Null string pointer");
            }
            if (input[0] == '\0') {
                throw runtime_error("Empty string");
            }
            int vowel_count = 0;
            bool found_null = false;
            for (int i = 0; i < 100; ++i) {
                if (input[i] == '\0') {
                    found_null = true;
                    break;
                }
                if (is_vowel(input[i])) {
                    vowel_count++;
                }
            }
            if (!found_null) {
                throw runtime_error("Missing null terminator");
            }
            if (vowel_count == 0) {
                throw runtime_error("No vowels");
            }
            return vowel_count;
        }
}; //No semicolon

    int main() {
        vowel_counter2<const char*> vc2; //structs have to be initialized
        vowel_counter<string> vc;
        string test1 = "Hello World";
        string test2 = "";
        string test3 = "Rhythm";
        char broken[] = { 'B','u','g','s', '\0' }; //Needs a null Terminator
        const char* test4 = broken;

        try {
            int count1 = vc.count(test1); //cant intialize struct that way
            cout << "Vowels in \"" << test1 << "\": " << count1 << endl;
        }
        catch (const exception& e) {
            cerr << "Error for test1: " << e.what() << endl;
        }

        try {
            int count2 = vc.count(test2);
            cout << "Vowels in \"" << test2 << "\": " << count2 << endl;
        }
        catch (const exception& e) {
            cerr << "Error for test2: " << e.what() << endl;
        }

        try {
            int count3 = vc.count(test3);
            cout << "Vowels in \"" << test3 << "\": " << count3 << endl;
        }
        catch (const exception& e) {
            cerr << "Error for test3: " << e.what() << endl;
        }

        try {
            int count4 = vc2.count(test4);
            cout << "Vowels in \"" << test4 << "\": " << count4 << endl;
        }
        catch (const exception& e) {
            cerr << "Error for test4: " << e.what() << endl;
        }

        return 0;
}