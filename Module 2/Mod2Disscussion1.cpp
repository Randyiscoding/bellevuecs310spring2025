//
// Created by Randy Easton on 3/11/2025.
//

/*
Create a simple C++ program using input/output processes and at least two errors.
The program should not execute and there should be at least two errors in the code.
 */


#include <iostream>
#include <iomanip>
#include <ios>

using namespace stad;
int main(){
   string name;
   int age;

   // Prompting user for input
   cout << "Enter your name: ";
   cin >> name;
   cout << "Enter your age: ";
   cin >> age;

   // Intentional Errors
   cout << "Hello, " << name << "! You are " << age << " years old." << endl
   cout.precision(2);
   cout.imbue(locale("en_US.UTF-8"));
   cout << "America Owes you the worker at least: " << showbase << put_money("123456789") << '\n';

}