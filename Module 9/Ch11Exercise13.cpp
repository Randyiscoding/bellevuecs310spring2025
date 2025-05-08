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
    long long ac_route_gen() {
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
            if (type == 0) {ac_type = "Checking";}
            else if (type == 1) {ac_type = "Savings";}
            else {ac_type = "unknown";}
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

    void setInterestRate(double rate) { interestRate = ac_balance/rate; }
    void postInterest() {ac_balance += ac_balance * interestRate;}
    bool withdraw(double amount) {return BankAccount::withdraw(amount);}


    void printAccountInfo() {
        cout << "Account Type: Savings\n";
        cout << "Interest Rate: " << interestRate << "\n";
    }
};

int BankAccount::ac_numbergen = 100000000;
int main() {

    string First;
    string last;
    int accountType = 10;
    double deposit = 0.00;
    int credit_score = 0;
    SavingsAccount newmember1;
    CheckingAccount newmember0;



    cout << "\nSetting up account" << endl;
    cout << "Enter account type (0 for Checking, 1 for Savings): ";
    while (!(cin >> accountType) || (accountType != 0 && accountType != 1)) {
        cout << "Invalid input. Please enter 0 for Checking or 1 for Savings: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    switch (accountType) {
        case 0:
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
        newmember0.set_ac_name(First, last);
        newmember0.set_ac_type(accountType);
        newmember0.set_ac_balance(deposit);
        newmember0.set_ac_interest_rate(credit_score);
        break;
        case 1:
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
        newmember1.set_ac_name(First, last);
        newmember1.set_ac_type(accountType);
        newmember1.set_ac_balance(deposit);
        newmember1.setInterestRate(credit_score);
        break;
    }

cout << "\nAccount Summaries:\n";
cout << fixed << setprecision(2);
switch (accountType) {
    case 0:
        cout << "\nAccount #" << newmember0.get_ac_number() << endl;
        cout << "\nRouting #" << newmember0.get_ac_routing() << endl;
        cout << "\nAccount Holder Name: " << newmember0.get_ac_fname() << " " << newmember0.get_ac_lname() << endl;
        cout << "\nBalance: $" << newmember0.get_ac_balance() << endl;
        newmember0.printAccountInfo();
    break;
    case 1:
        cout << "\nAccount #" << newmember1.get_ac_number() << endl;
        cout << "\nRouting #" << newmember1.get_ac_routing() << endl;
        cout << "\nAccount Holder Name: " << newmember1.get_ac_fname() << " " << newmember1.get_ac_lname() << endl;
        newmember1.printAccountInfo();
        cout << "\nBalance: $" << newmember1.get_ac_balance() << endl;
    break;
}







    return EXIT_SUCCESS;
}