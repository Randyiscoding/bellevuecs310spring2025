/*
Created by Randy Easton for CS310 on 4/21/2025
Assignment Title: Module 6: Ch08Exercise07.cpp
Revised 05/09/2025 Module 10: Ch12Exercise03
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
 string vowels = "0123456789!@#$%^&*()-_=+\|[]{};:/?.>";
 for (char charc : input) {
  if (vowels.find(charc) == string::npos) {
   ;
  }
  else {
   return -1;
  }
 }
 return 0;
}



int main() {
 int numCanidates = 0;
 string strinput;
 int intinput= 0;
 int vote_count = 0;

 cout << "How Many Candidates Will be Participating in this Election? (at least 2 candidates must participate) " << endl;
 while (true) {
  if (cin >> numCanidates && numCanidates > 1) {
   break; // valid input
  }
  else {
   cin.clear(); // clear error flags
   cin.ignore(10000, '\n'); // discard invalid input
   cout << "Invalid input. We need at least 2 participants." << endl;
  }
 }
 string canidates[3][numCanidates];
 for (int x = 0; x < numCanidates; x++) {
  // Error Handling for names
  cin.clear(); // clear error flags
  cin.ignore(10000, '\n'); // discard invalid input
  while (true) {
   cout << "Candidate name (" << x + 1 << " of "<< numCanidates << "): " << endl;
   getline(cin, strinput);
   if (!strinput.empty() && count_vowels(strinput) == 0 ) {
    canidates[0][x] = strinput;
    break; // exit name input loop
   }
   else {
    cout << "Invalid input. Please enter a valid candidate name. (Press Enter To Continue)\n";
    cin.clear();
    cin.ignore(10000, '\n');
   }
  }
  while (true) {
   cout << "How many votes did " << strinput << " receive: ";
   if (cin >> intinput && intinput >= 0) {
    canidates[1][x] = to_string(intinput);
    break; // valid input
   }
   else {
    cout << "Invalid input. Please enter a positive whole number.\n";
    cin.clear(); // reset error flags
    cin.ignore(10000, '\n'); // discard bad input
   }
  }
 }


 for (int x = 0; x < numCanidates; x++) {
  vote_count += stoi(canidates[1][x]);
 }
 for (int x = 0; x < numCanidates; x++) {
  canidates[2][x] = to_string(100 * (stod(canidates[1][x])/vote_count))+"%";
 }

 cout << "Canidates win totals" << endl;
 cout <<"Canidate Name:" << std::setw(30) <<  "Vote Numbers: " << std::setw(30) <<  "Percentage of votes: " << endl;
 for (int x = 0; x < numCanidates; x++) {
  cout << canidates[0][x] << std::setw(35) <<std::right << canidates[1][x] << std::setw(35) << std::right << canidates[2][x] << endl;
 }
 cout << "Total votes: " << vote_count << endl;


 return EXIT_SUCCESS;
}
