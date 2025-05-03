//
// Created by Randy Easton on 4/27/2025.
//

#include <iostream>
#include <random>
#include <cmath>
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
class BankAccount {
    static int ac_numbergen;
    //Random Number generator. credit: Google https://www.google.com/search?q=c%2B%2B+generate+random+12+digit+number&oq=c%2B%2B+generate+random+12+digit+number&gs_lcrp=EgZjaHJvbWUyBggAEEUYOdIBCTEyMzUxajBqN6gCCLACAfEF7V5t0Grwe5E&sourceid=chrome&ie=UTF-8
    int ac_route_gen() {
        // Seed the random number generator
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range for a 9-digit number
        long long min_val = 100000000LL; // Minimum 12-digit number
        long long max_val = 999999999LL; // Maximum 12-digit number

        // Create a uniform distribution within the range
        std::uniform_int_distribution<long long> dist(min_val, max_val);

        // Generate and print the random 9-digit number
        long long random_number = dist(gen);

        return random_number;
    }


    protected:
        string ac_fname;
        string ac_lname;
        string ac_type;
        int ac_number = ac_numbergen++;
        int ac_routing = ac_route_gen();
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
    void set_ac_interest_rate(int credit_score) {
            if (credit_score <= 500) {ac_interest_rate = .29;}
            else if (credit_score >= 850) {ac_interest_rate = .01;}
            else {ac_interest_rate = .29 - ((0.28/349)*(credit_score - 501));
            }
        }

        //get
        string get_ac_fname(){return ac_fname;}
        string get_ac_lname(){return ac_lname;}
        string get_ac_type(){return ac_type;}
        int get_ac_number(){return ac_number;}
        int get_ac_routing(){return ac_routing;}
        double get_ac_balance(){return ac_balance;}
        double get_ac_interest(){return ac_interest_rate;}


};
int BankAccount::ac_numbergen = 100000000;
int main() {
    BankAccount newmembers[10];

    string First;
    string last;
    int accountType = 10;
    double deposit = 0.00;
    int credit_score = 0;


    for (int i = 0; i < 10; i++) {
        cout << "\nSetting up account #" << i + 1 << endl;

        cout << "Enter first name: ";
        cin >> First;
        while (First.empty() || count_vowels(First) == -1) {
            cout << "First name cannot be empty or contain special characters. Please re-enter: ";
            cin >> First;
        }
        cout << "Enter last name: ";
        cin >> last;
        while (last.empty() || count_vowels(last) == -1) {
            cout << "First name cannot be empty or contain special characters. Please re-enter: ";
            cin >> last;
        }
        cout << "Enter account type (0 for Checking, 1 for Savings): ";
        while (!(cin >> accountType) || (accountType != 0 && accountType != 1)) {
            cout << "Invalid input. Please enter 0 for Checking or 1 for Savings: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "Enter Your credit Score: ";
        while (!(cin >> credit_score) || credit_score < 0 || credit_score > 850) {
            cout << "Invalid input. What is your credit score?: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "Enter initial deposit amount: $";
        while (!(cin >> deposit) || deposit < 0) {
            cout << "Invalid input. Please enter a positive number: $";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        newmembers[i].set_ac_name(First, last);
        newmembers[i].set_ac_type(accountType);
        newmembers[i].set_ac_balance(deposit);
        newmembers[i].set_ac_interest_rate(credit_score);
    }

    cout << "\nAccount Summaries:\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < 10; i++) {
        cout << "\nAccount #" << newmembers[i].get_ac_number() << endl;
        cout << "\nRouting #" << newmembers[i].get_ac_routing() << endl;
        cout << "\nAccount Holder Name: " << newmembers[i].get_ac_fname() << " " << newmembers[i].get_ac_lname() << endl;
        cout << "\nBalance: $" << newmembers[i].get_ac_balance() << endl;
        cout << "\nInterest Rate: " << newmembers[i].get_ac_interest() << endl;
    }







    return EXIT_SUCCESS;
}
