#include <iostream> //include statements require # sign in front of them to call them
using namespace std;

// Function to calculate how much this sucks (it always sucks 100%)
int how_much_suck(int num) { //Parenthesis not braceses
    return num + (100 - num); //Missing semi-colon
}

int main() {
    int sucks;

    // Input
    cout << "How much does this suck? Enter a number from 1 to 100: ";
    /* Code ask for a number between 1 and 100, there is no safeguard for
    putting a number more than 100  or less than 1. Fortunately, the code
    works as expected regardless, so i did not provide a fix but this is
     or could be an issue */
    cin >> sucks;
    //cout << endl; is unneeded

    // Output
    cout << "Yeah! This sucks " << how_much_suck(sucks) << "%." << endl;

    return 0;
}