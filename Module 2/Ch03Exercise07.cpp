//
// Created by Randy Easton on 3/10/2025.
//

/*
Source: chapter 3, programming exercise 7
Interest on a credit card’s unpaid balance is calculated using the average daily balance.
Write a program that accepts as input netBalance, payment, d1, d2, and interest rate per month. The program outputs the
interest. Format your output to two decimal places and use a thousands separator for the dollar amounts.
 */

#include <iostream>
#include <iomanip>
#include <ios>

using namespace std;
int main(){

  //Variables
  double dblNetbalance = 0;
  double dblPayment = 0;
  double dblBillCycleDays = 0; //D1
  double dblPaymentDays = 0; //D2
  double dblInterestRate = 0;


  //Inputs
  cout << "What is the Current Balance on your Bill?" << endl;
  cin >> dblNetbalance;
  cout << "How much did you pay on this month's Bill?" << endl;
  cin >> dblPayment;
  cout << "How many days are in your billing cycle?" << endl;
  cin >> dblBillCycleDays; //D1
  cout << "At the time you made the payment, How many days were left on the bill cycle" << endl;
  cout << "ex: If you have 30 days in your cycle and you paid on the 22nd day Then you" << endl;
  cout << "had/have 8 days left." << endl;
  cin >> dblPaymentDays; //D2
  cout << "What is the interest Rate?" << endl;
  cin >> dblInterestRate;

  //Calculations
  double DisplayInterest = 0;
  double calcAverageDailyBalance = (dblNetbalance*dblBillCycleDays - dblPayment*dblPaymentDays)/dblBillCycleDays;
  if (dblInterestRate < 1) {
    DisplayInterest = calcAverageDailyBalance*dblInterestRate;
  }
  else {
    DisplayInterest = calcAverageDailyBalance*(dblInterestRate/100);
  }

  //Output
  if (locale().name() == "C" or locale().name() == "*") {
    try{
      //Credit: https://en.cppreference.com/w/cpp/locale/money_put
      cout.precision(2);
      std::cout.imbue(std::locale("en_US.UTF-8"));
      //Credit. The above attempts to force the local from POSIX to the host system.
      //Doesn't seem to work well tho :( This is the easier and preferred route.
      //I think the problem is my IDE/Compiler (I use CLion by JetBrains).

      std::cout << "The interest You paid was: " << std::showbase << std::put_money(DisplayInterest) << '\n';

    }
    catch (...) {
      //Credit: https://www.daniweb.com/programming/software-development/threads/432889/currency-formatting
      struct group_facet: public std::numpunct<char> {
      protected:
        string do_grouping() const { return "\003"; }
      };
      cout.imbue(locale(cout.getloc(), new group_facet));
      //Credit

      cout.precision(2);
      cout << "The interest you paid was: $" << fixed << DisplayInterest << endl;
    }
  }

}