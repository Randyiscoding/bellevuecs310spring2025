#include <iostream>
using namespace std;

int main() {
    int number = 0; //Gotta initialize your variables
    cout << "Enter a number: ";
    cin >> number;

    if (number > 0) { //Expressions should be fully wrapped in parentheses'
        cout << "The number is positive." << endl;
    }
    else {
        cout << "The number is non-positive." << endl;
    }

// Yeah i dont even know why this was here, so I'm just commenting it out. Normally though i would have just erased this aha
//    if (result == 1) {
//        cout << "Result is 1." << endl;
//    }
    
    return 0;
}