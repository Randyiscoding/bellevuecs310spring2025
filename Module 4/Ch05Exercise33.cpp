//
// Created by Randy Easton on 3/31/2025.
//

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
int main(){

  //Variables
  double dblTimefirstdish;
  double dblTimeseconddish;
  double dblTimetoprep;
  double dblTimeupdate;
  string user;
  vector<double> dblArrayUpdate = {dblTimefirstdish};
  int arraylength = sizeof(dblArrayUpdate)/sizeof(dblArrayUpdate[0]);

  //Input
  cout << "Whats your first name \n";
  cin >> user;
  cout << "Enter the time for the first dish: \n";
  cin >> dblTimefirstdish; //a
  cout << "Enter the incremental time for each dish: \n";
  cin >> dblTimeseconddish; //b
  cout << "Enter the total available time: \n";
  cin >> dblTimetoprep; //t


  //Calculations
  dblTimeupdate = dblTimefirstdish + dblTimeseconddish;
  dblArrayUpdate.push_back(dblTimeupdate);

  while(dblTimeupdate <= dblTimetoprep) {
    dblTimeupdate = dblTimeseconddish + dblTimeupdate;
    dblArrayUpdate.push_back(dblTimeupdate);
  };




  double y;
  int counter = 0;
  for (double x : dblArrayUpdate) {
    if (y+x > dblTimetoprep){break;}
    else {
      y = x+y;
      counter++;
    }
  }


  //output
  cout << "Hi, " << user << "!" << endl;
  cout << "You have time to make " << counter << " dish(es)" << endl; //number of dishes

  system("PAUSE");
  return EXIT_SUCCESS;
  }