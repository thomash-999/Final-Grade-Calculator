#include "final_grade_calc.h"
#include <iostream>
using namespace std; 

int main() {
    int user_selection = 0;
    cout << "1. Calculate required grade needed on final for multiple courses " << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
    cin >> user_selection;

    if(user_selection == 1) {
        final_grade_calculator();
    }
    
}

