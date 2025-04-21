/*
Created by Randy Easton for CS310 on 4/21/2025
Assignment Title: Module 6: Ch07Exercise04.cpp
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int count_vowels(string input) {
 /*
 Function checks each character in the input, looks for each character in the input in the list of vowels
 returns "npos" if no character is found (characters that are npos are not vowels) and, adds them to a string
   */
 int adjusted = 0;
 string vowels = "0123456789";
 for (char charc : input) {
  if (vowels.find(charc) != string::npos) {
   return 0;
  }
  else {
   return -1;
  }
 }
}



int main() {
 string canidates[3][5] /*= {
  {"Johnson", "Miller", "Duffy", "Robinson", "Ashtony"},
  {"5000", "4000", "6000", "2500", "1800"}
 }*/; // 3 rows of 5 for the array, index 0 (aka row 1) is canidates name, index 1 (aka row 2) is vote count index 2 (row 3) for percentage
 string strinput;
 int intinput= 0;
 int vote_count = 0;

 for (int x = 0; x < 5; x++) {
  // Error Handling for names
  while (true) {
   cout << "Candidate name (" << x + 1 << " of 5): ";
   cin >> strinput;
   if (!strinput.empty() && count_vowels(strinput) == 0 ) {
    canidates[0][x] = strinput;
    break; // exit name input loop
   } else {
    cout << "Invalid input. Please enter a valid candidate name.\n";
    cin.clear();
    cin.ignore(10000, '\n');
   }
  }

  //Error Checking for Numerical inputs
  while (true) {
   cout << "How many votes did " << strinput << " receive: ";
   cin >> intinput;
   if (!cin.fail() && intinput >= 0) {
    canidates[1][x] = to_string(intinput);
    break; // exit vote input loop
   } else {
    cout << "Invalid input. Please enter a positive whole number.\n";
    cin.clear(); // reset error flags
    cin.ignore(10000, '\n'); // discard bad input
   }
  }
 }
  for (int x = 0; x < 5; x++) {
  vote_count += stoi(canidates[1][x]);
 }
 for (int x = 0; x < 5; x++) {
  canidates[2][x] = to_string(100 * (stod(canidates[1][x])/vote_count))+"%";
 }

 cout << "Canidates win totals" << endl;
 cout <<"Canidate Name:" << std::setw(30) <<  "Vote Numbers: " << std::setw(30) <<  "Percentage of votes: " << endl;
 for (int x = 0; x < 5; x++) {
  cout << canidates[0][x] << std::setw(35) <<std::right << canidates[1][x] << std::setw(35) << std::right << canidates[2][x] << endl;
 }
 cout << "Total votes: " << vote_count << endl;


 return EXIT_SUCCESS;
}