//
// Created by spy__ on 4/27/2025.
//

#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>

using namespace std;

class BankAccount {
    //Random Number generator. credit: Google https://www.google.com/search?q=c%2B%2B+generate+random+12+digit+number&oq=c%2B%2B+generate+random+12+digit+number&gs_lcrp=EgZjaHJvbWUyBggAEEUYOdIBCTEyMzUxajBqN6gCCLACAfEF7V5t0Grwe5E&sourceid=chrome&ie=UTF-8
    int ac_number_gen() {
        // Seed the random number generator
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range for a 12-digit number
        long long min_val = 10000000LL; // Minimum 12-digit number
        long long max_val = 99999999LL; // Maximum 12-digit number

        // Create a uniform distribution within the range
        std::uniform_int_distribution<long long> dist(min_val, max_val);

        // Generate and print the random 8-digit number
        long long random_number = dist(gen);

        return random_number;
    }
    int ac_number = ac_number_gen();


    protected:
        string ac_fname;
        string ac_lname;
        string ac_type;
        int ac_routing = 021000021;
        double ac_balance = 0.00;
        double ac_interest_rate = .00;

    
    public:
        //set
        void set_ac_name(string First_name, string Last_name) {
            ac_fname = First_name;
            ac_lname = Last_name;
        }
        void set_ac_type(int type) {
            if (type == 0){ac_type = "Checking";}
            if (type == 1){ac_type = "Savings";}
            else{ac_type = "unknown";}
        }
        void set_ac_balance(double bal) {
            ac_balance = round(bal * 100.00)/100.00;
        }

        //get
        string get_ac_fname(){return ac_fname;}
        string get_ac_lname(){return ac_lname;}
        int get_ac_number(){return ac_number;}
        int get_ac_routing(){return ac_routing;}
        double get_ac_balance(){return ac_balance;}
        double get_ac_interest(){return ac_interest_rate;}


};

int main() {
    BankAccount newmember;
    string First = "Randy";
    string last = "Easton";
    int accounttype = 1;
    double deposit = 23561.43;

    newmember.set_ac_name(First,last);
    newmember.set_ac_type(accounttype);
    newmember.set_ac_balance(deposit);

    cout << newmember.get_ac_number() << endl;
    cout << newmember.get_ac_fname()+" "+newmember.get_ac_lname() << endl;
    cout << fixed << setprecision(2);
    cout << "$"<<newmember.get_ac_balance() << endl;





    return EXIT_SUCCESS;
}
