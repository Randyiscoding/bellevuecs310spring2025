//
// Created by Randy Easton on 3/7/2025.
//

/*
Write a C++ program that prompts the user to input the elapsed time for
an event in seconds. The program then outputs the elapsed time in hours,
minutes, and seconds. (For example, if the elapsed time is 9630 seconds,
then the output is 2:40:30.)

 */
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
int main(){
    //Variables
    double dblTime = 0;
    string strTruetime = "";

    //Inputs
    cout << "Time in seconds" << endl;
    cin >> dblTime;

    //Calculations
    double dblHours = dblTime / 3600;
    double fractional = dblHours - floor(dblHours);
    int intHours = dblHours;

    double dblMinutes = fractional * 60;
    fractional = dblMinutes - floor(dblMinutes);
    int intMinutes = dblMinutes;

    double dblSeconds = fractional * 60;
    fractional = dblSeconds - floor(dblSeconds);
    int intSeconds = dblSeconds;

    strTruetime = to_string(intHours)+":"+to_string(intMinutes)+":"+to_string(intSeconds);
    cout << strTruetime << endl;



    system("PAUSE");
    return EXIT_SUCCESS;
} 