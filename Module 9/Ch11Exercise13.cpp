//
// Created by Randy Easton on 4/27/2025.
//

#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>

using namespace std;



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


        //New
        bool withdraw(double amount) {
            if (amount > 0 && amount <= ac_balance) {
                ac_balance -= amount;
                return true;
            }
            return false;
        }


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

class CheckingAccount : public BankAccount {
    double minBalance;
    double serviceCharge;
    void postInterest(){ac_balance += ac_balance * ac_interest_rate;}

public:
    //Set
    void setMinimumBalance(double minBal) { minBalance = minBal; }
    void setServiceCharge(double charge) { serviceCharge = charge; }
    void writeCheck(double amount) { withdraw(amount);}

    //Get
    double getMinimumBalance() const { return minBalance; }
    double getServiceCharge() const { return serviceCharge; }
    bool belowMinimum() {return ac_balance < minBalance;}

    void printAccountInfo() {
        cout << "Account Type: Checking\n";
        cout << "Interest Rate: " << ac_interest_rate << "\n";
        cout << "Minimum Balance: $" << minBalance << "\n";
        cout << "Service Charge (if below min): $" << serviceCharge << "\n";
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:

    void setInterestRate(double rate) { interestRate = rate; }
    void postInterest() {ac_balance += ac_balance * interestRate;}
    bool withdraw(double amount) {return BankAccount::withdraw(amount);}


    void printAccountInfo() {
        cout << "Account Type: Savings\n";
        cout << "Interest Rate: " << interestRate << "\n";
    }
};