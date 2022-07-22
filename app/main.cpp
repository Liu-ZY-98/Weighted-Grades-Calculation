#include <iostream>
#include <string>

#include "InputHandling.hpp"
#include "OutputHandling.hpp"

int main()
{
    int num_of_artifacts;
    std::cin >> num_of_artifacts;
    int* artifact_total = artifact_total_input(num_of_artifacts);
    int* artifact_weight = artifact_weight_input(num_of_artifacts);

    int num_of_students;
    std::cin >> num_of_students;
    Student* students = student_info_input(num_of_students);

    int num_of_raw_students;
    std::cin >> num_of_raw_students;
    student_grade_input(students, num_of_students, num_of_raw_students, num_of_artifacts);

    students_scores(students, artifact_total, artifact_weight, num_of_students, num_of_artifacts);
    total_scores_output(students, num_of_students);

    int cutpoints_set;
    std::cin >> cutpoints_set;
    for (int cutpoint = 0; cutpoint < cutpoints_set; cutpoint++)
    {
        double* cutpoints = cutpoint_input();
        final_score_output(students, cutpoints, num_of_students, cutpoint+1);
        delete[] cutpoints;
    }

    for (int n = 0; n < num_of_students;n++)
    {
        delete[] students[n].grades;
    }
    delete[] students;
    delete[] artifact_total;
    delete[] artifact_weight;
    
    return 0;
}

