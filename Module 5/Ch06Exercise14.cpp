//
// Created by Randy Easton on 3/31/2025.
//



#include <cstdlib>
#include <iostream>
#include <cmath>

double TaxBilling(double income, double Consult_time, double hourly_Rate) {
    double Billing_Price;

    if (income <= 25000 and Consult_time <= 30){Billing_Price = 0;}
    else if (income <= 25000 and Consult_time > 30){Billing_Price = (hourly_Rate *.40)*(Consult_time/60);}
    else if (income > 25000 and  Consult_time <= 20){Billing_Price = 0;}
    else {Billing_Price = (hourly_Rate *.70)*(Consult_time/60);}

    return Billing_Price;
}

using namespace std;
int main(){

  //Variables
  double dblIncome;
  double dblTime;
  double dblPrice;
  double dblHourlyrate;

  //Inputs
  cout << "Welcome to J&J Accounting Firm's Tax Consultation Billing System\n";
  cout << "-----------------------------------------------------------------\n\n";
  cout << "Please enter the hourly consultation rate (in dollars): $";
  cin >> dblHourlyrate;
  cout << "\nEnter the total consultation time (in minutes): ";
  cin >> dblTime;
  cout << "Enter your total income for the year: $";
  cin >> dblIncome;

  //Calculations
  dblPrice = TaxBilling(dblIncome, dblTime, dblHourlyrate);

  //Output
  struct group_facet: public std::numpunct<char> {
  protected:
    string do_grouping() const { return "\003"; }
  };
  cout.imbue(locale(cout.getloc(), new group_facet));
  cout.precision(2);

  cout << "\n-----------------------------------------------\n";
  cout << "Billing Summary:\n";
  cout << "Hourly Rate: $" << dblHourlyrate << "\n";
  cout << "Consultation Time: " << dblTime << " minutes\n";
  cout << "Income: $" << fixed << dblIncome << "\n";
  cout << "-----------------------------------------------\n";

  if (dblPrice == 0) {
      cout << "Great news! Your consultation is free of charge.\n";
  } else {
      cout << "Total amount due: $" << fixed << dblPrice << "\n";
  }
  cout << "Thank you for using our service!\n";
  cout << "-----------------------------------------------\n";



  system("PAUSE");
  return EXIT_SUCCESS;
}