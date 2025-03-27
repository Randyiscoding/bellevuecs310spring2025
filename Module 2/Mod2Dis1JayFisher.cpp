//Corrected Code for Jay Fisher by Randy Easton

/*
*Student Name: Jay Fisher
*File Name: Ch02Exercise13.cpp
*Data: 03/11/2025
*/

//  include <iostream> is used for inputs and outputs and <conio.h> is used for a press any key function _getch() 
#include <iostream>
#include <conio.h>

//  namespaces are used to group items much like a class or function
//  std is a namespace from <iostream> library
using namespace std;

int main() {
    
    //  declare variables
    string name; // Changed from char to string so that full name displays, instead of single character
    //This also for some reason fixed the automatic jump in the if/else statement
    int age, math1, math2, math3;

    //  Askin a series of math questions with inputs and outputs.  Using if/else statements to see if user is correct.
    cout << "\n\n  Welcome to math quiz";
    cout << "\n\n  What is first your name? ";
    cin >> name;
    cout << "\n  Hello " << name << ", lets get started with an easy math problem.";
    cout << "\n\n  What is 4 x 8? ";
    cin >> math1;

    if (math1 == 32) {
        cout << "\n  Great job, let's try a harder one.  What is 22 X 54? ";
        cin >> math2;
    }
    else {
        cout << "\n  Sorry, thanks for playing.";
        _getch();
        return 0;
    }
    if (math2 == 1188) {
        cout << "\n  Your good at math, lets try one more just to test your skills.";
        cout << "\n\n  What is the positive value for x?  (x ^ 2 + 5x - 84 = 0) "; // <--colon instead of semi-colon used here
        cin >> math3;
    }
    else {
        cout << "\n  Good try, maybe next time.";
        _getch();
        return 0;
    }
    if (math3 == 7) {
        cout << "\n  Your a superstar, thanks for showing your skills on the math test.";
        return EXIT_SUCCESS; //Added to automatically end the program/session
    }
    else {
        cout << "\n  Well, you came close, better luck next time.";
        _getch();
        return 0;
    }
    /*
    Removed below to accompany the exit return within the final if statement
    _getch();

    return 0;
    */
  
}
