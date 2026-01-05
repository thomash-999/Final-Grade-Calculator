#include <iostream> 
#include <limits>
#include <string>
using namespace std;

// ONLY checks and returns input if it is an integer
// 0 = not int
// 1 = double
int input_validated_integer(int input) {
    // return 0 if stream enters failed state (non-numbers) 
    if (cin.fail()) {
        // clear error state, then remove entire stream
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0; 
    }
    else if (input == static_cast<double>(input)) {
        return 1;
    }
    return input;
}

// Loops until valid integer is inputted
int get_validated_integer_input() {
    int input;

    while(!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "looped";
    }
    return input;
}

int ask_for_validated_integer() {
    int test_int;
    double test_double;

    cout << "Enter an integer: ";
    test_int = get_validated_integer_input();
    int datatype = input_validated_integer(test_int);
    cout << "you entered " << test_int << endl;
    cout << "input is a " << datatype << endl;
    
    
}