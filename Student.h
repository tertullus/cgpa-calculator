#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <ios>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

struct Course
{
    string course_code;
    int course_unit;
    string course_grade;
};

class Student
{
private:
//    int option;
    string name;
    string matric_no;
    string dept;
    int level;
    Course *courses;
    int num_courses;
    float grade_points;
    float total_units;
    float gpa, cgpa;

    Course *local_courses;
    int local_num_courses;
    float local_grade_points = 0;
    float local_total_units = 0;
public:
    Student();
    ~Student();

    float calcGPA();
    void calcCGPA();
    void printCGPA();
};

#endif // STUDENT_H
