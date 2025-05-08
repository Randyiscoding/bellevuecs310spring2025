
//Created by Randy Easton
//Derived from code based on w3schools
//Three very easy problems in this code
#include <iostream>

using namespace std;

class School {
public:
    void Studenttype() {
        cout << "This is a student \n";

};

class Freshman public School {
public:
    void Studenttype() {
        cout << "This is a Freshman Student \n";
    }
};

class Senior{
public:
    void Studenttype() {
        cout << "This is a Senior Student \n";
    }
};

int main() {
    School mySchool;
    Freshman myFreshman;
    Senior mySenior;

    mySchool.Studenttype();
    myFreshman.Studenttype();
    mySenior.Studenttype();

    return 0;
}