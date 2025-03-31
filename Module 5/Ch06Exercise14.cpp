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
  cin >> dblHourlyrate;
  cin >> dblTime;
  cin >> dblIncome;

  //Calculations
  dblPrice = TaxBilling(dblIncome, dblTime, dblHourlyrate);

  //Output
   cout << dblPrice;



  system("PAUSE");
  return EXIT_SUCCESS;
}