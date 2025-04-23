/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M7: Discussion
Professor:      Dr. Robert Flowers
Date:           04/22/2025
File Name:      M7_Discussion.cpp
Description:    This program uses a 2D array to print a grid of size 10 x 10. It then
asks the user which row and column to mark an 'x' in the grid, then prints the grid
with the 'x' in the correct location.
It has four errors. Find them.

Developed and tested (before errors) in Visual Studio 2022 (Windows).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

#include <iostream>
#include <limits>

using namespace std;

int main() {
    const int GRID_ROWS = 10;
    const int GRID_COLS = 10;
    // Create a 10 x 10 grid
    char grid[GRID_ROWS][GRID_COLS] = {};
    // Print message
    cout << "Current grid contents:" << endl;
    // Fill grid with 'o' and print it
    for (size_t r = 0; r < GRID_ROWS; r++) { // "r++" not "r+" to iterate r
        for (size_t c = 0; c < GRID_COLS; c++) {
            grid[r][c] = 'o';
            cout << grid[r][c];
        }
        cout << "\n";
    }

    // Get row position from user
    int row = 0;
    cout << "\nPlease enter the row you want the 'x' placed as a whole number 1-" << GRID_ROWS << " (inclusive):" << endl;
    // Keep asking for input until input is valid
    while (!(cin >> row) || row < 1 || row > GRID_ROWS) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid row as a whole number 1-" << GRID_ROWS << " (inclusive):" << endl;
    }

    // Get column position from user
    int col = 0;
    cout << "\nPlease enter the column you want the 'x' placed as a whole number 1-" << GRID_COLS << " (inclusive):" << endl;
    // Keep asking for input until input is valid
    while (!(cin >> col) || col < 1 || col > GRID_COLS) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid column as a whole number 1-" << GRID_COLS << " (inclusive):" << endl;
    }

    // Assign 'x' to given position
    grid[row-1][col-1] = 'x'; //x position was one off

    // Print message
    cout << "\nGrid with 'x' at input location:" << endl;

    // Print the grid using 'o' for every position, but
    // put 'x' at the given position
    for (size_t r = 0; r < GRID_ROWS; r++) { // <= will cause array access out-of-bound issues
        for (size_t c = 0; c < GRID_COLS; c++) { // <= will cause array access out-of-bound issues
            cout << grid[r][c]; //fixed row and collumn display
        }
        cout << "\n";
    }

    return 0;
}