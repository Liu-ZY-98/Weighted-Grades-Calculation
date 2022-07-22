#include <iostream>
#include "InputHandling.hpp"


int* artifact_total_input(int num_of_inputs)
{
    int* total = new int[num_of_inputs];
    for(int n = 0; n < num_of_inputs; n++)
    {
        std::cin >> total[n];
    }
    return total;
}


int* artifact_weight_input(int num_of_inputs)
{
    int* weight = new int[num_of_inputs];
    for(int n = 0; n < num_of_inputs; n++)
    {
        std::cin >> weight[n];
    }
    return weight;
}


Student* student_info_input(int num_of_students)
{
    Student* students = new Student[num_of_students];
    for(int n = 0; n < num_of_students; n++)
    {
        std::cin >> students[n].ID >> students[n].grade_option;
        std::cin.ignore(1);
        std::getline(std::cin, students[n].name);
    }
    return students;
}


void student_grade_input(Student*& students, int num_of_students, int num_of_raw_students, int num_of_grades)
{
    for(int n = 0; n < num_of_students; n++)
    {
        students[n].grades = new int[num_of_grades];
        for (int num = 0; num < num_of_grades; num++)
        {
            students[n].grades[num] = 0;
        }
    }
    for(int stu = 0; stu < num_of_raw_students; stu++)
    {
        int* scores = new int[num_of_grades + 1];
        for (int s = 0; s < (num_of_grades+1); s++)
        {
            std::cin >> scores[s];
        }
        for (int student = 0; student < num_of_students; student++)
        {
            if (students[student].ID == scores[0])
            {
                for (int grade = 0; grade < num_of_grades; grade++)
                {
                    students[student].grades[grade] = scores[grade+1];
                }
            }
        }
        delete[] scores;
    }
}


double* cutpoint_input()
{
    double* cutpoints = new double[4];
    for (int num = 0; num < 4; num++)
    {
        std::cin >> cutpoints[num];
    }
    return cutpoints;
}