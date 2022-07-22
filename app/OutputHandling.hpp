#ifndef OUTPUTHANDLING_HPP
#define OUTPUTHANDLING_HPP

#include "InputHandling.hpp"

void students_scores(Student*& students, int* totals, int* weights, int stu_num, int score_num);

void total_scores_output(Student* students, int stu_num);

void final_score_output(Student* students, double* cutpoints, int stu_num, int set_num);

#endif