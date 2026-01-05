// create struct for 
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    // create struct for a company division
    struct company_division {
        string division_name;
        // sales for each quarter in array to make easier to track
        float quarterly_sales[4];
        float total_annual_sales;
        float average_quarterly_sales;
    };

    // initialize four structs for each division
    // initialize division names
    company_division east;
    company_division west;
    company_division north; 
    company_division south;
    east.division_name = "East";
    west.division_name = "West";
    north.division_name = "North";
    south.division_name = "South";

     // print rows for each one with changeable column spacing
    // declare constants for column width
    // COL1 is only for first column, SPACING is width for dollar amounts
    const int COL1 = 23; 
    const int SPACING = 10;

    // create array of structs to iterate through each quarterly sales
    company_division all_company_divisions[4] = {east, west, north, south};
    float total_sales = 0;

      //TAKES INPUT FROM IOSTREAM - remove multi-line comment block to utilize
    for(int division = 0; division < 4; division++) {
        // for each division, user is asked to input each quarter
        // total sale amount goes in accumulator variable total_sales
        for(int quarter = 0; quarter < 4; quarter++) {
            cout << "Enter Q" << quarter + 1 << " sales for " << all_company_divisions[division].division_name << ": ";
            cin >> all_company_divisions[division].quarterly_sales[quarter];
            total_sales += all_company_divisions[division].quarterly_sales[quarter];
        }
        // assign values total_annual_sales and average_quarterly_sales for each division
        all_company_divisions[division].total_annual_sales = total_sales;
        all_company_divisions[division].average_quarterly_sales = total_sales / 4;
        // reset accumulator
        total_sales = 0;
    }
    
    // print out first line for table header
    cout << setw(COL1) << left<< "Division:";
    for(int division = 0; division < 4; division++) {
        cout << setw(SPACING) << left << all_company_divisions[division].division_name;
    }
    cout << endl;

    
    cout << fixed << setprecision(2);
    // print row of quarterly sales for each division
    // subtract number of preset characters from spacing (ie. dollar sign)
    for(int quarter = 0; quarter < 4; quarter++) {
        cout << "Q" << quarter + 1 << setw(COL1 - 2) << left << ":";
        for(int division = 0; division < 4; division ++) {
            cout << "$" << setw(SPACING - 1) << left << all_company_divisions[division].quarterly_sales[quarter];
        }
        cout << endl;
    }

    // print row for total_annual_sales member 
    cout<< setw(COL1) << left << "Total sales:";
    for(int division = 0; division < 4; division ++) {
        cout << "$" << setw(SPACING - 1) << left << all_company_divisions[division].total_annual_sales;
    }
    cout << endl;

    // print row for average_quarterly_sales member
    cout<< setw(COL1) << left << "Avg. quarterly sales:";
    for(int division = 0; division < 4; division ++) {
        cout << "$" << setw(SPACING - 1) << left << all_company_divisions[division].average_quarterly_sales;
    }
    cout << endl;
    

    
    // INPUT FROM FILE
    // opens the file "quarter_sales.txt" for input, a file of 16 numbers for each division's 4 quarterly sales
    // divisions are inputted in order East, West, North, South
    ifstream quarterly_sales_file("quarter_sales.txt");

    // reads numbers until end of file 
    while(!quarterly_sales_file.eof()) {
        for(int division = 0; division < 4; division++) {
            // total_sales = local variable/accumulator to sum quarterly sales
            total_sales = 0;
            // iterate through each division's 4 quarterly sales
            for(int quarter = 0; quarter < 4; quarter++) {
                quarterly_sales_file >> all_company_divisions[division].quarterly_sales[quarter];
                total_sales += all_company_divisions[division].quarterly_sales[quarter];
            }
            all_company_divisions[division].total_annual_sales = total_sales;
            all_company_divisions[division].average_quarterly_sales = total_sales / 4;
        }
    }

    // print the division names at the top of the table
    cout << setw(COL1) << left<< "Division:";
    for(int division = 0; division < 4; division++) {
        cout << setw(SPACING) << left << all_company_divisions[division].division_name;
    }
    cout << endl;

    // print row of quarterly sales for each division
    // subtract number of preset characters from spacing (ie. dollar sign)
    cout << fixed << setprecision(2);
    // reverse the division and quarter to print by each quarter for each row
    for(int quarter = 0; quarter < 4; quarter++) {
        cout << "Q" << quarter + 1 << setw(COL1 - 2) << left << ":";
        for(int division = 0; division < 4; division ++) {
            cout << "$" << setw(SPACING - 1) << left << all_company_divisions[division].quarterly_sales[quarter];
        }
        cout << endl;
    }

    // print row for each division's total_annual_sales member 
    cout<< setw(COL1) << left << "Total sales:";
    for(int division = 0; division < 4; division ++) {
        cout << "$" << setw(SPACING - 1) << left << all_company_divisions[division].total_annual_sales;
    }
    cout << endl;

    // print row for each division's average_quarterly_sales member
    cout<< setw(COL1) << left << "Avg. quarterly sales:";
    for(int division = 0; division < 4; division ++) {
        cout << "$" << setw(SPACING - 1) << left << all_company_divisions[division].average_quarterly_sales;
    }
    cout << endl;
    
}

