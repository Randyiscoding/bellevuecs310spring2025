#include <iostream>

// I am aware of the math not being correct for this code.I apologize and accept the consequences

using namespace std;
class BankAccount {
    protected:
        int ac_number = 0000;
        double ac_balance = 00.00;

    public:

        //set
        void set_ac_number(int ac_gen){ac_number = ac_gen; }
        virtual void set_balance_withdraw(double withdraw){ ac_balance -= withdraw;}
        virtual void set_balance_deposit(double deposit){ac_balance += deposit;}

        //get
        int get_ac_number(){ return ac_number;}
        double get_balance(){return ac_balance;}
        virtual void printaccountinfo() {
            cout << "Account number: " << ac_number << endl;
            cout << "Balance: $" << ac_balance << endl;
        }


};

class CheckingAccount : public BankAccount {
protected:
    double ca_interest = .00;
    double const minbal = .15 * ac_balance;;
    double const svc_charge = ca_interest * ac_balance;

public:

    //set
    void set_ca_interest(int credit_score){
        if (credit_score <= 500) {ca_interest = .29;}
        else if (credit_score >= 850) {ca_interest = .01;}
        else {ca_interest = .29 - ((0.28/349)*(credit_score - 501));}
    }
    void set_interest(){ac_balance = (ca_interest*ac_balance)+ac_balance;}
    void set_balance_withdraw (double ca_withdraw) override {ac_balance -= ca_withdraw;}
    void set_balance_deposit(double ca_deposit) override {ac_balance += ca_deposit * ca_interest;}

    //get
    double get_ca_interest() {return ca_interest*100;}
    double get_minimum_balance() {return minbal;}
    double get_svc_charge() {return svc_charge;}
    double get_ca_balance() {
        if (ac_balance < minbal) {
            ac_balance -= svc_charge;
        }
        return ac_balance;
    }

    void printaccountinfo() override {
        cout << "Your interest Rate is: " << get_ca_interest() <<"%" << endl;
        cout << "Your Minimum Balance is: $" << get_minimum_balance() << endl;
        cout << "Your Service Charge is: $" << get_svc_charge() << endl;
        cout << "Your Current Checking Account balance is: $" << get_ca_balance() << endl;
    };
};

class SavingsAccount : public BankAccount {
    protected:
        double sa_interest = .00;

    public:

        //set
        void set_sa_interest(double fed) {
            if (fed > 0 && fed < 1){sa_interest = fed;}
            else if (fed >= 1 && fed <= 100){ sa_interest = fed/100;}
            else {sa_interest = .0001; }
        }
        void set_balance_withdraw (double sa_withdraw) override {ac_balance -= sa_withdraw;}
        void set_balance_deposit(double sa_deposit) override {ac_balance += sa_deposit * sa_interest;}

        //get
        double get_sa_interest(){return sa_interest;}
        double get_sa_balance() {ac_balance += ac_balance*sa_interest; return ac_balance;}

        void printaccountinfo() override {
                cout << "Your interest Rate is: " << get_sa_interest() <<"%" << endl;
                cout << "Your Current Savings Account balance is: $" << get_sa_balance() << endl;
            };

};
int main() {
    // Create and test a Checking Account
    CheckingAccount myChecking;
    myChecking.set_ac_number(1001);
    myChecking.set_ca_interest(720); // Simulated credit score
    myChecking.set_balance_deposit(1000.00); // Deposit $1000
    myChecking.set_balance_withdraw(100.00); // Withdraw $100
    myChecking.set_interest(); // Post interest
    cout << "\n--- Checking Account Info ---\n";
    myChecking.printaccountinfo();

    // Create and test a Savings Account
    SavingsAccount mySavings;
    mySavings.set_ac_number(2001);
    mySavings.set_sa_interest(4.5); // 4.5% interest
    mySavings.set_balance_deposit(2000.00); // Deposit $2000
    mySavings.set_balance_withdraw(500.00); // Withdraw $500
    cout << "\n--- Savings Account Info ---\n";
    mySavings.printaccountinfo();
    return EXIT_SUCCESS;
}
