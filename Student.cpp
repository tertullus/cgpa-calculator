#include "Student.h"

Student::Student()
{
    level = 0;
    grade_points = 0.0;
    total_units = 0.0;
    gpa = 0.0;
    cgpa = 0.0;
    local_num_courses = 0;
    local_grade_points = 0;
    local_total_units = 0;

    cout << "Welcome to the CGPA Calculator Dashboard!" << endl << endl;
    cout << "As it is your first time here, please let us know you are." << endl << endl;
    cout << "Name: "; cin >> name; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Matric Number: "; cin >> matric_no; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Department: "; cin >> dept; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
}

Student::~Student()
{
}

float Student::calcGPA()
{
    cout << "How many courses did you offer? "; cin >> local_num_courses; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    local_courses = new Course[local_num_courses];

    cout << "\nEnter your course details below." << endl << endl;

    for(int i = 0; i < local_num_courses; i++)
    {
        cout << i + 1 << "." << endl;
        cout << "Course Code: "; cin >> local_courses[i].course_code; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Course Unit: "; cin >> local_courses[i].course_unit; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(local_courses[i].course_unit < 1 || local_courses[i].course_unit > 6)
        {
            cout << "Please enter a valid course unit: ";
            cin >> local_courses[i].course_unit; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Course Grade: "; cin >> local_courses[i].course_grade; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(local_courses[i].course_grade != "A" && local_courses[i].course_grade != "B" && local_courses[i].course_grade != "C" && local_courses[i].course_grade != "D" && local_courses[i].course_grade != "E" && local_courses[i].course_grade != "F")
        {
            cout << "Please enter a valid course grade: ";
            cin >> local_courses[i].course_grade; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl;
    }

    for(int i = 0; i < local_num_courses; i++)
    {
        if(local_courses[i].course_grade == "A")
        {
            local_grade_points += local_courses[i].course_unit * 5;
            grade_points += local_courses[i].course_unit * 5;
        }
        else if(local_courses[i].course_grade == "B")
        {
            local_grade_points += local_courses[i].course_unit * 4;
            grade_points += local_courses[i].course_unit * 4;
        }
        else if(local_courses[i].course_grade == "C")
        {
            local_grade_points += local_courses[i].course_unit * 3;
            grade_points += local_courses[i].course_unit * 3;
        }
        else if(local_courses[i].course_grade == "D")
        {
            local_grade_points += local_courses[i].course_unit * 2;
            grade_points += local_courses[i].course_unit * 2;
        }
        else if(local_courses[i].course_grade == "E")
        {
            local_grade_points += local_courses[i].course_unit * 1;
            grade_points += local_courses[i].course_unit * 1;
        }
        else
        {
            local_grade_points += local_courses[i].course_unit * 0;
            grade_points += local_courses[i].course_unit * 0;
        }
    }

    for(int i = 0; i < local_num_courses; i++)
    {
        local_total_units += local_courses[i].course_unit;
        total_units += local_courses[i].course_unit;
    }

    gpa = local_grade_points / local_total_units;
    return gpa;
}

void Student::calcCGPA()
{
    cout << "What's your level? "; cin >> level; cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while(level != 100 && level != 200 && level != 300 && level != 400 && level != 500)
    {
        cout << "Please enter a valid level: ";
        cin >> level; cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }

    for(int i = 0; i < level; i += 100)
    {
        cout << "\n" << i + 100 << " level" << endl;
        calcGPA();

        cout << "S/N" << "\t" << "Course Code" << "\t"
        << "Course Unit" << "\t" << "Grade" << "\t"
        << "Grade Point" << endl;
        for(int j = 0; j < local_num_courses; j++)
        {
            if(local_courses[j].course_grade == "A")
            {
                cout << j + 1 << "." << "\t" << local_courses[j].course_code
                << "\t\t   " << local_courses[j].course_unit << "\t\t  "
                << local_courses[j].course_grade << "\t   " << 5 << endl;
            }
            else if(local_courses[j].course_grade == "B")
            {
                cout << j + 1 << "." << "\t" << local_courses[j].course_code
                << "\t\t   " << local_courses[j].course_unit << "\t\t  "
                << local_courses[j].course_grade << "\t   " << 4 << endl;
            }
            else if(local_courses[j].course_grade == "C")
            {
                cout << j + 1 << "." << "\t" << local_courses[j].course_code
                << "\t\t   " << local_courses[j].course_unit << "\t\t  "
                << local_courses[j].course_grade << "\t   " << 3 << endl;
            }
            else if(local_courses[j].course_grade == "D")
            {
                cout << j + 1 << "." << "\t" << local_courses[j].course_code
                << "\t\t   " << local_courses[j].course_unit << "\t\t  "
                << local_courses[j].course_grade << "\t   " << 2 << endl;
            }
            else if(local_courses[j].course_grade == "E")
            {
                cout << j + 1 << "." << "\t" << local_courses[j].course_code
                << "\t\t   " << local_courses[j].course_unit << "\t\t  "
                << local_courses[j].course_grade << "\t  " << 1 << endl;
            }
            else
            {
                cout << j + 1 << "." << "\t" << local_courses[j].course_code
                << "\t\t   " << local_courses[j].course_unit << "\t\t  "
                << local_courses[j].course_grade << "\t   " << 0 << endl;
            }
        }
        cout << endl;
        cgpa = grade_points / total_units;
        cout << "CGPA: " << fixed << setprecision(4) << cgpa << endl;
    }
}
