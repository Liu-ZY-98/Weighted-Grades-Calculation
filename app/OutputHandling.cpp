#include <iostream>
#include "OutputHandling.hpp"

double calculate_total_points(int* totals, int* weights, int* scores, int num_of_scores)
{
    double total_score = 0;
    for (int score_num = 0; score_num < num_of_scores; score_num++)
    {
        total_score += ((scores[score_num] / (double)totals[score_num]) * weights[score_num]);
    }
    return total_score;
}


std::string compute_letter_grade(double* cutpoints, double score, char grade_option)
{
    if (score >= cutpoints[0])
    {
        if (grade_option == 'G')
            return "A";
        else
            return "P";
    }
    else if (score >= cutpoints[1])
    {   
        if (grade_option == 'G')
            return "B";
        else
            return "P";
    }
    else if (score >= cutpoints[2])
    {
        if (grade_option == 'G')
            return "C";
        else
            return "P";
    }
    else if (score >= cutpoints[3])
    {
        if (grade_option == 'G')
            return "D";
        else
            return "NP";
    }
    else
    {
        if (grade_option == 'G')
            return "F";
        else
            return "NP";
    }
}


void students_scores(Student*& students, int* totals, int* weights, int stu_num, int score_num)
{
    for (int student = 0; student < stu_num; student++)
    {
        students[student].total_score = 
                        calculate_total_points(totals, weights, students[student].grades, score_num);
    }
}

void total_scores_output(Student* students, int stu_num)
{
    std::cout << "TOTAL SCORES" << std::endl;
    for (int student = 0; student < stu_num; student++)
    {
        std::cout << students[student].ID << " ";
        std::cout << students[student].name << " ";
        std::cout << students[student].total_score << std::endl;
    }
}

void final_score_output(Student* students, double* cutpoints, int stu_num, int set_num)
{
    std::cout << "CUTPOINT SET " << set_num << std::endl;
    for (int student = 0; student < stu_num; student++)
    {
        std::cout << students[student].ID << " ";
        std::cout << students[student].name << " ";
        std::cout << compute_letter_grade
            (cutpoints, students[student].total_score, students[student].grade_option) << std::endl;
    }
}