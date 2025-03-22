//
// Created by Randy Easton on 3/22/2025.
//

#include <iostream>
#include <iomanip>
#include <ios>
#include <algorithm>

using namespace std;
//Credit: OpenAI
// Function to convert a double to a string with two decimal places
string formatCurrency(double value) {
  ostringstream out;
  out << "$" << fixed << setprecision(2) << value;
  return out.str();
}


int main(){
  //input variables
  double dblNetBookPrice = 0.00;
  int intCopiesSold = 0;

  //Inputs
  cout << "Enter the net price of each copy of the novel: " << endl;
  cin >> dblNetBookPrice;
  cout << "Enter the estimated number of copies that will be sold: " << endl;
  cin >> intCopiesSold;

  //calculation variables
  double option1 = 5000.00+20000.00;
  double option2 = (.125 * dblNetBookPrice)*intCopiesSold;
  double option3 = 0;
  int options = 0;


  //calculations
  if (intCopiesSold <= 4000) {
    option3 = (.1 * dblNetBookPrice) * intCopiesSold;
  }
  else {
      int Opt3copies = intCopiesSold - 4000;
      option3 = ((.1 * dblNetBookPrice) * 4000) + ((.14 * dblNetBookPrice) * Opt3copies);
  }

  double dblCalcResults[3] = {option1, option2, option3};
  int size = sizeof(dblCalcResults) / sizeof(dblCalcResults[0]);
  double* max = max_element(dblCalcResults, dblCalcResults + size);
  if (*max == option1){options = 1;}
  else if(*max == option2){options = 2;}
  else if(*max == option3){options = 3;}

  //Display Stuff
  string DisplayOption1 = "Royalties for Option 1 are: "+formatCurrency(option1);
  string DisplayOption2 = "Royalties for Option 2 are: "+formatCurrency(option2);
  string DisplayOption3 = "Royalties for Option 3 are: "+formatCurrency(option3);

  //Dispalay and Formating
  struct group_facet: public std::numpunct<char> {
  protected:
    string do_grouping() const { return "\003"; }
  };
  cout.imbue(locale(cout.getloc(), new group_facet));
  //Credit

  cout.precision(2);

  //outputs
  switch (options) {
    case 1:
      cout << fixed << DisplayOption2 << endl;
      cout << fixed << DisplayOption3 << endl;
      cout << "\n\nYou're best option is: Option 1 \nEstimated Payout is: $" << fixed << option1 << endl;
      break;
    case 2:
      cout << fixed << DisplayOption1 << endl;
      cout << fixed << DisplayOption3 << endl;
      cout << "\n\nYou're best option is: Option 2 \nEstimated Payout is: $" << fixed << option2 << endl;
      break;
    case 3:
      cout << fixed << DisplayOption1 << endl;
      cout << fixed << DisplayOption2 << endl;
      cout << "\n\nYou're best option is: Option 3 \nEstimated Payout is: $" << fixed << option3 << endl;
      break;
    default:
      cout << "There may have been an error along the way. \nRestart the program and try again." << endl;
      break;

  }

  return EXIT_SUCCESS;
}