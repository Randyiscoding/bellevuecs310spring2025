/*
Created by Randy Easton for CS310 on 4/11/2025
Assignment Title: Module 6: Ch07Exercise04.cpp
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int checkstring(string check) {
  const char* c_str = check.c_str(); // Gets C-style string (null-terminated)
  int length = check.length(); //gets length of string

  if (c_str[length] == '\0') { return 0; } //checks if string is null terminated
  else {return -1;}
  }


string remove_vowels(string input) {
/*
Function checks each character in the input, looks for each character in the input in the list of vowels
returns "npos" if no character is found (characters that are npos are not vowels) and, adds them to a string
  */
  string adjusted;
  string vowels = "aeiouAEIOU";
  for (char charc : input) {
    if (vowels.find(charc) == string::npos) {
      adjusted += charc;
    }
  }
  return adjusted;
}

string remove_vowels_substr(string input) {
  vector<string> vowels = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"};
  for (string x : vowels) {
    while (input.find(x) != string::npos) {
      int fpos = input.find(x);
      string sub = input.substr(fpos+1, input.length() - 1);
      input.erase(fpos);
      input.append(sub);
    }
  }
  return input;
}
int main(){

  string strInput;
  cout << "Enter any string: ";
  getline(cin, strInput); // captures input including whitespace

  if (strInput.empty()){ //checks if string is empty
    cout << "you did not input anything" << endl;
  }
  else if (checkstring(strInput) == 0) { //checks if string is null-terminated
    string is_copy = remove_vowels_substr(strInput);
    if (is_copy == strInput){
      cout << "No Vowels found in string" << endl;
    }
    else { cout << is_copy << endl;}
  }
  else {cout << "Bad input try again" << endl;}

  return EXIT_SUCCESS;
}
