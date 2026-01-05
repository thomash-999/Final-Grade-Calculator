#include <string> 
#include <vector>
using namespace std;

// header file for dealing with coursework

// struct for a course and it's required grades
struct Course {
    string name;
    double grade, final_exam_weight;
    vector <double> required_grades;
};

/* INPUT:   grade:              current grade percentage
            category_weight:    percent weight of category to calculate from
            grade_threshold:    threholds for each grade letter minimum
            num_grade_letters:  number of letter grades given
            required_grades:    pass by reference vector to append required grades to 
calculate grade for each given letter and return as an array
*/
void determine_grade_letter(double grade, double category_weight, double grade_threholds[], 
                            int num_grade_letters, vector <double>& required_grades) {
    // amount of point contribution from current grade                            
    double weighted_contribution = grade * (1 - category_weight / 100);

    // loop and append to a vector for each grade letter 
    for(int i = 0; i < num_grade_letters; i++) {
        double required = (grade_threholds[i] - weighted_contribution) / (category_weight / 100);
        required_grades.push_back(required);
    }
}
