// Created by Randy Easton on 3/7/2025.

/*
To make a profit, a local store marks up the prices of its items by a certain percentage.  Write a C++ program that
reads the original price of the item sold, the percentage of the marked-up price, and the sales tax rate.
The program then outputs the original price of the item, the percentage of the mark-up, the store's selling price of
the item, the sales tax rate, the sales tax, and the final price of the item.  (The final price of the item is the
selling price plus the sales tax.)

 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <conio.h>

using namespace std;

void RetailMarkup() {
    //I misread the assignment after completeing this function so instead of waisting the time i just turned into a
    //function

    //Variables
    double dblPrice = 0.00;
    double dblTax = 0.00;
    double dblPretax = 0.00;
    double dblCost = 0.00;
    double dblMarkup = 0.00;
    double displayMarkup = 0;
    double displayTax = 0;

    //Inputs
    cout << "Enter the price you paid for the item:" << endl;
    cin >> dblPrice;
    cout << "Enter your City's Sales Tax:" << endl;
    cin >> dblTax;
    cout << "Enter The Retail Markup percentage" << endl;
    cin >> dblMarkup;

    //Calculations
    if (dblTax < 1) { //allows user to input tax as whole or decimal number
        displayTax = dblTax * 100; //For Displaying tax rate
        dblTax = dblTax + 1;
    }
    else {
        displayTax = dblTax;
        dblTax = (dblTax/100)+1;
    }
    if (dblMarkup < 1) {
        displayMarkup = dblMarkup * 100; // For Displaying Markup Percentage
        dblMarkup = dblMarkup + 1;
    }
    else {
        displayMarkup = dblMarkup;
        dblMarkup = (dblMarkup/100) + 1;
    }
    dblPretax = dblPrice/dblTax; //Calcs the pretaxed cost of the item or cost-to-consumer price

    /* From https://alicepos.com/calculate-retail-markup/
    What is a Good Retail Markup?
    Usually, retailers aim for a retail markup of around 50%,
    but this can vary depending on industry, product types and
    several other factors. */

    dblCost = dblPretax/dblMarkup; //calcs the wholesale cost of the item

    //output
    cout << "The wholesale cost of this item is: $"<< dblCost << endl;
    cout << "The Markup you paid was: "<< displayMarkup <<"% of the Wholesale price" << endl;
    cout << "You paid: " << displayTax << "% in sales tax" << endl;
}

int main() {
    //VariablesInputs
    double dblOriginalPrice = 0;
    double dblMarkupPercentage = 0;
    double dblSalesTax = 0;

    //VariableOutputs
    double DisplayOriginalPrice;
    double DisplayMarkupPercentage = 0;
    double DisplayStorePrice = 0;
    double DisplayTaxRate = 0;
    double DisplaySalestax = 0;
    double DisplayFinalSale = 0;

    //inputs
    cout << "What is the wholesale or suspected wholesale cost of this item (USD)? " << endl;
    cin >> dblOriginalPrice;
    cout << "What is the expected retail markup of this item (Percentage)? " << endl;
    cin >> dblMarkupPercentage;
    cout << "What is your city's sales tax rate" << endl;
    cout << "(ex: Philadelphia's Sales tax is 8%)? " << endl;
    cin >> dblSalesTax;

    //Calculations
    DisplayOriginalPrice = dblOriginalPrice;
    if (dblMarkupPercentage < 1) {
        DisplayMarkupPercentage = dblMarkupPercentage * 100; // For Displaying Markup Percentage
        DisplayStorePrice = dblOriginalPrice + (dblOriginalPrice * dblMarkupPercentage);

        //dblMarkup = dblMarkup + 1;
    }
    else {
        DisplayMarkupPercentage = dblMarkupPercentage;
        dblMarkupPercentage = (dblMarkupPercentage/100);
        DisplayStorePrice = dblOriginalPrice + (dblOriginalPrice * dblMarkupPercentage);
    }
    if (dblSalesTax < 1) {
        DisplayTaxRate = dblSalesTax * 100; // For Displaying Markup Percentage
        DisplaySalestax = DisplayStorePrice * dblSalesTax;
    }
    else {
        DisplayTaxRate = dblSalesTax;
        DisplaySalestax = DisplayStorePrice * (dblSalesTax/100);
    }

    DisplayFinalSale = DisplayStorePrice + DisplaySalestax;

    //Outputs
    cout << endl;
    cout << endl;
    cout << "The Wholesale Cost of the Item is: $";
    cout << DisplayOriginalPrice << endl;
    cout << "The Retail Markup of the item is: ";
    cout << DisplayMarkupPercentage;
    cout << "%" << endl;
    cout << "The Store price is: $";
    cout << DisplayStorePrice << endl;
    cout << "Your City's Sales Tax Rate is: ";
    cout << DisplayTaxRate;
    cout << "%" << endl;
    cout << "You paid: $";
    cout << DisplaySalestax;
    cout << " in sales tax" << endl;
    cout << "Your final total is: $";
    cout << DisplayFinalSale << endl;
    cout << endl;
    cout << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}