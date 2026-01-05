#include "final_grade_calc.h"
#include <iostream>
using namespace std; 

int main() {
    int user_selection = 0;
    cout << "1. Calculate the grade needed on the final for multiple courses" << endl;
    cout << "2. Calculate the grade needed on the final with a test dropped" << endl;
    cout << "3. " << endl;
    cin >> user_selection;

    if(user_selection == 1) {
        final_grade_calculator();
    }
    
}

