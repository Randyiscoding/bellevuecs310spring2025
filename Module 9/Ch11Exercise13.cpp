//
// Created by Randy Easton on 4/27/2025.
//

#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>

using namespace std;

int count_vowels(string input) {
    string vowels = "0123456789!@#$%^&*()-_=+|[]{};:/?.>";
    for (char charc : input) {
        if (vowels.find(charc) != string::npos) {
            return -1;
        }
    }
    return 0;
}

class BankAccount {
    static int ac_numbergen;
    int ac_route_gen() {
        random_device rd;
        mt19937 gen(rd());
        long long min_val = 100000000LL;
        long long max_val = 999999999LL;
        uniform_int_distribution<long long> dist(min_val, max_val);
        return dist(gen);
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
    virtual bool withdraw(double amount) {
        if (amount > 0 && amount <= ac_balance) {
            ac_balance -= amount;
            return true;
        }
        return false;
    }

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
        else {ac_interest_rate = .29 - ((0.28/349)*(credit_score - 501));}
    }

    string get_ac_fname(){return ac_fname;}
    string get_ac_lname(){return ac_lname;}
    string get_ac_type(){return ac_type;}
    int get_ac_number(){return ac_number;}
    int get_ac_routing(){return ac_routing;}
    double get_ac_balance(){return ac_balance;}
    double get_ac_interest(){return ac_interest_rate;}

    virtual void printAccountInfo() const {cout << "General Account info \n";}
    virtual  ~BankAccount() = default;
};

class CheckingAccount : public BankAccount {
    double minBalance;
    double serviceCharge;
    void postInterest() { ac_balance += ac_balance * ac_interest_rate; }

public:
    void setMinimumBalance(double minBal) { minBalance = minBal; }
    void setServiceCharge(double charge) { serviceCharge = charge; }
    void writeCheck(double amount) { withdraw(amount); }
    double getMinimumBalance() const { return minBalance; }
    double getServiceCharge() const { return serviceCharge; }
    bool belowMinimum() { return ac_balance < minBalance; }

    void checkingaccount(string First, string last, int accountType, double deposit, int credit_score) {
        set_ac_name(First, last);
        set_ac_type(accountType);
        set_ac_balance(deposit);
        set_ac_interest_rate(credit_score);
    }

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
    void setInterestRate(double rate) { interestRate = ac_balance / rate; }
    void postInterest() { ac_balance += ac_balance * interestRate; }
    bool withdraw(double amount) override {
        return BankAccount::withdraw(amount);
    }

    void savingsaccount(string First, string last, int accountType, double deposit, int credit_score) {
        set_ac_name(First, last);
        set_ac_type(accountType);
        set_ac_balance(deposit);
        setInterestRate(credit_score);
    }

    void printAccountInfo() {
        cout << "Account Type: Savings\n";
        cout << "Interest Rate: " << interestRate << "\n";
    }
};

int BankAccount::ac_numbergen = 100000000;

int main() {
    BankAccount* newmembers[2];
    string First, last;
    int accountType;
    double deposit;
    int credit_score;

    for (int i = 0; i < 2; ++i) {
        cout << "\nSetting up account" << endl;
        cout << "Enter account type (0 for Checking, 1 for Savings): ";
        while (!(cin >> accountType) || (accountType != 0 && accountType != 1)) {
            cout << "Invalid input. Please enter 0 for Checking or 1 for Savings: ";
            cin.clear(); cin.ignore(10000, '\n');
        }
        cout << "Enter first name: "; cin >> First;
        while (First.empty() || count_vowels(First) == -1) {
            cout << "First name cannot be empty or contain special characters. Please re-enter: ";
            cin >> First;
        }
        cout << "Enter last name: "; cin >> last;
        while (last.empty() || count_vowels(last) == -1) {
            cout << "Last name cannot be empty or contain special characters. Please re-enter: ";
            cin >> last;
        }
        cout << "Enter Your credit Score: ";
        while (!(cin >> credit_score) || credit_score < 0 || credit_score > 850) {
            cout << "Invalid input. What is your credit score?: ";
            cin.clear(); cin.ignore(10000, '\n');
        }
        cout << "Enter initial deposit amount: $";
        while (!(cin >> deposit) || deposit < 0) {
            cout << "Invalid input. Please enter a positive number: $";
            cin.clear(); cin.ignore(10000, '\n');
        }

        if (accountType == 0) {
            CheckingAccount* newmember0 = new CheckingAccount();
            newmember0->checkingaccount(First, last, accountType, deposit, credit_score);
            newmembers[i] = newmember0;
        } else {
            SavingsAccount* newmember1 = new SavingsAccount();
            newmember1->savingsaccount(First, last, accountType, deposit, credit_score);
            newmembers[i] = newmember1;
        }
    }

    cout << "\nAccount Summaries:\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < 2; ++i) {
        cout << "\nAccount #" << newmembers[i]->get_ac_number() << endl;
        cout << "Routing #" << newmembers[i]->get_ac_routing() << endl;
        cout << "Account Holder Name: " << newmembers[i]->get_ac_fname() << " " << newmembers[i]->get_ac_lname() << endl;
        cout << "Balance: $" << newmembers[i]->get_ac_balance() << endl;
        newmembers[i]->printAccountInfo();
        newmembers[i]->get_ac_balance();
        delete newmembers[i];
    }

    return EXIT_SUCCESS;
}