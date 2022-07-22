#ifndef INPUTHANDLING_HPP
#define INPUTHANDLING_HPP

struct Student
{
    unsigned int ID;
    char grade_option;
    std::string name;
    int* grades;
    double total_score;
};

int* artifact_total_input(int num_of_inputs);

int* artifact_weight_input(int num_of_inputs);

Student* student_info_input(int num_of_students);

void student_grade_input(Student*& students, int num_of_students, int num_of_raw_students, int num_of_grades);

double* cutpoint_input();

#endif