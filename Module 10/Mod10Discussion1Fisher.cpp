/*
*Student Name: Jay Fisher
*File Name: M10_Discussion.cpp
*Date: 05/15/2025
*Visual C++ 2022   00476 - 80000 - 00000 - AA685
*Microsoft Visual C++ 2022
*/

#include <iostream>
#include <conio.h>

using namespace std;

//  -----------------------------------------------------------------------------------------
//  Program that generates 10 random numbers using a user input seed.
//  Shows how to use dynamic memory allocation with a pointer and deallocation.
//  There are three intentional errors in the code, can you find them?
//  -----------------------------------------------------------------------------------------

//  Random number generator function
int random_gen(unsigned long int& seed, int min, int max) {
    seed = (8976734 * seed + 1098373345) % 2398573634;
    return min + (seed % (max - min + 1));
}

//  Main program
int main() {

	//  Declare variables and using * to create a pointer with dynamic memory allocation
    int ran_num_pnt; //did not need to be a pointer object
    unsigned long int seed;
    ran_num_pnt  = 10; //incorrectltly initllized variable
	//  Used to store the starting address of the dynamic memory for later deallocation
    int* start_ptr = &ran_num_pnt; // initalized the pointer using ran_num
    //ran_num_pnt = nullptr; causes entire program to stop working

	//  Welcoming screen and user input
    cout << "\n\n  Welcome to the Random Number Generator!" << endl;
    cout << "\n  I can generate 10 random numbers for you." << endl;
    cout << "\n  But first I need a seed to start with." << endl;
    cout << "\n  Please enter a seed: ";
	//  Input validation loop
	while (true) {
		if (cin >> seed) {
			break;
		}
		else {
			cout << "  Please enter a valid unsigned long int number: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	//  Screen output
	cout << "\n  Thank you! Your seed is: " << seed << endl;
    cout << "\n  Now I will generate 10 random numbers for you." << endl;
    cout << "\n  Here they are: " << endl;
	//  Calls the random number generator function 10 times and uses ++ to increment the pointer
    for (int i = 0; i < 10; i++) {
        *start_ptr = random_gen(seed, 1, 100); //Bad variable name "seeds" and called incorrect variable for storage
        cout << "\n  " << *start_ptr; //called incorrect variable for storage
        ran_num_pnt++;
    }

    //  End of program screen
    cout << "\n\n  Thank you for using the Random Number Generator!" << endl;
    cout << "\n  Press any key to exit." << endl;
    (void)_getch();

	//  Deallocate the dynamic memory
    //delete start_ptr;

	return 0;
}


