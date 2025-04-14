/*
Created by Randy Easton for CS310 on 4/11/2025
Assignment Title: Module 6: Ch07Exercise04.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

int checkstring(string check) {
  const char* c_str = check.c_str(); // Gets C-style string (null-terminated)
  int length = check.length();

  if (c_str[length] == '\0') { return 0; } //checks if string is null terminated
  else {return -1;}
  }


string remove_vowels(string input) {
  string adjusted; //initializes new string
  string vowels = "aeiouAEIOU";
  for (char charc : input) { //Checks each character in the input
    if (vowels.find(charc) == string::npos) { //looks for each character in the input in the list of vowels; returns "npos" if no character is found
      adjusted += charc; //characters that are npos are not vowels and thus can be added to the string
    }
  }
  return adjusted;
}


int main(){

  string strInput;
  cout << "Enter any string: ";
  getline(cin, strInput); // captures input including whitespace

  if (strInput.empty()){
    cout << "you did not input anything" << endl;
  }
  else if (checkstring(strInput) == 0) {
      cout << remove_vowels(strInput) << endl;
    }
  else {cout << "Bad input try again" << endl;}

  return EXIT_SUCCESS;
}
