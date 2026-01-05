#include <iomanip> 
#include <iostream>
#include <fstream>
#include "courses.h"
using namespace std;


/* INPUT: prompt: string to ask user for what input
          min_value and max_value: sets bounds for acceptable input
    
    asks user the prompt parameter, then accepts input with CIN and returns if acceptable
*/
double get_validated_input(string prompt, double min_value, double max_value) {
    double value;
    while(true) {
        cout << prompt;
        cin >> value;
        
        if(cin.fail() || value < min_value|| value > max_value) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

// prints a row of double data with a title/item/category/type for the row
void print_data_row(string item, double number_data_points, vector <double> data_points, 
                int COL1_SPACING, int COL_SPACING) {
    cout << setw(COL1_SPACING) << left << item;
    cout << fixed << setprecision(2);
    
    for(int i = 0; i < number_data_points; i++) {
        cout << setw(COL_SPACING) << left << data_points[i];
    }
}

// write a row of double data with title/item/category/type for the row 
// INPUT:   ofstream file
//          item = row's category name
//          number_data_points = number of elements in vector
//          data_points = data to be written
void write_data_row(ofstream& File, string item, double number_data_points, vector <double> data_points, 
                int COL1_SPACING, int COL_SPACING) {
    File << setw(COL1_SPACING) << left << item;
    File << fixed << setprecision(2);
    for(int i = 0; i < number_data_points; i++) {
        File << setw(COL_SPACING) << left << data_points[i];
    }
    File << endl;
}


int final_grade_calculator() {
    // set constant for number of potential grade letters 
    const int NUMBER_POSSIBLE_GRADES = 5;
    // array for MINIMUM grade to get A, B, C, D, F
    double letter_grade_threholds[NUMBER_POSSIBLE_GRADES] = {90.0, 80.0, 70.0, 60.0, 50.0};
    char letter_grade_letters[NUMBER_POSSIBLE_GRADES] = {'A', 'B', 'C', 'D', 'F'};
    
    // ask user for number of courses
    // create a dynamic vector based on user input
    int user_number_of_courses = 0;
    cout << "Number of courses: ";
    cin >> user_number_of_courses;
    vector <Course> user_courses(user_number_of_courses);

    // INPUT VIA CONSOLE 
    // loops through vector for user to input courses and grades
    for(int i = 0; i < user_number_of_courses; i++) {

        cout << "Enter name for course " << i + 1 << ": ";
        cin >> user_courses[i].name;

        // use get_validated_input function to receive grades and exam weight
        user_courses[i].grade = get_validated_input("Enter grade: ", 0, 150);
        user_courses[i].final_exam_weight = get_validated_input("Enter final exam weight (%): ", 0, 100);
    }

    cout << "Grading thresholds based on " << user_courses[0].final_exam_weight << endl;
    int COL1_SPACING = 12;
    int COLUMN_SPACING = 10;

    // loop through number of courses given by user
    // course LOCAL variable = current course, accesses the user_courses array
    for(int course = 0; course < user_number_of_courses; course++) {
        determine_grade_letter(user_courses[course].grade, 
                                user_courses[course].final_exam_weight, 
                                letter_grade_threholds, 
                                NUMBER_POSSIBLE_GRADES, 
                                user_courses[course].required_grades);
    }
        // INNER LOOP: loops through letter grades 
        // creates table for grades 
        // print first column
    cout << setw(COL1_SPACING) << left << "CLASS";
    for(int i = 0; i < NUMBER_POSSIBLE_GRADES; i++) {
        cout << setw(COLUMN_SPACING) << left << letter_grade_letters[i];
        // cout << "To get an " << letter_grade_letters[i] << " in " << user_courses[course].name << ", you need a " 
        // << user_courses[course].required_grades[i] << "% on the final" << endl;
    } 
    cout << endl;

    // print first row of data for first course
    for(int course = 0; course < user_number_of_courses; course++) {
        print_data_row(user_courses[course].name, NUMBER_POSSIBLE_GRADES, user_courses[course].required_grades, COL1_SPACING, COLUMN_SPACING);
        cout << endl;
    } 
     
    
    // OUTPUT TO FILE 
    // open file called "req_grades.txt" 
    ofstream grades_file("req_grades.txt", ios::out);
    grades_file << setw(COL1_SPACING) << left << "CLASS";
    // write first row: grade letters for column headers 
    for(int i = 0; i < NUMBER_POSSIBLE_GRADES; i++) {
        grades_file << setw(COLUMN_SPACING) << left << letter_grade_letters[i];
    }
    grades_file << endl;

    // write data to file
    for(int i = 0; i < user_number_of_courses; i++) {
        write_data_row(grades_file, user_courses[i].name, NUMBER_POSSIBLE_GRADES, user_courses[i].required_grades,
                       COL1_SPACING, COLUMN_SPACING);
    }

    grades_file.close();

    return 0;
}

